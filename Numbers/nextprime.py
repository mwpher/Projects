# nextprime.py
import sys

primes = [1, 2, 3]
numofprimes = 3
fname = "none"

if len(sys.argv) == 1:
	n = 0
elif len(sys.argv) == 2:
	n = int(sys.argv[1])
elif len(sys.argv) == 3:
	n = int(sys.argv[1])
	fname = sys.argv[2]
else:
	print "BUH?!"

def nextprime():
	global primes
	global numofprimes
	global fname
	prime = False
	n = primes[len(primes) - 1] + 1
	while True:
		factor = isprime(n)
		if factor == 0:
			primes.append(n)
			break
		else:
			print str(n), "is divisible by", str(factor)
			n += 1
	print str(n), "is prime"
	numofprimes += 1
def isprime(n):
	i = 2
	while i < n:
		if (n % i) == 0:
			return i
		else:
			i += 1
			continue
	return 0
def outputresults():
	global primes
	global numofprimes
	global fname
	finalstate = "I found {0}: {1}".format(numofprimes, primes)
	if fname != "none":
		with open(fname, 'w') as f:
			f.write(finalstate)
	else:
		print finalstate

if n == 0:
	while True:
		nextprime()
		answer = raw_input("Continue? (Y/n)")
		if len(answer) > 0 and answer[0].lower() == 'n':
			outputresults()
			break
else:
	while numofprimes < n:
		nextprime()
	outputresults()
