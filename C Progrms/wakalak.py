# def minion_game(string):
#     kevinVCnt = 0
#     stuartCCnt = 0
#     reg = "AEIOU"

#     for i in range(len(string)):
#         for j in range(i+1,len(string)+1):
#             print(string[i:j])
    
#     for i in range(len(string)):
#         subStr = string[i]
        
#         if(subStr[0] in reg):
#             kevinVCnt += len(string) - i
#         else:
#             stuartCCnt += len(string) - i
    
#     if(stuartCCnt > kevinVCnt):
#         print("Stuart",stuartCCnt)
#     elif(stuartCCnt < kevinVCnt):
#         print("Kevin",kevinVCnt)
#     else:
#         print("Draw")

# if __name__ == '__main__':
#     s = input()
#     minion_game(s)

#########################################################

# def merge_the_tools(string, k):
#     snum = len(string) / k
    
#     for i in range(0,len(string)-k+1,k):
#         t = string[i:i+k]
#         u = ""
#         print("#",u,t)
#         for ele in t:
#             if(ele not in u):
#                 u += ele
#         print(u)

# if __name__ == '__main__':
#     string, k = input(), int(input())
#     merge_the_tools(string, k)

#########################################################

# dic = {}
# A = [x for x in range(20)] 
# for i in range(len(A)):
#     dic[A[i]] = []
#     dic[A[i]].append(A[i])
# print(dic)

# my_list = [x for x in range(20)]
# separator = "-"  # Define the separator (a comma followed by a space)

# result = str(separator.join(str(my_list)))

# print(result)

#########################################################

# my_list = [x for x in range(20)]

# # Using a generator expression to convert integers to strings
# string_list = [str(x) for x in my_list]

# # Using the join method to concatenate the string elements with a separator
# result_string = ", ".join(string_list)  # You can choose a different separator if needed

# print(result_string)

#########################################################

# A = [1, 2]
# B = [3, 4]

# AB1 = ["("+str(a)+", "+str(b)+")" for b in B for a in A]

# AB2 = ["("+str(a)+", "+str(b)+")" for a in A for b in B]

# print("AB1 (B for A):", AB1)
# print("AB2 (A for B):", AB2)

#########################################################

# from collections import Counter

# myList = [1,1,2,3,4,5,3,2,3,4,2,1,2,3]
# print(Counter(myList))
# print(Counter(myList).items())
# print(list(Counter(myList).items()))
# print(list(Counter(myList).keys()))
# print(list(Counter(myList).values()))

#########################################################

