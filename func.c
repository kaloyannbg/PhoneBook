#include <stdio.h>
#include <string.h>
#include "pro.h" //prototypes

/*
 for(int i = 0; username[i] != '\0'; i++) {
        if(!isDigit(username[i])) {
            return 0; //if return 0 your newNumber have symbols
        }
    }
*/

void newPhone(char *userName, char *name, char *phoneNumber)
{

    char fullPath[100] = "books/";

    strcat(fullPath, userName);

    strcat(fullPath, ".txt");

    FILE *fp;

    fp = fopen(fullPath, "r");

    char c = 0;
    int countNewLines = 1;
    int CountChars = 0;
    int isUserExist = 0;
    char buffer[100];

    while (c != EOF)
    {
        c = fgetc(fp);

        if (c != '\n')
        {
            buffer[CountChars] = c;
            CountChars++;
        }
        else if (c == '\n')
        {
            buffer[CountChars] = '\0';
            // printf("\n -- BUFFER %s  -- NAME %s --", buffer, name);
            // putchar('\n');

            if (strcmp(name, buffer) == 0)
            {
                isUserExist = 1;
                break;
            }
            memset(buffer, 0, 100);
            CountChars = 0;
        }
    }
    fclose(fp);
    if (isUserExist)
    {
        printf(" \n -- You cant save it. The name is already exist. -- \n");
    }
    else
    {
        fp = fopen(fullPath, "a");
        fputc('\n', fp);
        fputs(name, fp);
        fputc('\n', fp);
        fclose(fp);
        fp = fopen(fullPath, "a");
        fputs(phoneNumber, fp);
        fclose(fp);
    }
}

void savedPhones(char *userName)
{

    char fullPath[100] = "books/";

    strcat(fullPath, userName);

    strcat(fullPath, ".txt");

    FILE *fp;

    fp = fopen(fullPath, "r");

    char c = 0;
    int countNewLines = 1;

    while (c != EOF)
    {
        if (c == '\n')
        {
            if (countNewLines % 2 == 1)
            {
                printf(" -- %d. ", countNewLines);
            }
            printf(" --     ", countNewLines);

            countNewLines++;
        }
        c = fgetc(fp);
        putchar(c);
    }
    putchar('\n');
    fclose(fp);
}

int checkPhoneBook(char *userName)
{
    char fullPath[100] = "books/";

    strcat(fullPath, userName);

    strcat(fullPath, ".txt");

    if (!isFileExist(fullPath))
    {
        return 0;
    }

    return 1;
}

void phoneBookCheckAndCreate(char *userName)
{
    if (newPhoneBook(userName))
    {
        printf("\n -- Sucesfully create your phonebook -- \n");
    }
    else if (!newPhoneBook(userName))
    {
        printf("\n -- You already have phonebook -- \n");
    }
}

int newPhoneBook(char *username)
{

    char fullPath[100] = "books/";

    strcat(fullPath, username);

    strcat(fullPath, ".txt");

    if (!isFileExist(fullPath))
    {
        createNewFile(fullPath, username);
        return 1;
    }
    else if (isFileExist(fullPath))
    {
        return 0;
    }
}

void loggedMenu(char *username)
{

    printf(" -- Hello, %s --\n\n", username);
    printf(" -- Enter 1 for create my phonebook\n");
    printf(" -- Enter 2 for save new number\n");
    printf(" -- Enter 3 for check all numbers\n");
    printf(" -- Enter 0 for logout\n\n");

    printf(" -- Enter logged choice: ");
}

int printGetContinue(char c)
{
    do
    {
        printf("\n-- Do you want to continue use program? [y/n]: ");
        scanf("%s", &c);

    } while (c != 'y' && c != 'n' && c != 'Y' && c != 'N');

    return isContinue(c);
}

int isContinue(char c)
{
    if (c == 'y' || c == 'Y')
    {
        return 1;
    }
    else if (c == 'n' || c == 'N')
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

int checkPassword(char *fullPath, char *password)
{

    char buffer[100];

    FILE *fp;

    fp = fopen(fullPath, "r");

    fgets(buffer, 100, fp);

    if (strcmp(password, buffer) == 0)
    {
        return 1; // if they are equal
    }
    else
    {
        return 0; // if they are not equal
    }
}

int logIn(char *username, char *password)
{

    char fullPath[] = "users/";

    strcat(fullPath, username); // concatenation with username

    strcat(fullPath, ".txt"); // concatenation with .txt

    if (!isFileExist(fullPath))
    {
        return 0;
    }
    else if (isFileExist(fullPath))
    {
        checkPassword(fullPath, password);
    }
}

int newUser(char *username, char *password)
{

    char fullPath[] = "users/";

    strcat(fullPath, username); // concatenation with username

    strcat(fullPath, ".txt"); // concatenation with .txt

    if (isFileExist(fullPath))
    {
        return 0;
    }
    else if (!isFileExist(fullPath))
    {
        if (createNewFile(fullPath, password))
        {
            return 1;
        }
        return 0;
    }
}

int createNewFile(char *fullPath, char *password)
{
    FILE *fp;
    fp = fopen(fullPath, "w");
    // strcat(password, "/");
    fputs(password, fp);
    if (fp)
    {
        fclose(fp);
        return 1;
    }
    else
    {
        fclose(fp);
        return 0;
    }
}

int isFileExist(char *fileName)
{
    FILE *fp;
    fp = fopen(fileName, "r");
    if (fp == NULL)
    {
        fclose(fp);
        return 0;
    }
    fclose(fp);
    return 1;
}

int isDigit(char c)
{
    return (c >= '0' && c <= '9');
}