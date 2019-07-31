#!/sh/bin

## err 
##

#Python script to execute
pyScript='Task5.py'

#Color definitions
Green='\033[0;32m'
Red='\033[0;31m'
Blue='\033[0;34m'
testNum=0			# test automatic number


printf "\n ${Blue} Test ${pyScript}. \n"


################# TEST 1 #################
let "testNum++"							
correct_res="1 2 3 4 5 "
test_res=$(python3  ${pyScript} TEST=1 DEBUG=0 <<< $'5\n 1 2 3 4 5 \n 1 ')

if [ "$test_res" = "$correct_res" ]
then
	printf "\n ${Green} Test $testNum passed \n"
else
	printf "\n ${Red} Test $testNum failed"
	printf "\n ${Green} Correct: ${correct_res}"
	printf "\n ${Red} Output: ${test_res} \n"
fi
