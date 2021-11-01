INFILE="infile.txt"
OUTFILE="outfile.txt"
SOURCE="source.txt"


cp $SOURCE $INFILE
rm -rf $OUTFILE
./move $INFILE 2> /dev/null
if [ $? -ne 1 ] || [ ! -f $INFILE ] || [ -f $OUTFILE ]; then
	echo "FAILED ERROR TESTING: wrong number (1) of input arguments"
	exit -1
fi


cp $SOURCE $INFILE
rm -rf $OUTFILE
./move $INFILE $INFILE $INFILE 2> /dev/null
if [ $? -ne 1 ] || [ ! -f $INFILE ] || [ -f $OUTFILE ]; then
	echo "FAILED ERROR TESTING: wrong number (3) of input arguments"
	exit -1
fi


cp $SOURCE $INFILE
rm -rf $OUTFILE
./move $INFILE $INFILE 2> /dev/null
if [ $? -ne 2 ] || [ ! -f $INFILE ] || [ -f $OUTFILE ]; then
	echo "FAILED ERROR TESTING: infile and outfile should be different"
	exit -2
fi


cp $SOURCE $INFILE
rm -rf $OUTFILE
strace -e fault=openat:when=3 ./move $INFILE $OUTFILE 2> /dev/null
if [ $? -ne 3 ] || [ ! -f $INFILE ] || [ -f $OUTFILE ]; then
	echo "FAILED ERROR TESTING: error while opening infile"
	exit -3
fi


cp $SOURCE $INFILE
rm -rf $OUTFILE
strace -e fault=openat:when=4 ./move $INFILE $OUTFILE 2> /dev/null
if [ $? -ne 4 ] || [ ! -f $INFILE ] || [ -f $OUTFILE ]; then
	echo "FAILED ERROR TESTING: error while opening outfile"
	exit -4
fi


cp $SOURCE $INFILE
rm -rf $OUTFILE
strace -e fault=read:when=2 ./move $INFILE $OUTFILE 2> /dev/null
if [ $? -ne 5 ] || [ ! -f $INFILE ] || [ -f $OUTFILE ]; then
	echo "FAILED ERROR TESTING: error while reading the buf[100]"
	exit -5
fi


cp $SOURCE $INFILE
rm -rf $OUTFILE
strace -e fault=write:when=1 ./move $INFILE $OUTFILE 2> /dev/null
if [ $? -ne 6 ] || [ ! -f $INFILE ] || [ -f $OUTFILE ]; then
	echo "FAILED ERROR TESTING: error while writing the buf[100]"
	exit -6
fi


cp $SOURCE $INFILE
rm -rf $OUTFILE
strace -e fault=close:when=3 ./move $INFILE $OUTFILE 2> /dev/null
if [ $? -ne 7 ] || [ ! -f $INFILE ] || [ -f $OUTFILE ]; then
	echo "FAILED ERROR TESTING: error while closing infile"
	exit -7
fi


cp $SOURCE $INFILE
rm -rf $OUTFILE
strace -e fault=close:when=4 ./move $INFILE $OUTFILE 2> /dev/null
if [ $? -ne 8 ] || [ ! -f $INFILE ] || [ -f $OUTFILE ]; then
	echo "FAILED ERROR TESTING: error while closing outfile"
	exit -8
fi


cp $SOURCE $INFILE
rm -rf $OUTFILE
strace -e fault=unlink:when=1 ./move $INFILE $OUTFILE 2> /dev/null
if [ $? -ne 9 ] || [ ! -f $INFILE ] || [ -f $OUTFILE ]; then
	echo "FAILED ERROR TESTING: error while deleting infile"
	exit -9
fi


cp $SOURCE PROTECT_$INFILE
rm -rf $OUTFILE
LD_PRELOAD=`pwd`/protect.so ./move PROTECT_$INFILE $OUTFILE
if [ $? -ne 0 ] || [ ! -f PROTECT_$INFILE ] || [ ! -f $OUTFILE ]; then
	echo "FAILED ERROR TESTING: DELETE PROTECT FILE"
	exit -10
fi


echo "ALL TESTS ARE DONE"
