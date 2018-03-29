#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
	struct student{
		char name[10];
		int math;
	} *ptr; //Another type pointer the same with type* ptr;
	
	int NUM_student = 0;
	printf("Number of students : \n");
	scanf("%d",&NUM_student);
	//Dynamically
	ptr = (struct student*)malloc(sizeof(struct student)*NUM_student);
	
	for(int i=0;i<NUM_student;i++)
	{
		fflush(stdin);
		printf("Enter student name: \n");
		gets((ptr+i)->name);//Array self is address
		printf("Enter student score: \n");
		scanf("%d",&(ptr+i)->math);
	}
	
	//List Student
	for(int i=0;i<NUM_student;i++) printf("%s score is %d \n",(ptr+i)->name,(ptr+i)->math);
	free(ptr);
	ptr = NULL;//Avoid pointer to be Lost
	
	//Pointer test
	//printf("%s",*ptr->name);
	//--> Will Segementation Fault
	system("pause");
	return 0;
}
