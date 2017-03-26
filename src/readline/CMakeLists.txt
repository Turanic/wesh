set(SRC_READLINE
    events/on_arrow.cc
    events/on_backspace.cc
    line_buffer.cc
    readline.cc
    termcaps.cc
    terminal.cc)

  add_library(readline_objs OBJECT ${SRC_READLINE})
