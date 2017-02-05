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
  void operator()(const ast::pipeline_node& node) const;
  void operator()(const ast::logical_node& node) const;
  void operator()(const ast::statement_node& node) const;
  void operator()(const ast::ast_root& node) const;
};
} // visitors
} // parser
