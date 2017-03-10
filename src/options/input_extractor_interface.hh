#pragma once

#include <string>

namespace options
{
class InputExtractorInterface
{
public:
  virtual ~InputExtractorInterface() noexcept = default;

  virtual std::string input_get() const = 0;
  virtual bool should_loop() const noexcept = 0;
};
} // options
