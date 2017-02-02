#include "parser/parser.hh"

#include <iostream>
#include <string>

int main(void)
{
  std::string input1 { "hello  && world  ; testing|pipe| line ||    working&" };
  std::string input2 { "this && is a bad ;test;; here" };
  std::cout << "parsing: " << input1 << '\n';
  parser::parse_input(input1);
  std::cout << "parsing: " << input2 << '\n';
  parser::parse_input(input2);

  return 0;
}
