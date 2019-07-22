import sys
import re				# regular expressions library

print('Hello!')

pyStack = [] 			# Stack instructions (pop, push, max...)
#pyStackNumb = [] 		# Stack numbers 0, 100, -2

stack_top=-1 			# points to the top of the Stack

retString=str() 		# resulted line (output)

curr_val_to_push=-1		# current value to push
max_element=-1			# current maximum value in the stack

DEBUG=1

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
def is_stack_empty(stack_top_loc):
	if (stack_top_loc <= -1):
		stack_top_loc = -1
		return True
	return False
	
'''  
	Function returns true if it is push operation
	and then sets global variable curr_push
'''
def is_push_input(tempInput,curr_val_to_push):
	POP = False
	PUSH = True
	pop_s = "pop"
	push_s = "push"
	
	if pop_s in tempInput:
		return POP
	elif push_s in tempInput:
		curr_val_to_push = int(re.search(r'\d+', tempInput).group())	#use regular expression lib to find an integer
		#print('re: ', curr_val_to_push) 
		return PUSH

'''
	Function pushes an element ont the stack
'''		
def push(element, stack_top_pointer): 
	stack_top_pointer +=1
	pyStackNumb[stack_top_pointer]=element
	print('local',pyStackNumb)
	return

'''
	Remove top element from the stack
'''
def pop(stack_top_local) :
	bIsStackEmpty = is_stack_empty(stack_top_local)
	
	#if stack is empty, there is no element to remove
	if bIsStackEmpty:
		return
	
	pyStackNumb[stack_top_local] = 0
	stack_top_local -= 1

'''
 Get max value on the stack
'''
def get_max_on_stack(stack_top_local):
	max_element=0	#declare variable
	if ( stack_top_local == 0):
		max_element = pyStackNumb[0];
		return max_element

	max_element = stack[0]
	
	##derive max element in the stack
	for idx in range(stack_top_local+1):
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
	
pyStackNumb = [num_queries] 		# Stack numbers 0, 100, -2
	

pyString=str()	#init empty string

##Get all commands from keyboard
for numQue in range(num_queries):
	tempStr=raw_input()
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
		bIsPush = is_push_input(pyStack[queryIdx],curr_val_to_push)
		if (bIsPush == True) :	#PUSH OPERATION
			print('PUSH!')
			# if stack is empty, set max value
			bIsStackEmpty = is_stack_empty(stack_top) 
			if (bIsStackEmpty == True):
				max_element = curr_val_to_push
			
			push(curr_val_to_push,stack_top)
			print('global',pyStackNumb)
			
			#if current element > max_element then reset max value
			if (curr_val_to_push > max_element):
				max_element = curr_val_to_push
		#POP OPERATION
		else:
			bIsStackEmpty = is_stack_empty(stack_top)
			if ( bIsStackEmpty != True):
				if (pyStackNumb[stack_top] > max_element):
					pop(stack_top)
					
					##reevaluate maximum element on the stack
					bIsStackEmpty = is_stack_empty(stack_top)
					if (bIsStackEmpty != False):
						max_element = get_max_on_stack(stack_top);
			else:
				pop(stack_top) #just pop		
	else:
		'''
		actions if max was entered
		if stack is not empty - show current max value on the stack
		'''
		print('MAXMUM')
		bIsStackEmpty = is_stack_empty(stack_top) 
		if (bIsStackEmpty != True): #if stack is not empty
			#append output string
			if (DEBUG==1):
				print('HERE!')
			retString += str(max_element)
			retString += '\n'

## Print output result!
if DEBUG==1:
	print('Result: ', retString)
else:
	print(retString)
	

