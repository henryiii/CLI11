// ===================================================================
//   subcommand_a.cpp
// ===================================================================

#include "subcommand_a.hpp"

/// Set up a subcommand and capture a shared_ptr to a struct that holds all its options.
/// The variables of the struct are bound to the CLI options.
/// We use a shared ptr so that the addresses of the variables remain for binding,
/// You could return the shared pointer if you wanted to access the values in main.
void setup_subcommand_a(CLI::App &app) {
    // Create the option and subcommand objects.
    auto opt = std::make_shared<SubcommandAOptions>();
    auto sub = app.add_subcommand("subcommand_a", "performs subcommand a", true);

    // Add options to sub, binding them to opt.
    sub->add_option("-f,--file", opt->file, "File name")->required();
    sub->add_flag("--with-foo", opt->with_foo, "Counter");

    // Set the run function as callback to be called when this subcommand is issued.
    sub->set_callback([opt]() { run_subcommand_a(*opt); });

    // Note: In C++14, you could make a unique pointer, then pass it into the lambda function via
    // a move. That's slightly more elegant, but you won't be able to see the runtime difference
    // in skipping one mutex check for shared_ptr.
}

/// The function that runs our code.
/// This could also simply be in the callback lambda itself,
/// but having a separate function is cleaner.
void run_subcommand_a(SubcommandAOptions const &opt) {
    // Do stuff...
    std::cout << "Working on file: " << opt.file << std::endl;
    if(opt.with_foo) {
        std::cout << "Using foo!" << std::endl;
    }
}
