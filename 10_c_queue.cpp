#include<iostream>
using namespace std;
#define max 5

class circularqueue
{
    int front=-1;
    int rear=-1;
    int arr[max];
public:
    bool isempty()
    {
        if(front==-1 && rear==-1)
            return true;
        else
            return false;
    }
    bool isfull()
    {
        if((rear+1)%max==front)
            return true;
        else
            return false;
    }
    void enqueue(int val)
    {
        if(isfull())
        {
            cout<<"\nQueue is full"<<endl;
            return;
        }
        else if(isempty())
        {
            rear=0;
            front=0;
            arr[rear]=val;
        }
        else
        {
            rear++;
            arr[rear]=val;
        }
    }
    int dequeue()
    {
        int x;
        if(isempty())
        {
            cout<<"\nQueue is empty"<<endl;
            return 0;
        }
        else if(front==rear)
        {
            x=arr[front];
            arr[front]=0;
            rear=-1;
            front=-1;
            return x;
        }
        else
        {
            x=arr[front];
            arr[front]=0;
            front++;
            return x;
        }
    }
    void display()
    {
       if(isempty())
        {
            cout<<"\nQueue is empty"<<endl;
            return ;
        }
        else
        {
            int i=front;
            if(front<=rear)
            {
                while(i<=rear)
                {
                    cout<<arr[i]<<"\t";
                    i++;
                }
            }
            else
            {
                while(i<=max)
                {
                    cout<<arr[i]<<"\t";
                    i++;
                }
            }
        }
    }
};

int main()
{
    circularqueue q;
    int ch,a;
    do{
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
            cout<<"\nEnter no.:";
            cin>>a;
            q.enqueue(a);
            break;
        case 2:
            cout<<"\nDeleted no.: "<<q.dequeue()<<endl;
            break;
        case 3:
            cout<<"\nQueue: ";
            q.display();
            break;

        }
    }while(ch != 4);

    return 0;
}
