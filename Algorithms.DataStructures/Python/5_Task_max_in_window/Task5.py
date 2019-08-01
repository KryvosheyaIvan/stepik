##
## python3 Task5.py TEST=x DEBUG=y
## where
## x = [0..1] test off/on
## y = [0..m] debug off..DEBUG_LEVEL
##

import sys
import re				# regular expressions library

### Default values for testing and debugging
TEST=0

##Debug configuration
DEBUG=0
DEBUG_LEVEL=0															#current debug level

DEBUG_LEVEL_1=1
DEBUG_LEVEL_2=2
DEBUG_LEVEL_MAX=4

# Operation speed
LOW_SPEED=0
HIGH_SPEED=1
SPEED=LOW_SPEED
																		#not implemented for now

##Variables
array_A = []															# incoming array

array_B = []															# auxil array 1
array_C = []															# auxil array 2
array_MAX = []															# array to output
																		# contains max element in every block

arrLen=1																# array length
windLen=1																# window length

'''
	Function to define test and debug levels
'''
def parseArgs(arg):
	global TEST, DEBUG, DEBUG_LEVEL										# global vars used
	if "TEST" in arg:
		TEST = int(re.search(r'\d+', arg).group())						#use regular expression lib to find an integer
		if ( TEST < 0):
			TEST=0
		elif (TEST>1):
			TEST=1
	elif "DEBUG" in arg:
		DEBUG=1
		DEBUG_LEVEL=int(re.search(r'\d+', arg).group())					#use regular expression lib to find an integer
		if (DEBUG_LEVEL < 0):
			DEBUG=0
			DEBUG_LEVEL=0
		elif (DEBUG_LEVEL > DEBUG_LEVEL_MAX):
			DEBUG_LEVEL = DEBUG_LEVEL_MAX
			
	# Turn off debug if testing (debug interfere with automated test)
	if (TEST==1):
		DEBUG=0
		DEBUG_LEVEL=0
	return


def main():
	
	##Parse argument to define TEST and DEBUG level
	argsLen = len(sys.argv)
	if (argsLen > 1):  													# check args existence
		arg1 = sys.argv[1]
		parseArgs(arg1)													
		if (argsLen > 2):												# check if there is one more arg
			arg2 = sys.argv[2]
			parseArgs(arg2)	
	
	## Print args
	if DEBUG:
		print('TEST=', TEST)											#truly will always be zero
		print('DEBUG=', DEBUG)
		print('DEBUG LEVEL=', DEBUG_LEVEL)
		
		
	
	## Get length of the incoming array
	if DEBUG:
		print('Enter length of the array')
	arrLen = int(input())
	if (arrLen<1):
		exit(0)
	
	## Get all int values before new line char '\n'
	if DEBUG:
		print('Enter ',arrLen ,' numbers by spaces')
	
	if (SPEED==LOW_SPEED):
		array_A = list(map(int, input().split()))
	else:
		print('Not implemented')
	
	array_A.append(0)	
	
	if DEBUG:
		if (DEBUG_LEVEL >= DEBUG_LEVEL_MAX):
			print('Array ', array_A,' size: ', len(array_A))
			
	##get 'window' size
	if DEBUG:
		print('Enter size of the window')
	windLen = int(input())
	if (windLen<1):
		exit(0)
	
	##Special case if window len == 1
	if (windLen==1):
		if (SPEED==LOW_SPEED):											#print result
			for idx in range(arrLen):
				print(array_A[idx], end=" ")
		else:
			print('Not implemented')
		exit(0)															#suspend program. 
	
	###Algorithm
	
	#define number of blocks
	blocksNum = arrLen / (windLen - 1)
	blocksNum = int(blocksNum)			# cast to integer
	if (arrLen % (windLen - 1)):		# if blocksNum.23
		blocksNum += 1 					# then blocksNum++
	if DEBUG:
		print('Number of blocks: ', blocksNum)
		print('Size of the window: ', windLen)
		
	#rescale lists
	array_B   = [0 for i in range(arrLen+1)]				#range(blocksNum)
	array_C   = [0 for i in range(arrLen+1)]				#range(blocksNum)
	array_MAX = [0 for i in range(arrLen+1)]				#range(blocksNum)
	
	if DEBUG:
		if (DEBUG_LEVEL >= DEBUG_LEVEL_MAX):
			print('Array_B len ', len(array_B))
			print('Array_C len ', len(array_C))
		
	
	temp_max_B = 0
	temp_max_C = 0
	#set array B and C
	for i in range(blocksNum):
		for k in range(windLen-1):
			temp_max_B = 0
			temp_max_C = 0
			
			#derive temp_max_B
			for j in range(k+1): #include k
				#result = (onFalse,onTrue)[test] #ternar operation
				#temp_max_B = (array_A[i*(windLen-1)+j],temp_max_B)[temp_max_B>array_A[i*(windLen-1)+j]] #ternar operation python style
				if ( temp_max_B > array_A[i*(windLen-1)+j] ):
					temp_max_B = temp_max_B
				else:
					temp_max_B = array_A[i*(windLen-1)+j]

			array_B[i*(windLen-1)+k] = temp_max_B
			
			
			#derive temp_max_C
			for j in range(k,windLen-1):
				#result = (onFalse,onTrue)[test] #ternar operation 
				#temp_max_C = (array_A[i*(windLen-1)+j],temp_max_C)[temp_max_C>array_A[i*(windLen-1)+j]] #ternar operation python style
				#if DEBUG:
				#	if (DEBUG_LEVEL >= DEBUG_LEVEL_MAX):
				#		print('171 : ', i*(windLen-1)+j,' i= ', i, ' k=', k, ' j=', j )
					
				if ( temp_max_C > array_A[i*(windLen-1)+j] ):
					temp_max_C = temp_max_C
				else:
					temp_max_C = array_A[i*(windLen-1)+j]
			array_C[i*(windLen-1)+k] = temp_max_C
			
	## display intermediate results (array B and C)
	if DEBUG:
		if (DEBUG_LEVEL >= DEBUG_LEVEL_2):
			print('Array_B ', array_B)
			print('Array_C ', array_C)
			
			
	## derive max element for every block
	for idx in range(arrLen - windLen + 1):
		array_MAX[idx] = (array_B[idx + windLen - 1],array_C[idx])[array_C[idx] > array_B[idx + windLen - 1]]
		
	if DEBUG:
		if (DEBUG_LEVEL >= DEBUG_LEVEL_1):
			print('Array_MAX ', array_MAX)
	#elif TEST:
	else:
		for idx in range(arrLen - windLen + 1):
			print(array_MAX[idx], end=' ')
	
	exit(0)
				
		
	
	
#Start of the program
main()

