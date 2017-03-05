#pragma once

#include <iostream>
#include <string>

namespace readline
{
void print_prompt(std::ostream& os);
std::string read_input(std::istream& is);
} // readline
