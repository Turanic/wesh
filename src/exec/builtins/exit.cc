#include "exit.hh"

namespace exec::builtins
{
const char* ExitCalled::what() const noexcept
{
  return "Exit builtin called.";
}

[[noreturn]]
void exit()
{
  throw ExitCalled{};
}
} // exec::builtins
