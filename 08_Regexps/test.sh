#!/bin/bash

gold=($(echo '1234567890' | sed -E 's/(12[2-4]+).*(6[6-8]+)/==\1==\2==/'))
output=($(./esub '1234567890' '(12[2-4]+).*(6[6-8]+)' '==\1==\2=='))
if [[ $gold == $output ]]; then
	echo "Test 1 passed"
else
	echo "Error. Test 1 not passed"
	exit -1
fi

echo "TESTS DONE"
