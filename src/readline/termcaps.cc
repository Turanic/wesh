#include "termcaps.hh"
#include <cstdlib>
#include <curses.h>
#include <term.h>
#include <unistd.h>

namespace readline
{
namespace termcaps
{
termios init_terminal(char* buffer)
{
  /* store current config */
  termios cfg{};
  tcgetattr(STDIN_FILENO, &cfg);

  /* set non canonical non echoing mode */
  auto new_config = cfg;
  new_config.c_lflag &= static_cast<unsigned int>(~(ICANON | ECHO));
  tcsetattr(STDIN_FILENO, TCSANOW, &new_config);

  /* load terminal capabilities */
  tgetent(buffer, std::getenv("TERM"));

  return cfg;
}

void close_terminal(const termios& term)
{
  tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void move_cursor_left()
{
  putp(tgetstr("le", nullptr));
}

void move_cursor_right()
{
  putp(tgetstr("nd", nullptr));
}

void delete_selected_char()
{
  putp(tgetstr("dc", nullptr));
}

} // termcaps
} // readline
