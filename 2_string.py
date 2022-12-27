def printmenu (str):
    print("----------------------------MENU---------------------------")
    print(" \t1. Enter a new string: ")
    print(" \t2. Find the longest word in the string: ")
    print(" \t3. To check if the word is palindrome: ")
    print(" \t4. To find the index of first appearence of the sub string: ")
    print(" \t5. find frequency of appearence of a word or char: ")
    print(" \t6. Exit the program: ")
    print("-----------------------------------------------------------")
    print("Your string is: ", str)

def longest(str):
    str1=str.split()
    m=0
    word=0
    for i in range(len(str1)):
        if(m<len(str1[i])):
            m=len(str1[i])
            word=str1[i]
    print("The longest word in given string is : ",word)

def palindrome(str):
    p=str[::-1]
    if(str==p):        
        print("Given string is palindrome")
    else:
        print("Given string is Not a palindrome")


def substring(str):
    sub=input("Enter substring: ")
    f=0
    ind = -1
    str1=[x for x in str.lower()]
    for i in range(len(str1)-len(sub)+1):
        if(str1[i]==sub[0]):
            f=0
            ind=i
            for j in range(len(sub)):
                if(str1[i+j]!=sub[j]):
                    f=1
                    break
            if(f==0):
                break
    if(ind==-1 or f== 1):
        print("Sub string not found")
    elif(f==0):
        print("Sub string found at : ",ind)



def freq(str):
    str1=str.lower()
    a=input("Enter char or word whose frequency is needed: ")
    print(f"Frequency of {a} in given string : ",len(str1.split(a))-1)


printmenu('not given yet')
choice=1
while(choice!=6):
    if(choice==1):
        str=input("Enter your string: ")
    elif(choice==2):
        longest(str)
    elif(choice==3):
        palindrome(str)
    elif(choice==4):
        substring(str)
    elif(choice==5):
        freq(str)
    printmenu(str)
    choice = int(input("Enter your choice(press 6 if u want to exit): "))