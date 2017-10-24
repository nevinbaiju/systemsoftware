//Author : Nevin Baiju
//Program : C Scan scheduling algorithm

#include<stdio.h>
//Function to find head position

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
// Function to perform scan scheduling
 void scan(int pos[10],int p,int q,int hpos)
 {      int i,mov;
        	
		for(i=hpos;i<=q;i++)
                        printf("%d ",pos[i]);
                printf(" 1000 0 ");  
        
                for(i=p;i<=hpos-1;i++)
                        printf("%d ",pos[i]);      // first case
                

               if(hpos!=0)

			mov=(1000-pos[hpos])+(1000)+(pos[hpos-1]);
		else
			mov = 1000-pos[hpos];
                

                printf("\nTotal head movement = %d",mov);

        
        
        
            
        

 }
// MAin function
//headpos: head position
//temp: variable to do swapping operation
//hpos: to store headposition after sorting

int main()
{
        int i,n,j,headpos,pos[10],temp,hpos;
        printf("\nEnter initial head position:");
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
//Sorting portion
        for(i=0;i<=n;i++)
        {
                for(j=i;j>=0;j--)
                {

                        if(pos[j]<pos[j-1])
                        {
                                temp=pos[j];
                                pos[j]=pos[j-1];  //Swapping takes place
                                pos[j-1]=temp;
                        }
		}
	 }

        hpos=findheadpos(pos,0,n,headpos);//calling findheadpos function
        scan(pos,0,n,hpos);               // calling scan schedule algorithm
 }


