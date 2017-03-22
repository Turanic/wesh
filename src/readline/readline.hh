#pragma once

#include <iostream>
#include <string>
#include "terminal.hh"

namespace readline
{
void print_prompt(std::ostream& stream);
std::string read_input(std::istream& stream, Terminal& terminal);
} // readline
