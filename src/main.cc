#include "parser/parser.hh"

#include <iostream>
#include <string>

int main(void)
{
  std::string input1 { "echo test > lol.txt; true && true || echo check; cat lol.txt | grep -rn mdr;" };
  std::cout << "parsing: " << input1 << '\n';
  parser::parse_input(input1);

  return 0;
}
