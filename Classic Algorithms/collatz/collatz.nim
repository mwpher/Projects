# COLLATZ.NIM
# Matthew Pherigo

from strutils import parseint

proc collatz(i: int): int =
        if (i mod 2 == 0):
                result = int(i / 2)
        else:
                result = (i * 3) + 1
        return

var steps, n: int
steps = 0

stdout.write("An integer greater than 1, please: ")
while n <= 1:
        n = parseint(readLine(stdin))

while n != 1:
        if steps == 0:
                stdout.write(steps, ": ", n, "\n")
        inc(steps)
        n = collatz(n)
        stdout.write(steps, ": ", n, "\n")

