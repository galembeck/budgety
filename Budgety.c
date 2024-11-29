#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <ctype.h>

#include <unistd.h>

#include <locale.h>

#define max_char 100
#define max_employers 15

typedef struct {
	int employee_age, employee_code;
	float employee_salary, employee_work_time;
	char employee_name[max_char], employee_gender, employee_role[max_char], employee_rating;
} EmployeeData;



void companyShowcase();

void loginInformation();
void loginPage();

int optionsMenu();

void includeEmployee(EmployeeData employee_data[], int *employers_count);
void listAllEmployers(EmployeeData employee_data[], int employers_count);
void deleteEmployee(EmployeeData employee_data[], int *employers_count);
void setSalaryByRole(EmployeeData employee_data[], int employers_count);
void employersMenu();



int main() {
	setlocale(LC_ALL, "portuguese");

	EmployeeData employee_data[max_employers];
	int selected_option;

	// loginPage();

	while(1) {
		system("cls");

		selected_option = optionsMenu();

		switch(selected_option) {
			case 1:
				employersMenu();

				break;
			case 2:
				break;
			case 3:
                system("cls");

				sleep(1);

				printf("\n\t Obrigado por utilizar os serviços da \"Budgety\"!\n");

				exit(0);

			default:
				printf("\n A opção escolhida é inválida!\n\n");

				sleep(1);
				system("pause");
				system("cls");
				break;
		}
	}
}

void companyShowcase() {
   printf("\n  ******   **     ** *******     ********  ******** ********** **    **");
   printf("\n /*////** /**    /**/**////**   **//////**/**///// /////**/// //**  ** ");
   printf("\n /*   /** /**    /**/**    /** **      // /**          /**     //****  ");
   printf("\n /******  /**    /**/**    /**/**         /*******     /**      //**   ");
   printf("\n /*//// **/**    /**/**    /**/**    *****/**////      /**       /**   ");
   printf("\n /*    /**/**    /**/**    ** //**  ////**/**          /**       /**   ");
   printf("\n /******* //******* /*******   //******** /********    /**       /** ");
   printf("\n /*****/   /*****/  /*****/     /******/  /******/     /*        /*    \n\n");
}



void loginInformation() {
	companyShowcase();

	printf("\n Olá! Seja bem-vindo ao Sistema de Orçamento.");

	printf("\n\n Para acessar o painel de controle, informe seu login e senha.");
	printf("\n Há, ao total, apenas 3 tentativas para efetuar corretamente o login (após isso, o processo será cancelado).");

	printf("\n\n Informe, nos campos abaixo, o \"usuário\" e a \"senha\" corretos para acessar o painel.\n");
}

void loginPage() {
	char user[max_char];
	int password, trys = 0;

	do {
		loginInformation();

		sleep(1);

		printf("\n º Usuário: ");
		fflush(stdin);
		gets(user);

		printf(" º Senha: ");
		scanf("%d", &password);

		sleep(1);

		printf("\n Carregando");

		sleep(1);
		printf(" .");
		sleep(1);
		printf(" .");
		sleep(1);
		printf(" .\n");

		sleep(1);

		if((strcmp(user, "admin") != 0) || (password != 1234)) {
			trys++;

			printf("\n Usuário e/ou senha incorreto(s)! Restam-lhe %d tentativas...\n\n", 3-trys);

			sleep(1);
			system("pause");
			system("cls");
		}

		if(trys == 3) {
			companyShowcase();

			sleep(1);

			printf("\n Que pena! Sua tentativas de login se esgotaram :(");
			printf("\n Parece que você não conseguiu acessar o painel de controle...\n");

			sleep(1);

			exit(0);
		}
	} while((strcmp(user, "admin") != 0) || (password != 1234));

	system("cls");
}



int optionsMenu() {
	int selected_option;

	companyShowcase();

	printf("\n Olá! Seja bem-vindo ao Sistema de Orçamento da \"Budgety\".");

	printf("\n\n Abaixo, estão listadas todas as opções disponíveis para serem executadas em nosso sistema.");
	printf("\n Escolha, dentre as opções listadas abaixo (1-8), uma para ser executada a seguir.\n");

	sleep(1);

	printf("\n º Opção 1: Funcionários;");
	printf("\n º Opção 2: Insumos;");
	printf("\n º Opção 3: Sair;");

	printf("\n\n Opção: ");
	scanf("%d", &selected_option);

	return selected_option;
}



