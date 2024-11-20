#include <iostream>
#include <string>

std::string global_expression = "";

////////////////////////////////////////////////////////////////////////////////
// utils.cc

bool isOperator(std::string s)
{
    return (s == "+") || (s == "-") || (s == "*") || (s == "/");
}

bool isNumber(std::string s)
{
    return std::stoi(s) * 0 == 0;
}

/**
 * splitstringToArray splits s delimited by dl, determining the element
 * inserted into dst of length l.
 */
int splitstringToArray(const std::string s, const char dl, const int l, std::string dst[])
{
    std::string element = "";
    int index = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == dl)
        {
            dst[index] = element;
            element = "";
            index++;
        }
        else
            element += s[i];
    }

    // TODO
    // handle the last element in s, which has/should have no space after it.
    dst[index] = element;

    return 0;
}

/**
 * evaluateExpression returns an int corresponding to the
 * answer to the space delimited mathematical expression
 * from expr.
 */
int evaluateExpression(const std::string expr)
{
    // Determine length for array.
    int len = 1;
    if (expr[expr.size() - 1] == ' ')
        len--; // we shouldn't account for the last space

    for (int i = 0; i < expr.size(); i++)
    {
        if (expr[i] == ' ')
            len++;
    }

    std::string exprValues[len];

    splitstringToArray(expr, ' ', len, exprValues);

    // Expression evaluation with for loop
    std::string stack[len];
    int stackIndex = 0;
    for (int i = 0; i < len; i++) // TODO - Please improve this process lol
    {
        if (exprValues[i] == "(")
        {
            std::cout << "\t\t\topepa\t" << exprValues[i] << std::endl;
            continue;
        }

        else if ((exprValues[i] != ")") && (isOperator(exprValues[i]) || isNumber(exprValues[i])) && (i != (len - 1)))
        {
            stack[stackIndex] = exprValues[i];
            stackIndex++;

            continue;
        }

        else
        {
            if (i == (len - 1)) // handle the the last value.
            {
                stack[stackIndex] = exprValues[i];
                stackIndex++;
            }

            int tempAns = 0;
            while (stack[1] != "" && stack[2] != "")
            {
                int num1 = std::stoi(stack[0]);
                std::string oprtr = stack[1];
                int num2 = std::stoi(stack[2]);

                if (oprtr == "+")
                {
                    tempAns = num1 + num2;
                }
                if (oprtr == "-")
                {
                    tempAns = num1 - num2;
                }
                if (oprtr == "*")
                {
                    tempAns = num1 * num2;
                }
                if (oprtr == "/" && num2 != 0)
                {
                    tempAns = num1 / num2;
                }

                // empty values since they've already been used.
                stack[1] = "";
                stack[2] = "";

                // After processing, shift values by 2 positions in stack.
                int stackShiftIndex = 0;
                while (stackShiftIndex < (len - 3))
                {
                    stack[stackShiftIndex + 1] = stack[stackShiftIndex + 3];
                    stack[stackShiftIndex + 3] = ""; // clearing values to prevent infinite loop
                    stackShiftIndex++;
                }

                stack[0] = std::to_string(tempAns);
                stackIndex = 1;
            }

            continue;
        }
    }

    int ret = std::stoi(stack[0]);
    return ret;
}

////////////////////////////////////////////////////////////////////////////////
// gui.cc
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

    Gtk::Frame frame;
    Gtk::Grid grid;
    Gtk::Button btn0, btn1, btn2, btn3, btn4, btn5, btn6, btn7, btn8, btn9, btnPlus, btnMinus, btnTimes, btnDivision, btnEquals, btnClear;
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
      btnClear("CLR")
{
    set_child(frame);
    frame.set_child(grid);

    // Append visible components
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
    grid.attach_next_to(btn0, btn8, Gtk::PositionType::BOTTOM);

    grid.attach(btnPlus, 3, 0);
    grid.attach(btnMinus, 3, 1);
    grid.attach(btnTimes, 3, 2);
    grid.attach(btnDivision, 3, 3);
    grid.attach_next_to(btnClear, btn7, Gtk::PositionType::BOTTOM);
    grid.attach_next_to(btnEquals, btn9, Gtk::PositionType::BOTTOM);

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
    btnEquals.signal_clicked().connect(sigc::mem_fun(*this, &Calculator::on_btnEquals_click));
}

Calculator::~Calculator()
{
}

void Calculator::on_btn0_click()
{
    global_expression += "0";
}
void Calculator::on_btn1_click()
{
    global_expression += "1";
}
void Calculator::on_btn2_click()
{
    global_expression += "2";
}
void Calculator::on_btn3_click()
{
    global_expression += "3";
}
void Calculator::on_btn4_click()
{
    global_expression += "4";
}
void Calculator::on_btn5_click()
{
    global_expression += "5";
}
void Calculator::on_btn6_click()
{
    global_expression += "6";
}
void Calculator::on_btn7_click()
{
    global_expression += "7";
}
void Calculator::on_btn8_click()
{
    global_expression += "8";
}
void Calculator::on_btn9_click()
{
    global_expression += "9";
}
void Calculator::on_btnPlus_click()
{
    global_expression += "+";
}
void Calculator::on_btnMinus_click()
{
    global_expression += "-";
}
void Calculator::on_btnTimes_click()
{
    global_expression += "*";
}
void Calculator::on_btnDivision_click()
{
    global_expression += "/";
}
void Calculator::on_btnClear_click()
{
    global_expression = "";
}
void Calculator::on_btnEquals_click()
{
    std::cout << global_expression << std::endl;
}

////////////////////////////////////////////////////////////////////////////////
// main.cc

int main(int argc, char *argv[])
{
    // std::string toEvaluate;

    // std::cout << "Enter a mathematical expression to evaluate: ";
    // getline(std::cin, toEvaluate);
    // std::cout << std::endl;

    // int answer = evaluateExpression(toEvaluate);
    // std::cout << "The answer is " << answer << std::endl;

    auto app = Gtk::Application::create();

    return app->make_window_and_run<Calculator>(argc, argv);
}
