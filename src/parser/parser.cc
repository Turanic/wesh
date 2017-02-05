#include "parser.hh"

#include <boost/spirit/home/x3.hpp>
#include <iostream>

#include "ast.hh"
#include "grammar.hh"

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
  try
  {
     success = phrase_parse(iter, end, grammar::statements_rule, space, ast);
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
  for (const auto& e : *ast)
  {
    (void)e;
    std::cerr << "test\n";
  }
}

} // parser
