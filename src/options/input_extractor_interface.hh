#pragma once

#include <string>

namespace options
{
class InputExtractorInterface
{
public:
  virtual ~InputExtractorInterface() noexcept = default;

  virtual std::string input_get() = 0;
  virtual bool should_loop() noexcept = 0;
};
} // options
