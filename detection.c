#include<stdio.h>
int finish[20]={0};
int finishcount=0;
int main()
{	
	int i,j,k,y,procount,rescount,requestcount;
	printf("Enter no. of processes : ");
	scanf("%d",&procount);
	printf("Enter no. of resources : ");
	scanf("%d",&rescount);
	int work[rescount];
	int sequence[procount];
	struct process
	{
		int allocation[rescount];
		int request[rescount];
	};
	struct process p[procount];
	for(i=0;i<procount;i++)
	{
		printf("Enter the allocation of P%d:",i);
		for(j=0;j<rescount;j++)
		{
			scanf("%d",&p[i].allocation[j]);
		}
		printf("Enter the request of P%d:",i);
		for(j=0;j<rescount;j++)
		{
			scanf("%d",&p[i].request[j]);
		}
	}
	
	printf("Enter the available: ");
	for(j=0;j<rescount;j++)
	{
		scanf("%d",&work[j]);
	}
	y=0;
	int flag=0;
	while((finishcount<procount) && (flag<10))
	{
		flag++;
		for(i=0;i<procount;i++)
		{
			requestcount=0;
			if(finish[i]==0)
			{
				for(j=0;j<rescount;j++)
				{
					if(p[i].request[j]<=work[j])
					{
						requestcount++;
					}
				}
				if(requestcount==rescount)
				{
					finish[i]=1;
					finishcount++;
					sequence[y]=i;
					y++;
					for(k=0;k<rescount;k++)
					{
						work[k]=work[k]+p[i].allocation[k];
					}
					flag=0;
				}
			}
		}
	}
	if(finishcount==procount)
	{
		printf("System in safe state\n");
		printf("The sequence is: ");	
		for(i=0;i<procount;i++)
		{
			printf("P%d  ",sequence[i]);
		}
		printf("\n");				
	}
	else
	{
		printf("System in deadlock state\n");
		for(i=0;i<procount;i++)
		{
			if(finish[i]==0)
			{
				printf("Process P%d is in deadlock\n",i);
			}
		}
	}
	
}
