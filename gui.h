#ifndef GUI_H
#define GUI_H

#include <gtkmm.h>

class Calculator : public Gtk::Window
{

public:
    Calculator();
    ~Calculator() override;

protected:
    void on_btn0_click();
    void on_btn1_click();
    void on_btn2_click();
    void on_btn3_click();
    void on_btn4_click();
    void on_btn5_click();
    void on_btn6_click();
    void on_btn7_click();
    void on_btn8_click();
    void on_btn9_click();
    void on_btnPlus_click();
    void on_btnMinus_click();
    void on_btnTimes_click();
    void on_btnDivision_click();
    void on_btnEquals_click();
    void on_btnClear_click();
    void on_btnOpnParnth_click();
    void on_btnClsParnth_click();

    Gtk::Frame frame;
    Gtk::Grid grid;
    Gtk::TextView textView;
    Glib::RefPtr<Gtk::TextBuffer> textBuffer;
    Gtk::Button btn0, btn1, btn2, btn3, btn4, btn5, btn6, btn7, btn8, btn9, btnPlus, btnMinus, btnTimes, btnDivision, btnEquals, btnClear, btnOpnParnth, btnClsParnth;
};

#endif