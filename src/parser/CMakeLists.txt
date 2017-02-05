set(SRC_PARSER
    parser.cc
    visitors/printer.cc)

add_library(parser_objs OBJECT ${SRC_PARSER})
