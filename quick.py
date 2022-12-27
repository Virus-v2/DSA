def partition(array, low, high):
    pivot = array[high]
    i = low - 1
    for j in range(low, high):
        if array[j] <= pivot:
            i = i + 1
            (array[i], array[j]) = (array[j], array[i])
    (array[i + 1], array[high]) = (array[high], array[i + 1])
    return i + 1
 
def quickSort(array, low, high):
    if low < high: 
        pi = partition(array, low, high)
        quickSort(array, low, pi - 1)
        quickSort(array, pi + 1, high)
student = int(input("Enter no of Students:"))
marks = []
print("Enter marks of ",student, "students:")
for i in range(student):
    marks.append(float(input()))
quickSort(marks, 0, len(marks)-1)
print("Top 5 performers are:")
print(marks[:-6:-1 ])
