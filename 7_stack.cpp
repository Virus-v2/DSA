#include<iostream>
using namespace std;

class stack
{
    int top=-1;
    int a[5];
public:
    void push();
    int pop();
    bool isempty();
    bool isfull();
    void display();
};
bool stack::isempty()
{
    if(top==-1)
        return true;
    else
        return false;
}
bool stack::isfull()
{
    int n=sizeof(a)/sizeof(int);
    if (top==n-1)
        return true;
    else
        return false;
}
void stack::push()
{
    int value;
    if(isfull())
    {
        cout<<"\nStack is full"<<endl;
        return;
    }
    cout<<"\nEnter number: ";
    cin>>value;
    top++;
    a[top]=value;
}
int stack::pop()
{
    if(isempty())
    {
        cout<<"\nStack is empty"<<endl;
        return 0;
    }
    int x;
    x=a[top];
    a[top]=0;
    top--;
    return x;

}
void stack::display()
{
    cout<<"\nStack : ";
    for(int i=0;i<=top;i++)
    {
        cout<<a[i]<<"\t";
    }
}

int main()
{
    int ch;
    stack s;
    do
    {
        cout<<"\n--------Menu--------"<<endl;
        cout<<"1.Add element"<<endl;
        cout<<"2.Delete element"<<endl;
        cout<<"3.Display"<<endl;
        cout<<"4.Exit"<<endl;
        cout<<"--------------------"<<endl;
        cout<<"Enter your choice : ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            s.push();
            break;
        case 2:
            cout<<"Poped element: "<<s.pop()<<endl;
            break;
        case 3:
            s.display();
            break;
        }
    }while(ch!=4);
    return 0;
}
