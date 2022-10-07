#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>

int main()
{
int fd0[2];
int a;
a = pipe(fd0);


int fd1[2];
int a1;
a1 = pipe(fd1);


int fd2[2];
int a2;
a1 = pipe(fd2);

int fd = open("input.txt",O_RDONLY,S_IRUSR);

int fdd = open("output.txt",O_WRONLY);
int pid;
pid = fork();


if(pid == 0 )
{
char buf[100];
int size;
close(fd1[1]);

read(fd1[0],&size,sizeof(int));
close(fd1[0]);


close(fd0[1]);
read(fd0[0],&buf,sizeof(char)*size);
close(fd0[0]);


for(int i=0;i<size;i++)
{
if(buf[i]== '~' ||buf[i]== '!' ||buf[i]== '@' ||buf[i]== '#' ||buf[i]== '$' ||buf[i]== '%' || buf[i]== '^' || buf[i]== '&' )
{
buf[i] = ' ';
}
}


write(2, buf, size);

close (fd2[0]);
write(fd2[1],&buf,sizeof(buf));
close(fd2[1]);

}
else if (pid>0)
{

char buf[100];

int size = read(fd, buf,sizeof(buf));
write(2, buf, size);


close (fd1[0]);
write(fd1[1],&size,sizeof(size));
close(fd1[1]);

close (fd0[0]);
write(fd0[1],&buf,sizeof(buf));
close(fd0[1]);


close(fd2[1]);
read(fd2[0],&buf,sizeof(char)*size);
close(fd2[0]);


write(fdd, buf, sizeof(char)*size);



}


return 0;
}


