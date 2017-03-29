#include "terminal.hh"
#include <cassert>
#include <termios.h>
#include <unistd.h>
#include <iostream>

namespace readline
{
TerminalCfg::TerminalCfg()
    : term_config_{ std::make_unique<struct termios>() }
{
  tcgetattr(STDIN_FILENO, &*term_config_);

  auto new_config = *term_config_;
  new_config.c_lflag &= static_cast<unsigned int>(~(ICANON | ECHO));
  tcsetattr(STDIN_FILENO, TCSANOW, &new_config);
}

TerminalCfg::~TerminalCfg()
{
  tcsetattr(STDIN_FILENO, TCSANOW, &*term_config_);
}

} // readline
