#include "interactive_extractor.hh"
#include <readline/readline.hh>

namespace options
{
std::string InteractiveExtractor::input_get()
{
  readline::print_prompt(std::cout);
  return readline::read_input(std::cin, term_);
}

bool InteractiveExtractor::should_loop() noexcept
{
  return true;
}

} // options
