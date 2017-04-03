#pragma once

#include <cstddef>
#include <termios.h>

namespace readline::termcaps
{
termios init_terminal(char* buffer);
void close_terminal(const termios& term);
void move_cursor_left();
void move_cursor_right();
void set_cursor_offset(int offset);
void delete_selected_char();
void clear_line();

} // readline::termcaps
