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
correct_res="3_1<->4_0<->1_1<->3_"
test_res=$(./task6 TEST=1 DEBUG=0<<< $'5\n5 4 3 2 1\n')

if [ "$test_res" = "$correct_res" ]
#if [ ${test_res} == ${orrect_res}]
then
	printf "\n ${Green} Test 1 passed \n"
else
	printf "\n ${Red} Test 1 failed"
	printf "\n ${Green} Correct: ${correct_res}"
	printf "\n ${Red} Output: ${test_res} \n"
fi

exit 0