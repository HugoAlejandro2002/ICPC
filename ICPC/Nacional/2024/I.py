# import random

# with open('I.txt', 'w') as f:
#     nums = 100000
#     f.write(str(nums)+'\n')
#     for i in range(nums):
#         f.write(str(random.randint(1,1000000))+' ')
#     f.write('\n')
#     queries = 1
#     f.write(str(queries)+'\n')
#     for i in range(queries):
#         # f.write(str(random.randint(1,1000000))+'\n')
#         f.write(str(510510)+'\n')

nums = '595 715 935 1105 1001 1309 1547 2431 210 330 390 510 462 546 714 858 1122 1326 1547 2730 3570 4290 5610 1155 1925 2145 3213 4917 6435 2310 3570 3906 12870 286 364 715 1365 30030 57057 286'
nums = list(map(int, nums.split()))
s=set()
for n in nums:
    if(n%(17**2)==0):
        print(n)

print(s)