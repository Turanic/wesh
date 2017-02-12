#include "parser/parser.hh"

#include <iostream>
#include <string>

int main(void)
{
  std::string input1 { "echo test > lol.txt; true && false; cat lol.txt | grep -rn mdr;" };
  // std::string input2 { "echo test > lol.txt; cat lol.txt | grep test" };
  std::cout << "parsing: " << input1 << '\n';
  parser::parse_input(input1);
  // std::cout << "parsing: " << input2 << '\n';
  // parser::parse_input(input2);

  return 0;
}