def print_menu():
    print("-----------------------MENU--------------------")
    print("\t1. Display the addition of the matrix")
    print("\t2. Display the substraction of the matrix")
    print("\t3. Display the multiplication of matrices")
    print("\t4. Display the transpose of matrices")
    print("\t5. End")
    print("-----------------------------------------------")

n=int(input("Enter order of matrix 1 and matrix 2: "))
mat1=[]
mat2=[]
mat3=[[0 for i in range(n)]for i in range(n)]

print("Enter",n*n," elements for matrix 1: ")
for i in range(0,n):
    a=[]
    for j in range(n):
        a.append(int(input()))
    mat1.append(a)

print("Enter",n*n," elements for matrix 2: ")
for i in range(0,n):
    a=[]
    for j in range(n):
        a.append(int(input()))
    mat2.append(a)

def display(name,a):
    print(f"{name} : ")
    for i in range(len(a)):
        print(a[i])


display('Matrix1',mat1)
display('Matrix2',mat2)

def add(a,b,c):
    for i in range(n):
        for j in range(n):
            c[i][j]=a[i][j]+b[i][j]
    display("Addition",c)

def sub(a,b,c):
    for i in range(n):
        for j in range(n):
            c[i][j]=a[i][j]-b[i][j]
    display("Subtraction",c)

def mul(a,b,c):
    for i in range(n):
        for j in range(n):
            
            for k in range(n):
                c[i][j]+=a[i][j]*b[i][j]
    display("Multiplication",c)

def transpose(a,b):
    for i in range(n):
        for j in range(n):
            b[i][j]=a[j][i]
    display("Transpose",b)

print_menu()
ch = int(input("Enter your choice: "))
while(ch!=5):
    if(ch==1):
        add(mat1,mat2,mat3)
    elif(ch==2):
        sub(mat1,mat2,mat3)
    elif(ch==3):
        mul(mat1,mat2,mat3)
    elif(ch==4):
        choose=int(input("Transpose of which matrix (1 or 2): "))
        if(choose==1):
            transpose(mat1,mat3)
        elif(choose==2):
            transpose(mat2,mat3)
        else:print("Invalid input")
    else:print("Invalid input")
    print_menu()
    ch = int(input("Enter your choice: "))