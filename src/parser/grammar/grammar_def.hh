#pragma once

#include <ast/adapt_ast.hh>
#include <ast/ast.hh>
#include <boost/spirit/home/x3.hpp>
#include "grammar.hh"
#include "symbols.hh"

namespace parser
{
namespace grammar
{
using boost::spirit::x3::alnum;
using boost::spirit::x3::char_;
using boost::spirit::x3::eoi;
using boost::spirit::x3::eol;
using boost::spirit::x3::lexeme;
using boost::spirit::x3::lit;
using boost::spirit::x3::rule;
using boost::spirit::x3::ulong_;

/* declaring rules */
struct wesh_rule_class;
struct statements_rule_class;
struct logics_rule_class;
struct pipeline_rule_class;
struct simple_command_rule_class;
struct element_rule_class;
struct prefix_rule_class;
struct redirection_rule_class;
struct word_class;
struct assignement_class;

using wesh_rule_type = rule<wesh_rule_class, ast::ast_root>;
using statements_rule_type = rule<statements_rule_class, ast::statements>;
using logics_rule_type = rule<logics_rule_class, ast::expression_node>;
using pipeline_rule_type = rule<pipeline_rule_class, ast::expression_node>;
using simple_command_rule_type = rule<simple_command_rule_class, ast::cmd_node>;
using element_rule_type = rule<element_rule_class, ast::cmd_element>;
using prefix_rule_type = rule<prefix_rule_class, ast::cmd_element>;
using redirection_rule_type = rule<redirection_rule_class, ast::redir_node>;
using word_type = rule<word_class, std::string>;
using assignement_type = rule<assignement_class, std::string>;

static wesh_rule_type wesh_rule{ "main_rule" };
static statements_rule_type statements_rule{ "statement_list" };
static logics_rule_type logics_rule{ "logic_list" };
static pipeline_rule_type pipeline_rule{ "pipeline" };
static simple_command_rule_type simple_command_rule{ "simple_command" };
static element_rule_type element_rule{ "element" };
static prefix_rule_type prefix_rule{ "prefix" };
static redirection_rule_type redirection_rule{ "redirection" };
static word_type word{ "word" };
static assignement_type assignement{ "assignement" };
/* *** */

/* defining rules */
const auto wesh_rule_def = -statements_rule >> (eol | eoi);

const auto statements_rule_def = +(logics_rule >> separators_get());
const auto logics_rule_def = pipeline_rule
                             >> *(logical_op_get() >> pipeline_rule);

const auto pipeline_rule_def = simple_command_rule
                               >> *(pipe_op_get() >> simple_command_rule);

const auto simple_command_rule_def =
  (*prefix_rule >> +element_rule) | +prefix_rule;

const auto element_rule_def = word | redirection_rule;

const auto prefix_rule_def = assignement | redirection_rule;

const auto redirection_rule_def = -ulong_ >> redir_op_get() >> word;

const auto word_def = lexeme[+(alnum | char_(".-"))];

const auto assignement_def = lexeme[+alnum >> '='];
/* *** */

/* link rules */
BOOST_SPIRIT_DEFINE(wesh_rule,
                    statements_rule,
                    logics_rule,
                    pipeline_rule,
                    simple_command_rule,
                    element_rule,
                    prefix_rule,
                    redirection_rule,
                    word,
                    assignement)
/* *** */

} // grammar

const grammar::wesh_rule_type& rule_get()
{
  return grammar::wesh_rule;
}

} // parser
