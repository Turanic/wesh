#include "parser.hh"

#include <boost/spirit/home/x3.hpp>
#include <iostream>

#include "ast.hh"
#include "grammar.hh"
#include "visitors/printer.hh"

namespace parser
{
void parse_input(const std::string &input)
{
  using boost::spirit::x3::expectation_failure;
  using boost::spirit::x3::space;

  auto iter = input.begin();
  const auto end = input.end();

  bool success = false;
  ast::ast_root ast;
  visitors::Printer visitor {};
  try
  {
    success = phrase_parse(iter, end, grammar::wesh_rule, space, ast);
    visitor(ast);
  }
  catch (const expectation_failure<decltype(iter)>& error)
  {
    std::cerr << "syntax error : expecting " << error.which()
              << " after character " << *(error.where()) << '\n';
  }

  if (success && iter == end)
    std::cout << "SUCCESS!! \n";
  else
    std::cout << "ERROR >< \n";
}

} // parser
