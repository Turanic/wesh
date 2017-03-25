#pragma once

#include <termios.h>

namespace readline
{
namespace termcaps
{
termios init_terminal(char* buffer);
void close_terminal(const termios& term);
void move_cursor_left();
void move_cursor_right();
void delete_selected_char();

} // termcaps
} // readline
