#pragma once

#include <boost/spirit/home/x3.hpp>

namespace parser
{
namespace grammar
{
using boost::spirit::x3::symbols;
using boost::spirit::x3::unused_type;

/* symbols tables */
struct separators_ : symbols<>
{
  separators_()
  {
    add(";");
    add("&");
  }
} separators;

struct logical_op_ : symbols<>
{
  logical_op_()
  {
    add("&&");
    add("||");
  }
} logical_op;

struct redir_op_ : symbols<>
{
  redir_op_()
  {
    add(">");
    add(">>");
    add("<");
    add("<<");
  }
} redir_op;
/* *** */

} // grammar
} // parser
