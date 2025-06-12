class SegmentTree:
    def __init__(self, data, merge_fn, identity):
        self.n = len(data)
        self.size = 1
        while self.size < self.n:
            self.size <<= 1
        self.tree = [identity] * (2 * self.size)
        self.merge = merge_fn
        self.identity = identity

        for i in range(self.n):
            self.tree[self.size + i] = data[i]
        for i in range(self.size - 1, 0, -1):
            self.tree[i] = self.merge(self.tree[i << 1], self.tree[i << 1 | 1])

    def update(self, index, value):
        index += self.size
        self.tree[index] = value
        while index > 1:
            index >>= 1
            self.tree[index] = self.merge(self.tree[index << 1], self.tree[index << 1 | 1])

    def query(self, left, right):
        left += self.size
        right += self.size
        result = self.identity
        while left < right:
            if left & 1:
                result = self.merge(result, self.tree[left])
                left += 1
            if right & 1:
                right -= 1
                result = self.merge(result, self.tree[right])
            left >>= 1
            right >>= 1
        return result


n, q = map(int, input().split())
arr = list(map(int, input().split()))
st = SegmentTree(arr, merge_fn=min, identity=float('inf'))
for i in range(q):
    a, b = map(int, input().split())
    print(st.query(a-1, b))
