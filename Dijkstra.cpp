#include<iostream>
using namespace std;

void Digkstra(int length[10][10],int n)
{
    int a[n][n];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            a[i][j] = length[i][j];
        }
    }

    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if((a[i][k]+a[k][j]) < a[i][j])
                {
                    length[i][j] = a[i][k] + a[k][j];
                }
            }
        }
    }
}


void display(int a[10][10],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout << a[i][j] << "  ";
        }
        cout << endl;
    }
}

int main()
{
    int n;

    cout << "Enter the size of graph : ";
    cin >> n;

    int length[10][10];

    cout << endl << "Enter the " << n << "*" << n << " matrix : " << endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> length[i][j];
        }
    }

    cout << endl << "Before Matrix : " << endl;
    display(length,n);

    Digkstra(length,n);

    cout << endl << "After Digkstra's sort : " << endl;
    display(length,n);

    return 0;
}
