#include "echo.hh"
#include <iostream>

namespace exec::builtins
{
int echo(const std::vector<std::string>& args)
{
  auto separator = "";
  for (const auto& arg : args)
  {
    std::cout << separator << arg;
    separator = " ";
  }
  std::cout << std::endl;

  return 0;
}
} // exec::builtins
