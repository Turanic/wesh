set(SRC_READLINE
    events/on_arrow.cc
    events/on_backspace.cc
    events/on_end_of_line.cc
    events/on_exit.cc
    events/on_start_of_line.cc
    line_buffer.cc
    readline.cc
    termcaps.cc
    terminal.cc)

  add_library(readline_objs OBJECT ${SRC_READLINE})
