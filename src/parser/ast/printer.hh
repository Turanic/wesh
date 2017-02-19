#pragma once

#include <string>

#include "ast.hh"
#include "visitor_interface.hh"

namespace parser
{
namespace ast
{
class Printer : public VisitorInterface
{
public:
  void operator()(const std::string& str) const override;
  void operator()(const ast::redir_node& redir) const override;
  void operator()(const ast::cmd_element& element) const override;
  void operator()(const ast::cmd_node& node) const override;
  void operator()(const ast::operand& op) const override;
  void operator()(const ast::operator_node& node) const override;
  void operator()(const ast::expression_node& node) const override;
  void operator()(const ast::statement_node& node) const override;
  void operator()(const ast::ast_root &node) const override;
};
} // ast
} // parser
