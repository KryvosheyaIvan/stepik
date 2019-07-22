'''
def chSka(m):
	m[0] = 'cunt'
	return

x = 'ska'
chSka(x)

print(x)
'''

list_ska = [3]
list_ska[0]= '-1'

def foo():
	global list_ska
	list_ska[0]=-2
	
foo()
print(list_ska)
