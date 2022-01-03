#/bin/bash
clear
if [ ! -d ./src ]
then
    echo "Must have a src Dir.. Creating one"
    mkdir ./src
    echo "#include <stdio.h>

int main ()
{
    return 0;
}" > ./src/main.c
fi
    
if [ ! -d ./lib ]
then
    echo "Must have a lib Dir.. Creating one"
    mkdir ./lib
fi

if [ ! -d ./out ]
then
    echo "Must have a out Dir.. Creating one"
    mkdir ./out
fi


if [ $# = 1 ]
then
    #clear the name from dangerous chars
    if [ -e ./out/$1 ]
    then
        rm ./out/$1
    fi

    gcc ./src/*.c -o ./out/$1 -Wall -O3 -lm -lX11
    if [ $? -ne 0 ]
    then
        echo "Build failed..."
        exit
    fi

    echo "----------------Starting application $1----------------"
    time ./out/./$1
    echo "----------------Finished application $1----------------"
    exit
else
    echo "Must enter a output file name"
    exit
fi
