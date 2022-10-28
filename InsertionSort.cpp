#include<iostream>
using namespace std;

void InsertionSort(int arr[],int n)
{
    int key;
    int j;

    for(int i=1;i<n;i++)
    {
        key = arr[i];
        for(j=i-1;j>=0;j--)
        {
            if(arr[j]>key)
            {
                arr[j+1] = arr[j];
                for(int k=0;k<n;k++)
                {
                    cout << arr[k] << " ";
                }

                cout << endl;
                arr[j] = key;
                for(int k=0;k<n;k++)
                {
                    cout << arr[k] << " ";
                }

                cout << endl;
            }
        }
        cout << endl << endl;
    }
}

int main()
{
    int sz;

    cout << "Enter the size of the array : ";
    cin >> sz;

    int arr[sz];

    cout << "Enter " << sz << " integers in any order : " << endl;

    for(int i=0;i<sz;i++)
    {
        cin >> arr[i];
    }

    cout << "Array before sorting : " << endl;

    for(int i=0;i<sz;i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl << endl;

    cout << "METHOD : \n";

    InsertionSort(arr,sz);

    cout << "Array after sorting : " << endl;

    for(int i=0;i<sz;i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;



    return 0;
}
