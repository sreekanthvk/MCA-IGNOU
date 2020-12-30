/* Write an interactive C program for “MCA Student Semester-End Results” which 
 * prompts the user with the following menu options on the opening menu and
 * performs the corresponding functionalities:
 * 1) Registration Status (Registration details like enrolment no, current semester, 
 * fee-details, study centre, regional centre etc) 
 * 2) Courses in the Current Semester 
 * 3) Assignment Submission Schedules 
 * 4) Assignment Marks (semester-wise, course-wise till current semester) 
 * 5) Term End Exam Marks(semester-wise, course-wise till current semester) 
 * 6) Quit
 * Enter your choice:
 */

#include <stdio.h>
#include<string.h>
#include<stdlib.h>

/* structure declartion 
 * to hold the value from the file student.dat
 * The following information is available in binary file student.date
 * Name, Register, Different semesters. study center, region center, fees paid, 
 * assigment and term end EXAMINATION marks. It also have date of submission of assigment
 */
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
};

/* We assume that the largest semester in records will be the current semester
 * we read data and capture the data corresponding to me maximum semester for that 
 * enrolment number. IF enrolment number is not present it will alert. 
 */
void registration_status()
{
    FILE *file_pointer;
    char enrol_no[10];
    int found = 0, index = -1, max_ind = -1;
    struct students mca_students[6], mca_student;
    printf("Enter roll number of student:"); 
    scanf("%s",enrol_no); 
    /* opening a file in read mode */
    file_pointer=fopen("student.dat","r");
    /* reading from a file and writing on the screen */
    while(!feof(file_pointer))
    {
        fread(&mca_student,sizeof(struct students),1,file_pointer);
        /*checking of entered enrolment number is present or not*/
        if (strcmp(mca_student.reg_no, enrol_no) == 0)
        {
            found = 1;
            index = mca_student.semester - 1;
            mca_students[index] = mca_student;
            /*identifying the largest value of semester*/
            if (max_ind <= index)
            {
                max_ind = index;
            }
        }
        
    }
    /*if enrolment number is present show the results*/
    if (found == 1 )
    {
        printf("REGISTRATION STATUS\n");
        printf("Name: %s\n",mca_students[max_ind].name);
        printf("Enrolment No.: %s\n", mca_students[max_ind].reg_no);
        printf("Study Center: %s\n",mca_students[max_ind].study_center);
        printf("Region Center: %s\n", mca_students[max_ind].region_center);  
        printf("Current Semester: %d\n", mca_students[max_ind].semester);
        printf("Fees Paid: %.2f\n", mca_students[max_ind].fees);
    }
    else /* alerting when the enrolment no. not found */
    {
        printf("Enrolment number seems to be Invalid. Not found\n");
    }
    fclose(file_pointer);   
}
/* We assume that the largest semester in records will be the current semester
 * we read data and capture the data corresponding to me maximum semester for that 
 * enrolment number. List the courses in the current semester
 * IF enrolment number is not present it will alert. 
 */
void current_courses()
{
    FILE *file_pointer;
    char enrol_no[10];
    int found = 0, index = -1, max_ind = -1;
    struct students mca_students[6], mca_student;
    printf("Enter roll number of student:"); 
    scanf("%s",enrol_no); 
    /* opening a file in read mode */
    file_pointer=fopen("student.dat","r");
    /* reading from a file and writing on the screen */
    while(!feof(file_pointer))
    {
        fread(&mca_student,sizeof(struct students),1,file_pointer);
        if (strcmp(mca_student.reg_no, enrol_no) == 0)
        {
            found = 1;
            index = mca_student.semester - 1;
            mca_students[index] = mca_student;
            if (max_ind <= index)
            {
                max_ind = index;
            }
        }
        
    }
    if (found == 1 )
    {
        printf("COURSES IN THE CURRENT SEMESTER\n");
        printf("The following courses are studied in current Semester\n");
        for (int j = 0; j < 7; j++)
        {
            /* as in data file if there is no course corresponding to a course code 
             * is not present it is defined as NA. Hence only the courses which are not NA
             * are considered.
             */
            if (strcmp(mca_students[max_ind].course_name[j], "NA") != 0)
            {
                printf("%d. MCS-0%d%d: %s\n\n\n",j+1, mca_students[max_ind].semester, j+1, mca_students[max_ind].course_name[j]);
            }
        }
    }
    else
    {
        /* alerting when the enrolment no. not found */
        printf("Enrolment number seems to be Invalid. Not found\n\n\n");
    }
    fclose(file_pointer);   
}

void assignment_schdeule()
{
    printf("ASSIGNMENT SUBMISSION SCHEDULE\n");
    printf("For June batch the last date of assigment submission: October 31\n");
    printf("For January batch the last date of assigment submission: March 31\n");
}

