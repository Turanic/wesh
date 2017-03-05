#include "symbols.hh"

namespace parser
{
namespace grammar
{
symbol_table_t& separators_get()
{
  static bool first_call = true;
  static symbol_table_t separators{};

  if (first_call)
  {
    separators.add(";", symbol_type::SEMI_COLON);
    separators.add("&", symbol_type::AND);
    separators.add("\n\r", symbol_type::SEMI_COLON);
    separators.add("\n", symbol_type::SEMI_COLON);
    separators.add("\r", symbol_type::SEMI_COLON);
    first_call = false;
  }

  return separators;
}

symbol_table_t& logical_op_get()
{
  static bool first_call = true;
  static symbol_table_t logical_op{};

  if (first_call)
  {
    logical_op.add("&&", symbol_type::DOUBLE_AND);
    logical_op.add("||", symbol_type::DOUBLE_OR);
    first_call = false;
  }

  return logical_op;
}

symbol_table_t& pipe_op_get()
{
  static bool first_call = true;
  static symbol_table_t pipe_op{};

  if (first_call)
  {
    pipe_op.add("|", symbol_type::OR);
    pipe_op.add("|&", symbol_type::OR_AND);
    first_call = false;
  }

  return pipe_op;
}

symbol_table_t& redir_op_get()
{
  static bool first_call = true;
  static symbol_table_t redir_op{};

  if (first_call)
  {
    redir_op.add(">", symbol_type::RIGHT);
    redir_op.add(">>", symbol_type::DOUBLE_RIGHT);
    redir_op.add("<", symbol_type::LEFT);
    redir_op.add("<<", symbol_type::DOUBLE_LEFT);
    first_call = false;
  }

  return redir_op;
}
} // grammar
} // parser
