#include <iostream>
#include <string>

#include <gtkmm.h>

#include "gui.h"
#include "utils.h"

int main(int argc, char *argv[])
{
    auto app = Gtk::Application::create();
    return app->make_window_and_run<Calculator>(argc, argv);
}
