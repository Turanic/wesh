#pragma once

#include <string>
#include <ast/ast.hh>
#include <exec/command.hh>
#include "visitor_interface.hh"

namespace ast::visitors
{
class Launcher : public VisitorInterface
{
public:
  void operator()(const std::string& str) override;
  void operator()(const ast::redir_node& redir) override;
  void operator()(const ast::cmd_element& element) override;
  void operator()(const ast::cmd_node& node) override;
  void operator()(const ast::operand& op) override;
  void operator()(const ast::operator_node& node) override;
  void operator()(const ast::expression_node& node) override;
  void operator()(const ast::statement_node& node) override;
  void operator()(const ast::ast_root& node) override;

private:
  exec::Command current_cmd_{};
};
} // ast::visitors
