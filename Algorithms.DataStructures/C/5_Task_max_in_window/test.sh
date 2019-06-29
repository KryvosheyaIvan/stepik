#!/sh/bin

#Color definitions
Green='\033[0;32m'
Red='\033[0;31m'

################# TEST 1 #################
correct_res="7 7 5 6 6 "
test_res=$(./task5 <<< '8 2 7 3 1 5 2 6 2 4')

if [ "$test_res" = "$correct_res" ]
then
	printf "\n ${Green} Test 1 passed \n"
else
	printf "\n ${Red} Test 1 failed"
	printf "\n ${Green} Correct: ${correct_res}"
	printf "\n ${Red} Output: ${test_res} \n"
fi

################# TEST 2 #################
correct_res="2 1 5 "
test_res=$(./task5 <<< '3 2 1 5 1')

if [ "$test_res" = "$correct_res" ]
then
	printf "\n ${Green} Test 2 passed \n"
else
	printf "\n ${Red} Test 2 failed"
	printf "\n ${Green} Correct: ${correct_res}"
	printf "\n ${Red} Output: ${test_res} \n"
fi

################# TEST 3 #################
correct_res="9 "
test_res=$(./task5 <<< '3 2 3 9 3')

if [ "$test_res" = "$correct_res" ]
then
	printf "\n ${Green} Test 3 passed \n"
else
	printf "\n ${Red} Test 3 failed"
	printf "\n ${Green} Correct: ${correct_res}"
	printf "\n ${Red} Output: ${test_res} \n"
fi

################# TEST 4 #################
correct_res="93 93 93 93 "
test_res=$(./task5 <<< '15 28 7 64 40 68 86 80 93 4 53 32 56 68 18 59 12')

if [ "$test_res" = "$correct_res" ]
then
	printf "\n ${Green} Test 4 passed \n"
else
	printf "\n ${Red} Test 4 failed"
	printf "\n ${Green} Correct: ${correct_res}"
	printf "\n ${Red} Output: ${test_res} \n"
fi








