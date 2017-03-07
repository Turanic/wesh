#include <iostream>
#include <ast/visitors/launcher.hh>
#include <ast/visitors/printer.hh>
#include <options/opt_parser.hh>
#include <parser/parser.hh>
#include <readline/readline.hh>

int main(int argc, char* argv[])
{
  options::parse_options(argc, argv);
  while (true)
  {
    readline::print_prompt(std::cout);

    /* parse input */
    const auto ast = parser::parse_input(readline::read_input(std::cin));

    /* execute input */
    ast::visitors::Printer printer_visitor{};
    ast::visitors::Launcher launcher_visitor{};
    printer_visitor(ast);
    launcher_visitor(ast);
  }

  return 0;
}
