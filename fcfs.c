#include<stdio.h>

main()
{

        int n,p[20],wait[20],turn[20],i,j;
        printf("\nEnter no of process\n");
        scanf("%d",&n);
        printf("\nEntr burst times\n");
        for(i=0;i<n;i++)
        {
                printf("\nP%d:",i+1);
                scanf("%d",&p[i]);
        }
        wait[0]=0;
	turn[0]=p[0];
        for(i=1;i<n;i++)
        {
                wait[i]=0;
		for(j=0;j<i;j++)
                { 
                        wait[i]+=p[j];
                }
                turn[i]=wait[i]+p[i];
        }
        printf("\nProcess \t burst \t waiting \t turnar\n");
        for(i=0;i<n;i++)
        {
                printf("P %d: \t\t %d\t  %d\t\t  %d \n",(i+1),(p[i]),(wait[i]),(turn[i]));
        }
        float twait=0,tturn=0;
        for(i=0;i<n;i++)
        {
                twait+=wait[i];
                tturn+=turn[i];
        }
        printf("\nAvg Waiting time:%.2f\tAvg Turnaround:%.2f\n",twait/n,tturn/n);
}

