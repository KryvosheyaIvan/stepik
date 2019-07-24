#!/sh/bin

## Time limit 47 
##

#Color definitions
Green='\033[0;32m'
Red='\033[0;31m'
testNum=0			# test automatic number


echo "Please enable test in Task4_p3.py !"

#test_res=$(python3 Task4_p3.py <<< $'1 \n push 2 \n max')
#printf "\n ${Red} Output: ${test_res} \n"
#exit 0

################# TEST 1 #################
let "testNum++"							
correct_res="2;2;"
test_res=$(python3 Task4_p3.py <<< $'5\n push 2\npush 1\nmax\npop\nmax ')

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
test_res=$(python3 Task4_p3.py <<< $'3\n push 1\npush 7\npop ')

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
test_res=$(python3 Task4_p3.py <<< $'6\n push 7\npush 1\npush 7\n max \n pop \n max')

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
test_res=$(python3 Task4_p3.py <<< $'5\n push 1\npush 2\n max\n pop \n max')

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
test_res=$(python3 Task4_p3.py <<< $'10\n push 2\npush 3\n push 9\n push 7 \n push 2 \n max \n max \n max \n pop \n max')

if [ "$test_res" = "$correct_res" ]
then
	printf "\n ${Green} Test $testNum passed \n"
else
	printf "\n ${Red} Test $testNum failed"
	printf "\n ${Green} Correct: ${correct_res}"
	printf "\n ${Red} Output: ${test_res} \n"
fi

