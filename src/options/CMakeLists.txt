set(SRC_OPTIONS
  argument_extractor.cc
  interactive_extractor.cc
  opt_parser.cc)

add_library(options_objs OBJECT ${SRC_OPTIONS})
