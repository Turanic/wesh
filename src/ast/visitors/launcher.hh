#pragma once

#include <string>
#include <ast/ast.hh>
#include <memory>
#include "visitor_interface.hh"

namespace ast
{
namespace visitors
{
class Launcher : public VisitorInterface
{
public:
  Launcher();
  ~Launcher() noexcept override;
  Launcher(const Launcher&) = delete;
  Launcher& operator=(const Launcher&) = delete;
  Launcher(Launcher&&) noexcept = default;
  Launcher& operator=(Launcher&&) noexcept = default;

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
