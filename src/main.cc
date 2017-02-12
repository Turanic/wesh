#include "parser/parser.hh"

#include <iostream>
#include <string>

int main(void)
{
  std::string input1 { "echo test > lol.txt; true && false; cat lol.txt | grep -rn mdr;" };
  std::string input2 { "true && true|false  ||  false&& true&echo  hello world&" };
  std::cout << "parsing: " << input1 << '\n';
  parser::parse_input(input1);
  std::cout << "parsing: " << input2 << '\n';
  parser::parse_input(input2);

  return 0;
}
