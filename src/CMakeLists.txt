# set compilation flags
set(CMAKE_CXX_FLAGS "-std=c++14 -Wall -Wextra -pedantic")
set(CMAKE_CXX_FLAGS_DEBUG "-g3 -fsanitize=address -fsanitize=undefined -Werror -Wno-unused-parameter")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# include directories for compilation (-I)
include_directories(
  .
  ${Boost_INCLUDE_DIRS})

# get objects libraries from sources
add_subdirectory(ast)
add_subdirectory(exec)
add_subdirectory(parser)


# create the executable with project name
add_executable(${PROJECT_NAME}
  main.cc
  $<TARGET_OBJECTS:ast_objs>
  $<TARGET_OBJECTS:exec_objs>
  $<TARGET_OBJECTS:parser_objs>)
