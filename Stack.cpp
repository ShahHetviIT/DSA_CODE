// STACK

#include<iostream>
using namespace std;

class Stack
{
public:
    int top;
    int arr[5];

    Stack()
    {
        top = -1;

        for(int i=0;i<5;i++)
        {
            arr[i] = 0;
        }
    }

    bool isEmpty()
    {
        if(top==-1)
            return true;
        else
            return false;
    }

    bool isFull()
    {
        if(top==4)
            return true;
        else
            return false;
    }

    void push(int val)
    {
        if(isFull())
            cout << "Stack Overflow!!" << endl;
        else
        {
            top++;
            arr[top]=val;
        }
    }

    void pop()
    {
        if(isEmpty())
            cout << "Stack Underflow!!" << endl;
        else
        {
            cout << arr[top] << " is poped." << endl;

            arr[top]=0;
            top--;
        }
    }

    int Count()
    {
        return top;
    }

    int seek(int pos)
    {
        if(isEmpty())
        {
            cout << "Stack Underflow!!" << endl;
            return 0;
        }
        else
        {
            return arr[pos];
        }
     }

     void change(int val,int pos)
     {
         if(isEmpty())
         {
              cout << "Stack Underflow!!" << endl;
         }
         else
         {
             arr[pos] = val;
         }
     }

     void display()
     {
         cout << endl << "All values in stack are : " << endl;

         for(int i= top;i>=0;i--)
         {
             cout << arr[i] << endl;
         }
         cout << endl;
     }
};

int main()
{
    Stack S1;

    S1.pop();
    S1.push(10);
    S1.push(20);
    S1.push(30);
    S1.push(40);
    S1.push(50);

    S1.display();

    S1.push(60);

    cout << "Total elements : " << S1.Count() << endl;

    S1.pop();
    S1.pop();

    S1.display();

    cout << "Total elements : " << S1.Count() << endl;

    return 0;
}

