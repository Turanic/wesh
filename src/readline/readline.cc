#include "readline.hh"

namespace readline
{
void print_prompt(std::ostream& os)
{
  os << "WESH pre-alpha# ";
}

std::string read_input(std::istream& is)
{
  std::string input{};
  std::getline(is, input);
  input += "\n";

  return input;
}

} // readline
