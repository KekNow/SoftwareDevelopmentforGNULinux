Connfigurate:  
getline:  
autoreconf -fisv && ./configure --enable-readline  
make  

readline:  
autoreconf -fisv && ./configure  
make  

Test:  
make test  

Clear:  
make clean  
