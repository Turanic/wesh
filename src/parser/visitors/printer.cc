#include "printer.hh"

#include <cassert>
#include <iostream>

namespace parser
{
namespace visitors
{
namespace
{
class Ident
{
private:
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

Ident ident {};

} // anonymous

void Printer::operator()(const std::string& str) const
{
  ++ident;
  std::cout << ident << "element: " << str << '\n';
  --ident;
}

void Printer::operator()(const ast::redir_node& redir) const
{
  using grammar::symbol_type;

  ++ident;
  std::cout << ident << "redirection: ";

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
  --ident;
}

void Printer::operator()(const ast::cmd_element& element) const
{
  boost::apply_visitor(Printer(), element);
}

void Printer::operator()(const ast::cmd_node& node) const
{
  ++ident;
  std::cout << ident << "command\n";

  for (const auto& element_ptr : node)
    operator()(element_ptr.get());

  --ident;
}

void Printer::operator()(const ast::operand& op) const
{
  boost::apply_visitor(Printer(), op);
}

void Printer::operator()(const ast::operator_node& node) const
{
  using grammar::symbol_type;

  std::cout << ident;
  switch (node.op_type)
  {
  case symbol_type::DOUBLE_AND:
    std::cout << " && ";
    break;
  case symbol_type::DOUBLE_OR:
    std::cout << " || ";
    break;
  case symbol_type::AND:
    std::cout << " & ";
    break;
  case symbol_type::OR:
    std::cout << " | ";
    break;
  case symbol_type::SEMI_COLON:
    std::cout << " ; ";
    break;
  default:
    assert(false && "invalid redirection");
    break;
  }
  std::cout << std::endl;
  operator()(node.second);
}

void Printer::operator()(const ast::expression_node& node) const
{
  ++ident;
  std::cout << ident << "expression\n"
            << ident << "{\n";

  operator()(node.first);
  for (const auto& operation : node.rest)
    operator()(operation);

  std::cout << ident << "}\n";
  --ident;
}

void Printer::operator()(const ast::statements_nodes& node) const
{
  operator()(node.first);
  for (const auto& operation : node.rest)
    operator()(operation);
  if (node.last == grammar::symbol_type::AND)
    std::cout << " &\n";
}

void Printer::operator()(const ast::ast_root& node) const
{
  std::cout << "ast - begin\n";
  if (node)
    operator()(*node);
  else
    std::cout << "empty tree\n";
  std::cout << "ast - end\n";
}

} // visitors
} // parser
