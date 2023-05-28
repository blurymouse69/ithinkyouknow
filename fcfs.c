#include<stdio.h>

int main()
{
	struct proc
	{
	    int pid;
		int at;
		int bt;
		int wt;
		int tt;
		int et;
	};

	int i,n,e=0,min,j;
	double avwt=0,avtt=0;
	printf("FCFS Scheduling\n");
	printf("Enter the no. of processes: ");
	scanf("%d",&n);
	struct proc p[n];
	for(i=0;i<n;i++)
	{
	    p[i].pid=i;
		printf("Enter burst time for p%d: ",i);
		scanf("%d",&p[i].bt);
		printf("Enter arrival time for p%d: ",i);
		scanf("%d",&p[i].at);
	}

	//In case the given values of arrival time are not in correct order.
	struct proc temp;
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

	for(i=0;i<n;i++)
	{
		e=e+p[i].bt;
		p[i].et=e;
		p[i].tt=p[i].et-p[i].at;
		p[i].wt=p[i].tt-p[i].bt;
		avwt=avwt+p[i].wt;
		avtt=avtt+p[i].tt;
	}
	printf("\nProcess\tArrival\tBurst\tWaiting\tTurnaround\n");
	for(i=0;i<n;i++)
	{
		printf("\n  P%d\t   %d\t   %d\t   %d\t    %d\n",p[i].pid,p[i].at,p[i].bt,p[i].wt,p[i].tt);
	}
	avwt=avwt/n;
	avtt=avtt/n;
	printf("\nThe avg turnaround time is: %.2f",avtt);
	printf("\nThe avg waiting time is: %.2f\n",avwt);

}
