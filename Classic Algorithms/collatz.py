# collatz.py
import sys

class collatz:
	result = []
	
	def __init__(self, x):
		self.iterations = 0
		if self.isvalid(x) != 0:
			while x != 1:
				x = self.iterate(x)
				self.result.append(x)
			self.iterations = len(self.result)
	
	def iterate(self, num):
		if num % 2 == 0:
			return (num / 2)
		else:
			return ((num * 3) + 1)
	def isvalid(self, num):
		if (type(num) is int) and (int > 0):
			return num
		else:
			return 0

c = collatz(int(sys.argv[1]))
print "iterations: ", c.iterations, "\n", "result: ", c.result
