#include "readline.hh"
#include <cstdio>

namespace readline
{
void print_prompt(std::ostream& stream)
{
  constexpr auto ps1 = "WESH pre-alpha";
  stream << ps1 << "# ";
}

std::string read_input(std::istream& stream)
{
  std::string input{};

  char symbol = '\0';
  do
  {
    symbol = stream.get();
    input.push_back(symbol);
    std::cerr << symbol;
  }
  while (symbol != '\n');

  return input;
}

} // readline
