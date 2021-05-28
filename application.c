#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

struct weekday
{
	int days , workers;
	char name[10];
	bool isfull;
};
int main()
{
	struct weekday list[5];
	strcpy(list[0].name,"Monday");
	strcpy(list[1].name,"Tuesday");
	strcpy(list[2].name,"Wednesday");
	strcpy(list[3].name,"Thursday");
	strcpy(list[4].name,"Friday");
	printf("please enter how many workers you need each day: ");
	scanf("%d%d%d%d%d",&list[0].days,&list[1].days,&list[2].days,&list[3].days,&list[4].days);
	for(int i=0;i<5;i++)
	{
		list[i].workers=0;
		list[i].isfull=false;
	}//initialize the value
	FILE *fptr;
	fptr=fopen("applicants.txt","r");
	if(fptr==NULL)
	{
		printf("Error!");
		exit(1);
	}


	char chunk[128];//read every line
	while(fgets(chunk,sizeof(chunk),fptr)!=NULL)//read line by line
	{
	
		char name_[10],address[10],work[3][10];
		sscanf(chunk,"%[^,],%[^,], %s %s %s\n",&name_,&address,work[0],work[1],work[2]);
	
		for(int i=0;i<3;i++){
		if((strcmp(work[i],"Monday")==0)&&(list[1].isfull!=true))
	
			list[0].workers++;
		else if((strcmp(work[i],"Tuesday")==0)&&(list[1].isfull!=true))
			list[1].workers++;

		else if((strcmp(work[i],"Wednseday")==0)&&(list[2].isfull!=true))
			list[2].workers++;

		else if((strcmp(work[i],"Thursday")==0)&&(list[3].isfull!=true))
			list[3].workers++;

		else if((strcmp(work[i],"Friday")==0)&&(list[4].isfull!=true))
			list[4].workers++;


		}
		for(int i=0;i<5;i++)
		{
			if(list[i].workers==list[i].days)
				list[i].isfull=true;
		}
	}
	fclose(fptr);
	fptr=fopen("newlist.txt","w+");
	for(int i=0;i<5;i++)
	{
		if(list[i].isfull==false)
		fprintf(fptr,"%s %d not full\n",list[i].name,list[i].workers);
		else
			fprintf(fptr,"%s %d full\n",list[i].name,list[i].workers);
	}
	
}
//the vineyard needs one two three four five people on each day of the week
