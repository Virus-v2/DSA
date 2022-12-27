def bubblesort(data):
 N=len(data)
 for a in range(1,N):
    for b in range(0,N-1):
        if data[b]>data[b+1]:
            data[b],data[b+1]= data[b+1],data[b]
 return data

N=int(input("Enter number of students:"))
data=[float(x) for x in input("Enter percentage of students separated by space: ").split()]
min=0;max=99.99
NB=int(input("Enter number of buckets: "))

bucket=[ [] for i in range(NB)]

for number in data:
 bucketnumber=(int(number)-min)//NB
 bucket[bucketnumber].append(number)
print(bucket) 

sorteddata=[]
for i in range(NB):
 bucket[i]=bubblesort(bucket[i])
 sorteddata = sorteddata + bucket[i]
 
print("\nThe sorted data using Bucket sort is:\n",sorteddata)
print("\nTop five scores are : ",sorteddata[:-6:-1])