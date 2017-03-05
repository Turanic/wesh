#include <boost/spirit/home/x3.hpp>
#include "grammar_def.hh"

namespace parser
{
namespace grammar
{
namespace x3 = boost::spirit::x3;

using context_type = x3::phrase_parse_context<x3::blank_type>::type;
using iterator_type = std::string::const_iterator;

BOOST_SPIRIT_INSTANTIATE(wesh_rule_type, iterator_type, context_type);
} // grammar
} // parser
