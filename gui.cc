#include <gtkmm.h>

#include "main.h"
#include "utils.h"

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

Calculator::Calculator()
    : btn0("0"),
      btn1("1"),
      btn2("2"),
      btn3("3"),
      btn4("4"),
      btn5("5"),
      btn6("6"),
      btn7("7"),
      btn8("8"),
      btn9("9"),
      btnPlus("+"),
      btnMinus("-"),
      btnTimes("*"),
      btnDivision("/"),
      btnEquals("="),
      btnClear("CLR"),
      btnOpnParnth("("),
      btnClsParnth(")")
{
    set_child(frame);
    frame.set_child(grid);

    // Append visible components,
    set_title("Calculator");
    grid.attach(btn1, 0, 0);
    grid.attach(btn2, 1, 0);
    grid.attach(btn3, 2, 0);
    grid.attach(btn4, 0, 1);
    grid.attach(btn5, 1, 1);
    grid.attach(btn6, 2, 1);
    grid.attach(btn7, 0, 2);
    grid.attach(btn8, 1, 2);
    grid.attach(btn9, 2, 2);
    grid.attach(btn0, 1, 3);

    grid.attach(btnPlus, 3, 0);
    grid.attach(btnMinus, 3, 1);
    grid.attach(btnTimes, 3, 2);
    grid.attach(btnDivision, 3, 3);

    grid.attach(btnClear, 4, 0);
    grid.attach(btnOpnParnth, 4, 1);
    grid.attach(btnClsParnth, 4, 2);
    grid.attach(btnEquals, 4, 3);

    textBuffer = Gtk::TextBuffer::create();
    textView.set_buffer(textBuffer);
    textView.set_margin(10);
    textView.set_size_request(20, 20);
    textView.set_valign(Gtk::Align::CENTER);
    grid.attach_next_to(textView, btn1, Gtk::PositionType::TOP, 4);

    // Attach click signals to buttons
    btn0.signal_clicked().connect(sigc::mem_fun(*this, &Calculator::on_btn0_click));
    btn1.signal_clicked().connect(sigc::mem_fun(*this, &Calculator::on_btn1_click));
    btn2.signal_clicked().connect(sigc::mem_fun(*this, &Calculator::on_btn2_click));
    btn3.signal_clicked().connect(sigc::mem_fun(*this, &Calculator::on_btn3_click));
    btn4.signal_clicked().connect(sigc::mem_fun(*this, &Calculator::on_btn4_click));
    btn5.signal_clicked().connect(sigc::mem_fun(*this, &Calculator::on_btn5_click));
    btn6.signal_clicked().connect(sigc::mem_fun(*this, &Calculator::on_btn6_click));
    btn7.signal_clicked().connect(sigc::mem_fun(*this, &Calculator::on_btn7_click));
    btn8.signal_clicked().connect(sigc::mem_fun(*this, &Calculator::on_btn8_click));
    btn9.signal_clicked().connect(sigc::mem_fun(*this, &Calculator::on_btn9_click));

    btnPlus.signal_clicked().connect(sigc::mem_fun(*this, &Calculator::on_btnPlus_click));
    btnMinus.signal_clicked().connect(sigc::mem_fun(*this, &Calculator::on_btnMinus_click));
    btnTimes.signal_clicked().connect(sigc::mem_fun(*this, &Calculator::on_btnTimes_click));
    btnDivision.signal_clicked().connect(sigc::mem_fun(*this, &Calculator::on_btnDivision_click));

    btnClear.signal_clicked().connect(sigc::mem_fun(*this, &Calculator::on_btnClear_click));
    btnOpnParnth.signal_clicked().connect(sigc::mem_fun(*this, &Calculator::on_btnOpnParnth_click));
    btnClsParnth.signal_clicked().connect(sigc::mem_fun(*this, &Calculator::on_btnClsParnth_click));
    btnEquals.signal_clicked().connect(sigc::mem_fun(*this, &Calculator::on_btnEquals_click));
}

Calculator::~Calculator()
{
}

void Calculator::on_btn0_click()
{
    global_expression += "0";
    textBuffer->set_text(global_expression);
}
void Calculator::on_btn1_click()
{
    global_expression += "1";
    textBuffer->set_text(global_expression);
}
void Calculator::on_btn2_click()
{
    global_expression += "2";
    textBuffer->set_text(global_expression);
}
void Calculator::on_btn3_click()
{
    global_expression += "3";
    textBuffer->set_text(global_expression);
}
void Calculator::on_btn4_click()
{
    global_expression += "4";
    textBuffer->set_text(global_expression);
}
void Calculator::on_btn5_click()
{
    global_expression += "5";
    textBuffer->set_text(global_expression);
}
void Calculator::on_btn6_click()
{
    global_expression += "6";
    textBuffer->set_text(global_expression);
}
void Calculator::on_btn7_click()
{
    global_expression += "7";
    textBuffer->set_text(global_expression);
}
void Calculator::on_btn8_click()
{
    global_expression += "8";
    textBuffer->set_text(global_expression);
}
void Calculator::on_btn9_click()
{
    global_expression += "9";
    textBuffer->set_text(global_expression);
}
void Calculator::on_btnPlus_click()
{
    global_expression += " + ";
    textBuffer->set_text(global_expression);
}
void Calculator::on_btnMinus_click()
{
    global_expression += " - ";
    textBuffer->set_text(global_expression);
}
void Calculator::on_btnTimes_click()
{
    global_expression += " * ";
    textBuffer->set_text(global_expression);
}
void Calculator::on_btnDivision_click()
{
    global_expression += " / ";
    textBuffer->set_text(global_expression);
}
void Calculator::on_btnOpnParnth_click()
{
    global_expression += "( ";
    textBuffer->set_text(global_expression);
}
void Calculator::on_btnClsParnth_click()
{
    global_expression += " )";
    textBuffer->set_text(global_expression);
}
void Calculator::on_btnClear_click()
{
    global_expression = "";
    textBuffer->set_text(global_expression);
}
void Calculator::on_btnEquals_click()
{
    global_expression = evaluateExpression(global_expression);
    textBuffer->set_text(global_expression);
}
