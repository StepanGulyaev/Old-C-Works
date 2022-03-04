#include <stdio.h>
#include <string.h>

struct student
    {
    char last_name[100];
    char first_name[100];
    char middle_name[100];
    unsigned int marks[5];
    };
        
void add_student()
	{
	FILE *fp;
	fp = fopen("file.txt","a+");
	printf("Enter student data:\n");
    student* buff = new student;
	scanf("%s %s %s",buff->last_name,buff->first_name,buff->middle_name);
	fprintf(fp,"%s %s %s\n",buff->last_name,buff->first_name,buff->middle_name);
    for (size_t j = 0; j < 5;j++)
    	{
    	switch(j)
        	{
       		case 0: printf("	Math ");break;
        	case 1: printf("	Physics ");break;
        	case 2: printf("	Graphics ");break;
        	case 3: printf("	Chemistry ");break;
        	case 4: printf("	Strength_of_materials ");break;
			}
    	switch(j)
        	{
       		case 0: fprintf(fp,"	Math ");break;
        	case 1: fprintf(fp,"	Physics ");break;
        	case 2: fprintf(fp,"	Graphics ");break;
        	case 3: fprintf(fp,"	Chemistry ");break;
        	case 4: fprintf(fp,"	Strength_of_materials ");break;
			}
		scanf("%d",&buff->marks[j]);
    	fprintf(fp,"%d\n",buff->marks[j]);
		}	
	fprintf(fp,"\n");
	delete buff;
	fclose(fp);
	}

void copy_back()

	{
	FILE *fp;
	FILE *fp1;	
	fp = fopen("file.txt","w+");
	fp1 = fopen("file1.txt","r");

	fseek(fp1,0,SEEK_END);
	int end_check = ftell(fp1)-2;
	fseek(fp1,0,SEEK_SET);
		
	char buffer1[50];
	char buffer2[50];
	char buffer3[50];
	
	while(ftell(fp1) < end_check)
		{
		fscanf(fp1,"%s %s %s",buffer1,buffer2,buffer3);
		fprintf(fp,"%s %s %s\n",buffer1,buffer2,buffer3);
		for (size_t i = 0; i < 5; i++)
			{
			fscanf(fp1,"	%s %s",buffer1,buffer2);
			fprintf(fp,"	%s %s\n",buffer1,buffer2);
			}
		fprintf(fp,"\n");
		}
	fclose(fp);
	fclose(fp1);
	}

void change_name()
	{
	FILE *fp;
	FILE *fp1;	
	fp = fopen("file.txt","r");
	fp1 = fopen("file1.txt","w+");

	printf("Which student's name do you want to change?\n");
	char last_name_to_change[30];
	char name_to_change[30];
	char father_name_to_change[30];
	scanf("%s %s %s",last_name_to_change,name_to_change,father_name_to_change); 

	printf("Enter new name\n");
	char new_last_name[30];
	char new_name[30];
	char new_father_name[30];
	scanf("%s %s %s",new_last_name,new_name,new_father_name); 

	char buffer1[50];
	char buffer2[50];
	char buffer3[50];

	fseek(fp,0,SEEK_END);
	int end_check = ftell(fp)-2;
	fseek(fp,0,SEEK_SET);

	while(ftell(fp) < end_check)
		{
		fscanf(fp,"%s %s %s",buffer1,buffer2,buffer3);
		if( !(strcmp(buffer1,last_name_to_change)) && !(strcmp(buffer2,name_to_change)) && !(strcmp(buffer3,father_name_to_change)))
			{
			fprintf(fp1,"%s %s %s\n",new_last_name,new_name,new_father_name);
			}
		else 
			{
			fprintf(fp1,"%s %s %s\n",buffer1,buffer2,buffer3);
			}
		for (size_t i = 0; i < 5; i++)
			{
			fscanf(fp,"	%s %s",buffer1,buffer2);
			fprintf(fp1,"	%s %s\n",buffer1,buffer2);
			}
		}
	fclose(fp);
	fclose(fp1);
	copy_back();
	}

