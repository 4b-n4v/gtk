#include <gtkmm.h>
class MyWindow : public Gtk::Window
{
      public:
	MyWindow();
};

MyWindow::MyWindow()
{
	set_title("Empty");
	set_default_size(1920, 1080);
}

int main(int argc, char *argv[])
{
	auto app = Gtk::Application::create("org.gtkmm.examples.base");
	return app->make_window_and_run<MyWindow>(argc, argv);
}
