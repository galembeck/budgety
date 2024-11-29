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

				printf("\n\t Obrigado por utilizar os servi�os da \"Budgety\"!\n");

				exit(0);

			default:
				printf("\n A op��o escolhida � inv�lida!\n\n");

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

	printf("\n Ol�! Seja bem-vindo ao Sistema de Or�amento.");

	printf("\n\n Para acessar o painel de controle, informe seu login e senha.");
	printf("\n H�, ao total, apenas 3 tentativas para efetuar corretamente o login (ap�s isso, o processo ser� cancelado).");

	printf("\n\n Informe, nos campos abaixo, o \"usu�rio\" e a \"senha\" corretos para acessar o painel.\n");
}

void loginPage() {
	char user[max_char];
	int password, trys = 0;

	do {
		loginInformation();

		sleep(1);

		printf("\n � Usu�rio: ");
		fflush(stdin);
		gets(user);

		printf(" � Senha: ");
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

			printf("\n Usu�rio e/ou senha incorreto(s)! Restam-lhe %d tentativas...\n\n", 3-trys);

			sleep(1);
			system("pause");
			system("cls");
		}

		if(trys == 3) {
			companyShowcase();

			sleep(1);

			printf("\n Que pena! Sua tentativas de login se esgotaram :(");
			printf("\n Parece que voc� n�o conseguiu acessar o painel de controle...\n");

			sleep(1);

			exit(0);
		}
	} while((strcmp(user, "admin") != 0) || (password != 1234));

	system("cls");
}



int optionsMenu() {
	int selected_option;

	companyShowcase();

	printf("\n Ol�! Seja bem-vindo ao Sistema de Or�amento da \"Budgety\".");

	printf("\n\n Abaixo, est�o listadas todas as op��es dispon�veis para serem executadas em nosso sistema.");
	printf("\n Escolha, dentre as op��es listadas abaixo (1-8), uma para ser executada a seguir.\n");

	sleep(1);

	printf("\n � Op��o 1: Funcion�rios;");
	printf("\n � Op��o 2: Insumos;");
	printf("\n � Op��o 3: Sair;");

	printf("\n\n Op��o: ");
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

		printf("\n Para incluir um funcion�rio no sistema, � necess�rio preencher algumas informa��es...");

		printf("\n\n Primeiramente, quantos funcion�rios ser�o inclu�dos no sistema? ");
		scanf("%d", &employers_to_include);

		if((employers_to_include <= 0) || (*employers_count + employers_to_include > max_employers)) {
			printf("\n O n�mero informado de funcion�rios a serem inclu�dos � inv�lido!\n\n");

			sleep(1);
			system("cls");
		}
	} while((employers_to_include <= 0) || (*employers_count + employers_to_include > max_employers));

	printf("\n �timo! Com o n�mero de funcion�rios a serem inclu�dos definido, podemos continuar com o processo.\n\n");

	sleep(1);
	system("pause");
	system("cls");

	EmployeeData temp_employee_data[max_employers];
	int temp_employers_count = 0;

	for(i = 0; i < employers_to_include; i++) {
		companyShowcase();

		printf("\n Agora, com o n�mero de funcion�rios a serem inclu�dos definido, ser� necess�rio preencher alguns campos.");
		printf("\n\n Dentre as informa��es ncess�rias, informe, abaixo, os seguintes dados:");
		printf("\n\n � Nome do funcion�rio;");
		printf("\n � Idade;");
		printf("\n � Sexo;");
		printf("\n � C�digo de identifica��o;");
		printf("\n � Cargo (experi�ncia);");
		// printf("\n � N�vel (experi�ncia);");
		printf("\n � Carga hor�ria;\n");

		sleep(1);

		printf("\n | Nome do %d� funcion�rio: ", i+1);
		fflush(stdin);
		fgets(temp_employee_data[temp_employers_count].employee_name, max_char, stdin);
		temp_employee_data[temp_employers_count].employee_name[strcspn(temp_employee_data[temp_employers_count].employee_name, "\n")] = '\0';

		printf("\n | Idade do %d� funcion�rio: ", i+1);
		scanf("%d", &temp_employee_data[temp_employers_count].employee_age);

		do {
			printf("\n | Sexo do %d� funcion�rio [M/F]: ", i+1);
			fflush(stdin);
			temp_employee_data[temp_employers_count].employee_gender = getchar();

			if((toupper(temp_employee_data[temp_employers_count].employee_gender) != 'M') && (toupper(temp_employee_data[temp_employers_count].employee_gender) != 'F')) {
				printf("\n O sexo informado � inv�lido!\n");
			}
		} while((toupper(temp_employee_data[temp_employers_count].employee_gender) != 'M') && (toupper(temp_employee_data[temp_employers_count].employee_gender) != 'F'));

		printf("\n | C�digo de identifica��o do %d� funcion�rio: ", i+1);
		scanf("%d", &temp_employee_data[temp_employers_count].employee_code);

		printf("\n | Cargo (experi�ncia) do %d� funcion�rio: ", i+1);
		fflush(stdin);
		fgets(temp_employee_data[temp_employers_count].employee_role, max_char, stdin);
		temp_employee_data[temp_employers_count].employee_role[strcspn(temp_employee_data[temp_employers_count].employee_role, "\n")] = '\0';

		/*
		do {
			printf("\n | N�vel (experi�ncia) do %d� funcion�rio [J/P/S]: ", i+1);
			fflush(stdin);
			temp_employee_data[temp_employers_count].employee_rating = getchar();

			if((toupper(temp_employee_data[temp_employers_count].employee_rating) != 'J') && (toupper(temp_employee_data[temp_employers_count].employee_rating) != 'P') && (toupper(temp_employee_data[temp_employers_count].employee_rating) != 'S')) {
				printf("\n O n�vel (experi�ncia) informado � inv�lido!\n");
			}
		} while((toupper(temp_employee_data[temp_employers_count].employee_rating) != 'J') && (toupper(temp_employee_data[temp_employers_count].employee_rating) != 'P') && (toupper(temp_employee_data[temp_employers_count].employee_rating) != 'S'));
		*/

		printf("\n | Carga hor�ria do %d� funcion�rio: ", i+1);
		scanf("%f", &temp_employee_data[temp_employers_count].employee_work_time);

		temp_employers_count++;

		system("cls");
	}

	companyShowcase();

	sleep(1);

	printf("\n Ao t�rmino da inser��o dos dados/informa��es solicitadas, confirme a inclus�o dos seguintes funcion�rios: ");

	printf("\n\n Total de funcion�rios a serem inclu�dos: %d funcion�rio(s).\n", temp_employers_count);

	for(i = 0; i < temp_employers_count; i++) {
        printf("\n | Informa��es do \"%d�\" funcion�rio:", i+1);
		printf("\n   � Nome: %s", temp_employee_data[i].employee_name);
		printf("\n   � Idade: %d", temp_employee_data[i].employee_age);
		printf("\n   � Sexo: %c", toupper(temp_employee_data[i].employee_gender));
		printf("\n   � C�digo de identifica��o: %d", temp_employee_data[i].employee_code);
		printf("\n   � Cargo (experi�ncia): %s", temp_employee_data[i].employee_role);
		// printf("\n   � N�vel (experi�ncia): %c", toupper(temp_employee_data[i].employee_rating));
		printf("\n   � Carga hor�ria: %.2f\n", temp_employee_data[i].employee_work_time);
	}

	printf("\n Deseja confirmar a inclus�o do(s) funcion�rio(s) listados acima? [S/n]: ");

	do {
		fflush(stdin);
		inclusion_confirmation = getchar();
	} while((toupper(inclusion_confirmation) != 'S') && (tolower(inclusion_confirmation) != 'n'));

	if(toupper(inclusion_confirmation) == 'S') {
		for(i = 0; i < temp_employers_count; i++) {
			employee_data[*employers_count] = temp_employee_data[i];
			(*employers_count)++;
		}
		printf("\n Os funcion�rios listados foram inclu�dos com sucesso!\n\n");
	}
	else {
		printf("\n A inclus�o dos funcion�rios listados foi cancelada!\n\n");
	}

	sleep(1);
    system("pause");
    system("cls");
}

