// Accept two file names from user and copy the contents of one file into another file.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

void FileCopy(char *Src,char *Dest)
{
 int fdsrc = 0;
 int fddest = 0;
 int iRet = 0;
 int i = 0;
 char mug[100] = {'\0'};
 
 fdsrc = open(Src, O_RDWR);
 
 if(fdsrc == -1)
 {
   printf("Unable to open the source file \n");
   return;
 }
 
 fddest = open(Dest, O_RDWR | O_CREAT , 0777);
 
 if(fddest == -1)
 {
	 printf("Unable to open the destination file \n");
	 close(fdsrc);
	 return;
 }
 
 while((iRet = read(fdsrc,mug,sizeof(mug))) != 0)
 {
	    printf("Iteration : %d Size Read : %d\n", i, iRet);
        i++;
    write(fddest,mug,iRet);	 
 }
 
 close(fdsrc);
 close(fddest);
 
}

int main()
{
 char Name1[20];
 char Name2[20];
 
 printf("Enter the source file name\n");
 scanf("%s",Name1);
 printf("Enter the destination file name \n");
 scanf("%s",Name2);
 
 FileCopy(Name1,Name2);

return 0;
}

/*

output

Enter the source file name
india.txt
Enter the destination file name
nikita
Iteration : 0 Size Read : 68

*/