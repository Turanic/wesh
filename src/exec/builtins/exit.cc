#include "exit.hh"

namespace exec
{
namespace builtins
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
} // builtins
} // exec
