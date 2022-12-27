#include<iostream>
using namespace std;
#define n 5
class queue
{
    int arr[n];
    int front=-1;
    int rear=-1;
public:
    void enqueue()
    {
        int val;
        if(rear==n-1)
        {
            cout<<"\nQueue overflow "<<endl;
            return;
        }
        cout<<"\nEnter no.: ";
        cin>>val;

            rear++;
            arr[rear]=val;
            if(front==-1)
                front++;
    }
    int dequeue()
    {
        if(front==-1 || front>rear)
        {
            cout<<"\nQueue underflow "<<endl;

        }
        else{
        int temp=arr[front];
        arr[front]=0;
        front++;
        cout<<"\nDeleted element is  : "<<temp<<endl;}
    }
    void display()
    {
        if(front==-1 || front>rear)
        {
            cout<<"\nQueue is empty "<<endl;
            return;
        }
        cout<<"\nQueue : ";
        for(int i=front;i<=rear;i++)
        {
            cout<<arr[i]<<"\t";
        }
    }
};
int main()
{
    int ch;
    queue q;
    do
    {
        cout<<"\n------menu------\n";
        cout<<"1.Add element"<<endl;
        cout<<"2.Delete element"<<endl;
        cout<<"3.Display queue"<<endl;
        cout<<"4.Exit"<<endl;
        cout<<"-----------------";
        cout<<"\nEnter your choice : ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            q.enqueue();
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.display();
            break;
        default:
            cout<<"\n Invalid Input";
            break;

        }
    }while(ch!=4);
        return 0;
}
