#include "opt_parser.hh"
#include <iostream>
#include <boost/program_options.hpp>
#include "argument_extractor.hh"
#include "interactive_extractor.hh"

#ifndef WESH_VERSION
#define WESH_VERSION 0.0
#endif

namespace options
{
std::unique_ptr<InputExtractorInterface> parse_options(int argc, char* argv[])
{
  namespace opt = boost::program_options;

  opt::options_description description{ "Options list" };
  { /* fill options */
    auto add = description.add_options();
    add("help,h", "show usage");
    add("version,v", "display current version");
    add("interactive,i", "use the interactive shell");
    add("command,c", opt::value<std::string>(), "pass the command in a string");
  }
  const auto parse_result = opt::parse_command_line(argc, argv, description);

  opt::variables_map vmap{};
  opt::store(parse_result, vmap);
  opt::notify(vmap);

  if (vmap.count("help"))
  {
    std::cout << description << std::endl;
    return nullptr;
  }

  if (vmap.count("version"))
  {
    std::cout << "Wesh pre-alpha version " << WESH_VERSION << std::endl;
    return nullptr;
  }

  if (vmap.count("interactive"))
    return std::make_unique<InteractiveExtractor>();
  if (vmap.count("command"))
    return std::make_unique<ArgumentExtractor>(
      vmap["command"].as<std::string>());

  return std::make_unique<InteractiveExtractor>();
}
} // options
