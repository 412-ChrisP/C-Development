#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

bool isOperand(char c)
{
    return isdigit(c);
}

bool isOperator(char c)
{
    switch(c)
    {
        case '+':
        case '-':
        case '*':
        case '/':
            return true;
        default:
            return false;
    }
}

int performOperation(char operation, int op1, int op2)
{
    switch(operation)
    {
        case '+':
            return op1 + op2;
        case '-':
            return op1 - op2;
        case '*':
            return op1 * op2;
        case '/':
            return op1 / op2;
        default:
            return 0;
    }
}

int evaluatePostfix(string exp)
{
    stack<int> s;
    for(int i = 0; i < exp.length(); i++)
    {
        if(exp[i] == ' ' || exp[i] == ':')
        {
            continue;
        }
        else if(isOperator(exp[i]))
        {
            if(s.size() < 2)
            {
                cout << "Invalid postfix expression! - less than 2 entries in stack for arithmetic operation" << endl;
                return 0;
            }
            else
            {
                int op2 = s.top();
                s.pop();
                int op1 = s.top();
                s.pop();
                int result = performOperation(exp[i], op1, op2);
                s.push(result);
                cout << "Token = " << exp[i] << " Pop " << op1 << " Pop " << op2 << " Push " << result << endl;
            }
        }
        else if(isOperand(exp[i]))
        {
            int operand = exp[i] - '0';
            s.push(operand);
            cout << "Token = " << operand << " Push " << operand << endl;
        }
        else
        {
            cout << "Invalid postfix expression - invalid character -> " << exp[i] << endl;
            return 0;
        }
    }
    if(s.size() == 1)
    {
        int result = s.top();
        s.pop();
        cout << "Token = Pop " << result << endl;
        return result;
    }
    else
    {
        cout << "Invalid postfix expression! - more than 1 entry in stack after evaluation" << endl;
        return 0;
    }
}

int main()
{
    char choice = 'Y';
    while(choice == 'Y' || choice == 'y')
    {
        string expression;
        cout << "Please enter the postfix expression (RPN) to be evaluated:" << endl;
        getline(cin, expression);
        int result = evaluatePostfix(expression);
        if(result != 0)
        {
            cout << "Result = " << result << endl;
        }
        cout << "type 'Y' or 'y' to continue or type any other letter to quit: ";
        cin >> choice;
        cin.ignore();
        cout << endl;
    }
    return 0;
}
/*
EXECUTION CODE:

Please enter the postfix expression (RPN) to be evaluated:
9 2 1 + / 4 *
Token = 9 Push 9
Token = 2 Push 2
Token = 1 Push 1
Token = + Pop 2 Pop 1 Push 3
Token = / Pop 9 Pop 3 Push 3
Token = 4 Push 4
Token = * Pop 3 Pop 4 Push 12
Token = Pop 12
Result = 12
type 'Y' or 'y' to continue or type any other letter to quit: y

Please enter the postfix expression (RPN) to be evaluated:
2 3 4 + *
Token = 2 Push 2
Token = 3 Push 3
Token = 4 Push 4
Token = + Pop 3 Pop 4 Push 7
Token = * Pop 2 Pop 7 Push 14
Token = Pop 14
Result = 14
type 'Y' or 'y' to continue or type any other letter to quit: y

Please enter the postfix expression (RPN) to be evaluated:
5 6 @
Token = 5 Push 5
Token = 6 Push 6
Invalid postfix expression - invalid character -> @
type 'Y' or 'y' to continue or type any other letter to quit: y

Please enter the postfix expression (RPN) to be evaluated:
9 +
Token = 9 Push 9
Invalid postfix expression! - less than 2 entries in stack for arithmetic operation
type 'Y' or 'y' to continue or type any other letter to quit: q

 */