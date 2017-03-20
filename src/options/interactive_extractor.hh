#pragma once

#include <readline/terminal.hh>
#include "input_extractor_interface.hh"

namespace options
{
class InteractiveExtractor : public InputExtractorInterface
{
public:
  std::string input_get() const override;
  bool should_loop() const noexcept override;

private:
  const readline::TerminalCfg term_cfg_{};
};
} // options