void includeEmployee(EmployeeData employee_data[], int *employers_count) {
	int i, j;
	int employers_to_include;

	char inclusion_confirmation;

	system("cls");

	do {
		companyShowcase();

		printf("\n Para incluir um funcionário no sistema, é necessário preencher algumas informações...");

		printf("\n\n Primeiramente, quantos funcionários serão incluídos no sistema? ");
		scanf("%d", &employers_to_include);

		if((employers_to_include <= 0) || (*employers_count + employers_to_include > max_employers)) {
			printf("\n O número informado de funcionários a serem incluídos é inválido!\n\n");

			sleep(1);
			system("cls");
		}
	} while((employers_to_include <= 0) || (*employers_count + employers_to_include > max_employers));

	printf("\n Ótimo! Com o número de funcionários a serem incluídos definido, podemos continuar com o processo.\n\n");

	sleep(1);
	system("pause");
	system("cls");

	EmployeeData temp_employee_data[max_employers];
	int temp_employers_count = 0;

	for(i = 0; i < employers_to_include; i++) {
		companyShowcase();

		printf("\n Agora, com o número de funcionários a serem incluídos definido, será necessário preencher alguns campos.");
		printf("\n\n Dentre as informações ncessárias, informe, abaixo, os seguintes dados:");
		printf("\n\n º Nome do funcionário;");
		printf("\n º Idade;");
		printf("\n º Sexo;");
		printf("\n º Código de identificação;");
		printf("\n º Cargo (experiência);");
		// printf("\n º Nível (experiência);");
		printf("\n º Carga horária;\n");

		sleep(1);

		printf("\n | Nome do %dº funcionário: ", i+1);
		fflush(stdin);
		fgets(temp_employee_data[temp_employers_count].employee_name, max_char, stdin);
		temp_employee_data[temp_employers_count].employee_name[strcspn(temp_employee_data[temp_employers_count].employee_name, "\n")] = '\0';

		printf("\n | Idade do %dº funcionário: ", i+1);
		scanf("%d", &temp_employee_data[temp_employers_count].employee_age);

		do {
			printf("\n | Sexo do %dº funcionário [M/F]: ", i+1);
			fflush(stdin);
			temp_employee_data[temp_employers_count].employee_gender = getchar();

			if((toupper(temp_employee_data[temp_employers_count].employee_gender) != 'M') && (toupper(temp_employee_data[temp_employers_count].employee_gender) != 'F')) {
				printf("\n O sexo informado é inválido!\n");
			}
		} while((toupper(temp_employee_data[temp_employers_count].employee_gender) != 'M') && (toupper(temp_employee_data[temp_employers_count].employee_gender) != 'F'));

		printf("\n | Código de identificação do %dº funcionário: ", i+1);
		scanf("%d", &temp_employee_data[temp_employers_count].employee_code);

		printf("\n | Cargo (experiência) do %dº funcionário: ", i+1);
		fflush(stdin);
		fgets(temp_employee_data[temp_employers_count].employee_role, max_char, stdin);
		temp_employee_data[temp_employers_count].employee_role[strcspn(temp_employee_data[temp_employers_count].employee_role, "\n")] = '\0';

		/*
		do {
			printf("\n | Nível (experiência) do %dº funcionário [J/P/S]: ", i+1);
			fflush(stdin);
			temp_employee_data[temp_employers_count].employee_rating = getchar();

			if((toupper(temp_employee_data[temp_employers_count].employee_rating) != 'J') && (toupper(temp_employee_data[temp_employers_count].employee_rating) != 'P') && (toupper(temp_employee_data[temp_employers_count].employee_rating) != 'S')) {
				printf("\n O nível (experiência) informado é inválido!\n");
			}
		} while((toupper(temp_employee_data[temp_employers_count].employee_rating) != 'J') && (toupper(temp_employee_data[temp_employers_count].employee_rating) != 'P') && (toupper(temp_employee_data[temp_employers_count].employee_rating) != 'S'));
		*/

		printf("\n | Carga horária do %dº funcionário: ", i+1);
		scanf("%f", &temp_employee_data[temp_employers_count].employee_work_time);

		temp_employers_count++;

		system("cls");
	}

	companyShowcase();

	sleep(1);

	printf("\n Ao término da inserção dos dados/informações solicitadas, confirme a inclusão dos seguintes funcionários: ");

	printf("\n\n Total de funcionários a serem incluídos: %d funcionário(s).\n", temp_employers_count);

	for(i = 0; i < temp_employers_count; i++) {
        printf("\n | Informações do \"%dº\" funcionário:", i+1);
		printf("\n   º Nome: %s", temp_employee_data[i].employee_name);
		printf("\n   º Idade: %d", temp_employee_data[i].employee_age);
		printf("\n   º Sexo: %c", toupper(temp_employee_data[i].employee_gender));
		printf("\n   º Código de identificação: %d", temp_employee_data[i].employee_code);
		printf("\n   º Cargo (experiência): %s", temp_employee_data[i].employee_role);
		// printf("\n   º Nível (experiência): %c", toupper(temp_employee_data[i].employee_rating));
		printf("\n   º Carga horária: %.2f\n", temp_employee_data[i].employee_work_time);
	}

	printf("\n Deseja confirmar a inclusão do(s) funcionário(s) listados acima? [S/n]: ");

	do {
		fflush(stdin);
		inclusion_confirmation = getchar();
	} while((toupper(inclusion_confirmation) != 'S') && (tolower(inclusion_confirmation) != 'n'));

	if(toupper(inclusion_confirmation) == 'S') {
		for(i = 0; i < temp_employers_count; i++) {
			employee_data[*employers_count] = temp_employee_data[i];
			(*employers_count)++;
		}
		printf("\n Os funcionários listados foram incluídos com sucesso!\n\n");
	}
	else {
		printf("\n A inclusão dos funcionários listados foi cancelada!\n\n");
	}

	sleep(1);
    system("pause");
    system("cls");
}

