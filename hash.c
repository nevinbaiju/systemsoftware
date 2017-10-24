//Author : Nevin Baiju
//Program : Symbol Table Using Hashing


#include<stdio.h>
#include<string.h>

//Structure to define symbol
struct symbol
{
        int address;
        char label[10];
}sy[11];
//Function to find key value
int insert(int num)
{
        int key;
        key = num % 11;
        return(key);
}


//Main function

void main()
{
        int i,choice,key,a[11],count=0,flag=0,num,set=0;
        char l[11];                           //choice - to get the choice
        for(i=0;i<11;i++)                     // num - to get the address
                a[i]=0;                       //key- index value of hash table  
        do{
        
	printf("\nMenu Driven");
        printf("\n1.Insert");
        printf("\n2.Display");
        printf("\n3.Search");
        printf("\n4.Exit");
    	printf("\nEnter your option:");
        scanf("%d",&choice);

        switch(choice)
        {
                case 1 : printf("\nEnter the address:"); // Hashing by division method
                                 scanf("%d",&num);       // linear probing done to avoid collision
                                 key = insert(num);
                                 printf("\nEnter the label:");
                                 scanf("%s",l);

                                if(a[key]==0)
                                        {
                                        a[key]=num;

                                     sy[key].address=num;            //if no data is present in key new data is stored
                                     strcpy(sy[key].label,l);

                                        }

                                 else
                                 {
                                   i=0;
                                   count=0;                           //if data is present in key, data is stored on next free location  
                                   while(i<11)
                                         {
                                                if(a[i]!=0)
                                                 {
                                                         count++;
                                                 }
                                                i++;
                                         }







                                   if(count==11)
                                        {
   
                                                printf("\n Hash table is full");
                                                 break;
                                        }


                                   for(i=key+1;i<11;i++)
                                          {

                                                 if(a[i]==0)
                                                 {
                                                         flag=1;
                                                         a[i]=num;
                                                         sy[i].address=num;
                                                         strcpy(sy[i].label,l);
                                                                                              break;
                                                 }

                                          }
                                    if(key==10){
                                    for(i=0;i<key;i++)
                                         {
                                                 if(a[i]==0)
                                                 {

                                                         a[i]=num;
                                                         sy[i].address=num;
                                                         strcpy(sy[i].label,l);
                                                         break;
                                                 }
                                         }
                                         }
                                    }


                                 break;
                case 2:
                                printf("\nIndex\tAddress\tLabel\n");   //option to display the hash table
                                for(i=0;i<11;i++)
                                {
                                        printf("\n%d\t %d\t %s",i,sy[i].address,sy[i].label);
                                }
                                break;

        	case 3: 	printf("\nEnter the label name:"); //option to search for a label
                                scanf("%s",l);
                                for(i=0;i<11;i++)
                                {
                                        if(a[i]!=0)
                                        {
                                                if(strcmp(sy[i].label,l)==0)
                                                {
                                                        set=1;
                                                        break;
                                                }
                                        }
                                }
                                if(set==1)
                                {
                                        printf("Label found at index :%d which have address :%d",i,a[i]);
                                }
				else
				{
			           printf("Label Not found");	
				}

        }

    }while(choice!=4);

}
