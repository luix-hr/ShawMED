#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_USERS 100
#define MAX_TYPE_LENGTH 100
#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50
#define MAX_CPF_LENGTH 11

typedef struct
{
    char type[MAX_TYPE_LENGTH];
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char cpf[MAX_CPF_LENGTH];
} User;

User users[MAX_USERS];
int numUsers = 0;

void loadUsers()
{
    FILE *file = fopen("users.txt", "r");
    if (file != NULL)
    {
        while (fscanf(file, "%s %s %s %s", users[numUsers].type, users[numUsers].username, users[numUsers].password, users[numUsers].cpf) == 4)
        {
            numUsers++;
        }
        fclose(file);
    }
}

void saveUsers()
{
    FILE *file = fopen("users.txt", "w");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    for (int i = 0; i < numUsers; i++)
    {
        fprintf(file, "%s %s %s %s\n", users[i].type, users[i].username, users[i].password, users[i].cpf);
    }
    fclose(file);
}

int isUserRegistered(char *type, char *username, char *password)
{
    for (int i = 0; i < numUsers; i++)
    {
        if (strcmp(users[i].type, type) == 0 && strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0)
        {
            return 1; // Usuário encontrado
        }
    }
    return 0; // Usuário não encontrado
}

int isCPFRegistered(char *cpf)
{
    for (int i = 0; i < numUsers; i++)
    {
        if (strcmp(users[i].cpf, cpf) == 0)
        {
            return 1; // CPF encontrado
        }
    }
    return 0; // CPF não encontrado
}

void boasVindas()
{
    printf("*  ___  _                __ __  ___  ___ *\n");
    printf("* / __>| |_  ___  _ _ _ |  \\  \\| __>| . \\*\n");
    printf("* \\__ \\| . |<_> || | | ||     || _> | | |*\n");
    printf("* <___/|_|_|<___||__/_/ |_|_|_||___>|___/*\n");
    printf("                 Bem-vindo!\n");
    printf("-------------------------------------------\n");
    printf("       Seu consultorio medico online.\n");
}

int loginAdmin()
{
    char type[MAX_TYPE_LENGTH] = "ADMIN";
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char cpf[MAX_CPF_LENGTH];
    char choice;

    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    if (isUserRegistered(type, username, password))
    {
        printf("Login bem-sucedido como Admin");
        return 1;
    }
    else
    {
        printf("Usuário não cadastrado.\n");
        printf("Deseja realizar o cadastro? (s/n): ");
        scanf(" %c", &choice);
        if (choice == 's' || choice == 'S')
        {
            printf("Digite seu CPF: ");
            scanf("%s", cpf);

            if (isCPFRegistered(cpf))
            {
                printf("CPF já cadastrado!\n");
                return 0;
            }

            strcpy(users[numUsers].type, type);
            strcpy(users[numUsers].username, username);
            strcpy(users[numUsers].password, password);
            strcpy(users[numUsers].cpf, cpf);
            numUsers++;

            saveUsers();

            printf("Cadastro realizado com sucesso!\n");
            return 0;
        }
        else
        {
            printf("Operação finalizada.\n");
            return 0;
        }
    }
}

int loginMedico()
{
    char type[MAX_TYPE_LENGTH] = "MEDICO";
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char cpf[MAX_CPF_LENGTH];
    char choice;

    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    if (isUserRegistered(type, username, password))
    {
        printf("Login bem-sucedido como Medico");
        return 1;
    }
    else
    {
        printf("Usuário não cadastrado.\n");
        printf("Deseja realizar o cadastro? (s/n): ");
        scanf(" %c", &choice);
        if (choice == 's' || choice == 'S')
        {
            printf("Digite seu CPF: ");
            scanf("%s", cpf);

            if (isCPFRegistered(cpf))
            {
                printf("CPF já cadastrado!\n");
                return 0;
            }

            strcpy(users[numUsers].type, type);
            strcpy(users[numUsers].username, username);
            strcpy(users[numUsers].password, password);
            strcpy(users[numUsers].cpf, cpf);
            numUsers++;

            saveUsers();

            printf("Cadastro realizado com sucesso!\n");
            return 0;
        }
        else
        {
            printf("Operação finalizada.\n");
            return 0;
        }
    }
}

int loginAtendente()
{
    char type[MAX_TYPE_LENGTH] = "ATENDENTE";
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char cpf[MAX_CPF_LENGTH];
    char choice;

    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    if (isUserRegistered(type, username, password))
    {
        printf("Login bem-sucedido como Atendente");
        return 1;
    }
    else
    {
        printf("Usuário não cadastrado.\n");
        printf("Deseja realizar o cadastro? (s/n): ");
        if (choice == 's' || choice == 'S')
        {
            printf("Digite seu CPF: ");
            scanf("%s", cpf);

            if (isCPFRegistered(cpf))
            {
                printf("CPF já cadastrado!\n");
                return 0;
            }
            
            strcpy(users[numUsers].type, type);
            strcpy(users[numUsers].username, username);
            strcpy(users[numUsers].password, password);
            strcpy(users[numUsers].cpf, cpf);
            numUsers++;

            saveUsers();

            printf("Cadastro realizado com sucesso!\n");
            return 0;
        }
        else
        {
            printf("Operação finalizada.\n");
            return 0;
        }
    }
}

int main()
{

    setlocale(LC_ALL, "Portuguese");
    loadUsers();
    boasVindas();

    int choice;
    int login;

    printf("Escolha o tipo de usuário:\n");
    printf("1. Admin\n");
    printf("2. Médico\n");
    printf("3. Atendente\n");
    printf("Opção: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        loginAdmin();
        login = loginAdmin();
        if (login != 0)
        {
            printf("\nTela ADMIN");
        }else{
            loginAdmin();
        }
        break;
    case 2:
        loginMedico();
        break;
    case 3:
        loginAtendente();
        break;
    default:
        printf("Opção inválida!\n");
    }
}