#include <iostream>
#include <string>

#include <ast/visitors/launcher.hh>
#include <ast/visitors/printer.hh>
#include <parser/parser.hh>

int main(void)
{
  /* input construction */
  std::string input1 { "echo test > lol.txt; true && true || echo check; cat lol.txt | grep -rn mdr;" };

  /* parse input */
  const auto ast = parser::parse_input(input1);

  /* execute input */
  ast::visitors::Printer printer_visitor{};
  ast::visitors::Launcher launcher_visitor{};
  printer_visitor(ast);
  launcher_visitor(ast);

  return 0;
}
