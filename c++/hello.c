#include <stdio.h>


void interpreter(char str[]) { 
        puts(str);
        }


int main(int argc, char *argv[]){
    interpreter(argv[1]);
    return 0;
}