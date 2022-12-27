#include<iostream>
using namespace std;

void linear_search(int arr[],int n, int num)
{
    int temp=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==num)
        {
            cout<<"Student found at "<<i+1<<" position"<<endl;
            temp=1;
            break;
        }
    }
    if(temp==0)
    {
        cout<<"\nStudent not found "<<endl;
    }
}


int main()
{
    int n;
    cout<<"\nEnter no. of students in SE : ";
    cin>>n;
    int arr[n],key;
    cout<<"\nEnter roll no of students : "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"\nEnter roll no of student to be searched : ";
    cin>>key;
    linear_search(arr,n,key);
    return 0;
}
