#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include "pro.h" //prototypes

void printMenu();

int main()
{

    char userName[100];

    char passWord[100];

    char name[100];

    char number[100];

    int iChoice = 0;

    int iLoggedChoice = 0;

    char cContinue = 0;

    char cLoggedContinue = 0;

    do
    {

        cLoggedContinue = 0;
        cContinue = 0;

        system("cls");

        printMenu();

        scanf("%d", &iChoice);

        switch (iChoice)
        {
        case 1:
            printf(" -- Enter user: ");

            scanf("%s", &userName);

            printf(" -- Enter pass: ");

            scanf("%s", &passWord);

            if (newUser(userName, passWord))
            {
                printf("Succesfully reg.");
            }
            else
            {
                printf("Username is already taken.");
            }
            break;
        case 2:
            printf(" -- Enter user: ");

            scanf("%s", &userName);

            printf(" -- Enter pass: ");

            scanf("%s", &passWord);

            if (logIn(userName, passWord))
            {

                while (cLoggedContinue != 'n' && cLoggedContinue != 'N')
                {
                    system("cls");

                    loggedMenu(userName);

                    scanf("%d", &iLoggedChoice);

                    if (iLoggedChoice == 1)
                    {
                        phoneBookCheckAndCreate(userName);
                    }
                    else if (iLoggedChoice == 2)
                    {
                        if (!checkPhoneBook(userName))
                        {
                            printf("\n -- Please first create your own phonebook. -- \n");
                        }
                        else
                        {
                            printf(" -- Enter name: ");
                            scanf("%s", &name);
                            printf(" -- Enter number: ");
                            scanf("%s", &number);
                            newPhone(userName, name, number);
                        }
                    }
                    else if (iLoggedChoice == 3)
                    {
                        if (!checkPhoneBook(userName))
                        {
                            printf("\n -- Please first create your own phonebook. -- \n");
                        }
                        else
                        {
                            savedPhones(userName);
                        }
                    }

                    printf(" -- Do you want to stay in your account, %s? [y/n]: ", userName);

                    scanf("%s", &cLoggedContinue);
                }
            }
            else
            {
                printf("Wrong username or password.");
            }
            break;
        default:
            break;
        }

        if (iChoice == 0 || !printGetContinue(cContinue))
        {
            break;
        }
    } while (iChoice != 0);

    return 0;
}

void printMenu()
{
    printf("\n\n      -- PHONE BOOK -- \n\n");
    printf("  -- Enter 1 for register.\n");
    printf("  -- Enter 2 for log IN\n");
    printf("  -- Enter 0 for quit\n\n");
    printf("  -- Enter choice: ");
}