import os
path = os.getcwd()
print("You is now working on " + path)
while(1):
    move = input("Do you want to continue?(yes/no): ")
    if move == 'yes':
        oldlist = os.listdir(path)
        oldlist.remove('littletool.py')
        newlist = []
        for i in oldlist:
            newlist.append(i[0:-4])
        print(newlist)
        confirm = input("Desired output?(yes/no): ")
        if confirm == 'yes':
            for i in range(len(oldlist)):
                os.rename(oldlist[i], newlist[i])
            print('Work done...')
            break;
        elif confirm == 'no':
            print('Alright...')
            break;
        else:
            print('Fuckyou')
    elif move == 'no':
        print('Exit program...')
        break
    else:
        print('Unrecognized token...')
