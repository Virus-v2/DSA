def insertion_sort(arr):
    for i in range(1,len(arr)):
        k=arr[i]
        j=i-1
        while(j>=0 and arr[j]>k):
            arr[j+1]=arr[j]
            j=j-1
        else:
            arr[j+1]=k
    return arr

def shell_sort(arr):
    size=len(arr)
    gap=size//2
    while(gap>0):
        for i in range(gap,size):
            k=arr[i]
            j=i
            while(j>=gap and arr[j-gap]>k):
                arr[j]=arr[j-gap]
                j-=gap
            arr[j] =k
        gap=gap//2
    return arr

def top_five(arr):
    print("Top five : ",arr[:-6:-1],sep="  ")


marks = [] 
n=int(input("Enter no. of students: "))
for i in range(n):
    i=float(input("Enter percentage : "))
    marks.append(i)
print("Before sorting: ",marks)
print("After insertion sort : ",insertion_sort(marks))
print("After shell sort : ",shell_sort(marks))
top_five(marks)