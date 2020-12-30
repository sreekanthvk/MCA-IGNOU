#include<stdio.h>
#include<string.h>

/* Structure Declaration */
struct worker
{
    char name[50];
    int hours;
    int wages;
};

int main()
{
    char date[12];
    /* Structure Array Declaration */
    char worker_name[50];
    
    struct worker contract_worker[7];
        
    printf("\n Enter the Date [DD-MM-YYYY] : ");
    fgets(date, 12, stdin);
    /* Input Total Working Hours for each Worker */
    for(int i=0; i<7; i++)
    {
        printf("Enter the name of the worker %d: ", i + 1);
        fgets(worker_name, 50, stdin);
        strcpy(contract_worker[i].name, worker_name);
        do
        {
            printf("\n Enter the total working hours of %s : ",contract_worker[i].name);
            scanf(" %d",&contract_worker[i].hours);
            if(contract_worker[i].hours <= 4)
            {
                contract_worker[i].wages = contract_worker[i].hours * 100;
            }
            else
            {
                printf("\n Wrong Input - Allow maximum upto 4 Hours per day for each Worker");
            }
        } while(contract_worker[i].hours > 4);
    }

    /* Display the Wages pay to each Worker */
    printf("\n\n\n Date - %s", date);
    for(int i=0; i<7; i++)
    {
        printf("\n\n Name - %s", contract_worker[i].name);
        printf("\n Wages - %d", contract_worker[i].wages);
    }
    return 0;
}
