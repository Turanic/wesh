#include <iostream>
#include <ast/visitors/launcher.hh>
#include <ast/visitors/printer.hh>
#include <exec/builtins/exit.hh>
#include <options/opt_parser.hh>
#include <parser/parser.hh>

int main(int argc, char* argv[])
{
  const auto input_extractor_ptr = options::parse_options(argc, argv);
  if (not input_extractor_ptr)
    return 0;

  try
  {
    do
    {
      /* parse input */
      const auto ast = parser::parse_input(input_extractor_ptr->input_get());

      /* execute input */
      ast::visitors::Printer printer_visitor{};
      ast::visitors::Launcher launcher_visitor{};
      printer_visitor(ast);
      launcher_visitor(ast);
    } while (input_extractor_ptr->should_loop());
  }
  catch (const exec::builtins::ExitCalled&)
  {
    /* Nothing to do here, exiting the program normally. */
  }

  return 0;
}
