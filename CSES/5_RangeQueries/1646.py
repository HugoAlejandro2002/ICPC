class SegmentTree:
    def __init__(self, data):
        self.n = len(data)
        self.size = 1
        while self.size < self.n:
            self.size <<= 1
            self.tree = [0] * (2 * self.size)
 
        # Build the tree
        for i in range(self.n):
            self.tree[self.size + i] = data[i]
        for i in range(self.size - 1, 0, -1):
            self.tree[i] = self.tree[i << 1] + self.tree[i << 1 | 1]
 
    def update(self, index, value):
        # Point update: set data[index] = value
        index += self.size
        self.tree[index] = value
        while index > 1:
            index >>= 1
            self.tree[index] = self.tree[index << 1] + self.tree[index << 1 | 1]
 
    def query(self, left, right):
        # Range query on [left, right)
        left += self.size
        right += self.size
        result = 0
        while left < right:
            if left & 1:
                result += self.tree[left]
                left += 1
            if right & 1:
                right -= 1
                result += self.tree[right]
            left >>= 1
            right >>= 1
        return result
    
n,q=map(int,input().split())
arr = list(map(int,input().split()))
st = SegmentTree(arr)
for i in range(q):
    a,b=map(int,input().split())
    print(st.query(a-1,b))