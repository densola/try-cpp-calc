#include <string>

#include "utils.h"

bool isOperator(std::string s)
{
    return (s == "+") || (s == "-") || (s == "*") || (s == "/");
}

bool isNumber(std::string s)
{
    if (s == "")
        return false;

    bool isNum = true;
    for (int i = 0; i < s.size(); i++)
    {
        if ((i == 0) && (s[i] == '-') && (s.size() > 1))
            continue;

        if ((s[i] != '0') && (s[i] != '1') && (s[i] != '2') && (s[i] != '3') && (s[i] != '4') && (s[i] != '5') && (s[i] != '6') && (s[i] != '7') && (s[i] != '8') && (s[i] != '9'))
            isNum = false;
    }

    return isNum;
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
std::string evaluateExpression(const std::string expr)
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
        if (exprValues[i] == "(" && (i < len - 1))
            continue;

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
                if (!isNumber(stack[0]) || !isNumber(stack[2]) || (len < 3))
                    return "ERROR";

                int num1 = std::stoi(stack[0]);
                std::string oprtr = stack[1];
                int num2 = std::stoi(stack[2]);

                if (oprtr == "+")
                    tempAns = num1 + num2;
                else if (oprtr == "-")
                    tempAns = num1 - num2;
                else if (oprtr == "*")
                    tempAns = num1 * num2;
                else if (oprtr == "/" && num2 != 0)
                    tempAns = num1 / num2;
                else
                    return "ERROR";

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

        return "ERROR";
    }

    if (isNumber(stack[0]))
        return stack[0];

    return "ERROR";
}
