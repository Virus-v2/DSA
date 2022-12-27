
def takeinput(sport):
    players=int(input(f"Enter no of players playing {sport} : "))
    a=[]
    for i in range(0,players):
        a.append(input("Enter name of player : "))
    # return a
    print(f"{sport} (original): ",a)
    print(f"{sport} (without duplicates) : ",remove_duplicate(a))
    return a

    

def union(l1,l2):
    res=l1.copy()
    for i in l2:
        if(i not in res):
            res.append(i)
    return res

def intersection(l1,l2):
    res=[]
    for i in l1:
        if i in l2:
            res.append(i)
    return res

def diff(l1,l2):
    res=[]
    for i in l1:
        if i not in l2:
            res.append(i)
    return res

def symm_diff(l1,l2):
    res=[]
    d1=diff(l1,l2)
    d2=diff(l2,l1)
    res=union(d1,d2)
    return res

def remove_duplicate(l1):
    res=[]
    for i in l1:
        if i not in res:
            res.append(i)
    return res


c=takeinput('cricket')
b=takeinput('badminton')
fb=takeinput('football')

# a) List of students who play both c and badminton
print("Students who play both cricket and badminton : ",intersection(c,b))

#b) List of students who play either c or badminton but not both
print("students who play either c or badminton but not both: ",diff(union(c,b),intersection(c,b)))

# c) Number of students who play neither c nor badminton
print("students who play neither c nor badminton: ",diff(fb,union(c,b)))

# d) Number of students who play c and football but not badminton.
print("students who play c and football but not badminton.: ",diff(intersection(c,fb),b))
