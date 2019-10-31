#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
        int fd1, fd2;
        char Ch;
        if(argc < 3){
                perror("Bad Arguments");
                exit(0);
        }
        fd1 = open(argv[1], O_RDONLY);
        if(fd1 == -1){
                perror("Failed To open file 1");
                exit(1);
        }
        fd2 = open(argv[2], O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
        if(fd2 == -1){
                perror("Failed To open file 2");
                exit(2);
        }
        while(read(fd1, &Ch, 1)){
                write(fd2, &Ch, 1);
        }
        return 0;
}
