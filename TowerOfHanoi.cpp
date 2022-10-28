#include<iostream>
using namespace std;

void TOH(int n,char Sour,char Help,char Des)
{
    if(n==0)
    {
        return;
    }
    else
    {
        TOH(n-1,Sour,Des,Help);
        cout << "Move Disk " << n << " from " << Sour << " to " << Des << endl;
        TOH(n-1,Help,Sour,Des);
    }
}

int main()
{
    int n;

    cout << "Enter no. of disk : ";
    cin >> n;

    TOH(n,'A','B','C');

    return 0;
}
