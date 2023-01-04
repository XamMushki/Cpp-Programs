#include <iostream>
using namespace std;
// Global variables
const int _stacksize = 5;
int _top = _stacksize - 1;
int _stack[_stacksize];

void printStack()
{
    cout << "Stack:" << endl;
    for (int i = _top + 1; i < _stacksize; i++)
    {
        cout << _stack[i] << endl;
    }
    cout<<endl;
}

void push(int num)
{
    if (_top < 0)
    {
        cout << "Stack Overflow!!!\n" << endl;
    }
    else
    {
        _stack[_top] = num;
        _top--;
        cout << num << " Pushed" << endl;
        printStack();
    }
}

void pop()
{
    if (_top == _stacksize - 1)
    {
        cout << "Stack Underflow!!!\n" << endl;
    }
    else
    {
        _top++;
        int element = _stack[_top];
        cout << element << " Popped" << endl;
        printStack();
    }
}

int main()
{
    push(13);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
    push(12);
    pop();
    pop();
    pop();

    return (0);
}