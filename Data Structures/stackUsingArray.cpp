#include <iostream>
using namespace std;
int _stacksize = 50;
int _top = _stacksize - 1;
int _stack[50];

void printStack()
{
    cout << "Stack:" << endl;
    for (int i = _top + 1; i < _stacksize; i++)
    {
        cout << _stack[i] << endl;
    }
}

void push(int num)
{
    _stack[_top] = num;
    _top--;
    cout << "\nElement Pushed" << endl;
    printStack();
}

void pop()
{
    _top++;
    cout << "\nElement Popped" << endl;
    printStack();
}

int main()
{
    push(13);
    push(24);
    pop();
    push(12);
    pop();

    return (0);
}