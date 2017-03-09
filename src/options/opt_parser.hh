#pragma once

#include <memory>
#include "input_extractor_interface.hh"

namespace options
{
std::unique_ptr<InputExtractorInterface> parse_options(int argc, char* argv[]);
} // options
