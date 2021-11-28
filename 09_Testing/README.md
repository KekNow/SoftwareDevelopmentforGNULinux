Solution of task 9

CONFIGURATE:  
autoreconf -fisv && ./configure --enable-gcov  
make

TEST:  
make check  
make gcov
