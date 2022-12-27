#include<iostream>
using namespace std;


void sub(int a[3][3],int b[3][3])
{
    int n=3;
    cout<<"\nAddition : "<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<a[i][j]-b[i][j]<<"\t";
        }
        cout<<endl;
    }
}

void mul(int a[3][3],int b[3][3])
{
    int n=3,c[3][3];
    cout<<"\nMultiplication : "<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            c[i][j]=0;
            for(int k=0;k<n;k++)
                c[i][j]+=a[i][k]*b[k][j];

        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<c[i][j]<<"\t";
        }
        cout<<endl;
    }
}

int main()
{
    int ch;
    int n=3;
    int m1[3][3],m2[3][3];
    cout<<"\nEnter element of matrix 1: "<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>m1[i][j];
        }
    }
    cout<<"\nEnter element of matrix 2: "<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>m2[i][j];
        }
    }

    cout<<"\nMatrix 1 : "<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<m1[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"\nMatrix 2 : "<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<m2[i][j]<<"\t";
        }
        cout<<endl;
    }

    do
    {
        cout<<"\n-------Menu-------"<<endl;
        cout<<"1.Subtraction"<<endl;
        cout<<"2.Multiplication"<<endl;
        cout<<"3.Exit"<<endl;
        cout<<"------------------"<<endl;
        cout<<"\nEnter your choice: ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            sub(m1,m2);
            break;
        case 2:
            mul(m1,m2);
            break;

        }
    }while(ch!=3);
    return 0;

}
