#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

#define MAX_PACIENTES 100
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

Paciente paciente[MAX_PACIENTES];
int numPacientes = 0;

void carregarUsers()
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

void salvarUsers()
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

int verificarUser(char *type, char *username, char *password)
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

int verificarCPFUsers(char *cpf)
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

    if (verificarUser(type, username, password))
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

    if (verificarUser(type, username, password))
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

    if (verificarUser(type, username, password))
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

    if (verificarCPFUsers(cpf))
    {
        printf("CPF já cadastrado!\n");
        return;
    }

    strcpy(users[numUsers].type, type);
    strcpy(users[numUsers].username, username);
    strcpy(users[numUsers].password, password);
    strcpy(users[numUsers].cpf, cpf);
    numUsers++;

    salvarUsers();

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

    if (verificarCPFUsers(cpf))
    {
        printf("CPF já cadastrado!\n");
        return;
    }

    strcpy(users[numUsers].type, type);
    strcpy(users[numUsers].username, username);
    strcpy(users[numUsers].password, password);
    strcpy(users[numUsers].cpf, cpf);
    numUsers++;

    salvarUsers();

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

    if (verificarCPFUsers(cpf))
    {
        printf("CPF já cadastrado!\n");
        return;
    }

    strcpy(users[numUsers].type, type);
    strcpy(users[numUsers].username, username);
    strcpy(users[numUsers].password, password);
    strcpy(users[numUsers].cpf, cpf);
    numUsers++;

    salvarUsers();

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

    char escolha;
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
        scanf(" %c", &escolha);
        paciente.haveHealthPlan = (escolha == 's' || escolha == 'S');

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
        numPacientes++;

        printf("Deseja cadastrar outro paciente? (s/n): ");
        scanf(" %c", &escolha);
        getchar();

    } while (escolha == 's' || escolha == 'S');

    fclose(file);
}

int verificarCPFPacientes(Paciente *paciente, int numPacientes, char *cpf)
{
    for (int i = 0; i < numPacientes; i++)
    {
        if (strcmp(paciente[i].cpf, cpf) == 0)
        {
            return 1;
        }
    }
    return 0;
}

void listarDadosPaciente()
{
    FILE *file = fopen("pacientes.txt", "r");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    Paciente paciente;

    char cpf[MAX_CPF_LENGTH];
    printf("Digite o CPF do paciente que deseja verificar: ");
    scanf("%s", cpf);

    int encontrado = 0;

    while (fscanf(file, "%[^,],%[^,],%d,%c,%[^,],%[^,],%lf,%lf,%d\n",
                  paciente.nomeCompleto,
                  paciente.cpf,
                  &paciente.idade,
                  &paciente.genero,
                  paciente.telefone,
                  paciente.estadoCivil,
                  &paciente.peso,
                  &paciente.altura,
                  &paciente.haveHealthPlan) == 9)
    {
        if (strcmp(cpf, paciente.cpf) == 0)
        {
            encontrado = 1;
            printf("\n--- Dados do Paciente ---\n");
            printf("Nome Completo: %s\n", paciente.nomeCompleto);
            printf("CPF: %s\n", paciente.cpf);
            printf("Idade: %d\n", paciente.idade);
            printf("Gênero: %c\n", paciente.genero);
            printf("Telefone: %s\n", paciente.telefone);
            printf("Estado Civil: %s\n", paciente.estadoCivil);
            printf("Peso: %.2f kg\n", paciente.peso);
            printf("Altura: %.2f cm\n", paciente.altura);
            printf("Possui plano de saúde? %s\n", paciente.haveHealthPlan ? "Sim" : "Não");
            break;
        }
    }

    if (!encontrado)
    {
        printf("Paciente não encontrado.\n");
    }

    fclose(file);

    char escolha;
    printf("Deseja pesquisar outro paciente? (s/n): ");
    scanf(" %c", &escolha);

    if (escolha == 's' || escolha == 'S')
    {
        listarDadosPaciente();
    }
}

