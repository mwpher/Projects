#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
File: collatz.py  
Author: Matthew Pherigo  
Email: hybrid120@gmail.com  
Github: github.com/mwpher  
Description: given a number, see how many collatz iterations it takes to reach
one.  
The collatz algorithm works like this:  

- take number x  
- if num is even, divide by 2  
- if num is odd, multiply by 3 plus 1  
- repeat until reaching 1  

Usage:  
- collatz.py 42 | find how many collatz iterations it takes to find 42
"""


import sys

result = []


def iterate(num):
	"""
	- if num is even, divide by 2
	- if num is odd, multiply by 3 and add 1
	"""
	if num % 2 == 0:
		return (num / 2)
	else:
		return ((num * 3) + 1)
def isvalid(num):
	"""
	make sure initial number isn't invalid
	"""
	if (type(num) is int) and (int > 0):
		return num
	else:
		return 0

n = int(sys.argv[1])

iterations = 0
if isvalid(n) == 0:
	print "Please enter a positive integer!"

while n != 1:
	n = iterate(n)
	result.append(n)
iterations = len(result)
print "iterations: ", iterations, "\n", "result: ", result
