#pragma once

#include <cstdint>

#include <boost/spirit/home/x3.hpp>

namespace parser
{
namespace grammar
{
using boost::spirit::x3::symbols;

/* symbols enums */
enum class symbol_type : int8_t
{
  SEMI_COLON,
  AND,
  OR,
  OR_AND,
  DOUBLE_AND,
  DOUBLE_OR,
  RIGHT,
  DOUBLE_RIGHT,
  LEFT,
  DOUBLE_LEFT
};
/* *** */

/* symbols tables access */
using symbol_table_t = symbols<symbol_type>;
symbol_table_t& separators_get();
symbol_table_t& logical_op_get();
symbol_table_t& pipe_op_get();
symbol_table_t& redir_op_get();
/* *** */

} // grammar
} // parser
