#include "interactive_extractor.hh"
#include <iostream>
#include <readline/readline.hh>

namespace options
{
std::string InteractiveExtractor::input_get() const
{
  readline::print_prompt(std::cout);
  return readline::read_input(std::cin);
}

} // options
