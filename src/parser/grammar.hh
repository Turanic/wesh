#pragma once

#include <boost/spirit/home/x3.hpp>

#include "symbols.hh"

namespace parser
{
namespace grammar
{
using boost::spirit::x3::alnum;
using boost::spirit::x3::eoi;
using boost::spirit::x3::eol;
using boost::spirit::x3::lit;
using boost::spirit::x3::rule;
using boost::spirit::x3::ulong_;

/* declaring rules */
rule<class Wesh> wesh_rule{ "main_rule" };
rule<class Statements> statements_rule{ "statement_list" };
rule<class Logics> logics_rule{ "logic_list" };
rule<class Pipeline> pipeline_rule{ "pipeline" };

rule<class Simple_Command> simple_command_rule{ "simple_command" };

rule<class Element> element_rule{ "element" };
rule<class Prefix> prefix_rule{ "prefix" };

rule<class Redirection> redirection_rule{ "redirection" };
rule<class Word> word{ "word" };
rule<class Assignement> assignement{ "assignement" };
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

const auto word_def = +(alnum | '.' | '-');
const auto assignement_def = +alnum >> '=';
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
