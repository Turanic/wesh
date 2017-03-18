set(SRC_EXEC
    builtins/builtin.cc
    builtins/echo.cc
    builtins/exit.cc
    command.cc
    process.cc)

add_library(exec_objs OBJECT ${SRC_EXEC})
