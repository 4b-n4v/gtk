#ifndef GTKMM_EXAMPLE_BUTTONS_H
#define GTKMM_EXAMPLE_BUTTONS_H

#include <gtkmm/button.h>
#include <gtkmm/window.h>

class Buttons : public Gtk::Window
{
      public:
	Buttons();
	virtual ~Buttons();

      protected:
	// signal handlers:
	void on_button_clicked();

	// Child widgets:
	Gtk::Button m_button;
};

#endif // GTKMM_EXAMPLE_BUTTONS_H
