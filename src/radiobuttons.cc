#include "radiobuttons.h"
#include "sigc++/functors/mem_fun.h"

RadioButtons::RadioButtons()
    : m_Box_Top(Gtk::Orientation::VERTICAL),
      m_Box1(Gtk::Orientation::VERTICAL, 10),
      m_Box2(Gtk::Orientation::VERTICAL, 10),
      m_RadioButton1("button1"),
      m_RadioButton2("button2"),
      m_RadioButton3("button3"),
      m_Button_Close("Close")
{
        // Set title and border of the window
        set_title("radio buttons");

        // GtkLCheckButton and Gtk::ToggleButton have set_group() methods.
        // They act as radio buttons, if they are included in a group.

        // Put radio buttons 2 and 3 in the same group as 1:
        m_RadioButton2.set_group(m_RadioButton1);
        m_RadioButton3.set_group(m_RadioButton1);

        // Add outer box to the window (because the window
        // can only contain a single widget)
        set_child(m_Box_Top);

        // Put the inner boxes and the separator in the outer box:
        m_Box_Top.append(m_Box1);
        m_Box_Top.append(m_Separator);
        m_Box_Top.append(m_Box2);
        m_Separator.set_expand();

        // Set the inner boxes' margins
        m_Box1.set_margin(10);
        m_Box2.set_margin(10);

        // Put the radio buttons in Box1:
        m_Box1.append(m_RadioButton1);
        m_Box1.append(m_RadioButton2);
        m_Box1.append(m_RadioButton3);
        m_RadioButton1.set_expand();
        m_RadioButton2.set_expand();
        m_RadioButton3.set_expand();

        // Set the second button active
        m_RadioButton2.set_active(true);

        // Put Close Button in Box2:
        m_Box2.append(m_Button_Close);
        m_Button_Close.set_expand();

        // Make the button the default widget
        set_default_widget(m_Button_Close);

        // Connect the toggled signal of the button to
        // RadioButtons::on_button_toggled()
        m_Button_Close.signal_clicked().connect(sigc::mem_fun(*this,
                                                              &RadioButtons::on_button_clicked));
}

RadioButtons::~RadioButtons()
{
}

void RadioButtons::on_button_clicked()
{
        set_visible(false);
}
