#pragma once

#include <string>
#include <vector>

namespace exec
{
int start_process(const std::string& name,
                  const std::vector<std::string>& args);
// int start_pipeline();
} // exec
