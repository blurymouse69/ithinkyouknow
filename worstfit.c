#include<stdio.h>
void main()
{
	int blocks,jobs,i,j,k,min,max;
	printf("Enter the no. of blocks: ");
	scanf("%d",&blocks);
	int block_size[blocks];
	printf("Enter the block sizes: ");
	for(i=0;i<blocks;i++)
	{
		scanf("%d",&block_size[i]);
	}
	printf("Enter the no. of jobs: ");
	scanf("%d",&jobs);
	struct jobstr
	{
		int size;
		int bsize;
		int frag; 
	}job[jobs];
	printf("Enter the job sizes: ");
	for(i=0;i<jobs;i++)
	{
		scanf("%d",&job[i].size);
		job[i].bsize=-1;
		job[i].frag=-1;
	}
	int temp;
	struct jobstr tempstr;
	for(i=0;i<jobs;i++)
	{
		min=i;
		for(j=i;j<jobs;j++)
		{
			if(job[j].size<job[min].size)
			{	min=j;	}
		}
		tempstr=job[i];
		job[i]=job[min];
		job[min]=tempstr;
	}
	
	for(i=0;i<blocks;i++)
	{
		max=i;
		for(j=i;j<blocks;j++)
		{
			if(block_size[j]>block_size[max])
			{	max=j;	}
		}
		temp=block_size[i];
		block_size[i]=block_size[max];
		block_size[max]=temp;
	}
	
	j=0;
	for(i=0;i<jobs;i++)
	{
		k=0;
		while(k<blocks)
		{
			if(job[i].size<=block_size[j])
			{
				job[i].bsize=block_size[j];
				job[i].frag=job[i].bsize-job[i].size;
				block_size[j]=-1;
				break;
			}
			j=(j+1)%blocks;
			k++;
		}
	}
	printf("Job Size\t Block size\t Internal Fragmentation\n");
	for(i=0;i<jobs;i++)
	{
		printf("%d\t %d\t %d\n",job[i].size,job[i].bsize,job[i].frag);
	}
}
