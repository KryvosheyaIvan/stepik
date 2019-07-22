#!/sh/bin

#echo "Test 1"
#python3 Task4_p3.py <<< $'5\npush 2\npush 1\nmax\npop\nmax'
#echo "correct 2 2"

#Color definitions
Green='\033[0;32m'
Red='\033[0;31m'

################# TEST 1 #################

correct_res="correct: 2\n2\n"
python3 Task4_p3.py <<< $'5\n push 2\npush 1\nmax\npop\nmax '

printf " ${correct_res}"

: '
if [ "$test_res" = "$correct_res" ]
then
	printf "\n ${Green} Test 1 passed \n"
else
	printf "\n ${Red} Test 1 failed"
	printf "\n ${Green} Correct: ${correct_res}"
	printf "\n ${Red} Output: ${test_res} \n"
fi
'

