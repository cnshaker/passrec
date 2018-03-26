#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//呵呵
int main(int argc,char* argv[])
{
	int i;
	for(i=0;i<argc;i++)
	{
		printf("%d ==> %s\n",i,argv[i]);
	}
	FILE *pf=fopen("e:\\20180312-0318_passrec.csv","r");
	if(pf==NULL)
	{
		printf("Open file fault!\n");
		return -1;
	}
	char buffer[1024];
	for(i=0;i<2;i++)
	{
		fgets(buffer,1024,pf);
		const char * d=",";
		char *p;
		p=strtok(buffer,d);
		do
		{
			printf("%s\n",p);
		}while((p=strtok(NULL,d))!=NULL);
	}
	fclose(pf);
	return 0;
}
