#pragma once

#include <string>
#include <vector>
#include <boost/optional.hpp>
#include <boost/spirit/home/x3/support/ast/variant.hpp>
#include <parser/grammar/symbols.hh>

namespace ast
{
using boost::spirit::x3::forward_ast;
using boost::spirit::x3::variant;
using parser::grammar::symbol_type;

struct redir_node
{
  boost::optional<long> io_number;
  symbol_type type;
  std::string file;
};

struct cmd_element : public variant<std::string, redir_node>
{
  using base_type::base_type;
  using base_type::operator=;
};
using cmd_node = std::vector<forward_ast<cmd_element>>;

struct expression_node;
struct operand : public variant<cmd_node, forward_ast<expression_node>>
{
  using base_type::base_type;
  using base_type::operator=;
};

struct operator_node
{
  symbol_type op_type;
  operand second;
};

struct expression_node
{
  operand first;
  std::vector<operator_node> rest;
};

struct statement_node
{
  expression_node exp;
  symbol_type separator;
};

using statements = std::vector<statement_node>;
using ast_root = boost::optional<statements>;

} // ast
