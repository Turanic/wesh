#pragma once

#include <readline/terminal.hh>
#include "input_extractor_interface.hh"

namespace options
{
class InteractiveExtractor : public InputExtractorInterface
{
public:
  std::string input_get() override;
  bool should_loop() noexcept override;

private:
  readline::Terminal term_{};
};
} // options
