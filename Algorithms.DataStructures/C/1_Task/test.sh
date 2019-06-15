#!sh/bin

echo "Test 1 "
./task1 <<< '([](){([])})'
printf "\nTrue: Success"
printf "\n\n"

echo "Test 2 "
./task1 <<< '()[]}'
printf "\nTrue: 5"
printf "\n\n"

echo "Test 3 "
./task1 <<< '{{[()]]'
printf "\nTrue: 7"
printf "\n\n"

echo "Test 4 "
./task1 <<< '((('
printf "\nTrue: 1"
printf "\n\n"

echo "Test 5 "
./task1 <<< '[[['
printf "\nTrue: 1"
printf "\n\n"

echo "Test 6 "
./task1 <<< '([](){([])})'
printf "\nTrue: Success"
printf "\n\n"

echo "Test 7 "
./task1 <<< '()[]}'
printf "\nTrue: 5"
printf "\n\n"

echo "Test 8 "
./task1 <<< '{{[()]]'
printf "\nTrue: 7"
printf "\n\n"

echo "Test 9 "
./task1 <<< '{{{[][][]'
printf "\nTrue: 1"
printf "\n\n"

echo "Test 10 "
./task1 <<< '{*{{}'
printf "\nTrue: 1"
printf "\n\n"

echo "Test 11 "
./task1 <<< '[[*'
printf "\nTrue: 1"
printf "\n\n"

echo "Test 12 "
./task1 <<< '{*}'
printf "\nTrue: Success"
printf "\n\n"

echo "Test 13"
./task1 <<< '{{'
printf "\nTrue: 1"
printf "\n\n"

echo "Test 14 "
./task1 <<< '{}'
printf "\nTrue: Success"
printf "\n\n"

echo "Test 15 "
./task1 <<< '"'
printf "\nTrue: Success"
printf "\n\n"

echo "Test 16 "
./task1 <<< '}'
printf "\nTrue: 1"
printf "\n\n"

echo "Test 17 "
./task1 <<< '*{}'
printf "\nTrue: Success"
printf "\n\n"

echo "Test 18 "
./task1 <<< '{{{**[][][]'
printf "\nTrue: 1"
printf "\n\n"

echo "Test 19 "
./task1 <<< '{[}'
printf "\nTrue: 3"
printf "\n\n"

echo "Test 20 "
./task1 <<< 'foo(bar);'
printf "\nTrue: Success"
printf "\n\n"

echo "Test 21 "
./task1 <<< 'foo(bar[i);'
printf "\nTrue: 10"
printf "\n\n"

exit 0