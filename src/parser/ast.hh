#pragma once

#include <boost/fusion/include/adapt_struct.hpp>
#include <boost/spirit/home/x3/support/ast/variant.hpp>
#include <boost/optional.hpp>
#include <string>
#include <vector>

#include "symbols.hh"

namespace parser
{
namespace ast
{
namespace x3 = boost::spirit::x3;

struct redir_node
{
  boost::optional<long> io_number;
  grammar::symbol_type type;
  std::string file;
};

struct cmd_element : public x3::variant<std::string, redir_node>
{
  using base_type::base_type;
  using base_type::operator=;
};
using cmd_node = std::vector<x3::forward_ast<cmd_element>>;

struct expression_node;
struct operand : public x3::variant<cmd_node, x3::forward_ast<expression_node>>
{
  using base_type::base_type;
  using base_type::operator=;
};

struct operator_node
{
  grammar::symbol_type op_type;
  operand second;
};

struct expression_node
{
  operand first;
  std::vector<operator_node> rest;
};

struct statements_nodes
{
  operand first;
  std::vector<operator_node> rest;
  grammar::symbol_type last;
};

using ast_root = boost::optional<statements_nodes>;

} // ast
} // parser

BOOST_FUSION_ADAPT_STRUCT(parser::ast::redir_node, io_number, type, file)
BOOST_FUSION_ADAPT_STRUCT(parser::ast::operator_node, op_type, second)
BOOST_FUSION_ADAPT_STRUCT(parser::ast::expression_node, first, rest)
BOOST_FUSION_ADAPT_STRUCT(parser::ast::statements_nodes, first, rest, last)
