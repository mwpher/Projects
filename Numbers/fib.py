# fib.py
import sys

class fib:
	result = [1, 1]
	iterations = len(result) - 1
	
	def __init__(self, n=0):
		print "#0 is", str(self.result[0])
		self.printlast()
		if n == 0:
			while True:
				self.iter()
				self.printlast()
				answer = raw_input('Continue? (Y/n) ->')
				if (len(answer) > 0) and answer[0] == ('N' or 'n'):
					break
				else:
					continue
		else:
			while self.iterations < n:
				self.iter()
				self.printlast()

	def iter(self):
		self.result.append(self.result[self.iterations - 1] + self.result[self.iterations])
		self.iterations += 1
	def printlast(self):
		print "#" + str(self.iterations), "is", str(self.result[self.iterations])

if len(sys.argv) > 1:
	f = fib(int(sys.argv[1]))
else:
	f = fib()

print "iterations: ", f.iterations, "\n", "result: ", f.result
