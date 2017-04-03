#pragma once

#include <string>
#include <vector>
#include <experimental/optional>
#include <boost/spirit/home/x3/support/ast/variant.hpp>
#include <parser/grammar/symbols.hh>

namespace ast
{
using boost::spirit::x3::forward_ast;
using boost::spirit::x3::variant;
using parser::grammar::symbol_type;
using std::experimental::optional;

struct redir_node
{
  optional<long> io_number{};
  symbol_type type{};
  std::string file{};
};

struct cmd_element : public variant<std::string, redir_node>
{
  using base_type::base_type;
  using base_type::operator=;
  cmd_element()
      : base_type(){}
  explicit cmd_element(const std::string& val)
      : base_type(val)
  {
  }
  explicit cmd_element(const redir_node& val)
      : base_type(val)
  {
  }
};
using cmd_node = std::vector<forward_ast<cmd_element>>;

struct expression_node;
struct operand : public variant<cmd_node, forward_ast<expression_node>>
{
  using base_type::base_type;
  using base_type::operator=;
  operand()
      : base_type(){}
  explicit operand(const cmd_node& val)
      : base_type(val)
  {
  }
  explicit operand(forward_ast<expression_node> val)
      : base_type(val)
  {
  }
};

struct operator_node
{
  symbol_type op_type{};
  operand second{};
};

struct expression_node
{
  operand first{};
  std::vector<operator_node> rest{};
};

struct statement_node
{
  expression_node exp{};
  symbol_type separator{};
};

using statements = std::vector<statement_node>;
using ast_root = optional<statements>;

} // ast
