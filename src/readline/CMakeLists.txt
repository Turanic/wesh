set(SRC_READLINE
    events/on_backspace.cc
    readline.cc
    termcaps.cc
    terminal.cc)

  add_library(readline_objs OBJECT ${SRC_READLINE})
