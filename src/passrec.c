#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//呵呵
int main(int argc,char* argv[])
{
	int i,l;
	if(argc<=1)
	{
		printf("Usage:\n\t%s filename\n",argv[0]);
		return 0;
	}
	FILE *pf=fopen(argv[1],"r");
	if(pf==NULL)
	{
		printf("Error:\n\tOpen file fault!\n");
		return -1;
	}
	char buffer[1024];
	char szBuf[128];
	for(i=0;i<2;i++)
	{
		fgets(buffer,1024,pf);
		//printf("%s\n",buffer);
		l=strlen(buffer)-1;
		while((buffer[l]==(char)0xa)||(buffer[l]==(char)0xd)){buffer[l]='\0';l--;}
		const char * d=",";
		char *p;
		p=strtok(buffer,d);
		do
		{
			while((*p=='"')||(*p==' '))p++;
			strcpy(szBuf,p);
			l=strlen(szBuf)-1;
			while((szBuf[l]=='"')||(szBuf[l]==' ')){szBuf[l]='\0';l--;}
			printf("%s\n",szBuf);
		}while((p=strtok(NULL,d))!=NULL);
	}
	fclose(pf);
	return 0;
}