void agendarConsultaPaciente()
{
    FILE *filePacientes = fopen("pacientes.txt", "r");
    if (filePacientes == NULL)
    {
        printf("Erro ao abrir o arquivo de pacientes.\n");
        return;
    }

    FILE *fileMedicos = fopen("medicos.txt", "r");
    if (fileMedicos == NULL)
    {
        printf("Erro ao abrir o arquivo de médicos.\n");
        fclose(filePacientes);
        return;
    }

    char cpf[MAX_CPF_LENGTH];
    printf("Digite o CPF do paciente para agendar a consulta: ");
    scanf("%s", cpf);

    int encontradoPaciente = 0;
    Paciente paciente;

    while (fscanf(filePacientes, "%[^,],%[^,],%d,%c,%[^,],%[^,],%lf,%lf,%d\n",
                  paciente.nomeCompleto,
                  paciente.cpf,
                  &paciente.idade,
                  &paciente.genero,
                  paciente.telefone,
                  paciente.estadoCivil,
                  &paciente.peso,
                  &paciente.altura,
                  &paciente.haveHealthPlan) == 9)
    {
        if (strcmp(cpf, paciente.cpf) == 0)
        {
            encontradoPaciente = 1;
            printf("\n--- Dados do Paciente ---\n");
            printf("Nome Completo: %s\n", paciente.nomeCompleto);
            printf("CPF: %s\n", paciente.cpf);
            printf("Idade: %d\n", paciente.idade);
            printf("Gênero: %c\n", paciente.genero);
            printf("Telefone: %s\n", paciente.telefone);
            printf("Estado Civil: %s\n", paciente.estadoCivil);
            printf("Peso: %.2f kg\n", paciente.peso);
            printf("Altura: %.2f cm\n", paciente.altura);
            printf("Possui plano de saúde? %s\n", paciente.haveHealthPlan ? "Sim" : "Não");
            break;
        }
    }

    fclose(filePacientes);

    if (!encontradoPaciente)
    {
        printf("Paciente não encontrado.\n");
        fclose(fileMedicos);
        return;
    }

    char nomeMedico[MAX_NAME_LENGTH];
    char especialidade[MAX_NAME_LENGTH];
    char dataConsulta[MAX_NAME_LENGTH];

    int encontradoMedico = 0;

    printf("\n--- Escolha o Médico e informe a data da consulta ---\n");

    while (fscanf(fileMedicos, "%s %s", nomeMedico, especialidade) == 2)
    {
        printf("Nome do Médico: %s\n", nomeMedico);
        printf("Especialidade: %s\n", especialidade);
        printf("Data da Consulta (DD/MM/AAAA): ");
        scanf("%s", dataConsulta);

        encontradoMedico = 1;

        FILE *fileAgendamentos = fopen("agendamentos.txt", "a");
        if (fileAgendamentos == NULL)
        {
            printf("Erro ao abrir o arquivo de agendamentos.\n");
            fclose(fileMedicos);
            return;
        }

        fprintf(fileAgendamentos, "%s;%s;%s\n", paciente.nomeCompleto, nomeMedico, dataConsulta);

        fclose(fileAgendamentos);

        printf("Consulta agendada com sucesso!\n");
        printf("--------------------------------------\n");
        printf("Deseja agendar outra consulta? (s/n): ");
        char escolha;
        scanf(" %c", &escolha);
        if (escolha == 'n' || escolha == 'N')
        {
            break;
        }
    }

    fclose(fileMedicos);

    if (!encontradoMedico)
    {
        printf("Nenhum médico cadastrado.\n");
        return;
    }
}

int main()
{

    carregarUsers();
    boasVindas();

    int escolha;

    do
    {
        int login;

        printf("\nEscolha o tipo de usuário:\n");
        printf("1. Admin\n");
        printf("2. Médico\n");
        printf("3. Atendente\n");
        printf("4. Sair\n");
        printf("Opção: ");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            login = loginAdmin();
            if (login != 0)
            {
                printf("\n--- TELA ADMIN ---\n");
                cadastrarAtendente();
            }
            else
            {
                escolha = 1;
            }
            break;
        case 2:
            login = loginMedico();
            if (login != 0)
            {
                printf("\n--- TELA MEDICO ---\n");
            }
            else
            {
                escolha = 1;
            }
            break;

        case 3:
            login = loginAtendente();
            if (login != 0)
            {
                printf("\n--- TELA ATENDENTE ---\n");
                agendarConsultaPaciente();
                listarDadosPaciente();
            }
            else
            {
                escolha = 1;
            }
            break;

        case 4:
            printf("Saindo..");
            break;

        default:
            printf("Opção inválida!\n");
        }
    } while (escolha != 4);
}