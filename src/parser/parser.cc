#include "parser.hh"

#include <iostream>

#include <boost/spirit/home/x3.hpp>

#include "grammar/grammar.hh"

namespace parser
{
ast::ast_root parse_input(const std::string &input)
{
  using boost::spirit::x3::expectation_failure;
  using boost::spirit::x3::space;

  auto iter = input.begin();
  const auto end = input.end();

  bool success = false;
  ast::ast_root ast;
  try
  {
    success = phrase_parse(iter, end, grammar::wesh_rule, space, ast);
  }
  catch (const expectation_failure<decltype(iter)>& error)
  {
    std::cerr << "syntax error : expecting " << error.which()
              << " after character " << *(error.where()) << '\n';
    throw error;
  }

  if (!success || iter != end)
    std::cerr << "Error ><\n";

  return ast;
}

} // parser
