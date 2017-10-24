//Author : Nevin Baiju
//Program: Banker's Algorithm
#include<stdio.h>

void main()
{
	//avail - resources available 
	//allocated - resources allocation matrix
	//max - max matrix
	// rz - no . of resources
	// pno -  no . of processes
 
	int k=0;
	int output[10];
	int d=0;
	int t=0;
	int ins[5];
	int i;
	int avail[5];
	int allocated[10][5];
	int need[10][5];
	int MAX[10][5];
	int pno,P[10];
	int j;
	int rz;
	int count=0;

	printf("\n Enter the number of resources : ");
	scanf("%d", &rz);

	printf("\n enter the max instances of each resources\n");
	for(i=0;i<rz;i++)
	{
		avail[i]=0;
		printf("%c= ",(i+97));
		scanf("%d",&ins[i]);
	 }
	 printf("\n Enter the number of processes : ");
	 scanf("%d", &pno);

	//Getting value of allocation matrix
	printf("\n Enter the allocation matrix \n     ");

	for(i=0;i<rz;i++)
 		printf(" %c",(i+97));
	printf("\n");
	for(i=0;i <pno;i++)
	{
		P[i]=i;
		printf("P[%d]  ",P[i]);
		for(j=0;j<rz;j++)
		{
			scanf("%d",&allocated[i][j]); //Calculating available
			avail[j]+=allocated[i][j];
		}
 	}
	//Getting value of max matrix
	printf("\nEnter the MAX matrix \n     ");
	for(i=0;i<rz;i++)
	{      
		printf(" %c",(i+97));
		avail[i]=ins[i]-avail[i];   
	}
	printf("\n");
 	for(i=0;i <pno;i++)
 	{
		printf("P[%d]  ",i);
 		for(j=0;j<rz;j++)
 			scanf("%d", &MAX[i][j]);
 	}

 	printf("\n");
 	A: d=-1;
 	for(i=0;i <pno;i++)
 	{	
 		count=0; t=P[i];
 		for(j=0;j<rz;j++)
 		{
 			need[t][j] = MAX[t][j]-allocated[t][j];  // Calculatiing need matrix
 			if(need[t][j]<=avail[j])
	 			count++;
 		}
		if(count==rz)
 		{
			output[k++]=P[i];
 			for(j=0;j<rz;j++)
				avail[j]+=allocated[t][j];   //Updating available 
 		}
 		else
 			P[++d]=P[i];
 	}

 	if(d!=-1)
 	{
		pno=d+1;
	   	goto A;
 	}
 	printf("\t ");

	for(i=0;i<k;i++)
 		printf(" P[%d] ",output[i]);  // Printing Output
 	printf("\n");

}

