#include "readline.hh"
#include <cstdio>

namespace readline
{
void print_prompt(std::ostream& stream)
{
  constexpr auto ps1 = "WESH pre-alpha";
  stream << ps1 << "# ";
}

std::string read_input(std::istream&, Terminal& term)
{
  while (term.next_char())
  {
  }

  return term.input_get();
}

} // readline
