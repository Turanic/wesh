#pragma once

#include <boost/spirit/home/x3.hpp>
#include <vector>

#include "ast.hh"
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
rule<class Wesh, ast::ast_root> wesh_rule                     { "main_rule" };
rule<class Statements, ast::statement_node> statements_rule   { "statement_list" };
rule<class Logics, ast::logical_node> logics_rule             { "logic_list" };
rule<class Pipeline, ast::pipeline_node> pipeline_rule        { "pipeline" };

rule<class Simple_Command, ast::cmd_node> simple_command_rule    { "simple_command" };

rule<class Element, ast::cmd_element> element_rule               { "element" };
rule<class Prefix, ast::cmd_element> prefix_rule                 { "prefix" };

rule<class Redirection, ast::redir_node> redirection_rule   { "redirection" };
rule<class Word, std::string> word                          { "word" };
rule<class Assignement, std::string> assignement            { "assignement" };
/* *** */

/* defining rules */
const auto wesh_rule_def = -statements_rule >> (eol | eoi);
const auto statements_rule_def = (logics_rule % (eol | separators))
                                 >> -(eol | separators);
const auto logics_rule_def = pipeline_rule % logical_op;
const auto pipeline_rule_def = simple_command_rule % '|';

const auto simple_command_rule_def =
  (*prefix_rule >> +element_rule) | +prefix_rule;
const auto element_rule_def = word | redirection_rule;
const auto prefix_rule_def = assignement | redirection_rule;

const auto redirection_rule_def = -ulong_ >> redir_op >> word;

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
} // parser
