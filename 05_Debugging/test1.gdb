break 15 if i % 5 == 0
	command 1
	printf "@@@%d %d %d %d\n", start, finish, inc, i
	continue
end

run 1 12 > /dev/null

quit
