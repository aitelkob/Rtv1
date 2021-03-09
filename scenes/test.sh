
echo '---run-start----' > log
i=0
while true
 	do echo "try num $i:" >> log
	cat test5.t | sed "s/@1/$(( $RANDOM % 226 ))/;s/@2/$(( $RANDOM % 226 ))/" > test5
	./RTv1 test5 2>&1 >>log & true
	echo $i
	sleep 3
	i=$((i + 1))
	killall RTv1
	[ $i -eq  500 ] && break
done

	