void change_subject()
	{
	FILE *fp;
	FILE *fp1;	
	fp = fopen("file.txt","r");
	fp1 = fopen("file1.txt","w+");

	printf("Which subject do you want to change?\n");
	char subject_to_change[50];
	scanf("%s",subject_to_change);

	printf("Enter new subject\n");
	char new_subject[50];
	scanf("%s",new_subject);

	char buffer1[50];
	char buffer2[50];
	char buffer3[50];

	fseek(fp,0,SEEK_END);
	int end_check = ftell(fp)-2;
	fseek(fp,0,SEEK_SET);

	while(ftell(fp) < end_check)
		{
		fscanf(fp,"%s %s %s",buffer1,buffer2,buffer3);
		fprintf(fp1,"%s %s %s\n",buffer1,buffer2,buffer3);
		for (size_t i = 0; i < 5; i++)
			{
			fscanf(fp,"	%s %s",buffer1,buffer2);
			if ( !( strcmp(subject_to_change,buffer1) ) )
				{
				fprintf(fp1,"	%s %s\n",new_subject,buffer2);
				}
			else
				{
				fprintf(fp1,"	%s %s\n",buffer1,buffer2);
				}
			}
		}
	fclose(fp);
	fclose(fp1);
	copy_back();
	}

void change_mark()
	{
	FILE *fp;
	FILE *fp1;	
	fp = fopen("file.txt","r");
	fp1 = fopen("file1.txt","w+");
	
	char last_name_from_file[30];
	char name_from_file[30];
	char father_name_from_file[30];

	char last_name_to_change[30];
	char name_to_change[30];
	char father_name_to_change[30];

	char buffer1[50];
	char buffer2[50];
	printf("Which student's data you want to change?\n");
	scanf("%s %s %s",last_name_to_change,name_to_change,father_name_to_change); 

	fseek(fp,0,SEEK_END);
	int end_check = ftell(fp)-2;
	fseek(fp,0,SEEK_SET);

	while(ftell(fp) < end_check)
		{
		fscanf(fp,"%s %s %s",last_name_from_file, name_from_file,father_name_from_file);
		if( !(strcmp(last_name_from_file,last_name_to_change)) && !(strcmp(name_from_file,name_to_change)) && !(strcmp(father_name_from_file,father_name_to_change)))
			{
			fprintf(fp1,"%s %s %s\n",last_name_from_file, name_from_file,father_name_from_file);

			printf("What subject's mark do you want to change\n");
			char subject_to_change[50];
			char subject_from_file[50];
			scanf("%s",subject_to_change);
			for (size_t i = 0; i < 5;i++)
				{
				fscanf(fp,"%s %s",subject_from_file,buffer2);
				if ( !(strcmp(subject_from_file,subject_to_change)) )
					{
					printf("Enter new mark\n");
					int mark;
					scanf("%d",&mark);
					fprintf(fp1,"	%s %d\n",subject_from_file,mark);
					}
				else 
					{
					fprintf(fp1,"	%s %s\n",subject_from_file,buffer2);
					}
				}
			}
		else 
			{
			fprintf(fp1,"%s %s %s\n",last_name_from_file, name_from_file,father_name_from_file);
			for (size_t i = 0; i < 5; i++)
				{
				fscanf(fp,"	%s %s",buffer1,buffer2);
				fprintf(fp1,"	%s %s\n",buffer1,buffer2);
				}
			}
		}
	fclose(fp);
	fclose(fp1);
	copy_back();
	}

void change_data()
	{
	printf("Enter '1' to change student's name, enter '2' to change subject, enter '3' to change exact student's mark, enter '0' to return to the main menu\n");
	int option;
	wrong_input:
	scanf("%d",&option);
	switch(option)
		{
		case 0: return; break;
		case 1: change_name();break;
		case 2: change_subject();break;
		case 3: change_mark(); break;
		default: printf("Wrong input!\n");goto wrong_input;
		}
	}

void count_ones_bad_in_subject()
	{
	FILE *fp;
	fp = fopen("file.txt","r");	
	
	fseek(fp,0,SEEK_END);
	int end_check = ftell(fp)-2;
	fseek(fp,0,SEEK_SET);
	
	size_t counter = 0;
	
	char subject[30];
	printf("Which subject do you want to check?\n");
	scanf("%s",subject);
	while(ftell(fp) < end_check)
		{
		char buffer1[50];
		int buffer2;
		fscanf(fp,"%s",buffer1);
		if (!(strcmp(buffer1,subject)))
			{
			fscanf(fp,"%d",&buffer2);
			if (buffer2 <= 2){counter++;}
			}
		}
	printf("Number of students with bad %s mark: %lu\n",subject,counter);
	fclose(fp);
	}

int main()
    {
    int option = 0;
    while(1)
    	{
    	printf("Enter '1' to add student, '2' to change data, '3' to count how many students have a bad mark, enter '0' to quit:\n");
		wrong_input:
    	scanf("%d",&option);
    	switch(option)
    		{
    		case 0:return 0;break;
    		case 1:add_student();break;
    		case 2:change_data();break;
    		case 3:count_ones_bad_in_subject();break;
			default: printf("Wrong input!\n");goto wrong_input;
			}
		}
	}