void listAllEmployers(EmployeeData employee_data[], int employers_count) {
    int i;

    system("cls");

    companyShowcase();

    printf("\n Neste painel, é possível consultar/listar todos os funcionários registrados no banco de dados do sistema.");

    printf("\n\n | Total de funcionários registrados: %d\n", employers_count);

    if(employers_count > 0) {
        for(i = 0; i < employers_count; i++) {
            printf("\n | Informações do \"%dº\" funcionário:", i+1);
            printf("\n   º Nome: %s", employee_data[i].employee_name);
            printf("\n   º Idade: %d", employee_data[i].employee_age);
            printf("\n   º Sexo: %c", toupper(employee_data[i].employee_gender));
            printf("\n   º Código de identificação: %d", employee_data[i].employee_code);
            printf("\n   º Cargo (experiência): %s", employee_data[i].employee_role);
            // printf("\n   º Nível (experiência): %c", toupper(employee_data[i].employee_rating));
            printf("\n   º Carga horária: %.2f\n", employee_data[i].employee_work_time);
        }
    } else {
        printf("\n º Não há nenhum funcionário registrado no banco de dados do sistema (sem dados para exibir)...\n");
    }

    printf("\n");
    sleep(1);
    system("pause");
    system("cls");
}

void deleteEmployee(EmployeeData employee_data[], int *employers_count) {
    int i, j, deletable_code, stored_employee = -1;
    char deletion_confirmation;

    system("cls");

    companyShowcase();

    printf("\n Neste painel, é possível excluir um determinado funcionário registrado no sistema.");

    printf("\n\n Para que um funcionário seja excluído efetivamente, é necessário que seu código seja informado.");
    printf("\n Abaixo estão listados todos os códigos dos funcionários registrados no banco de dados do sistema da \"Budgety\".");

    printf("\n\n | Total de funcionários registrados: %d funcionário(s).\n", employers_count);

    if(*employers_count > 0) {
        for(i = 0; i < *employers_count; i++) {
            printf("\n > Código do %dº funcionário: %d", i+1, employee_data[i].employee_code);
        }

        printf("\n\n º Código do funcionário (a ser excluído): ");
        scanf("%d", &deletable_code);

        for(j = 0; j < *employers_count; j++) {
            if(employee_data[j].employee_code == deletable_code) {
                stored_employee = j;
                break;
            }
        }

        if(stored_employee == -1) {
            printf("\n Nenhum funcionário com código \"%d\" foi encontrado no banco de dados do sistema.\n\n", deletable_code);

            sleep(1);
            system("pause");

            return;
        }

        system("cls");

        companyShowcase();

        printf("\n As informações do funcionário a ser excluído são:");
        printf("\n º Nome: %s", employee_data[stored_employee].employee_name);
        printf("\n º Idade: %d", employee_data[stored_employee].employee_age);
        printf("\n º Sexo: %c", toupper(employee_data[stored_employee].employee_gender));
        printf("\n º Código de identificação: %d", employee_data[stored_employee].employee_code);
        printf("\n º Cargo (experiência): %s", employee_data[stored_employee].employee_role);
        // printf("\n º Nível (experiência): %c", toupper(employee_data[stored_employee].employee_rating));
        printf("\n º Carga horária: %.2f\n", employee_data[stored_employee].employee_work_time);

        printf("\n Deseja confirmar a exclusão do funcionário listado acima? [S/n]: ");

        do {
            fflush(stdin);
            deletion_confirmation = getchar();
        } while ((toupper(deletion_confirmation) != 'S') && (tolower(deletion_confirmation) != 'n'));

        if (toupper(deletion_confirmation) == 'S') {
            for (i = stored_employee; i < *employers_count - 1; i++) {
                employee_data[i] = employee_data[i + 1];
            }
            (*employers_count)--;

            printf("\n O funcionário foi excluído com sucesso!\n\n");
        } else {
            printf("\n A exclusão do funcionário foi cancelada!\n\n");
        }

        sleep(1);
        system("pause");
    } else {
        printf("\n º Não há nenhum funcionário registrado no banco de dados do sistema (sem dados para exibir)...\n\n");

        sleep(1);
        system("pause");
        system("cls");
        return;
    }
}

