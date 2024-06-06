#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>

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

#define MAX_NAME_LENGTH 100
#define MAX_PHONE_LENGTH 15
#define MAX_STATUS_LENGTH 20

typedef struct
{
    char nomeCompleto[MAX_NAME_LENGTH];
    char cpf[MAX_CPF_LENGTH];
    int idade;
    char genero;
    char telefone[MAX_PHONE_LENGTH];
    char estadoCivil[MAX_STATUS_LENGTH];
    float peso;
    float altura;
    bool haveHealthPlan;

} Paciente;

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

    system("cls");
    printf("\n--- FAÇA SEU LOGIN ---\n");

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
        return 0;
    }
}

int loginMedico()
{
    char type[MAX_TYPE_LENGTH] = "MEDICO";
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char cpf[MAX_CPF_LENGTH];

    system("cls");
    printf("\n--- FAÇA SEU LOGIN ---\n");

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
        printf("Solicite o casdastro ao ADMIN!!");

        return 0;
    }
}

int loginAtendente()
{
    char type[MAX_TYPE_LENGTH] = "ATENDENTE";
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char cpf[MAX_CPF_LENGTH];

    system("cls");
    printf("\n--- FAÇA SEU LOGIN ---\n");

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
        printf("Solicite o casdastro ao ADMIN!!");

        return 0;
    }
}

void cadastrarMedico()
{
    char type[MAX_TYPE_LENGTH] = "MEDICO";
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char cpf[MAX_CPF_LENGTH];

    system("cls");
    printf("\n--- CADASTRO DE MEDICOS ---\n");

    printf("Digite seu USUARIO: ");
    scanf("%s", username);
    printf("Digite sua SENHA: ");
    scanf("%s", password);
    printf("Digite seu CPF: ");
    scanf("%s", cpf);

    if (isCPFRegistered(cpf))
    {
        printf("CPF já cadastrado!\n");
        return;
    }

    strcpy(users[numUsers].type, type);
    strcpy(users[numUsers].username, username);
    strcpy(users[numUsers].password, password);
    strcpy(users[numUsers].cpf, cpf);
    numUsers++;

    saveUsers();

    printf("Cadastro realizado com sucesso!\n");
}

void cadastrarAtendente()
{
    char type[MAX_TYPE_LENGTH] = "ATENDENTE";
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char cpf[MAX_CPF_LENGTH];

    system("cls");
    printf("\n--- CADASTRO DE ATENDENTE ---\n");

    printf("Digite seu USUARIO: ");
    scanf("%s", username);
    printf("Digite sua SENHA: ");
    scanf("%s", password);
    printf("Digite seu CPF: ");
    scanf("%s", cpf);

    if (isCPFRegistered(cpf))
    {
        printf("CPF já cadastrado!\n");
        return;
    }

    strcpy(users[numUsers].type, type);
    strcpy(users[numUsers].username, username);
    strcpy(users[numUsers].password, password);
    strcpy(users[numUsers].cpf, cpf);
    numUsers++;

    saveUsers();

    printf("Cadastro realizado com sucesso!\n");
}

void cadastrarAdmin()
{
    char type[MAX_TYPE_LENGTH] = "ADMIN";
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char cpf[MAX_CPF_LENGTH];

    system("cls");
    printf("\n--- CADASTRO DE ADMIN ---\n");

    printf("Digite seu USUARIO: ");
    scanf("%s", username);
    printf("Digite sua SENHA: ");
    scanf("%s", password);
    printf("Digite seu CPF: ");
    scanf("%s", cpf);

    if (isCPFRegistered(cpf))
    {
        printf("CPF já cadastrado!\n");
        return;
    }

    strcpy(users[numUsers].type, type);
    strcpy(users[numUsers].username, username);
    strcpy(users[numUsers].password, password);
    strcpy(users[numUsers].cpf, cpf);
    numUsers++;

    saveUsers();

    printf("Cadastro realizado com sucesso!\n");
}

void cadastrarPaciente()
{
    FILE *file = fopen("pacientes.txt", "a");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    char choice;
    do
    {
        Paciente paciente;

        printf("Nome Completo: ");
        scanf("%s", paciente.nomeCompleto);

        printf("CPF: ");
        scanf("%s", paciente.cpf);

        printf("Idade: ");
        scanf("%d", &paciente.idade);

        printf("Gênero (M/F): ");
        scanf(" %c", &paciente.genero);

        printf("Telefone: ");
        scanf("%s", paciente.telefone);

        printf("Estado Civil: ");
        scanf("%s", paciente.estadoCivil);

        printf("Peso (kg): ");
        scanf("%f", &paciente.peso);

        printf("Altura (cm): ");
        scanf("%f", &paciente.altura);

        printf("Possui plano de saúde? (s/n): ");
        scanf(" %c", &choice);
        paciente.haveHealthPlan = (choice == 's' || choice == 'S');

        fprintf(file, "%s,%s,%d,%c,%s,%s,%.2f,%.2f,%s\n",
                paciente.nomeCompleto,
                paciente.cpf,
                paciente.idade,
                paciente.genero,
                paciente.telefone,
                paciente.estadoCivil,
                paciente.peso,
                paciente.altura,
                paciente.haveHealthPlan ? "Sim" : "Não");

        printf("Paciente cadastrado com sucesso!\n");

        printf("Deseja cadastrar outro paciente? (s/n): ");
        scanf(" %c", &choice);
        getchar(); // Limpar o buffer de entrada

    } while (choice == 's' || choice == 'S');

    fclose(file);
}

int main()
{

    setlocale(LC_ALL, "Portuguese");
    loadUsers();
    boasVindas();

    int choice;

    do
    {
        int login;

        printf("\nEscolha o tipo de usuário:\n");
        printf("1. Admin\n");
        printf("2. Médico\n");
        printf("3. Atendente\n");
        printf("4. Sair\n");
        printf("Opção: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            login = loginAdmin();
            if (login != 0)
            {
                printf("\n--- TELA ADMIN ---\n");
                cadastrarMedico();
            }
            else{
                choice = 1;
            }
            break;
        case 2:
            login = loginMedico();
            if (login != 0)
            {
                printf("\n--- TELA MEDICO ---\n");
            }
            else{
                choice = 1;
            }
            break;

        case 3:
            login = loginAtendente();
            if (login != 0)
            {
                printf("\n--- TELA ATENDENTE ---\n");
            }
            else{
                choice = 1;
            }
            break;

        case 4:
            printf("Saindo..");
            break;

        default:
            printf("Opção inválida!\n");
        }
    } while (choice != 4);
}