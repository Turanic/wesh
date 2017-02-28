#pragma once

#include <vector>

#include <ast/ast.hh>
#include <boost/spirit/home/x3.hpp>

namespace parser
{
namespace grammar
{
using boost::spirit::x3::rule;

struct wesh_rule_class;
using wesh_rule_type = rule<wesh_rule_class, ast::ast_root>;
using wesh_rule_id = wesh_rule_type::id;
BOOST_SPIRIT_DECLARE(wesh_rule_type)

} // grammar

const grammar::wesh_rule_type& rule_get();

} // parser
