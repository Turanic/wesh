#pragma once

#include <iostream>
#include <string>

namespace readline
{
void print_prompt(std::ostream& stream);
std::string read_input(std::istream& stream);
} // readline
