#pragma once

#include <memory>
#include <string>
#include <ast/ast.hh>
#include "visitor_interface.hh"

namespace ast
{
namespace visitors
{
class Printer : public VisitorInterface
{
public:
  Printer() noexcept;
  ~Printer() noexcept override;
  Printer(const Printer&) = delete;
  Printer& operator=(const Printer&) = delete;
  Printer(Printer&&) noexcept = default;
  Printer& operator=(Printer&&) noexcept = default;

  void operator()(const std::string& str) const override;
  void operator()(const ast::redir_node& redir) const override;
  void operator()(const ast::cmd_element& element) const override;
  void operator()(const ast::cmd_node& node) const override;
  void operator()(const ast::operand& op) const override;
  void operator()(const ast::operator_node& node) const override;
  void operator()(const ast::expression_node& node) const override;
  void operator()(const ast::statement_node& node) const override;
  void operator()(const ast::ast_root& node) const override;

private:
  struct Implem;
  mutable std::unique_ptr<Implem> pimpl_;
};
} // visitors
} // ast