void marks_of_assignment()
{
    FILE *file_pointer;
    char enrol_no[10];
    int found = 0, index = -1, max_ind = -1;
    struct students mca_students[6], mca_student;
    printf("Enter roll number of student:"); 
    scanf("%s",enrol_no); 
    /* opening a file in read mode */
    file_pointer=fopen("student.dat","r");
    /* reading from a file and writing on the screen */
    while(!feof(file_pointer))
    {
        fread(&mca_student,sizeof(struct students),1,file_pointer);
        if (strcmp(mca_student.reg_no, enrol_no) == 0)
        {
            found = 1;
            index = mca_student.semester - 1;
            mca_students[index] = mca_student;
            if (max_ind <= index)
            {
                max_ind = index;
            }
        }
        
    }
    if (found == 1 )
    {
        printf("ASSIGNMENT MARKS\n");
        printf("Student Name: %s \t Enrolment No.: %s\n",mca_students[max_ind].name,  mca_students[max_ind].reg_no);
        /*getting marks for each semester*/
        for (int i = 0; i < max_ind + 1; i++ )
        {
            printf("Semester: %d\n", mca_students[i].semester);
            /*getting marks for each course*/
            for (int j = 0; j < 7; j++)
            {
                /* as in data file if there is no course corresponding to a course code 
                * is not present it is defined as NA. Hence only the courses which are not NA
                * are considered.
                */
                if (strcmp(mca_students[i].course_name[j], "NA") != 0)
                {
                    printf("%d. MCS-0%d%d: %s: %.2f\n",j+1, mca_students[i].semester, j+1, mca_students[i].course_name[j], mca_students[i].assignment_marks[j]);
                }
            }
        }
        printf("\n\n");

    }
    else
    {
        printf("Enrolment number seems to be Invalid. Not found\n\n\n");
    }
    fclose(file_pointer);   
}

void marks_of_tee()
{
    FILE *file_pointer;
    char enrol_no[10];
    int found = 0, index = -1, max_ind = -1;
    struct students mca_students[6], mca_student;
    printf("Enter roll number of student:"); 
    scanf("%s",enrol_no); 
    /* opening a file in read mode */
    file_pointer=fopen("student.dat","r");
    /* reading from a file and writing on the screen */
    while(!feof(file_pointer))
    {
        fread(&mca_student,sizeof(struct students),1,file_pointer);
        if (strcmp(mca_student.reg_no, enrol_no) == 0)
        {
            found = 1;
            index = mca_student.semester - 1;
            mca_students[index] = mca_student;
            if (max_ind <= index)
            {
                max_ind = index;
            }
        }
        
    }
    if (found == 1 )
    {
        printf("TERM END EXAMINATION MARKS\n");
        printf("Student Name: %s \t Enrolment No.: %s\n",mca_students[max_ind].name,  mca_students[max_ind].reg_no);
        /*getting marks for each semester*/
        for (int i = 0; i < max_ind + 1; i++ )
        {
            printf("Semester: %d\n", mca_students[i].semester);
            /*getting marks for each course*/
            for (int j = 0; j < 7; j++)
            {
                 /* as in data file if there is no course corresponding to a course code 
                * is not present it is defined as NA. Hence only the courses which are not NA
                * are considered.
                */
                if (strcmp(mca_students[i].course_name[j], "NA") != 0)
                {
                    printf("%d. MCS-0%d%d: %s: %.2f\n",j+1, mca_students[i].semester, j+1, mca_students[i].course_name[j], mca_students[i].tee_marks[j]);
                }
            }
        }
        printf("\n\n");

    }
    else
    {
        printf("Enrolment number seems to be Invalid. Not found\n\n\n");
    }
    fclose(file_pointer);   
}

int main()
{
    int choice; 
    do
    {
        
        printf("===========================MENU===========================\n");
        printf("1. Registration Status\n");
        printf("2. Courses in the Current Semester\n");     
        printf("3. Assignment Submission Schedules\n");
        printf("4. Assignment Marks\n");          
        printf("5. Term End Exam Marks\n");  
        printf("6. Exit\n"); 
        printf("Enter your choice:"); 
        scanf(" %d", &choice);
        switch(choice)
        {
            case 1: registration_status();
                    break;
            case 2: current_courses();
                    break;                    
            case 3: assignment_schdeule();
                    break;     
            case 4: marks_of_assignment();
                    break;
            case 5: marks_of_tee();
                    break;                    
            case 6: printf("Exiting");
                    break; 
            default: printf("Invalid entry. Try again");
        }

    } while (choice != 6); 
    return 0;
}
