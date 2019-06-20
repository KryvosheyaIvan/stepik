#!sh/bin

#echo "Test 1 "
#./task3 <<< '2 4 0 1 0 2 1 3 1 2'    

#echo "Test 2 "
#./task3 <<< '2 8 0 0 0 0 0 0 1 0 1 0 1 1 1 2 1 3' 

echo "Test 3"
./task3 <<< '3 6 0 7 0 0 2 0 3 3 4 0 5 0' 
echo  "correct 0 7 7 -1 -1 -1"

echo "Test 4"
./task3 <<< '2 6 0 2 0 0 2 0 3 0 4 0 5 0' 
echo "correct 0 2 2 3 4 5"

echo "Test 5"
./task3 <<< '4 5 0 7 2 7 4 7 6 7 21 7' 
echo "correct 0 7 14 21 28 "
