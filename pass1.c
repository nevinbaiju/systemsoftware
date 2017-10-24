//Author :Nevin Baiju
//Program:pass1 of two pass assembler
#include<stdio.h>

#include<string.h>
//Main function
void main()
{
 //opcode - array to fetch opcode from file
// operand-array to fetch operand fom file
//label: - array to fetch label from file
//mneumonic- to store opcode

 char opcode[10],operand[10],label[10],code[10][10],ch; char mnemonic[10][10]={"START","LDA","STA","LDCH","STCH","END"};
 int locctr,start,len,i=0,j=0;
 FILE *fp1,*fp2,*fp3;
//fp1,fp2,fp3 are files
//fp1-input file
//fp2=symtab file
 
 fp1=fopen("ip.txt","r");
 fp2=fopen("sym.txt","w");
 fp3=fopen("out.txt","w");
 fscanf(fp1,"%s%s%s",label,opcode,operand);
//sacaninf fp 1 and storing it in arrays 
 if(strcmp(opcode,"START")==0) //checking opcode = start
  {
   start=atoi(operand);
   locctr=start;
   fprintf(fp3,"%s\t%s\t%s\n",label,opcode,operand);
   fscanf(fp1,"%s%s%s",label,opcode,operand);
  }
 else
  locctr=0;
 while(strcmp(opcode,"END")!=0)//cheching end of code
  {
   fprintf(fp3,"%d",locctr);
   if(strcmp(label,"**")!=0)
     fprintf(fp2,"%s\t%d\n",label,locctr);
   strcpy(code[i],mnemonic[j]);
   while(strcmp(mnemonic[j],"END")!=0)
    {
     if(strcmp(opcode,mnemonic[j])==0)
     {
      locctr+=3;
      break;
     }
     strcpy(code[i],mnemonic[j]);
     j++;
    }
   if(strcmp(opcode,"WORD")==0)
    locctr+=3;
   else if(strcmp(opcode,"RESW")==0)  //checking conditions to modify loocctr
    locctr+=(3*(atoi(operand)));
   else if(strcmp(opcode,"RESB")==0)
    locctr+=(atoi(operand));
   else if(strcmp(opcode,"BYTE")==0)
    ++locctr;
   fprintf(fp3,"\t%s\t%s\t%s\n",label,opcode,operand);
   fscanf(fp1,"%s%s%s",label,opcode,operand);
  }
  fprintf(fp3,"%d\t%s\t%s\t%s\n",locctr,label,opcode,operand);
  fcloseall();
  printf("\n\nThe contents of Input Table :\n\n"); //printing contents of input table
  fp1=fopen("ip.txt","r");
  ch=fgetc(fp1);
  while(ch!=EOF)      
   {                                
    printf("%c",ch);
    ch=fgetc(fp1);
   }
  printf("\n\nThe contents of Output Table :\n\n\t"); //printong contents of output table
  fp3=fopen("out.txt","r");
  ch=fgetc(fp3);
  while(ch!=EOF)
   {
    printf("%c",ch);
    ch=fgetc(fp3);
   }
  len=locctr-start;
  printf("\nThe length of the program is %d.\n\n",len);
  printf("\n\nThe contents of Symbol Table :\n\n"); //printing contents of symbol table
  fp2=fopen("sym.txt","r");
  ch=fgetc(fp2);
  while(ch!=EOF)
   {
    printf("%c",ch);
    ch=fgetc(fp2);
   }
  fcloseall(); //closing file

}
