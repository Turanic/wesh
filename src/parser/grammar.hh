#pragma once

#include <boost/spirit/home/x3.hpp>

namespace parser
{
namespace grammar
{
using boost::spirit::x3::alnum;
using boost::spirit::x3::eol;
using boost::spirit::x3::lit;
using boost::spirit::x3::rule;

/* declaring rules */
rule<class Statements> statements_rule { "statement_list" };
rule<class Logics> logics_rule  { "logic_list" };
rule<class Pipeline> pipeline_rule  { "pipeline" };
rule<class Simple_Command> simple_command_rule { "simple_command" };
rule<class Word> word_rule { "word" };

/* defining rules */
const auto statements_rule_def =
  *(logics_rule > (lit(';') | lit('&') | eol));
const auto logics_rule_def = pipeline_rule % (lit("&&") | lit("||"));
const auto pipeline_rule_def = simple_command_rule % '|';
const auto simple_command_rule_def = +word_rule;
const auto word_rule_def = +alnum;


/* link rules */
BOOST_SPIRIT_DEFINE(statements_rule,
                    logics_rule,
                    pipeline_rule,
                    simple_command_rule,
                    word_rule)

} // grammar
} // parser
