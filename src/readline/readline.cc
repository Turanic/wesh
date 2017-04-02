#include "readline.hh"
#include <cstdio>

namespace readline
{
void print_prompt()
{
  std::cout << kps1 << "# ";
}

std::string read_input(Terminal& term)
{
  while (term.next_char())
  {
  }
  std::cout << std::endl;

  return term.input_get();
}

} // readline
