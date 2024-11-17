#include <iostream>
#include <string>

////////////////////////////////////////////////////////////////////////////////
// utils.cc

void panic(std::string msg)
{
    std::cout << msg << std::endl;
    exit(1);
}

bool isOperator(std::string s)
{
    return (s == "+") || (s == "-") || (s == "*") || (s == "/");
}

bool isNumber(std::string s)
{
    // Condition looks out for the chance that s is the last
    // character in the expression
    if (s == ")")
        return false;

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

    // handle the last element in s, which has no space after it.
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
    // Start at 1 since last char will not be space.
    int len = 1;
    for (char c : expr)
    {
        if (c == ' ')
            len++;
    }
    std::string exprValues[len];

    splitstringToArray(expr, ' ', len, exprValues);

    // for (size_t i = 0; i < len; i++)
    // {
    //     std::cout << "exprVal:\t" << exprValues[i] << std::endl;
    // }

    std::string stack[len];
    int stackIndex = 0;
    for (int i = 0; i < len; i++)
    {
        if (exprValues[i] == "(")
        {
            std::cout << "\t\t\topepa\t" << exprValues[i] << std::endl;
            continue;
        }

        else if ((isOperator(exprValues[i]) || isNumber(exprValues[i])) && (i != (len - 1)))
        {
            // std::cout << "isO|N\t" << exprValues[i] << std::endl;

            stack[stackIndex] = exprValues[i];
            stackIndex++;

            continue;
        }

        else
        {
            // std::cout << "clopa\t" << exprValues[i] << std::endl;

            if (i == (len - 1)) // handle the the last value.
            {
                stack[stackIndex] = exprValues[i];
                stackIndex++;
            }

            std::cout << "\t\t\tstack[0] is " << stack[0] << std::endl;

            int tempAns = 0;
            while (stack[1] != "" && stack[2] != "")
            {
                int num1 = std::stoi(stack[0]);
                std::string oprtr = stack[1];
                int num2 = std::stoi(stack[2]);
                std::cout << "\t\t\t\tprocessing expression " << num1 << oprtr << num2 << std::endl;

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
                    std::cout << std::endl
                              << "\t\t\t\t\tstackShiftIndex == " << stackShiftIndex << std::endl;
                    std::cout << "\t\t\t\t\treplacing " << stack[stackShiftIndex + 1] << " with " << stack[stackShiftIndex + 3] << std::endl;

                    stack[stackShiftIndex + 1] = stack[stackShiftIndex + 3];
                    stack[stackShiftIndex + 3] = ""; // clearing values to prevent infinite loop
                    stackShiftIndex++;
                }

                std::cout << "\t\t\t\tchanging " << stack[0] << " to " << tempAns << std::endl;

                stack[0] = std::to_string(tempAns);
                stackIndex = 1;
            }

            std::cout << "\t\t\tstack is now: " << std::endl;
            for (int k = 0; k < len; k++)
            {
                std::cout << "\t\t\t\tk == " << k << "\t" << "stack[k] == " << stack[k] << std::endl;
            }
            std::cout << std::endl;

            continue;
        }
    }

    int ret = std::stoi(stack[0]);
    return ret;
}

////////////////////////////////////////////////////////////////////////////////
// gui.cc

////////////////////////////////////////////////////////////////////////////////
// main.cc

int main()
{
    std::string toEvaluate;

    std::cout << "Enter a mathematical expression to evaluate: ";
    getline(std::cin, toEvaluate);
    std::cout << std::endl;

    int answer = evaluateExpression(toEvaluate);
    std::cout << "The answer is " << answer << std::endl;
}
