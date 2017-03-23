#include "symbols.hh"

namespace parser
{
namespace grammar
{
const symbol_table_t& separators_get()
{
  static const symbol_table_t separators{ { ";", symbol_type::SEMI_COLON },
                                          { "&", symbol_type::AND },
                                          { "\n\r", symbol_type::SEMI_COLON },
                                          { "\n", symbol_type::SEMI_COLON },
                                          { "\r", symbol_type::SEMI_COLON } };

  return separators;
}

const symbol_table_t& logical_op_get()
{
  static const symbol_table_t logical_op{ { "&&", symbol_type::DOUBLE_AND },
                                          { "||", symbol_type::DOUBLE_OR } };

  return logical_op;
}

const symbol_table_t& pipe_op_get()
{
  static const symbol_table_t pipe_op{ { "|", symbol_type::OR },
                                       { "|&", symbol_type::OR_AND } };

  return pipe_op;
}

const symbol_table_t& redir_op_get()
{
  static const symbol_table_t redir_op{ { ">", symbol_type::RIGHT },
                                        { ">>", symbol_type::DOUBLE_RIGHT },
                                        { "<", symbol_type::LEFT },
                                        { "<<", symbol_type::DOUBLE_LEFT } };

  return redir_op;
}
} // grammar
} // parser
