#!/sh/bin

## Wrong answer #55
##



#Color definitions
Green='\033[0;32m'
Red='\033[0;31m'
testNum=0			# test automatic number
objFile='task4_v2'


################# TEST 1 #################
let "testNum++"							
correct_res="2;2;"
test_res=$(./${objFile} TEST=1 <<< $'5\n push 2\npush 1\nmax\npop\nmax ')

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
correct_res=""
test_res=$(./${objFile} TEST=1 <<< $'3\n push 1\npush 7\npop ')

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
correct_res="7;7;"
test_res=$(./${objFile} TEST=1 <<< $'6\npush 7\npush 1\npush 7\nmax \npop \nmax')

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
correct_res="2;1;"
test_res=$(./${objFile} TEST=1 <<< $'5\npush 1\npush 2\nmax\npop \nmax')

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
correct_res="9;9;9;9;"
test_res=$(./${objFile} TEST=1 <<< $'10\npush 2\npush 3\npush 9\npush 7 \npush 2 \nmax \nmax \nmax \npop \nmax')

if [ "$test_res" = "$correct_res" ]
then
	printf "\n ${Green} Test $testNum passed \n"
else
	printf "\n ${Red} Test $testNum failed"
	printf "\n ${Green} Correct: ${correct_res}"
	printf "\n ${Red} Output: ${test_res} \n"
fi
