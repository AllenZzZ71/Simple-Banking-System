#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool accountValidation(char* accountName, int* accountRow);
bool passwordValidation(char* password, int* accountRow);
bool deposit(int* accountRow);
bool withdrawl(int* accountRow);
int mainOperatingSystem(int* accountRow);
void signup(void);
void getStatus(int* accountRow);
void nameChange(char* accountName);
void passwordChange(char* accountName);

int main(void)
{
   char* accountName = (char*)malloc(sizeof(char) * 16);
   char* accountPassword = (char*)malloc(sizeof(char) * 36);
   int accountRow;
   int option = 0;

   printf("\n\nWelcome to my Banking System!\n");
   while(1)
   {
       accountRow = 0;
       printf("\nPlease enter your account name: ");
       scanf("%s", accountName);
       if(accountValidation(accountName, &accountRow) != true)
       {
           option = 0;
           printf("\nThe account you entered has not been found in the data base, would you like to retry or sign-up for a new account?\n\n1. Retry\n2. Sign up\n3. Exit\n\n");
           while(scanf("%d", &option) != 1)
           {
               printf("\nWrong operation number, please re-enter a correct operation number.    ");
               continue;
           }
           switch(option)
           {
                case 1:
                    break;
                case 2:
                    signup();
                    break;
                case 3:
                    free(accountName);
                    free(accountPassword);
                    return 0;
           }
       }
       else
       {
           printf("\nWelcome %s! Please enter your password: ", accountName);
           scanf("%s", accountPassword);
           if(!passwordValidation(accountPassword, &accountRow))
           {
               option = 0;
               printf("\nThe password you have entered does not match up with the user name, would you like to retry or change your password?\n\n1. Retry\n2. Change my password\n3. Exit\n\n");
               while(scanf("%d", &option) != 1)
                {
                   printf("\nWrong operation number, please re-enter a correct operation number.    ");
                   continue;
                }
                switch(option)
                {
                case 1:
                    break;
                case 2:
                    //passwordChange();
                    break;
                case 3:
                    free(accountName);
                    free(accountPassword);
                    return 0;
                }
           }
           else
           {
               printf("\nLogin successful, welcome!\n");
               mainOperatingSystem(&accountRow);
               free(accountName);
               free(accountPassword);
               return 0;
           }
       }
   }
    free(accountName);
    free(accountPassword);
}

int mainOperatingSystem(int* accountRow)
{
    int operation = 0;
    while(true)
    {
        printf("\nPlease choose the service that you would like:\n1. Deposit\n2. withdrawl\n3. Change password\n4. Change account name\n5. Customer service\n6. Account status check\n7. Exit\n\n");
        while(scanf("%d", &operation) != 1)
        {
            printf("\nWrong Operation number, please re-enter a correct operation number.   ");
            continue;
        }
        switch(operation)
        {
            case 1:
                //deposit();
                break;
            case 2:
                //withdrawl();
                break;
            case 3:
                //passwordChange();
                break;
            case 4:
                //nameChange();
                break;
            case 5:
                printf("\nThis service is not yet avaliable, please choose other operations.\n\n");
                break;
            case 6:
                getStatus(accountRow);
                break;
            case 7:
                printf("\n\n\nThank you for using our service! Have a wonderful day!\n\n\n");
                return 0;
                break;
        }
    }
    return 0;
}

bool accountValidation(char* name, int* accountRow)
{
   FILE* accountData = fopen("accountData.csv", "r");
   char userInfo[2047];
   char* accountName = (char*)malloc(sizeof(char) * 36);
   char* pointer;
   while(fgets(userInfo, 2047, accountData) != NULL)
   {
        pointer = strtok(userInfo, ",");
        strcpy(accountName, pointer);
        if(strcmp(accountName, name) == 0)
        {
            free(accountName);
            free(pointer);
            fclose(accountData);
            return true;
        }
        else
        {
            *accountRow += 1;
            continue;
        }
   }
   free(accountName);
   free(pointer);
   fclose(accountData);
   return false;
}


bool passwordValidation(char* password, int* accountRow)
{
   FILE* accountData = fopen("accountData.csv", "r");
   char userInfo[100];
   char* accountPassword = (char*)malloc(sizeof(char) * 36);
   char* pointer;
   int row = *accountRow;
   while(fgets(userInfo, 2047, accountData) != NULL)
   {
        if(row > 0)
        {
            row--;
            continue;
        }
        pointer = strtok(userInfo, ",");
        pointer = strtok(NULL, ",");
        strcpy(accountPassword, pointer);
        if(strcmp(accountPassword, password) == 0)
        {
            free(accountPassword);
            fclose(accountData);
            return true;
        }
        else
        {
            free(accountPassword);
            fclose(accountData);
            return false;
        }
   }
   free(accountPassword);
   fclose(accountData);
   return false;
}

void signup(void)
{
    FILE* accountData = fopen("accountData.csv", "a");
    char* accountName = (char*)malloc(sizeof(char) * 16);
    char* accountPassword = (char*)malloc(sizeof(char) * 36);
    
    printf("\nPlease create a user name: ");
    scanf("%15s", accountName);
    printf("\nPlease create a password: ");
    scanf("%35s", accountPassword);

    fprintf(accountData, "%s %s 0\n", accountName, accountPassword);
    free(accountName);
    free(accountPassword);
    fclose(accountData);
    printf("\nSigned up complete! Processing to the login page...\n\n\n");
}

bool deposit(int* accountRow)
{
    FILE* accountData = fopen("accountData.csv", "r");
    char userInfo[2047];
    int balance = 0;
    int amount = 0;
  //  while(fgets(userInfo, 2047, accountData))
   // {
   //    if(strstr(userInfo, accountName))
   //    {
  // //        sscanf(userInfo, "%*s %*s %d", &balance);
    //   }
    //   break;
   // }
    printf("Please enter the amount of money being deposited:   ");
    scanf("%d", &amount);
    fclose(accountData);
    return true;
}

bool withdrawl(int* accountRow)
{
    return true;
}

void getStatus(int* accountRow)
{
    FILE* accountData = fopen("accountData.csv", "r");
    char userInfo[2047];
    char* accountName = (char*)malloc(sizeof(char) * 16);
    char* accountPassword = (char*)malloc(sizeof(char) * 36);
    int row = *accountRow;
    int balance = 0;
    char* pointer;
    while(fgets(userInfo, 2047, accountData) != NULL)
    {
        pointer = strtok(userInfo, ",");
        strcpy(accountName, pointer);
        if(row > 0)
        {
            row--;
            continue;
        }
        pointer = strtok(NULL, ",");
        strcpy(accountPassword, pointer);
        pointer = strtok(NULL, ",");
        balance = atoi(pointer);
        break;
    }
    printf("\nHello, %s!", accountName);
    printf("\nYour password is: %s", accountPassword);
    printf("\n\nYour balance is: %d", balance);
    printf("\n\n\n\n\n\nEnter any number to continue.        ");
    scanf("%*d");
    free(accountPassword);
    fclose(accountData);
}

void nameChange(char* accountName)
{

}

void passwordChange(char* accountName)
{

}
