def printmenu():
    print("\n------Menu------")
    print("1.Seletion sort")
    print("2.Bubble sort")
    print("3.Exit")

def takeinput():
    n=int(input("Enter number of students whose marks are to be displayed :"))
    print("Enter percentage : ")
    a=[]
    for i in range(n):
        el=int(input())
        a.append(el)
    return a

def selection_sort(marks):
    a=marks
    for i in range(len(a)):
        min=i
        for j in range(i+1,len(a)):
            if(a[j]<a[min]):
                min=j
        a[i],a[min]=a[min],a[i]
    print("\nSorted list (Selection sort): ",a)

def bubble_sort(marks):
    a=marks
    for i in range(len(a)):
        for j in range(len(a)-1):
            if(a[j+1]<a[j]):
                a[j],a[j+1]=a[j+1],a[j]
    print("\nSorted list (Bubble sort): ",a)


def top_five(a):
    print("Top five:")
    print(a[:-6:-1],end=" ")
            
#main
marks=takeinput()
print("\nOriginal list: ",end=" ")
for i in range(len(marks)):
    print(marks[i],end='\t')
printmenu()
ch=int(input("Enter your choice: "))
while(ch!=3):
    if(ch==1):
        selection_sort(marks)
        x=input("Do u want to print top five percentage (y/n): ")
        if(x=='y'):
            top_five(marks)
        
    elif(ch==2):
        bubble_sort(marks)
        x=input("Do u want to print top five percentage (y/n): ")
        if(x=='y'):
            top_five(marks)
    else:
        print("invalid output")
    printmenu()
    ch=int(input("Enter your choice: "))