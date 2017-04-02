#pragma once

#include <iostream>
#include <string>
#include "terminal.hh"

namespace readline
{
constexpr auto kps1 = "WESH pre-alpha";

void print_prompt();
std::string read_input(Terminal& terminal);
} // readline
