from io import StringIO
import sys
 
class StringBuilder:
    _file_str = None
 
    def __init__(self):
        self._file_str = StringIO()
 
    def append(self, str):
        self._file_str.write(str)
        return self
 
    def to_string(self):
        return str(self)
 
    def __str__(self):
        return self._file_str.getvalue()



n,q = map(int, sys.stdin.readline().split())
nums = [0]
s = 0
for i in list(map(int, sys.stdin.readline().split())):
	s += i
	nums.append(s)

r = StringBuilder()

for i in range(q):
	s,e = map(int, sys.stdin.readline().split())
	r.append(str(nums[e]-nums[s-1])).append("\n")

sys.stdout.write(r.to_string())