#pragma once

#include <boost/fusion/include/adapt_struct.hpp>
#include <boost/spirit/home/x3/support/ast/variant.hpp>
#include <boost/optional.hpp>
#include <string>
#include <vector>

namespace parser
{
namespace ast
{
namespace x3 = boost::spirit::x3;

struct redir_node
{
  boost::optional<long> io_number {};
  std::string file {};
};

struct cmd_element : x3::variant<std::string, redir_node>
{
  using base_type::base_type;
  using base_type::operator=;
};

using cmd_node = std::vector<x3::forward_ast<cmd_element>>;
using pipeline_node = std::vector<cmd_node>;
using logical_node = std::vector<pipeline_node>;
using statement_node = std::vector<logical_node>;
using ast_root = boost::optional<statement_node>;

} // ast
} // parser

BOOST_FUSION_ADAPT_STRUCT(parser::ast::redir_node, io_number, file)
