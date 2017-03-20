#pragma once

#include <memory>

struct termios; // forward declaration of termios structure
namespace readline
{
class TerminalCfg
{
public:
  TerminalCfg();
  ~TerminalCfg();

private:
  std::unique_ptr<struct termios> term_config_;
};
} // readline
