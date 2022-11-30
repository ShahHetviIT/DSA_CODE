#include<iostream>
using namespace std;

int Partition(int arr[],int s,int e)
{
    int pivot = arr[e];
    int pIndex = s;

    for(int i=s;i<e;i++)
    {
        if(arr[i] < pivot)
        {
            int temp = arr[i];
            arr[i] = arr[pIndex];
            arr[pIndex] = temp;
            pIndex++;
        }

    }

    int temp = arr[e];
    arr[e] = arr[pIndex];
    arr[pIndex] = temp;

    return pIndex;
}

void QuickSort(int arr[],int s,int e)
{
    if(s<e)
    {
        int p = Partition(arr,s,e);
        QuickSort(arr,s,p-1);  // recursive for left partition
        QuickSort(arr,(p+1),e);  // recursive for right partition
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

    cout << endl;

    cout << "Before sorting : " << endl;

    for(int i=0;i<sz;i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    QuickSort(arr,0,(sz-1));

    cout << "After sorting : " << endl;

    for(int i=0;i<sz;i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
