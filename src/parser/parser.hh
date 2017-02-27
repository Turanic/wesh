#pragma once

#include <string>

#include <ast/ast.hh>

namespace parser
{
ast::ast_root parse_input(const std::string &input);
}
