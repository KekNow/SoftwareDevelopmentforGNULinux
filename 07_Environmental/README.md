Connfigurate:  
getline:  
autoreconf -fisv && ./configure  
make  

readline:  
autoreconf -fisv && ./configure --enable-readline  
make  

Test:  
make test  

Clear:  
make clean  
