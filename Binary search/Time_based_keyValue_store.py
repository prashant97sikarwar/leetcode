class TimeMap:
    from collections import defaultdict
    import math
    def __init__(self):
        self.hash = defaultdict(list)
        

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.hash[key].append((timestamp,value))
    
        
        

    def get(self, key: str, timestamp: int) -> str:
        if key not in self.hash:
            return ""
        dep = self.hash[key]
        if timestamp < dep[0][0]:
            return ""
        l = 0
        r = len(dep) - 1
        while l < r:
            mid = (l + r + 1)//2
            if dep[mid][0] > timestamp:
                r = mid - 1
            else:
                l = mid
        return dep[l][1]
            
            