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

int main()
{
    char response = 'N';
    int choice; 
    do
    {
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
                case 1: printf("Status");
                        break;
                case 2: printf("Courses");
                        break;                    
                case 3: printf("Courses");
                        break;     
                case 4: printf("Status");
                        break;
                case 5: printf("Courses");
                        break;                    
                case 6: printf("Courses");
                        break; 
                default: printf("Invalid entry. Try again");
            }

        } while (choice < 1 || choice > 6); 
        printf("Do you want to continue? (Y for continue, any other key for exit)\n");
        scanf(" %c", &response);
    }while(response == 'Y' || response == 'y');
    return 0;
}
