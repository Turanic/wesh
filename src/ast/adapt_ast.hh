#pragma once

#include <boost/fusion/include/adapt_struct.hpp>

#include "ast.hh"

BOOST_FUSION_ADAPT_STRUCT(ast::redir_node, io_number, type, file)
BOOST_FUSION_ADAPT_STRUCT(ast::operator_node, op_type, second)
BOOST_FUSION_ADAPT_STRUCT(ast::expression_node, first, rest)
BOOST_FUSION_ADAPT_STRUCT(ast::statement_node, exp, separator)
