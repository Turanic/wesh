# set compilation flags
set(CMAKE_CXX_FLAGS "-std=c++14 -Wall -Wextra -pedantic -Weffc++")
set(CMAKE_CXX_FLAGS_DEBUG "-g3 -fsanitize=address -fsanitize=undefined -Werror")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# get objects libraries from sources
add_subdirectory(parser)

# include directories for compilation (-I)
include_directories(
  .
  ${Boost_INCLUDE_DIRS})

# create the executable with project name
add_executable(${PROJECT_NAME}
  main.cc
  $<TARGET_OBJECTS:parser_objs>)
