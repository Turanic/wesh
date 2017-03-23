#include "printer.hh"
#include <cassert>
#include <iostream>
#include <parser/grammar/symbols.hh>

namespace ast
{
namespace visitors
{
namespace
{
class Ident
{
private:
  /* identation size constant */
  static constexpr std::size_t kident_ = 2;
  std::size_t level_ = 0;

public:
  std::string operator()() const
  {
    return std::string(level_, ' ');
  }

  Ident& operator++()
  {
    level_ += kident_;

    return *this;
  }

  Ident& operator--()
  {
    assert(level_ >= 2);
    level_ -= kident_;

    return *this;
  }
};

std::ostream& operator<<(std::ostream& os, const Ident& ident)
{
  os << ident();

  return os;
}
} // anonymous

struct Printer::Implem
{
  Ident ident{};
};

Printer::Printer() noexcept
    : VisitorInterface::VisitorInterface()
    , pimpl_{ std::make_unique<Implem>() }
{
}

Printer::~Printer() noexcept = default;

void Printer::operator()(const std::string& str)
{
  ++pimpl_->ident;
  std::cout << pimpl_->ident << "element: " << str << '\n';
  --pimpl_->ident;
}

void Printer::operator()(const ast::redir_node& redir)
{
  using parser::grammar::symbol_type;

  ++pimpl_->ident;
  std::cout << pimpl_->ident << "redirection: ";

  if (redir.io_number)
    std::cout << *(redir.io_number);

  switch (redir.type)
  {
  case symbol_type::LEFT:
    std::cout << " < ";
    break;
  case symbol_type::RIGHT:
    std::cout << " > ";
    break;
  case symbol_type::DOUBLE_LEFT:
    std::cout << " << ";
    break;
  case symbol_type::DOUBLE_RIGHT:
    std::cout << " >> ";
    break;
  default:
    assert(false && "invalid redirection");
    break;
  }
  std::cout << redir.file << '\n';
  --pimpl_->ident;
}

void Printer::operator()(const ast::cmd_element& element)
{
  element.apply_visitor(*this);
}

void Printer::operator()(const ast::cmd_node& node)
{
  ++pimpl_->ident;
  std::cout << pimpl_->ident << "command =>\n";

  for (const auto& element : node)
    operator()(element);

  --pimpl_->ident;
}

void Printer::operator()(const ast::operand& op)
{
  op.apply_visitor(*this);
}

void Printer::operator()(const ast::operator_node& node)
{
  using parser::grammar::symbol_type;

  std::cout << pimpl_->ident << "operation ";
  switch (node.op_type)
  {
  case symbol_type::DOUBLE_AND:
    std::cout << "&&";
    break;
  case symbol_type::DOUBLE_OR:
    std::cout << "||";
    break;
  case symbol_type::OR:
    std::cout << "|";
    break;
  default:
    assert(false && "invalid operation");
    break;
  }
  std::cout << std::endl;
  operator()(node.second);
}

void Printer::operator()(const ast::expression_node& node)
{
  ++pimpl_->ident;
  std::cout << pimpl_->ident << "expression\n" << pimpl_->ident << "{\n";

  operator()(node.first);
  for (const auto& operation : node.rest)
    operator()(operation);

  std::cout << pimpl_->ident << "}\n";
  --pimpl_->ident;
}

void Printer::operator()(const ast::statement_node& node)
{
  using parser::grammar::symbol_type;

  std::cout << pimpl_->ident << "statement"
            << (node.separator == symbol_type::AND ? " [background]\n" : "\n")
            << pimpl_->ident << "(\n";

  operator()(node.exp);

  std::cout << pimpl_->ident << ")\n";
}

void Printer::operator()(const ast::ast_root& node)
{
  std::cout << "###ast - begin###\n";
  if (node)
    for (const auto& statement : *node)
      operator()(statement);
  else
    std::cout << "(empty tree)\n";
  std::cout << "##ast - end###\n";
}

} // visitors
} // ast
