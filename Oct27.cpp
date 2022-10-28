// STACK

/*#include<iostream>
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
}*/

//LINEAR QUEUE

/*#include<iostream>
#include<string>
using namespace std;

class Queue
{
public:
    int Front;
    int rear;
    int arr[5];
    Queue()
    {
        Front = -1;
        rear = -1;

        for(int i=0;i<5;i++)
        {
            arr[i] = 0;
        }
    }

    bool isEmpty()
    {
        if(Front==-1 && rear == -1)
            return true;
        else
            return false;
    }

    bool isFull()
    {
        if(rear == 4)
            return true;
        else
            return false;
    }

    void enqueue(int val)
    {
        if(isFull())
            cout << "Queue full!!" << endl;
        else if(isEmpty())
        {
            rear = Front = 0;
            arr[rear] = val;
        }
        else
        {
            rear++;
            arr[rear] = val;

        }
    }

    void dequeue()
    {
        if(isEmpty())
        {
            cout << "Queue is Empty!!" << endl;
        }
        else if(Front == rear)
        {
            cout << arr[Front] << " is dequeued." << endl;
            arr[Front] = 0;
            Front = rear = -1;
        }
        else
        {
            cout << arr[Front] << " is dequeued." << endl;
            arr[Front] = 0;
            Front++;
        }
    }

    int Count()
    {
        return (rear - Front + 1);
    }

    void display()
    {
        cout << endl << "All values in the Queue are : " << endl;
        for(int i=0;i<5;i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl << endl;
    }
};

int main()
{
    Queue Q1;

    Q1.dequeue();
    Q1.enqueue(10);
    Q1.enqueue(20);
    Q1.enqueue(30);
    Q1.enqueue(40);
    Q1.enqueue(50);

    Q1.display();

    Q1.enqueue(60);

    cout << "Total values : " << Q1.Count() << endl;

    Q1.dequeue();
    Q1.dequeue();

    Q1.display();

    cout << "Total values : " << Q1.Count() << endl;

    return 0;

}
*/

//CIRCULAR QUEUE

#include<iostream>
using namespace std;

class Queue
{
    int Front;
    int rear;
    int arr[5];
    int itemctr=0;

public:
    Queue()
    {
        Front = rear = -1;

        for(int i=0;i<5;i++)
        {
            arr[i] = 0;
        }
    }

    bool isEmpty()
    {
        if(rear == -1 && Front == -1)
            return true;
        else
            return false;
    }

    bool isFull()
    {
        if((rear+1)%5==Front)
            return true;
        else
            return false;
    }

    void enqueue(int val)
    {
        if(isFull())
            cout << "Queue is Full!!" << endl;
        else if(isEmpty())
        {
            Front = rear = 0;
            arr[rear] = val;
            itemctr++;
        }
        else
        {
            rear = (rear+1)%5;
            arr[rear] = val;
            itemctr++;
        }
    }

    void dequeue()
    {
        if(isEmpty())
            cout << "Queue is Empty!!" << endl;
        else if(Front == rear)
        {
            cout << arr[Front] << " is dequeued." << endl;
            arr[Front] = 0;
            Front = rear = -1;
            itemctr--;
        }
        else
        {
            cout << arr[Front] << " is dequeued." << endl;
            arr[Front] = 0;
            Front = (Front+1)%5;
            itemctr--;
        }
    }

    int Count()
    {
        return itemctr;
    }

    void display()
    {
        cout << endl << "All values in the Queue are : " << endl;
        for(int i=0;i<5;i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl << endl;
    }
};


int main()
{
    Queue Q1;

    Q1.dequeue();
    Q1.enqueue(10);
    Q1.enqueue(20);
    Q1.enqueue(30);
    Q1.enqueue(40);
    Q1.enqueue(50);

    Q1.display();

    Q1.enqueue(60);

    cout << "Total values : " << Q1.Count() << endl;

    Q1.dequeue();
    Q1.dequeue();

    Q1.display();

    cout << "Total values : " << Q1.Count() << endl;

    Q1.enqueue(60);
    Q1.enqueue(70);
    Q1.dequeue();

    Q1.display();

    cout << "Total values : " << Q1.Count() << endl;

    return 0;

}

