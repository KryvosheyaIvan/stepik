import sys
import re				# regular expressions library


pyStack = [] 			# Stack instructions (pop, push, max...)
#pyStackNumb = [] 		# Stack numbers 0, 100, -2

stack_top=-1 			# points to the top of the Stack

retString=str() 		# resulted line (output)

curr_val_to_push=-1		# current value to push
max_element=-1			# current maximum value in the stack

DEBUG=0

''' 
Function returns true if there is "max" in tempStr
	else - false
'''
def is_max_input(tempStr):
	
	if "max" in tempStr:	#check if there is #max in tempStr
		return True
	else:
		return False

''' 
Function returns true if pyStack is empty
'''
def is_stack_empty():
	global stack_top
	if (stack_top <= -1):
		stack_top = -1
		return True
	return False
	
'''  
	Function returns true if it is push operation
	and then sets global variable curr_push
'''
def is_push_input(tempInput):
	POP = False
	PUSH = True
	pop_s = "pop"
	push_s = "push"
	
	global curr_val_to_push
	
	if pop_s in tempInput:
		return POP
	elif push_s in tempInput:
		curr_val_to_push = int(re.search(r'\d+', tempInput).group())	#use regular expression lib to find an integer
		return PUSH

'''
	Function pushes an element ont the stack
'''		
def push(element): 
	global stack_top
	global pyStackNumb
	
	stack_top +=1
	pyStackNumb[stack_top]=element
	return

'''
	Remove top element from the stack
'''
def pop():
	global stack_top
	global pyStackNumb
	
	bIsStackEmpty = is_stack_empty()
	
	#if stack is empty, there is no element to remove
	if (bIsStackEmpty == True):
		return
	
	pyStackNumb[stack_top] = 0
	stack_top -= 1
	return

'''
 Get max value on the stack
'''
def get_max_on_stack():
	global stack_top
	global pyStackNumb
	
	max_element=0	#declare variable
	if ( stack_top == 0):
		max_element = pyStackNumb[0];
		return max_element

	max_element = pyStackNumb[0]
	
	##derive max element in the stack
	for idx in range(stack_top+1):
		if (pyStackNumb[idx] > max_element):
			max_element = pyStackNumb[idx]
	
	return max_element



### Start of the program ###
#init values once again


# Get number of queries
num_queries = int(input())

'''
if DEBUG:
	print('Queries: ', num_queries)
'''

#fool protection
if num_queries <= 0:
	print('Error 1')
	exit(0)
	
pyStackNumb = [0 for c in range(num_queries)] 		# Stack numbers 0, 100, -2

#print('len ' , len(pyStackNumb))
	

pyString=str()	#init empty string

##Get all commands from keyboard
for numQue in range(num_queries):
	tempStr=input()
	pyString += tempStr
	pyString += '\n'			# add empty line

# DEBUG
#print(pyString)
#print(pyString.splitlines())

## Split inut. Assign command to every next index
pyStack = pyString.splitlines()

#Print prev operation result
'''
if DEBUG:
	lengthStack = len(pyStack)
	for index in range(lengthStack):
		print(pyStack[index])	
'''

## Going through the whole range of instructions
for queryIdx in range(num_queries):
	#print(queryIdx)
	bIsMax = is_max_input(pyStack[queryIdx]) # is there a max instruction?
	
	if bIsMax != True :
		bIsPush = is_push_input(pyStack[queryIdx]) #get curr_val_to_push also!
		if (bIsPush == True) :	#PUSH OPERATION
			#print('PUSH!')
			# if stack is empty, set max value
			bIsStackEmpty = is_stack_empty() 
			if (bIsStackEmpty == True):
				max_element = curr_val_to_push
			
			push(curr_val_to_push)
			
			#if current element > max_element then reset max value
			if (curr_val_to_push > max_element):
				max_element = curr_val_to_push
		#POP OPERATION
		else:
			bIsStackEmpty = is_stack_empty()
			if ( bIsStackEmpty != True):
				if (pyStackNumb[stack_top] >= max_element):
					pop()
					
					##reevaluate maximum element on the stack
					bIsStackEmpty = is_stack_empty()
					if (bIsStackEmpty != True):
						max_element = get_max_on_stack();
			else:
				pop() #just pop		
	else:
		'''
		actions if max was entered
		if stack is not empty - show current max value on the stack
		'''
		bIsStackEmpty = is_stack_empty() 
		if (bIsStackEmpty != True): #if stack is not empty
			#append output string
			retString += str(max_element)
			retString += '\n'

## Print output result!
if DEBUG==1:
	print('Result: ', retString)
else:
	print(retString)
	

