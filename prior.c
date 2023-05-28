#include<stdio.h>

int main()
{
	struct proc
	{
		int at;
		int bt;
		int pri;
		int wt;
		int tt;
		int et;
	};
	
	int i,n,e=0,min,j,k;
	double avwt=0,avtt=0;
	printf("Priority Scheduling\n");
	printf("Enter the no. of processes: ");
	scanf("%d",&n);
	struct proc p[n];
	for(i=0;i<n;i++)
	{
		printf("Enter burst time for p%d: ",i);
		scanf("%d",&p[i].bt);
		printf("Enter arrival time for p%d: ",i);
		scanf("%d",&p[i].at);
		printf("Enter priority for p%d: ",i);
		scanf("%d",&p[i].pri);
		
	}
	struct proc temp;
	
	//To sort based on arrival time. No need for this if the given values are in correct order of arrival time.
	for(i=0;i<n;i++)
	{
		min=i;
		for(j=i;j<n;j++)
		{
			if(p[j].at<p[min].at)
			{	min=j;	}
		}
		temp=p[i];
		p[i]=p[min];
		p[min]=temp;
	}
	
	//To sort the remaining processes based on priority  (Higher number means higher priority)
	
	for(k=0;k<n;k++)
	{	i=k+1;
		while((p[i].at<=p[k].bt) && (i<n))
		{
			min=i;
			for(j=i;j<n;j++)
			{
			
				if((p[j].pri>p[min].pri)&&(p[j].at<=p[k].bt))
				{	min=j;	}
			}
			temp=p[i];
			p[i]=p[min];
			p[min]=temp;
			i=i+1;
		}
	}
	
	
	
	for(i=0;i<n;i++)
	{
		e=e+p[i].bt;
		p[i].et=e;
		p[i].tt=p[i].et-p[i].at;
		p[i].wt=p[i].tt-p[i].bt;
		avwt=avwt+p[i].wt;
		avtt=avtt+p[i].tt;
	}
	
	printf("\nProcess\tArrival\tBurst\tExit\tWaiting\tTurnaround\n");
	for(i=0;i<n;i++)
	{
		printf("\n  P%d\t   %d\t   %d\t   %d\t   %d\t    %d\n",i,p[i].at,p[i].bt,p[i].et,p[i].wt,p[i].tt);
	}
	avwt=avwt/n;
	avtt=avtt/n;
	printf("\nThe avg turnaround time is: %.2f",avtt);
	printf("\nThe avg waiting time is: %.2f\n",avwt);	
}
