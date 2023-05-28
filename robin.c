#include<stdio.h>

int que[50];

int front=0,rear=0,q=0;

void enque(int val)
{
	que[rear]=val;
	rear=rear+1;
	q=q+1;
}

int deque()
{
	front=front+1;
	q=q-1;
	return que[front-1];
}

int empty()
{
	if(q==0)
	{	return 1;	}
	else
	{	return 0;	}
}

int main()
{
	struct proc
	{
		int at;
		int bt;
		int rt;
		int wt;
		int tt;
		int et;
	};

	int i,n,e=0,min,j,tq,tot=0;
	double avwt=0,avtt=0;
	printf("Round Robin Scheduling\n");
	printf("Enter the no. of processes: ");
	scanf("%d",&n);
	printf("Enter the time quantum: ");
	scanf("%d",&tq);
	struct proc p[n];
	struct proc temp;
	for(i=0;i<n;i++)
	{
		printf("Enter burst time for p%d: ",i);
		scanf("%d",&p[i].bt);
		p[i].rt=p[i].bt;
		printf("Enter arrival time for p%d: ",i);
		scanf("%d",&p[i].at);		
	}
	
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
	int prodone=0,y=0,a;
	enque(0);
	prodone++;
	while(!empty())
	{
		a=deque();
		if(p[a].rt<tq)
		{
			tot=tot+p[a].rt;
			p[a].rt=0;
		}
		else
		{
			tot=tot+tq;
			p[a].rt=p[a].rt-tq;
		}
		if(prodone<n)
		{	for(j=prodone;j<n;j++)
			{
				if(p[j].at<=tot) 
				{	enque(j);
					prodone++;
				}					
			}
		}
		if(p[a].rt>0)
			{	enque(a);	}
		else if(p[a].rt==0)
		{	p[a].et=tot;	}
	}	
	for(i=0;i<n;i++)
	{
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
