#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
File: fib.py  
Author: Matthew Pherigo  
Email: hybrid120@gmail.com  
Github: github.com/mwpher  
Description: output fibonacci numbers in 2 ways, depending on how it is called
(see 'usage'). The fibonacci sequence is a list of numbers derived by adding the
latest number to its predecessor. The list is started with [1, 1].

Usage:

- fib.py | print fib numbers until the user stops asking
- fib.py 42 | print 42 fib numbers

"""

import sys

fname = "none"

if len(sys.argv) == 1:
	n = 0
elif len(sys.argv) == 2:
	n = int(sys.argv[1])
elif len(sys.argv) == 3:
	n, fname = int(sys.argv[1]), sys.argv[2]
else:
	print "Too many arguments!"

def printresults():
	"""
	print results to file or stdout
	"""
	global d
	global fname

	finalstate = "Here are {0} fibonacci numbers:\n".format(d['iter'])
	for value in d['result']:
		finalstate += "{0}\n".format(value)
	if fname != "none":
		with open(fname, 'w') as f:
			f.write(finalstate)
	else:
		print finalstate
def printlatest():
	"""
	for use in interactive mode
	"""
	global counter
	print "#" + str(counter), "is", str(d['result'][counter])
def fibiter(n=1):
	"""
	perform a single iteration of the fibonacci sequence
	"""
	global d
	global counter
	i = 0
	while i < n:
		nextone = d['result'][counter] + d['result'][(counter - 1)]
		d['result'].append(nextone)
		d['iter'] += 1
		counter += 1
		i += 1

counter = 1
d = {'result': [1, 1], 'iter': 2}
if n == 0: # interactive mode
	print "#0 is 1\n#1 is 1"
	while True:
		fibiter()
		printlatest()
		answer = raw_input("Continue? (Y/n) ->").lower()
		if len(answer) > 0 and answer[0] == 'n':
			break
		else:
			continue
	print "Done!"
else:
	fibiter(n - 2)
	printresults()
