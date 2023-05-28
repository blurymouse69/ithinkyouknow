#include<stdio.h>
int main(int argc,char* argv[])
{
    FILE *f1,*f2;
    char ch;
    f1=fopen(argv[1],"r");
    f2=fopen(argv[2],"w");
    while(1)
    {
        if(ch==EOF)
        {
            break;
        }
        ch=fgetc(f1);
        fputc(ch,f2);
    }
    fclose(f1);
    fclose(f2);
    return 0;
}
