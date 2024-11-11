#include "stack_queue.h"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;
using namespace std;
char invertBrackets(char ch)
{
    if (ch == '(') return ')';
    else if (ch == '[') return ']';
    else if (ch == '{') return '}';
    return ' ';
}

bool checkBrackets(string& s)
{
    Stack<char> stack;
    size_t len = s.length();
    for (size_t i = 0; i < len; i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            stack.push(s[i]);
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
            if (!stack.isEmpty() && s[i] == invertBrackets(stack.top()))
                stack.pop();
            else return 0;
    }
    return (stack.isEmpty());
       
}

int main()
{
    // Тестовые строки для проверки
    string test1 = "({[]})"; 
    string test2 = "({[})"; 
    string test3 = "(()())"; 
    string test4 = "{[("; 

    // Проверка строк
    cout << "Test 1: " << test1 << " - " << (checkBrackets(test1) ? "Valid" : "Invalid") << endl;
    cout << "Test 2: " << test2 << " - " << (checkBrackets(test2) ? "Valid" : "Invalid") << endl;
    cout << "Test 3: " << test3 << " - " << (checkBrackets(test3) ? "Valid" : "Invalid") << endl;
    cout << "Test 4: " << test4 << " - " << (checkBrackets(test4) ? "Valid" : "Invalid") << endl;

    return 0;

}