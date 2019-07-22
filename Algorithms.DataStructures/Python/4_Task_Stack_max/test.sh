#!/sh/bin

echo "Test 1"
./task5 <<< $'5\npush 2\npush 1\nmax\npop\nmax'
#echo "correct 2 2"