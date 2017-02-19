#pragma once

#include "ast.hh"

BOOST_FUSION_ADAPT_STRUCT(parser::ast::redir_node, io_number, type, file)
BOOST_FUSION_ADAPT_STRUCT(parser::ast::operator_node, op_type, second)
BOOST_FUSION_ADAPT_STRUCT(parser::ast::expression_node, first, rest)
BOOST_FUSION_ADAPT_STRUCT(parser::ast::statement_node, exp, separator)
