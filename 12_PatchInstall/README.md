# Solution of task 12  

## Configure:  
autoreconf -fisv && ./configure --prefix=/usr && make  

## Install:  
make install DESTDIR=<path_to_example_directory>  


## Usage:  
cd /{path_to_example_directory}/usr/bin  
### In russian:  
LANG=ru_RU.UTF-8 ./binsearch  
### In english:  
LANG=en_EN.UTF-8 ./binsearch  

## Hints:  
./binsearch --version  
./binsearch --help  
