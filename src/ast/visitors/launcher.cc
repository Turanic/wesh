#include "launcher.hh"
#include <cassert>
#include <vector>
#include <boost/optional.hpp>
#include <exec/process.hh>

namespace ast
{
namespace visitors
{
namespace
{
class Command
{
private:
  boost::optional<std::string> name{};
  std::vector<std::string> args{};

public:
  bool operator()()
  {
    assert(name);

    bool rcode = exec::start_process(*name, args);
    args = {};
    name = boost::optional<std::string>{};

    return rcode;
  }

  void operator+=(const std::string& arg)
  {
    if (name)
      args.push_back(arg);
    else
      name = arg;
  }
};

} // anonymous

struct Launcher::Implem
{
  Command cmd{};
  bool last_rcode = false;
};

Launcher::Launcher()
    : VisitorInterface::VisitorInterface()
    , pimpl_{ std::make_unique<Implem>() }
{
}

Launcher::~Launcher() noexcept = default;

void Launcher::operator()(const std::string& str)
{
  pimpl_->cmd += str;
}

void Launcher::operator()(const ast::redir_node&)
{
}

void Launcher::operator()(const ast::cmd_element& element)
{
  element.apply_visitor(*this);
}

void Launcher::operator()(const ast::cmd_node& node)
{
  for (const auto& element : node)
    operator()(element);
  pimpl_->last_rcode = pimpl_->cmd();
}

void Launcher::operator()(const ast::operand& op)
{
  op.apply_visitor(*this);
}

void Launcher::operator()(const ast::operator_node& node)
{
  using parser::grammar::symbol_type;

  switch (node.op_type)
  {
  case symbol_type::DOUBLE_AND:
    if (pimpl_->last_rcode)
      return;
    break;
  case symbol_type::DOUBLE_OR:
    if (!pimpl_->last_rcode)
      return;
    break;
  case symbol_type::OR:
    break;
  default:
    assert(false && "invalid operation");
    break;
  }
  operator()(node.second);
}

void Launcher::operator()(const ast::expression_node& node)
{
  operator()(node.first);
  for (const auto& operation : node.rest)
    operator()(operation);
}

void Launcher::operator()(const ast::statement_node& node)
{
  operator()(node.exp);
}

void Launcher::operator()(const ast::ast_root& node)
{
  if (node)
    for (const auto& statement : *node)
      operator()(statement);
}

} // visitors
} // ast
