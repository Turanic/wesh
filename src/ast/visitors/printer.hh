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
  struct Implem;
  std::unique_ptr<Implem> pimpl_;
};
} // visitors
} // ast
