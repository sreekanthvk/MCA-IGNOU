/* A program to search a given string among the available strings, 
 * using Binary Search.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int num_of_strings, low,high,mid;
    char string_list[50][50],search_string[50];
    printf("Enter the number of strings to be added\n");
    scanf("%d",&num_of_strings);
    printf("Enter the strings\n");
    for(int i = 0; i < num_of_strings; i++)
    {
    scanf("%s",&string_list[i]);
    }
    printf("\n");
    printf("Enter the string to be searched\n");
    scanf("%s",&search_string);

    low=0;
    high=num_of_strings-1;
    while( low <= high )
    {
		mid=(low+high)/2;
		if (strcmp(search_string,string_list[mid])==0)
		{
			printf("key found at the position %d\n",mid+1);
			exit(0);
		}
		else if(strcmp(search_string,string_list[mid])>0)
		{
			high=high;
			low=mid+1;
		}
		else
		{
			low=low;
			high=mid-1;
		}
    }
    printf("String not found\n");
    return 0;
 }
