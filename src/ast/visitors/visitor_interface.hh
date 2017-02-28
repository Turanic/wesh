#pragma once

#include <ast/ast.hh>
#include <boost/variant/apply_visitor.hpp>

namespace ast
{
namespace visitors
{
class VisitorInterface : public boost::static_visitor<>
{
public:
  VisitorInterface() = default;
  virtual ~VisitorInterface() noexcept = default;
  VisitorInterface(const VisitorInterface&) = delete;
  VisitorInterface& operator=(const VisitorInterface&) = delete;
  VisitorInterface(VisitorInterface&&) noexcept = default;
  VisitorInterface& operator=(VisitorInterface&&) noexcept = default;

  virtual void operator()(const std::string& str) const = 0;
  virtual void operator()(const ast::redir_node& redir) const = 0;
  virtual void operator()(const ast::cmd_element& element) const = 0;
  virtual void operator()(const ast::cmd_node& node) const = 0;
  virtual void operator()(const ast::operand& op) const = 0;
  virtual void operator()(const ast::operator_node& node) const = 0;
  virtual void operator()(const ast::expression_node& node) const = 0;
  virtual void operator()(const ast::statement_node& node) const = 0;
  virtual void operator()(const ast::ast_root& node) const = 0;
};
} // visitors
} // ast
