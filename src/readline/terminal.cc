#include "terminal.hh"
#include <termios.h>
#include <unistd.h>

namespace readline
{
TerminalCfg::TerminalCfg()
    : term_config_{ std::make_unique<struct termios>() }
{
  tcgetattr(STDIN_FILENO, &*term_config_);

  auto new_config = *term_config_;
  new_config.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &new_config);
}

TerminalCfg::~TerminalCfg()
{
  tcsetattr(STDIN_FILENO, TCSANOW, &*term_config_);
}

} // readline
