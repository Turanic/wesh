#pragma once

#include "input_extractor_interface.hh"

namespace options
{
class InteractiveExtractor : public InputExtractorInterface
{
public:
  std::string input_get() const override;
  bool should_loop() const noexcept override;
};
} //options
