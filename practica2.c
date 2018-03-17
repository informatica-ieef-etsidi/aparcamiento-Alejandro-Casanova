#include <stdio.h>
#include <string.h>

void main() {
	char opcion = 'B', tipov = 'B';
	char mat1[8], mat2[8], mat3[8], matB[8];
	int plaza1 = 0, plaza2 = 0, plaza3 = 0;
	int salir = 0;

	while (salir == 0) {
		system("cls");
		system("color 0E");
		printf("Seleccione una de estas opciones:\n");
		printf("R - Reservar plaza\n");
		printf("A - Abandonar plaza\n");
		printf("E - Estado del aparcamiento\n");
		printf("B - Buscar Vehiculo por matricula\n");
		printf("S - Salir del programa\n");
		scanf_s("%c", &opcion);
		switch (opcion) {
		case 'R':
			printf("Se trata de un coche <C> o una moto <M>?\n");
			getchar();
			scanf_s("%c", &tipov);
			switch (tipov) {
			case 'C':
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
				else {
					printf("No hay plazas de coche libres.\n");
					system("Pause");
				}
				break;
			case 'M':
				if (plaza3 == 0) {
					plaza3 = 1;
					printf("Introduzca el numero de matricula:\n");
					scanf_s("%s", mat3, 8);
				}
				else {
					printf("No hay plazas de moto libres.\n");
					system("Pause");
				}
				break;
			default:
				printf("El caracter no es valido\n");
				break;
			}
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
			else if (plaza3 != 0) {
				plaza3 = 0;
				printf("Se ha vaciado la plaza 3\n");
			}
			else
				printf("Todas las plazas estan vacias.\n");
			system("pause"); 
			break;
		case 'E':
			if (plaza1 == 0) {
				printf("Plaza 1 - Coche - Libre\n");
				}
			else if (plaza1 == 1) {
				printf("Plaza 1 - Coche - Ocupada - Matricula: %s\n", mat1);
				}
			if (plaza2 == 0) {
				printf("Plaza 2 - Coche - Libre\n");
				}
			else if (plaza2 == 1) {
				printf("Plaza 2 - Coche - Ocupada - Matricula: %s\n", mat2);
				}
			if (plaza3 == 0) {
				printf("Plaza 3 - Moto - Libre\n");
			}
			else if (plaza3 == 1) {
				printf("Plaza 3 - Moto - Ocupada - Matricula: %s\n", mat3);
			}
			system("pause");
			break;
		case 'B':
			printf("Introduzca la matricula que desea buscar:\n");
			scanf_s("%s", matB, 8);
			if (strncmp(matB, mat1, 8) == 0) {
				printf("El vehiculo se encuentra en la plaza 1\n");
			}
			else if (strncmp(matB, mat2, 8) == 0) {
				printf("El vehiculo se encuentra en la plaza 2\n");
			}
			else if (strncmp(matB, mat3, 8) == 0) {
				printf("El vehiculo se encuentra en la plaza 3\n");
			}
			else {
				printf("El vehiculo no se encuentra en el aparcamiento\n");
			}
			system("Pause");
			break;
		case 'S':
			salir = 1;
			break;
		default:
			printf("La opcion no es valida\n");
			system("pause");
			break;
		}
		getchar();
	}
}