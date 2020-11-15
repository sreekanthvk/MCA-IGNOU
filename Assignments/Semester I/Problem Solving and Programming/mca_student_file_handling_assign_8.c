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
        float assignment_marks[7];
        float tee_marks[7];
        float total_marks[7];
    } mca_students[2], mca_student;
    FILE *file_pointer;
    double consolidated_marks;
    double average_marks;
    char grade;
    /*opening the file in write mode*/
    if((file_pointer=fopen("stu.dat","w"))== NULL)
    {
        printf("Error while creating a file\n");
        exit(0); 
    }
    /* reading an array of students */
    for(int i = 0; i < 2; i++)
    {   
        printf("Enter name of student:"); 
        scanf("%s",mca_students[i].name);
        printf("Enter roll number of student:"); 
        scanf("%s",mca_students[i].reg_no); 
        for(int j = 0; j < 7 ; j++)
        {
           printf("Enter assignment marks of student %d  MCS-01%d:", i + 1, j + 1); 
           scanf(" %f", &mca_students[i].assignment_marks[j]);
           printf("Enter term end marks of student %d  MCS-01%d:", i + 1, j + 1); 
           scanf(" %f", &mca_students[i].tee_marks[j]);
           mca_students[i].total_marks[j] = mca_students[i].assignment_marks[j] + mca_students[i].tee_marks[j];
        }
         
    }
    /* writing to a file*/
    fwrite(mca_students,sizeof(struct students),2,file_pointer);
    fclose(file_pointer);
    /* opening a file in read mode */
    file_pointer=fopen("stu.dat","r");
    /* reading from a file and writing on the screen */
    while(!feof(file_pointer))
    {
        fread(&mca_student,sizeof(struct students),1,file_pointer);
        consolidated_marks = ( mca_student.total_marks[0] + mca_student.total_marks[1]  + mca_student.total_marks[2] + mca_student.total_marks[3] + mca_student.total_marks[4] + mca_student.total_marks[5] + mca_student.total_marks[6]);
        average_marks = consolidated_marks / 7; 
        if (average_marks >= 90 && average_marks <= 100)
        {
            grade = 'S';
        }
        else if (average_marks >= 80 &&  average_marks < 90)
        {
            grade = 'A';
        }
        else if (average_marks >= 70 &&  average_marks < 80)
        {
            grade = 'B';
        }
        else if (average_marks >= 60 &&  average_marks < 70)
        {
            grade = 'C';
        }
        else if (average_marks >= 50 &&  average_marks < 60)
        {
            grade = 'D';
        }
        else if (average_marks >= 40 &&  average_marks < 50)
        {
            grade = 'E';
        }
        else if (average_marks < 40)
        {
            grade = 'F';
        }
        printf("The total  and average marks of student %s is respectively %.2lf and %.2lf \n",mca_student.name,consolidated_marks,average_marks);
        printf("The grade of the student %s is %c\n",mca_student.name, grade );
    }
    fclose(file_pointer);
    return 0;
 }
