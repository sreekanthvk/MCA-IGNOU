/* Using file handling, write a C program: 
 * (a) To generate 10 records for MCA 1st semester students and store them in stu.dat along with appropriate fields. 
 * (b) To read the data from the file stu.dat (created above) and compute the total marks and average marks and display the grade(assumptions can be made).
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int  main()
{
    
    struct students
    {
        char name[255];
        char reg_no[10];
		int semester;
		float fees; 
		char study_center[25];
		char region_center[25];
        char course_name[7][25];
        float assignment_marks[7];
        float tee_marks[7];
        char assignment_submission_date[12];
    } mca_students[6];
    FILE *file_pointer;
    /*opening the file in write mode*/
    if((file_pointer=fopen("student1.dat","w"))== NULL)
    {
        printf("Error while creating a file\n");
        exit(0); 
    }
    /* reading an array of students */
    for(int i = 0; i < 6; i++)
    {   
        printf("Enter name of student:"); 
        scanf("%s",mca_students[i].name);
        printf("Enter roll number of student:"); 
        scanf("%s",mca_students[i].reg_no); 
        printf("Enter study_center of student:"); 
        scanf("%s",mca_students[i].study_center); 
		printf("Enter region_center of student:"); 
        scanf("%s",mca_students[i].region_center); 
		printf("Enter semester of student:"); 
        scanf(" %d",&mca_students[i].semester);
 		printf("Enter fees paid by student this semester:"); 
        scanf(" %f",&mca_students[i].fees);
 		printf("Enter date of assignment submission [DD/MM/YYYY]:"); 
        scanf("%s",mca_students[i].assignment_submission_date);		
        for(int j = 0; j < 7 ; j++)
        {
           printf("Enter the course name of MCS-0%d%d: ", mca_students[i].semester, j + 1);
           scanf(" %s", &mca_students[i].course_name[j]);
           printf("Enter assignment marks of student %s  MCS-0%d%d:", mca_students[i].name, mca_students[i].semester, j + 1); 
           scanf(" %f", &mca_students[i].assignment_marks[j]);
           printf("Enter tee marks of student %s  MCS-0%d%d:", mca_students[i].name, mca_students[i].semester, j + 1); 
           scanf(" %f", &mca_students[i].tee_marks[j]);
        }
         
    }
    /* writing to a file*/
    fwrite(mca_students,sizeof(struct students),6,file_pointer);
    fclose(file_pointer);
    return 0;
 }
