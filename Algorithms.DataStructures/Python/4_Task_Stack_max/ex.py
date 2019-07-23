
import sys

pyStack = [] 


data = sys.stdin.readlines()
print("Counted", len(data), "lines.")
print(data)
exit(0)



#pyStack = map(int, line.split()) for line in sys.stdin)

#pyStack = tuple(map(str, line.split()) for line in sys.stdin)

for line in sys.stdin:
	pyStack[i] = line
	if "end" in line:
		print('fuck')
		break

print(pyStack)
