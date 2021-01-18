#Problem Link:- https://leetcode.com/problems/design-hashmap/

"""Design a HashMap without using any built-in hash table libraries.To be specific, your 
design should include these functions:

put(key, value) : Insert a (key, value) pair into the HashMap. If the value already exists in the HashMap, update the value.
get(key): Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
remove(key) : Remove the mapping for the value key if this map contains the mapping for the key."""

class MyHashMap:

    def __init__(self):
        self.arr = [None for i in range(1000001)]
        

    def put(self, key: int, value: int) -> None:
        self.arr[key] = value
        

    def get(self, key: int) -> int:
        return self.arr[key] if self.arr[key] != None else -1
        
        

    def remove(self, key: int) -> None:
        self.arr[key] = None
        


# Your MyHashMap object will be instantiated and called as such:
# obj = MyHashMap()
# obj.put(key,value)
# param_2 = obj.get(key)
# obj.remove(key)

