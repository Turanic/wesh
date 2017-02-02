#include "parser.hh"

#include <boost/spirit/home/x3.hpp>
#include <iostream>

#include "grammar.hh"

namespace parser
{
void parse_input(const std::string &input)
{
  using boost::spirit::x3::space;

  auto iter = input.begin();
  const auto end = input.end();

  bool success = phrase_parse(iter, end, grammar::statements_rule, space);

  if (success && iter == end)
    std::cout << "SUCCESS!! \n";
  else
    std::cout << "ERROR >< \n"
              << "iterator stopped at character :"
              << *iter
              << '\n';
}

} // parser
