#include <iostream>
#define SIZE 100
using namespace std;

class Stack
{
    int stck[SIZE];
    int top;
    public:
        Stack()
        {
            stck[SIZE]=0;
            top=-1;
        }
        void push(int n);
        int pop();
        void peek(); //peek
        void display();
        void display(int d);

};
void Stack::push(int n)
{
    if(top==SIZE)
    {
        cout << "\nStack is full!" << endl;
        return;
    }
    stck[++top]=n;
}
int Stack::pop()
{
    int v;
    if(top==-1)
    {
        cout << "\nStack Underflow" << endl;
        return -9999;
    }
    v=stck[top--];
    return v;
}
void Stack::peek()
{
    if(top==-1)
    {
        cout << "\nStack empty!" << endl;
        return;
    }
    cout << "Topmost element is: " << stck[top] << endl;
}
void Stack::display()
{
    if(top==-1)
    {
        cout << "Stack is empty!" << endl;
        return;
    }
    cout << "Stack is: " << endl;
    for(int i=0;i<=top;i++)
        cout << stck[i] << " ";
}
void Stack::display(int depth)
{
    if(top==-1)
    {
        cout << "Stack is empty!" << endl;
        return;
    }
    if(depth>=0&&depth<=top)
        cout << "The element at depth " << depth << " is " << stck[depth] << endl;
    else
        cout << "Entered depth is out of range of stack" << endl;
}
int main()
{
    Stack stk;
    int ch,n;
    do{
        cout << "\n----------------MENU---------------";
        cout << "\n1. Push \n2. Pop \n3. Peek \n4. Display Stack \n5. Display element at a depth \n0. Exit." << endl;
        cout << "\n\nEnter your choice from below: ";
        cin >> ch;
        switch(ch)
        {
        case 0:
            break;
        case 1:
            cout << "\nEnter an element: ";
            cin >> n;
            stk.push(n);
            break;
        case 2:
            n=stk.pop();
            if(n!=-9999)
                cout << "Popped element: " << n << endl;
            break;
        case 3:
            stk.peek();
            break;
        case 4:
            stk.display();
            break;
        case 5:
            cout << "\nEnter the depth: ";
            cin >> n;
            stk.display(n);
            break;
        default:
            cout << "Invalid Choice! Try again!" << endl;
            break;

        }
    }while(ch);
    return 0;
}


