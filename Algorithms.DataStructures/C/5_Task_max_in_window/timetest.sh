#!/sh/bin

#Color definitions
Green='\033[0;32m'
Red='\033[0;31m'

################# TIME TEST #################

#need to form a long array
count=0					#counter
input_data="100000 "		#first var indicating len of an array

while [ $count -lt  100000 ] #100000
do
	input_data+=" 99999"
	let count=count+1
done
input_data+=" 2"

#input="3 2 1 5 1 "

start_time=`date +%s%3N`
start_clock=`date +%T.%3N`
test_res=$(./task5 <<< ${input_data})
end_time=`date +%s%3N`
end_clock=`date +%T.%3N`

runtime=$((end_time-start_time))

echo " Start Task5.c equals ${start_clock}"
echo " End Task5.c equals ${end_clock}"
echo " Runtime Task5.c equals ${runtime} ms"

#printf "\n ${Red} Output: ${test_res} \n"

exit 0