void listAllEmployers(EmployeeData employee_data[], int employers_count) {
    int i;

    system("cls");

    companyShowcase();

    printf("\n Neste painel, � poss�vel consultar/listar todos os funcion�rios registrados no banco de dados do sistema.");

    printf("\n\n | Total de funcion�rios registrados: %d\n", employers_count);

    if(employers_count > 0) {
        for(i = 0; i < employers_count; i++) {
            printf("\n | Informa��es do \"%d�\" funcion�rio:", i+1);
            printf("\n   � Nome: %s", employee_data[i].employee_name);
            printf("\n   � Idade: %d", employee_data[i].employee_age);
            printf("\n   � Sexo: %c", toupper(employee_data[i].employee_gender));
            printf("\n   � C�digo de identifica��o: %d", employee_data[i].employee_code);
            printf("\n   � Cargo (experi�ncia): %s", employee_data[i].employee_role);
            // printf("\n   � N�vel (experi�ncia): %c", toupper(employee_data[i].employee_rating));
            printf("\n   � Carga hor�ria: %.2f\n", employee_data[i].employee_work_time);
        }
    } else {
        printf("\n � N�o h� nenhum funcion�rio registrado no banco de dados do sistema (sem dados para exibir)...\n");
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

    printf("\n Neste painel, � poss�vel excluir um determinado funcion�rio registrado no sistema.");

    printf("\n\n Para que um funcion�rio seja exclu�do efetivamente, � necess�rio que seu c�digo seja informado.");
    printf("\n Abaixo est�o listados todos os c�digos dos funcion�rios registrados no banco de dados do sistema da \"Budgety\".");

    printf("\n\n | Total de funcion�rios registrados: %d funcion�rio(s).\n", employers_count);

    if(*employers_count > 0) {
        for(i = 0; i < *employers_count; i++) {
            printf("\n > C�digo do %d� funcion�rio: %d", i+1, employee_data[i].employee_code);
        }

        printf("\n\n � C�digo do funcion�rio (a ser exclu�do): ");
        scanf("%d", &deletable_code);

        for(j = 0; j < *employers_count; j++) {
            if(employee_data[j].employee_code == deletable_code) {
                stored_employee = j;
                break;
            }
        }

        if(stored_employee == -1) {
            printf("\n Nenhum funcion�rio com c�digo \"%d\" foi encontrado no banco de dados do sistema.\n\n", deletable_code);

            sleep(1);
            system("pause");

            return;
        }

        system("cls");

        companyShowcase();

        printf("\n As informa��es do funcion�rio a ser exclu�do s�o:");
        printf("\n � Nome: %s", employee_data[stored_employee].employee_name);
        printf("\n � Idade: %d", employee_data[stored_employee].employee_age);
        printf("\n � Sexo: %c", toupper(employee_data[stored_employee].employee_gender));
        printf("\n � C�digo de identifica��o: %d", employee_data[stored_employee].employee_code);
        printf("\n � Cargo (experi�ncia): %s", employee_data[stored_employee].employee_role);
        // printf("\n � N�vel (experi�ncia): %c", toupper(employee_data[stored_employee].employee_rating));
        printf("\n � Carga hor�ria: %.2f\n", employee_data[stored_employee].employee_work_time);

        printf("\n Deseja confirmar a exclus�o do funcion�rio listado acima? [S/n]: ");

        do {
            fflush(stdin);
            deletion_confirmation = getchar();
        } while ((toupper(deletion_confirmation) != 'S') && (tolower(deletion_confirmation) != 'n'));

        if (toupper(deletion_confirmation) == 'S') {
            for (i = stored_employee; i < *employers_count - 1; i++) {
                employee_data[i] = employee_data[i + 1];
            }
            (*employers_count)--;

            printf("\n O funcion�rio foi exclu�do com sucesso!\n\n");
        } else {
            printf("\n A exclus�o do funcion�rio foi cancelada!\n\n");
        }

        sleep(1);
        system("pause");
    } else {
        printf("\n � N�o h� nenhum funcion�rio registrado no banco de dados do sistema (sem dados para exibir)...\n\n");

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
        printf("\n N�o h� funcion�rios registrados no sistema.\n");
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

    printf("\n Cargos dispon�veis no sistema:\n");
    for (i = 0; i < unique_count; i++) {
        printf(" %d. %s\n", i + 1, unique_roles[i]);
    }

    do {
        printf("\n Informe o n�mero do cargo que deseja definir o sal�rio (1-%d): ", unique_count);
        scanf("%d", &selected_role);
        if (selected_role < 1 || selected_role > unique_count) {
            printf("\n Op��o inv�lida. Tente novamente.\n");
        }
    } while (selected_role < 1 || selected_role > unique_count);

    printf("\n Sal�rio para o cargo \"%s\": ", unique_roles[selected_role - 1]);
    scanf("%f", &role_salary);

    printf("\n Deseja confirmar o sal�rio de %.2f para o cargo \"%s\"? [S/n]: ", role_salary, unique_roles[selected_role - 1]);
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

        printf("\n Sal�rio definido para o cargo \"%s\": %.2f\n", unique_roles[selected_role - 1], role_salary);

        printf("\n Lista de funcion�rios com o novo sal�rio:\n");
        for (i = 0; i < employers_count; i++) {
            if (strcasecmp(unique_roles[selected_role - 1], employee_data[i].employee_role) == 0) {
                printf("\n | Informa��es do funcion�rio:");
                printf("\n   � Nome: %s", employee_data[i].employee_name);
                printf("\n   � Idade: %d", employee_data[i].employee_age);
                printf("\n   � Sexo: %c", toupper(employee_data[i].employee_gender));
                printf("\n   � C�digo de identifica��o: %d", employee_data[i].employee_code);
                printf("\n   � Cargo (experi�ncia): %s", employee_data[i].employee_role);
                printf("\n   � Sal�rio: %.2f", employee_data[i].employee_salary);
                printf("\n   � Carga hor�ria: %.2f\n", employee_data[i].employee_work_time);
            }
        }
    } else {
        printf("\n A opera��o foi cancelada.\n");
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

		printf("\n Neste painel � poss�vel consultar todas as op��es dispon�veis para serem executadas para os funcion�rios.");

		printf("\n\n As op��es dispon�veis incluem: registrar funcion�rios no banco de dados do sistema, listar todos os funcion�rios\n registrados, deletar um funcion�rio espec�fico e filtr�-los por diferentes categorias.");
		printf("\n\n Escolha, dentre as op��es listadas abaixo (1-5), uma para ser executada a seguir.\n");

		sleep(1);

		printf("\n � Op��o 1: Incluir funcion�rio(s);");
		printf("\n � Op��o 2: Listar funcion�rios;");
		printf("\n � Op��o 3: Excluir funcion�rio;");
		printf("\n � Op��o 4: Filtrar funcion�rios;");
		printf("\n � Op��o 5: Voltar;");

		printf("\n\n Op��o: ");
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
				printf("\n A op��o escolhida � inv�lida!\n\n");

				sleep(1);
				system("pause");
				system("cls");
		}
	}
}
