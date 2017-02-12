#pragma once

#include <boost/spirit/home/x3.hpp>
#include <cstdint>

namespace parser
{
namespace grammar
{
using boost::spirit::x3::symbols;
using boost::spirit::x3::unused_type;

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

/* symbols tables */
static struct separators_ : symbols<symbol_type>
{
  separators_()
  {
    add(";", symbol_type::SEMI_COLON);
    add("&", symbol_type::AND);
    add("\n", symbol_type::SEMI_COLON);
    add("\n\r", symbol_type::SEMI_COLON);
  }
} separators;

static struct logical_op_ : symbols<symbol_type>
{
  logical_op_()
  {
    add("&&", symbol_type::DOUBLE_AND);
    add("||", symbol_type::DOUBLE_OR);
  }
} logical_op;

static struct pipe_op_ : symbols<symbol_type>
{
  pipe_op_()
  {
    add("|", symbol_type::OR);
    add("|&", symbol_type::OR_AND);
  }
} pipe_op;

static struct redir_op_ : symbols<symbol_type>
{
  redir_op_()
  {
    add(">",  symbol_type::RIGHT);
    add(">>", symbol_type::DOUBLE_RIGHT);
    add("<",  symbol_type::LEFT);
    add("<<", symbol_type::DOUBLE_LEFT);
  }
} redir_op;
/* *** */

} // grammar
} // parser
