//Author: Nevin Baiju
//Program- Disk fcfs

#include<stdio.h>
//Main function
int  main()
{
 	int i,n,head,position[10],headmov=0;      //head- startig head position
                                                  //position- array
 	printf("\nEnter initial head position:");
        scanf("%d",&head);
        printf("\nEnter the no. of proceses:");
 	scanf("%d",&n);
  	for(i=0;i<n;i++)
	{
		printf("\nEnter the position %d:",i+1);
 		scanf("%d",&position[i]);
	}
	headmov=abs(position[0]-head); 
 	printf("\n Scheduled Order: %d",head);//scheduled order
        for(i=0;i<n;i++)
	{
		printf(" %d",position[i]);
	}
 	for(i=1;i<n;i++) //loop to find head position
	{
 		headmov=headmov+abs(position[i]-position[i-1]);
 	}
      
  	printf("\n Total head movement = %d",headmov);//printing head movement
   return(0);
 }
