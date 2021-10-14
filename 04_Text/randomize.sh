#!/bin/bash
stringx=""
stringy=""
symbols=""

i=0
sum=0
while IFS= read -r line
do
	j=0
	while [ $j -le ${#line} ]
	do
		if [ ${line:j:1} != " " ]
		then
			stringx+=$j" "
			stringy+=$i" "
			symbols+=${line:j:1}" "
			sum=$((sum+1))
		fi
		j=$((j+1))
	done
	i=$((i+1))
done

clear
for j in $(seq $sum | shuf)
do
	let "x=$(echo $stringx | cut -d' ' -f$j)"
	let "y=$(echo $stringy | cut -d' ' -f$j)"
	let "rand=$RANDOM % 8 + 90"
	
	tput cup $y $x 
	echo -e "\e[${rand}m$(echo $symbols | cut -d' ' -f$j)\e[0m"
	
	if [ $# -gt 0 ]
  		then sleep $1
	fi
done

tput cup $i 0
echo
