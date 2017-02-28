#pragma once

#include <string>
#include <vector>

namespace exec
{
int start_process(std::string name, std::vector<std::string> args);
// int start_pipeline();
} // exec
