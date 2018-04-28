#include <stdio.h>
#include <string.h>
#define NPLAZAS 10
#define NUSUARIOS 5

struct plaza {
	int estado; // 0 - Libre / 1 - Ocupada
	char tipov; // M - Moto / C - Coche
	char mat[8]; // Formato de la matrícula: NNNNLLL
};
struct usuario {
	char usuario[50];
	char contrasena[25];
};

int comprobarMat(char mat[]);

void main() {
	char opcion = 'B', tipov = 'B';
	char matB[8];
	int salir = 0;
	struct usuario usuarioc;
	struct usuario usuario[NUSUARIOS] = { {"alex", "1234"}, {"fran", "1234"} };
	int i, n = 0, m = 0;
	struct plaza aparcamiento[NPLAZAS]; 

	for (i = 0; i < NPLAZAS; i++) {
		aparcamiento[i].estado = 0; //Para evitar errores declaro todos los aparcamientos como "vacios"
	}

	system("color 07");

	for (i = 0; i < 3; i++) {
		system("cls");
		printf("Introduzca el usuario: ");
		scanf_s("%s", usuarioc.usuario, 50);
		printf("Introduzca la contrasena: ");
		scanf_s("%s", usuarioc.contrasena, 25);
		m = 0;
		for (m = 0; m < NUSUARIOS; m++) {
			if (strcmp(usuario[m].usuario, usuarioc.usuario) == 0 && strcmp(usuario[m].contrasena, usuarioc.contrasena) == 0) {
				printf("Usuario y Contrasena correctos.\n");
				system("color 2A");
				system("pause");
				break;
			}
		}
		if (m == NUSUARIOS) {
				printf("El usuario o la contrasena son incorrectos. Tiene %d intentos mas.\n", -i + 2);
				system("color 4C");
				system("pause");
		}
		
	}
	if (i == 4)
		return;
	getchar();
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
				n = 0;
				while (1) {
					if (n > NPLAZAS) {
						printf("No hay plazas de libres.\n");
						system("Pause");
						break;
					}
					if (aparcamiento[n].estado != 0) {
						n++;
					}
					else {
						aparcamiento[n].tipov = 'C';
						aparcamiento[n].estado = 1;
						printf("Introduzca el numero de matricula:\n");
						scanf_s("%s", aparcamiento[n].mat, 8);
						printf("El vehiculo con matricula [%s] ha sido aparcado en la plaza %d\n", aparcamiento[n].mat, n + 1);
						system("Pause");
						break;
					}
				}
				break;
			case 'M':
				n = 0;
				while (1) {
					if (n > NPLAZAS) {
						printf("No hay plazas libres.\n");
						system("Pause");
						break;
					}
					if (aparcamiento[n].estado != 0) {
						n++;
					}
					else {
						aparcamiento[n].tipov = 'M';
						aparcamiento[n].estado = 1;
						printf("Introduzca el numero de matricula:\n");
						scanf_s("%s", aparcamiento[n].mat, 8);
						printf("El vehiculo con matricula [%s] ha sido aparcado en la plaza %d\n", aparcamiento[n].mat, n + 1);
						system("Pause");
						break;
					}
				}
				break;
			default:
				printf("El caracter no es valido\n");
				system("pause");
				break;
			}
			break;
		case 'A':
			printf("Introduzca la matricula del vehiculo que desea retirar: ");
			scanf_s("%s", matB, 8);
			n = 0;
			while (1) {
				if (strncmp(matB, aparcamiento[n].mat, 8) == 0) {
					aparcamiento[n].estado = 0;
					printf("El vehiculo ha sido retirado de la plaza %d\n", n + 1);
					system("pause");
					break;
				}
				else {
					n++;
				}
				if (n > NPLAZAS) {
					printf("El vehiculo no se encuentra en el aparcamiento\n");
					system("Pause");
					break;
				}
			}
			break;
		case 'E':
			for (i = 0; i < NPLAZAS; i++) {
				if (aparcamiento[i].estado == 0) {
					printf("Plaza %d - Libre\n", i + 1);
				}
				else {
					printf("Plaza %d - ", i + 1);
					if (aparcamiento[i].tipov == 'C')
						printf("Coche - Ocupada - ");
					else
						printf("Moto - Ocupada - ");
					printf("Matricula: %s\n", aparcamiento[i].mat);
				}
			}
			system("pause");
			break;
		case 'B':
			printf("Introduzca la matricula que desea buscar:\n");
			scanf_s("%s", matB, 8);
			n = 0;
			while (1) {
				if (strncmp(matB, aparcamiento[n].mat, 8) == 0) {
					printf("El vehiculo se encuentra en la plaza %d\n", n + 1);
					system("pause");
					break;
				}
				else {
					n++;
				}
				if (n > NPLAZAS) {
					printf("El vehiculo no se encuentra en el aparcamiento\n");
					system("Pause");
					break;
				}
			}
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

int comprobarMat(char mat[]) { //Sin implementar
	int i = 0;
	if (mat[8] != '\0') {
		return 0;
	}
	i = 0;
	for (i = 0; i < 4; i++) {
		if (mat[i] < 48 || mat[i] > 57) {
			return 0;
		}
	}
	i = 5;
	for (i = 5; i < 7; i++) {
		if (mat[i] < 65 || mat[i] > 90) {
			return 0;
		}
	}
	return 1;
}
