set(SRC_PARSER
    parser.cc
    grammar/grammar.cc
    grammar/symbols.cc)

add_library(parser_objs OBJECT ${SRC_PARSER})
