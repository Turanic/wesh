#pragma once

#include <string>

namespace options
{
class InputExtractorInterface
{
public:
  virtual ~InputExtractorInterface() noexcept = default;

  virtual std::string input_get() const = 0;
};
} // options
