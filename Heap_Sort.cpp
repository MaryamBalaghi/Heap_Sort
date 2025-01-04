#include <iostream>
#include <algorithm>
using namespace std;
void Max_Heapify(int arr[],int n,int i)
{
    int largest=i;
    int left_child=2*i+1;
    int right_child=2*i+2;
    if(left_child<n && arr[left_child]>arr[i])
        largest=left_child;
    if(right_child<n && arr[right_child]>arr[largest])
        largest=right_child;
    if(largest!=i)
    {
        swap(arr[largest],arr[i]);
        Max_Heapify(arr,n,largest);
    }
}
void HeapSort(int arr[],int n)
{
    for(int i= n/2-1;i>=0;i--)     //build heap
    {
        Max_Heapify(arr,n,i);
    }
    for(int i=n-1;i>0;i--)
    {
        swap(arr[0],arr[i]);
        Max_Heapify(arr,i,0);
    }
}
void print_array(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}
int main()
{
    int n;
    cout<<"Please enter the size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter array for sort: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    HeapSort(arr,n);
    cout << "Sorted array is: \n";
    print_array(arr,n);
}