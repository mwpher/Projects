# nextprime.py
import sys

class nextprime:
	primes = [1, 2, 3]
	numofprimes = len(primes)
	def __init__(self, n=0):
		if n == 0:
			while True:
				self.nextprime()
				answer = raw_input("Continue? (Y/n)")
				if len(answer) > 0 and answer[0].lower() == 'n':
					break
		else:
			while self.numofprimes < n:
				self.nextprime()
		print "I found", str(self.numofprimes) + ":", str(self.primes)
	def nextprime(self):
		prime = False
		n = self.primes[len(self.primes) - 1] + 1
		while True:
			factor = self.isprime(n)
			if factor == 0:
				self.primes.append(n)
				break
			else:
				print str(n), "is divisible by", str(factor)
				n += 1
		print str(n), "is prime"
		self.numofprimes += 1
	def isprime(self, n):
		i = 2
		while i < n:
			if (n % i) == 0:
				return i
			else:
				i += 1
				continue
		return 0

if len(sys.argv) == 1:
	p = nextprime()
elif len(sys.argv) == 2:
	p  = nextprime(int(sys.argv[1]))
else:
	print "BUH?!"
