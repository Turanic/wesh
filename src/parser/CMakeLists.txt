set(SRC_PARSER
    parser.cc
    ast/printer.cc
    grammar/symbols.cc)

add_library(parser_objs OBJECT ${SRC_PARSER})
