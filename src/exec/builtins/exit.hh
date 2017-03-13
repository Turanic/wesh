#pragma once

#include <exception>

namespace exec
{
namespace builtins
{
class ExitCalled : public std::exception
{
  const char* what() const noexcept override;
};

[[noreturn]]
void exit();

} // builtins
} // exec
