#include "readline.hh"
#include <cstdio>

namespace readline
{
void print_prompt(std::ostream& stream)
{
  constexpr auto ps1 = "WESH pre-alpha";
  stream << ps1 << "# ";
}

std::string read_input(std::istream& stream, Terminal& term)
{
  std::string input{};

  char symbol = '\0';
  do
  {
    symbol = static_cast<char>(stream.get());
    term.send_event(symbol);
  }
  while (symbol != '\n');

  return term.input_get();
}

} // readline
