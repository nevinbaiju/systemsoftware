#include<stdio.h>
main()
{
        int p[20],bt[20],wt[20],turn[20],prio[20];
        printf("\nEnter no of Process:");
        int i,j,n,temp,pos;
        float waittot=0,turntot=0;

        scanf("%d",&n);
        printf("\nEnter Burst times & Priority\n");
        for(i=0;i<n;i++)
        {
                printf("\nProcess P[%d] Burst\n",i+1);
                scanf("%d",&bt[i]);
                printf("\nPriority :");
                scanf("%d",&prio[i]);
                p[i]=i+1;
        }
        for(i=0;i<n;i++)
        {
                pos=i;
                for(j=i+1;j<n;j++)
                {
                if(prio[j]<prio[pos])
                        pos=j;
                }
                temp=prio[i];
                prio[i]=prio[pos];
                prio[pos]=temp;

                temp=bt[i];
                bt[i]=bt[pos];
                bt[pos]=temp;

                temp=p[i];
                p[i]=p[pos];
                p[pos]=temp;
        }

        wt[0]=0;
        for(i=1;i<n;i++)
        {
                wt[i]=0;
                for(j=0;j<i;j++)
                        wt[i]+=bt[j];
                waittot+=wt[i];
        }
        for(i=0;i<n;i++)
        {
                turn[i]=bt[i]+wt[i];
                turntot+=turn[i];
        }
        printf("\nprocess \t Bursttime  \t Priority\t waiting time \t turnaround time\n");
        for(i=0;i<n;i++)
        {
                        printf("   P%d \t    %d  \t  %d  \t %d  \t   %d  \n",p[i],bt[i],prio[i],wt[i],turn[i]);
        }
        printf("\navg wt:%f \t avg turn:%f\n",(waittot/n),(turntot/n));
}
       
