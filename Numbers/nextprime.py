#!/usr/bin/env python
# -*- coding: utf-8 -*-

# nextprime.py
"""
File: nextprime.py  
Author: Matthew Pherigo  
Email: hybrid120@gmail.com  
Github: github.com/mwpher  
Description: Finds prime numbers  

Usage:  

- nextprime.py | interactive
- nextprime.py 42 | output 42 primes
- nextprime.py 42 primes.txt | output 42 primes to primes.txt

"""

import sys

primes = [1, 2, 3]
numofprimes = 3
fname = "none"

if len(sys.argv) == 1:
	n = 0
elif len(sys.argv) == 2:
	n = int(sys.argv[1])
elif len(sys.argv) == 3:
	n, fname = int(sys.argv[1]), sys.argv[2]
else:
	print "BUH?!"

def nextprime():
	"""
	find the next prime and add it to primes[]
	"""
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
	"""
	check if (n) is prime. if not, return first factor found for use by
	program.
	"""
	i = 2
	while i < n:
		if (n % i) == 0:
			return i
		else:
			i += 1
			continue
	return 0
def outputresults():
	"""
	print results to file or stdout
	"""
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
	"""
	if n is 0, enter interactive mode
	"""
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
