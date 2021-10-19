int isFileExist(char *fileName);

int newUser(char *username, char *password);

int createNewFile(char *fullPath, char *password);

int logIn(char *username, char *password);

int checkPassword(char *fullPath, char *password);

int isContinue(char c);

int printGetContinue(char c);

void loggedMenu(char *username);

int newPhoneBook(char *username);

void phoneBookCheckAndCreate(char *userName);

int checkPhoneBook(char *userName);

void savedPhones(char *userName);

void newPhone(char *userName, char *name, char *phoneNumber);