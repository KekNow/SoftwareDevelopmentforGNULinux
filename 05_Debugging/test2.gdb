set $j = 1

break 15 if $j >= 28 & $j++ <= 35
	command 1
	printf "@@@%d %d %d %d\n", start, finish, inc, i
	continue
end

run -100 100 3 > /dev/null

quit
