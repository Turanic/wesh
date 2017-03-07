#include "opt_parser.hh"
#include <iostream>
#include <boost/program_options.hpp>

#ifndef WESH_VERSION
  #define WESH_VERSION 0.0
#endif

namespace options
{
void parse_options(int argc, char* argv[])
{
  namespace opt = boost::program_options;

  opt::options_description description{ "Options list" };
  { /* fill options */
    auto add = description.add_options();
    add("help,h", "show usage");
    add("version,v", "display current version");
  }
  const auto parse_result = opt::parse_command_line(argc, argv, description);

  opt::variables_map vmap{};
  opt::store(parse_result, vmap);
  opt::notify(vmap);

  if (vmap.count("help"))
  {
    std::cout << description << std::endl;
    std::exit(0);
  }

  if (vmap.count("version"))
  {
    std::cout << "Wesh pre-alpha version " <<  WESH_VERSION << std::endl;
    std::exit(0);
  }
}
} // options
