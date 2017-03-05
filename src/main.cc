#include <iostream>
#include <ast/visitors/launcher.hh>
#include <ast/visitors/printer.hh>
#include <parser/parser.hh>
#include <readline/readline.hh>

int main(void)
{
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
