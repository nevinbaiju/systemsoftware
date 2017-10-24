//Author:Nevin Baiju
//Program Scan algorithm

#include<stdio.h>
//Function to find Head position
int findheadpos(int pos[10],int p,int q,int headpos)
{
	int mid;	
	mid=(p+q)/2;
	if(headpos==pos[mid])
	{
		return mid;
	}
	else if(pos[mid]<headpos)
	{
		return(findheadpos(pos,mid+1,q,headpos));
	}
	else
	{
		return(findheadpos(pos,p,mid-1,headpos));
	}

 }
//Function to perform Scanning
 void scan(int pos[10],int p,int q,int hpos)  
 {	int i;
	if(pos[hpos]-pos[hpos-1] < pos[hpos+1]-pos[hpos])
	{
		for(i=hpos;i>=p;i--)
			printf("%d ",pos[i]);     //Checking conditions
		printf(" 0 ");

		for(i=hpos+1;i<=q;i++)
			printf("%d ",pos[i]);
		

		printf("\nTotal head movement = %d",(1000-pos[q])+(pos[hpos]));
                
	}
	else
	{
		for(i=hpos;i<=q;i++)
                        printf("%d ",pos[i]);
                printf(" 1000 ");
		
		 for(i=hpos-1;i>=p;i--)
                        printf("%d ",pos[i]);
                                                              //Calculating total head movement
                 
		printf("\nTotal head movement = %d",(1000-pos[0])+(1000-pos[hpos]));
	}

 }
//Main function
int main()                                    // headpos - Contain head position
                                               //pos- array to store all positions 
{                                              // temp - to store temparay value
	int i,n,j,headpos,pos[10],temp,hpos;
	printf("\nEnter initial head position:");  //Entering initial values 
	scanf("%d",&headpos);
 	printf("\nEnter the number of disk access:");
	scanf("%d",&n);
	printf("\n Enter the disc points:\n");
	for(i=0;i<n;i++)
	{
		printf("\nEnter the point %d:",i+1);
		scanf("%d",&pos[i]);
	}
	pos[n]= headpos;

	for(i=0;i<=n;i++)   //Sorting takes place
	{
		for(j=i;j>=0;j--)
		{
			if(pos[j]<pos[j-1])
			{
		        	temp=pos[j-1];
				pos[j-1]=pos[j];
				pos[j]=temp;
			}
		}
	}
  
	hpos=findheadpos(pos,0,n,headpos);   //Calling scan and findheadpos functon
	scan(pos,0,n,hpos);
 }
