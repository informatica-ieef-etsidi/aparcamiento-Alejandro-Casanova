#include <stdio.h>
#include <string.h>

struct plaza {
	int estado; // 0 - Libre / 1 - Ocupada
	char tipov; // M - Moto / C - Coche
	char mat[8]; // Formato de la matrícula: NNNNLLL
};

void main() {
	char opcion = 'B', tipov = 'B';
	char matB[8];
	int salir = 0;
	char usuario[50], contrasena[25];
	char usuarioc[50] = "alex", contrasenac[25] = "1234";
	int i;
	struct plaza plaza1 = { 0 , 'C' }, plaza2 = { 0 , 'C' }, plaza3 = { 0 , 'M' };

	for (i = 0; i < 3; i++) {
		system("cls");
		printf("Introduzca el usuario: ");
		scanf_s("%s", usuario, 50);
		printf("Introduzca la contrasena: ");
		scanf_s("%s", contrasena, 25);
		if (strcmp(usuario, usuarioc) == 0 && strcmp(contrasena, contrasenac) == 0) {
			printf("Usuario y Contrasena correctos.\n");
			system("pause");
			break;
		}
		else {
			printf("El usuario o la contrasena son incorrectos. Tiene %d intentos mas.\n", -i + 2);
			system("pause");
		}
	}
	if (i == 3)
	return;
	
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
		if (opcion >= 'a'&& opcion <= 'z') {
			opcion -= 32;
		}
		switch (opcion) {
		case 'R':
			printf("Se trata de un coche <C> o una moto <M>?\n");
			getchar();
			scanf_s("%c", &tipov);
			switch (tipov) {
			case 'C':
				if (plaza1.estado == 0) {
					plaza1.estado = 1;
					printf("Introduzca el numero de matricula:\n");
					scanf_s("%s", plaza1.mat, 8);
				}
				else if (plaza2.estado == 0) {
					plaza2.estado = 1;
					printf("Introduzca el numero de matricula:\n");
					scanf_s("%s", plaza2.mat, 8);
				}
				else {
					printf("No hay plazas de coche libres.\n");
					system("Pause");
				}
				break;
			case 'M':
				if (plaza3.estado == 0) {
					plaza3.estado = 1;
					printf("Introduzca el numero de matricula:\n");
					scanf_s("%s", plaza3.mat, 8);
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
			if (plaza1.estado != 0) {
				plaza1.estado = 0;
				printf("Se ha vaciado la plaza 1\n");
			}
			else if (plaza2.estado != 0) {
				plaza2.estado = 0;
				printf("Se ha vaciado la plaza 2\n");
			}
			else if (plaza3.estado != 0) {
				plaza3.estado = 0;
				printf("Se ha vaciado la plaza 3\n");
			}
			else
				printf("Todas las plazas estan vacias.\n");
			system("pause");
			break;
		case 'E':
			if (plaza1.estado == 0) {
				printf("Plaza 1 - Coche - Libre\n");
			}
			else if (plaza1.estado == 1) {
				printf("Plaza 1 - Coche - Ocupada - Matricula: %s\n", plaza1.mat);
			}
			if (plaza2.estado == 0) {
				printf("Plaza 2 - Coche - Libre\n");
			}
			else if (plaza2.estado == 1) {
				printf("Plaza 2 - Coche - Ocupada - Matricula: %s\n", plaza2.mat);
			}
			if (plaza3.estado == 0) {
				printf("Plaza 3 - Moto - Libre\n");
			}
			else if (plaza3.estado == 1) {
				printf("Plaza 3 - Moto - Ocupada - Matricula: %s\n", plaza3.mat);
			}
			system("pause");
			break;
		case 'B':
			printf("Introduzca la matricula que desea buscar:\n");
			scanf_s("%s", matB, 8);
			if (strncmp(matB, plaza1.mat, 8) == 0) {
				printf("El vehiculo se encuentra en la plaza 1\n");
			}
			else if (strncmp(matB, plaza2.mat, 8) == 0) {
				printf("El vehiculo se encuentra en la plaza 2\n");
			}
			else if (strncmp(matB, plaza3.mat, 8) == 0) {
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