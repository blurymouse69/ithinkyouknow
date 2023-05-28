#include<stdio.h>
#include<dirent.h>

void main(int argc,char* argv[])
{
    DIR *p;
    struct dirent *d;
    p=opendir(argv[1]);
    if(p==NULL)
    {
        perror("cannot find directory");
    }
    while(d=readdir(p))
    {
        printf("%s\n",d->d_name);
    }
}
