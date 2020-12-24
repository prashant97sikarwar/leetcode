#Problem Link:- https://leetcode.com/problems/kth-largest-element-in-a-stream/

"""Design a class to find the kth largest element in a stream. Note that it is the kth 
largest element in the sorted order, not the kth distinct element.Implement KthLargest 
class:KthLargest(int k, int[] nums) Initializes the object with the integer k and the 
stream of integers nums.int add(int val) Returns the element representing the kth largest 
element in the stream."""

class KthLargest:
    def __init__(self, k: int, nums: List[int]):
        import heapq
        self.heap = []
        self.k = k
        n = len(nums)
        if n >= k:
            for i in range(k):
                heapq.heappush(self.heap,nums[i])
            for i in range(k,len(nums)):
                if nums[i] < self.heap[0]:
                    continue
                else:
                    heapq.heappop(self.heap)
                    heapq.heappush(self.heap,nums[i])
        else:
            for i in range(len(nums)):
                heapq.heappush(self.heap,nums[i])

    def add(self, val: int) -> int:
        if len(self.heap) < self.k:
            heapq.heappush(self.heap,val)
        else:
            if val >= self.heap[0]:
                heapq.heappop(self.heap)
                heapq.heappush(self.heap,val)
                return self.heap[0]
        return self.heap[0]
        


# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)