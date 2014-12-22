# fib.py

import sys

class fib:
	d = dict()
	counter = 1
	def __init__(self, n=0):
		self.d = {'result': [1, 1], 'iterations': 2}
		if n == 0:
			self.printresults()
			while True:
				self.iter()
				self.printlatest()
				answer = raw_input("Continue? (Y/n) ->").lower()
				if len(answer) > 0 and answer[0] == 'n':
					break
				else:
					continue
			print "Done! \n\n"
			self.printresults()
		else:
			self.iter(n - 2)
			self.printresults()
	
	def printresults(self):
		i = 0
		while i < len(self.d['result']):
			print "#" + str(i + 1), "is", str(self.d['result'][i])
			i += 1
	def printlatest(self):
		print "#" + str(self.counter + 1), "is", str(self.d['result'][self.counter])
	def iter(self, n=1):
		i = 0
		while i < n:
			nextone = self.d['result'][self.counter] + self.d['result'][(self.counter - 1)]
			self.d['result'].append(nextone)
			self.d['iterations'] += 1
			self.counter += 1
			i += 1

if len(sys.argv) > 1:
	f = fib(int(sys.argv[1]))
else:
	f = fib()
