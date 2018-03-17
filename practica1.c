#include <stdio.h>
#include <string.h>

void main() {
	char opcion = 'B';
	char mat1[8], mat2[8];
	int plaza1 = 0, plaza2 = 0;

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
				plaza1 = 1;
				printf("Introduzca el numero de matricula:\n");
				scanf_s("%s", mat1, 8);
			}
			else if (plaza2 == 0) {
				plaza2 = 1;
				printf("Introduzca el numero de matricula:\n");
				scanf_s("%s", mat2, 8);
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
					printf("Plaza 2 - Ocupada - Matricula: %s\n", mat2);
				}
			}
			else {
				if (plaza2 == 0) {
					printf("Plaza 1 - Ocupada - Matricula: %s\n", mat1);
					printf("Plaza 2 - Libre\n");
				}
				else {
					printf("Plaza 1 - Ocupada - Matricula: %s\n", mat1);
					printf("Plaza 2 - Ocupada - Matricula: %s\n", mat2);
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