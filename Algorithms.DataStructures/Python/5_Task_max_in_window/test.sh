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

################# TEST 2 #################
let "testNum++"
correct_res="7 7 5 6 6 "
test_res=$(python3  ${pyScript} TEST=1 <<< $'8\n 2 7 3 1 5 2 6 2\n 4')

if [ "$test_res" = "$correct_res" ]
then
	printf "\n ${Green} Test $testNum passed \n"
else
	printf "\n ${Red} Test $testNum failed"
	printf "\n ${Green} Correct: ${correct_res}"
	printf "\n ${Red} Output: ${test_res} \n"
fi

################# TEST 3 #################

let "testNum++"
correct_res="2 1 5 "
test_res=$(python3  ${pyScript} TEST=1 <<<$'3\n 2 1 5\n 1')

if [ "$test_res" = "$correct_res" ]
then
	printf "\n ${Green} Test $testNum passed \n"
else
	printf "\n ${Red} Test $testNum failed"
	printf "\n ${Green} Correct: ${correct_res}"
	printf "\n ${Red} Output: ${test_res} \n"
fi

################# TEST 4 #################
let "testNum++"
correct_res="9 "
test_res=$(python3  ${pyScript} TEST=1 <<< $'3\n  2 3 9\n  3')

if [ "$test_res" = "$correct_res" ]
then
	printf "\n ${Green} Test $testNum passed \n"
else
	printf "\n ${Red} Test $testNum failed"
	printf "\n ${Green} Correct: ${correct_res}"
	printf "\n ${Red} Output: ${test_res} \n"
fi

################# TEST 5 #################
let "testNum++"
correct_res="93 93 93 93 "
test_res=$(python3  ${pyScript} TEST=1 <<< $'15\n  28 7 64 40 68 86 80 93 4 53 32 56 68 18 59\n 12')

if [ "$test_res" = "$correct_res" ]
then
	printf "\n ${Green} Test $testNum passed \n"
else
	printf "\n ${Red} Test $testNum failed"
	printf "\n ${Green} Correct: ${correct_res}"
	printf "\n ${Red} Output: ${test_res} \n"
fi