void setSalaryByRole(EmployeeData employee_data[], int employers_count) {
    int i, j, selected_role, unique_count = 0, found = 0;
    float role_salary;
    char unique_roles[max_employers][max_char], conclusion_confirmation;

    if (employers_count == 0) {
        printf("\n Não há funcionários registrados no sistema.\n");
        sleep(1);
        system("pause");
        system("cls");
        return;
    }

    for (i = 0; i < employers_count; i++) {
        for (j = 0; j < unique_count; j++) {
            if (strcasecmp(unique_roles[j], employee_data[i].employee_role) == 0) {
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(unique_roles[unique_count], employee_data[i].employee_role);
            unique_count++;
        }
    }

    system("cls");

    companyShowcase();

    printf("\n Cargos disponíveis no sistema:\n");
    for (i = 0; i < unique_count; i++) {
        printf(" %d. %s\n", i + 1, unique_roles[i]);
    }

    do {
        printf("\n Informe o número do cargo que deseja definir o salário (1-%d): ", unique_count);
        scanf("%d", &selected_role);
        if (selected_role < 1 || selected_role > unique_count) {
            printf("\n Opção inválida. Tente novamente.\n");
        }
    } while (selected_role < 1 || selected_role > unique_count);

    printf("\n Salário para o cargo \"%s\": ", unique_roles[selected_role - 1]);
    scanf("%f", &role_salary);

    printf("\n Deseja confirmar o salário de %.2f para o cargo \"%s\"? [S/n]: ", role_salary, unique_roles[selected_role - 1]);
    do {
        fflush(stdin);
        conclusion_confirmation = getchar();
    } while ((toupper(conclusion_confirmation) != 'S') && (tolower(conclusion_confirmation) != 'n'));

    if (toupper(conclusion_confirmation) == 'S') {
        for (i = 0; i < employers_count; i++) {
            if (strcasecmp(unique_roles[selected_role - 1], employee_data[i].employee_role) == 0) {
                employee_data[i].employee_salary = role_salary;
            }
        }

        system("cls");

        companyShowcase();

        printf("\n Salário definido para o cargo \"%s\": %.2f\n", unique_roles[selected_role - 1], role_salary);

        printf("\n Lista de funcionários com o novo salário:\n");
        for (i = 0; i < employers_count; i++) {
            if (strcasecmp(unique_roles[selected_role - 1], employee_data[i].employee_role) == 0) {
                printf("\n | Informações do funcionário:");
                printf("\n   º Nome: %s", employee_data[i].employee_name);
                printf("\n   º Idade: %d", employee_data[i].employee_age);
                printf("\n   º Sexo: %c", toupper(employee_data[i].employee_gender));
                printf("\n   º Código de identificação: %d", employee_data[i].employee_code);
                printf("\n   º Cargo (experiência): %s", employee_data[i].employee_role);
                printf("\n   º Salário: %.2f", employee_data[i].employee_salary);
                printf("\n   º Carga horária: %.2f\n", employee_data[i].employee_work_time);
            }
        }
    } else {
        printf("\n A operação foi cancelada.\n");
    }

    printf("\n");
    sleep(1);
    system("pause");
    system("cls");
}

void employersMenu() {
    EmployeeData employee_data[max_employers];
	int selected_option, employers_count = 0;

	system("cls");

	while (1) {
		companyShowcase();

		printf("\n Neste painel é possível consultar todas as opções disponíveis para serem executadas para os funcionários.");

		printf("\n\n As opções disponíveis incluem: registrar funcionários no banco de dados do sistema, listar todos os funcionários\n registrados, deletar um funcionário específico e filtrá-los por diferentes categorias.");
		printf("\n\n Escolha, dentre as opções listadas abaixo (1-5), uma para ser executada a seguir.\n");

		sleep(1);

		printf("\n º Opção 1: Incluir funcionário(s);");
		printf("\n º Opção 2: Listar funcionários;");
		printf("\n º Opção 3: Excluir funcionário;");
		printf("\n º Opção 4: Filtrar funcionários;");
		printf("\n º Opção 5: Voltar;");

		printf("\n\n Opção: ");
		scanf("%d", &selected_option);

		switch (selected_option) {
			case 1:
				includeEmployee(employee_data, &employers_count);

				break;
			case 2:
                listAllEmployers(employee_data, employers_count);

				break;
            case 3:
                deleteEmployee(employee_data, &employers_count);

                break;
            case 4:
                setSalaryByRole(employee_data, employers_count);

                break;
			case 5:
				return;
			default:
				printf("\n A opção escolhida é inválida!\n\n");

				sleep(1);
				system("pause");
				system("cls");
		}
	}
}
