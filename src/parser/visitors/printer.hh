#pragma once

#include <boost/variant/apply_visitor.hpp>
#include <string>

#include <parser/ast.hh>

namespace parser
{
namespace visitors
{
class Printer : public boost::static_visitor<>
{
public:
  void operator()(const std::string& str) const;
  void operator()(const ast::redir_node& redir) const;
  void operator()(const ast::cmd_element& element) const;
  void operator()(const ast::cmd_node& node) const;
  void operator()(const ast::operand& op) const;
  void operator()(const ast::operator_node& node) const;
  void operator()(const ast::expression_node& node) const;
  void operator()(const ast::statements_nodes& node) const;
  void operator()(const ast::ast_root& node) const;
};
} // visitors
} // parser
