#!/bin/bash

gold=($(md5sum file.txt))
output=($(echo Md5 file.txt | ./rhasher))
if [[ ${gold[0]} == $output ]] || [[ ${gold[0]} == ${output[2]} ]]; then
	echo "Test Md5 done"
else
	echo "Error. Md5 doesnt work"
	exit -1
fi

output=($(echo 'Md5 "123' | ./rhasher))
if [[ ${gold[0]} == $output ]] || [[ ${gold[0]} == ${output[2]} ]]; then
	echo "Test Md5 done"
else
	echo "Error. Md5 doesnt work"
	exit -1
fi

gold=($(sha1sum file.txt))
output=($(echo Sha1 file.txt | ./rhasher))
if [[ ${gold[0]} == $output ]] || [[ ${gold[0]} == ${output[2]} ]]; then
	echo "Test Sha1 done"
else
	echo "Error. Sha1 doesnt work"
	exit -1
fi

gold=($(sha1sum file.txt))
output=($(echo 'Sha1 "123' | ./rhasher))
if [[ ${gold[0]} == $output ]] || [[ ${gold[0]} == ${output[2]} ]]; then
	echo "Test Sha1 done"
else
	echo "Error. Sha1 doesnt work"
	exit -1
fi

echo "TESTS DONE"

