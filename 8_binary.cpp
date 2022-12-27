#include<iostream>
using namespace std;

void binary_search(int arr[],int n, int num)
{
    int temp=0;
    int low=0,high=n;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]==num)
        {
            cout<<"Student found at "<<mid+1<<" position"<<endl;
            temp=1;
            break;
        }
        else
        {if(arr[mid]<num)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;

        }
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
    binary_search(arr,n,key);
    return 0;
}
