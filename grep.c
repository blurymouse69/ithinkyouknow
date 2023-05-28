#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<string.h>
int main(int argc, char* argv[]) 
{    char temp[200];
    FILE *fp;     
    fp = fopen(argv[1], "r");    
    while (!feof(fp)) 
    {
    	fgets(temp, sizeof(fp), fp);        
    	if (strcmp(temp, argv[2]))
    	{     printf("%s", temp);    }
    }    
    fclose(fp);
    return 1;
    
}


