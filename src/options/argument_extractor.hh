#pragma once

#include "input_extractor_interface.hh"

namespace options
{
class ArgumentExtractor : public InputExtractorInterface
{
public:
  ArgumentExtractor(std::string argument) noexcept;

  std::string input_get() const override;

private:
  std::string input_;
};
} // options
