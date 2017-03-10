# set compilation flags
set(CMAKE_CXX_FLAGS "-std=c++14 -Wall -Wextra -pedantic -DWESH_VERSION=${WESH_VERSION}")
set(CMAKE_CXX_FLAGS_DEBUG "-g3 -Werror -Wno-unused-parameter")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# include directories for compilation (-I)
include_directories(
  .
  ${Boost_INCLUDE_DIRS})

# get objects libraries from sources
add_subdirectory(ast)
add_subdirectory(exec)
add_subdirectory(options)
add_subdirectory(parser)
add_subdirectory(readline)

find_package(Boost COMPONENTS program_options REQUIRED)

# create the executable with project name
add_executable(${PROJECT_NAME}
  main.cc
  $<TARGET_OBJECTS:ast_objs>
  $<TARGET_OBJECTS:exec_objs>
  $<TARGET_OBJECTS:options_objs>
  $<TARGET_OBJECTS:parser_objs>
  $<TARGET_OBJECTS:readline_objs>)
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
