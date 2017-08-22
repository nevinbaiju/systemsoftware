////////////////////////////////////////////////////////////////////////////
//Program : Single Level Directory					  //
//Date    : 20-08-2017							  //
//Author  : Nevin Baiju							  //	
//Location: 1541@10.0.2.250/R5/single_file_directory.c			  //
////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<string.h>
//Defining Struct
typedef struct direct
{
	char dname[20];
	char fname[20][20];
	int fcount;
}dir;

main()
{
	dir mydir;
	printf("\nEnter Dir name:");
	scanf("%s",mydir.dname);
	mydir.fcount=0;
	int i,ch=0,flag=0;
	
	char f[20];
	do
	{
		printf("\n1.Create File \n2.Delete File\n3.Search File\n4.Display File\n5.Exit\n:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("\nEnter File name:");scanf("%s",mydir.fname[mydir.fcount]);
				mydir.fcount++;break;//File Creation
			case 2:printf("\nEnter File name:");scanf("%s",f);
				for(i=0,flag=0;i<mydir.fcount && flag ==0;i++)
				{
					if(!strcmp(mydir.fname[i],f))
					{
						flag=1;
						for(i;i<mydir.fcount;i++)
						strcpy(mydir.fname[i],mydir.fname[i+i]);
						mydir.fcount--;
						printf("\n File %s Deleted\n",f); //Searching And Deleting
					}
				}
				if (flag==0) printf("\nFile not Found\n");break;
			case 3:printf("\nEnter File name:");scanf("%s",f);
                                for(i=0,flag=0;i<mydir.fcount && flag ==0;i++)
                                {
                                        if(!strcmp(mydir.fname[i],f))
                                        {       flag=1;
						printf("\nFile Found\n");//Searching
					}
				}
				if (flag==0) printf("\nFile not Found\n");
				break;
			case 4:printf("\nFiles Are\n");
				for(i=0;i<mydir.fcount;i++)
						printf("\t %s",mydir.fname[i]);
				break;//Display Files
			case 5:printf("\nThank you\n");break;
			default:printf("\nInvalid Entry\n");
		}
	}while(ch!=5);
}

