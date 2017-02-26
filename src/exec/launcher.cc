#include "launcher.hh"

#include "command.hh"

namespace parser
{
namespace exec
{
namespace
{
::exec::Command current_cmd;
} // anonymous

void Launcher::operator()(const std::string& str) const
{
  current_cmd += str;
}

void Launcher::operator()(const ast::redir_node&) const
{

}

void Launcher::operator()(const ast::cmd_element& element) const
{
  boost::apply_visitor(Launcher(), element);
}

void Launcher::operator()(const ast::cmd_node& node) const
{
  for (const auto& element : node)
    operator()(element);
  current_cmd();
}

void Launcher::operator()(const ast::operand& op) const
{
  boost::apply_visitor(Launcher(), op);
}

void Launcher::operator()(const ast::operator_node& node) const
{
  using grammar::symbol_type;

  switch (node.op_type)
  {
  case symbol_type::DOUBLE_AND:
    if (!current_cmd.rcode) return;
    break;
  case symbol_type::DOUBLE_OR:
    if (current_cmd.rcode) return;
    break;
  case symbol_type::OR:
    break;
  default:
    assert(false && "invalid operation");
    break;
  }
  operator()(node.second);
}

void Launcher::operator()(const ast::expression_node& node) const
{
  operator()(node.first);
  for (const auto& operation : node.rest)
    operator()(operation);
}

void Launcher::operator()(const ast::statement_node& node) const
{
  operator()(node.exp);
}

void Launcher::operator()(const ast::ast_root& node) const
{
  if (node)
    for (const auto& statement : *node)
      operator()(statement);
}

} // launcher
} // parser
