set(SRC_READLINE
    events/on_backspace.cc
    readline.cc
    terminal.cc)

  add_library(readline_objs OBJECT ${SRC_READLINE})
