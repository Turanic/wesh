set(SRC_EXEC
    builtins/builtin.cc
    process.cc)

add_library(exec_objs OBJECT ${SRC_EXEC})
