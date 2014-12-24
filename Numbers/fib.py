# fib.py

import sys

if len(sys.argv) > 1:
	n = int(sys.argv[1])
else:
	n = 0

def printresults():
	global d
	i = 0
	while i < len(d['result']):
		print "#" + str(i + 1), "is", str(d['result'][i])
		i += 1
def printlatest():
	global counter
	print "#" + str(counter + 1), "is", str(d['result'][counter])
def fibiter(n=1):
	global d
	global counter
	i = 0
	while i < n:
		nextone = d['result'][counter] + d['result'][(counter - 1)]
		d['result'].append(nextone)
		d['fibiterations'] += 1
		counter += 1
		i += 1

counter = 1
d = {'result': [1, 1], 'fibiterations': 2}
if n == 0:
	print "#1 is 1\n#1 is 1"
	while True:
		fibiter()
		printlatest()
		answer = raw_input("Continue? (Y/n) ->").lower()
		if len(answer) > 0 and answer[0] == 'n':
			break
		else:
			continue
	print "Done! \n\n"
	printresults()
else:
	fibiter(n - 2)
	printresults()

