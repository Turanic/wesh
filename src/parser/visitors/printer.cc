#include "printer.hh"

#include <iostream>

namespace parser
{
namespace visitors
{
void Printer::operator()(const std::string& str) const
{
  std::cout << str << '\n';
}

void Printer::operator()(const ast::redir_node& redir) const
{
  if (redir.io_number)
    std::cout << *(redir.io_number);
  std::cout << redir.file << '\n';
}

void Printer::operator()(const ast::cmd_element& element) const
{
  boost::apply_visitor(Printer(), element);
}

void Printer::operator()(const ast::cmd_node& node) const
{
  for (const auto& element_ptr : node)
    operator()(element_ptr.get());
}

void Printer::operator()(const ast::pipeline_node& node) const
{
  for (const auto& command : node)
    operator()(command);
}

void Printer::operator()(const ast::logical_node& node) const
{
  for (const auto& pipeline : node)
    operator()(pipeline);
}

void Printer::operator()(const ast::statement_node& node) const
{
  for (const auto& logical : node)
    operator()(logical);
}

void Printer::operator()(const ast::ast_root& node) const
{
  if (node)
    operator()(*node);
  else
    std::cout << "empty tree\n";
}

} // visitors
} // parser
