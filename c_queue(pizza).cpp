#include<iostream>
using namespace std;

const int MAX = 5;

class order
{
    int order_id;
    char orderer_name[10];

    public:
    void acceptorder()
    {
        cout<<"enter order id: "<<endl;
        cin>>order_id;
        cout<<"enter order name: "<<endl;
        cin>>orderer_name;
    }

    void displayorder()
    {
        cout<<order_id<<"\t\t"<<orderer_name<<endl;

    }
    friend class queue;

};

class queue
{
    order data[MAX];
    int front,rear;
    
    public:
    queue() //constructor
    {
        front=-1;
        rear=-1;
    }
    void enqueue();
    void dequeue();
    int isfull();
    int isempty();
    void display();
};

int queue::isfull() //func def outsde class
{
    if ((front==00 && rear==MAX-1)||front==rear+1)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

int queue::isempty() //func def outsde class
{
    if (front==-1 && rear ==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void queue::enqueue() //func def outsde class
{
    if (isfull())
    {
        cout<<"can't place order, Queue is full"<<endl;
    }
    else
    {
        order temp; //obj of 1st class obj temp class order
        temp.acceptorder(); // calling func for accepting order

        if (rear == MAX-1 && front!= 0)
        {
            rear=-1;
        }
    

    data[++rear]= temp;
    cout<<"order placed successfully"<<endl;
    if (front == -1)
    front=0; //when order wwant to del, front should be 0
    }

}

void queue::dequeue() //func def outsde class
{
    if (isempty())
    {
        cout<<"no order to serve"<<endl;
    }
    else
    {
        front++;
        cout<<"order srved successfully"<<endl;
        if (front==MAX)
        front=0;
        if (front-1==rear)
        front=rear=-1;


    }
}

void queue::display() //func def outsde class
{
    if (isempty())
        {
            cout<<"no order to display"<<endl;
        }
        else
        {
            int i= front;

            cout<< "order in queue"<<endl;
            cout<<"order id \t\t  order name"<<endl;

            if(front<=rear)
            {
                while(i<=rear)
                {
                    data[i].displayorder();
                    i++;
                    
                }
            }
            else
            {
                while(i<=MAX)
                {
                    data[i].displayorder();
                    i++;

                }
            }
        }
}


int main()
{
    int ch;
    queue q;
    cout<<" -----------------------------pizza parlor-------------------------------------"<<endl;
    cout<<"\t\t 1. pizza order"<<endl;
    cout<<"\t\t 2. serve order"<<endl;
    cout<<"\t\t 3. display order"<<endl;
    cout<<"\t\t 4. exit"<<endl;

    do
    {
        cout<<"enter your choice"<<endl;
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
        }
    }while(ch!=4);
}