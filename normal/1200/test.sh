make > /dev/null
dos2unix src/ans[0-9].txt &> /dev/null
for i in `seq 20`
do
        echo -n "="
done
echo
declare -a arr=(1 2 3 4)
for num in ${arr[@]}
do
	./a < src/input$num.txt > src/output$num.txt
	(diff src/ans$num.txt src/output$num.txt) && echo test$num passed
	for i in `seq 20` 
	do 
		echo -n "="
	done
	echo
done
make clean > /dev/null
echo "All tests are completed!!"
