#!/sh/bin

#Color definitions
Green='\033[0;32m'
Red='\033[0;31m'

FILE=task6


if [ ! -f "$FILE" ]
then
	printf "\n${Red} No object file ${FILE}! \n exiting script...\n"
	exit 1
fi

################# TEST 1 #################
correct_res="3 1 4 0 1 1 3 "
test_res=$(./task6 <<< '5 5 4 3 2 1 ')

if [ "$test_res" = "$correct_res" ]
then
	printf "\n ${Green} Test 1 passed \n"
else
	printf "\n ${Red} Test 1 failed"
	printf "\n ${Green} Correct: ${correct_res}"
	printf "\n ${Red} Output: ${test_res} \n"
fi

exit 0