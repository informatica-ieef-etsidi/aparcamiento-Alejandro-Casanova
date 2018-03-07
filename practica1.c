#include <stdio.h>

void main() {
	char opcion = 'B';
	int plaza1 = 0, plaza2 = 0;
	char n1 = 'B', n2 = 'B', n3 = 'B', n4 = 'B', n5 = 'B', n6 = 'B';

	while (1) {
		system("cls");
		system("color 0E");
		printf("Seleccione una de estas opciones:\n");
		printf("R - Reservar plaza\n");
		printf("A - Abandonar plaza\n");
		printf("E - Estado del aparcamiento\n");
		scanf_s("%c", &opcion);
		switch (opcion) {
		case 'R':
			if (plaza1 == 0) {
				printf("Introduzca el numero de matricula:\n");
				scanf_s("%d", &plaza1);
				printf("Introduzca la primera letra de la matricula:\n");
				getchar();
				scanf_s("%c", &n1);
				printf("Introduzca la segunda letra de la matricula:\n");
				getchar();
				scanf_s("%c", &n2);
				printf("Introduzca la primera letra de la matricula:\n");
				getchar();
				scanf_s("%c", &n3);
			}
			else if (plaza2 == 0) {
				printf("Introduzca el numero de matricula:\n");
				scanf_s("%d", &plaza2);
				printf("Introduzca la primera letra de la matricula:\n");
				getchar();
				scanf_s("%c", &n4);
				printf("Introduzca la segunda letra de la matricula:\n");
				getchar();
				scanf_s("%c", &n5);
				printf("Introduzca la primera letra de la matricula:\n");
				getchar();
				scanf_s("%c", &n6);
			}
			else
				printf("El aparcamiento esta lleno.\n");
			break;
		case 'A':
			if (plaza1 != 0) {
				plaza1 = 0;
				printf("Se ha vaciado la plaza 1\n");
			}
			else if (plaza2 != 0) {
				plaza2 = 0;
				printf("Se ha vaciado la plaza 2\n");
			}
			else
				printf("Todas las plazas estan vacias.\n");
			break;
		case 'E':
			if (plaza1 == 0) {
				if (plaza2 == 0) {
					printf("Plaza 1 - Libre\n");
					printf("Plaza 2 - Libre\n");
				}
				else {
					printf("Plaza 1 - Libre\n");
					printf("Plaza 2 - Ocupada - Matricula: %d%c%c%c\n", plaza2, n4, n5, n6);
				}
			}
			else {
				if (plaza2 == 0) {
					printf("Plaza 1 - Ocupada - Matricula: %d%c%c%c\n", plaza1, n1, n2, n3);
					printf("Plaza 2 - Libre\n");
				}
				else {
					printf("Plaza 1 - Ocupada - Matricula: %d%c%c%c\n", plaza1, n1, n2, n3);
					printf("Plaza 2 - Ocupada - Matricula: %d%c%c%c\n", plaza2, n2, n3, n4);
				}
			} 
			break;
		default:
			printf("La opcion no es valida\n");
			break;
		}
		system("pause");
		getchar();
	}
}