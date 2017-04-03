#pragma once

#include <exception>

namespace exec::builtins
{
class ExitCalled : public std::exception
{
  const char* what() const noexcept override;
};

[[noreturn]]
void exit();

} // exec::builtins
