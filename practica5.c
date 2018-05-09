#include <stdio.h>
#include <string.h>
#define NPLAZAS 10
#define NUSUARIOS 5

struct plaza {
	int estado; // 0 - Libre / 1 - Ocupada
	char tipov; // M - Moto / C - Coche
	char mat[8]; // Formato de la matr�cula: NNNNLLL
};
struct usuario {
	char usuario[50];
	char contrasena[25];
};

char menu();
int esDigitoValido(char caracter);
int esLetraValida(char caracter);
int esMatriculaValida(char matricula[]);
int existeUsuario(struct usuario *usuarioValido, char username[], char password[]);


void main() {
	char opcion = 'B', tipov = 'B';
	char matB[8];
	int salir = 0, saliru = 0;
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
			if (existeUsuario(&usuarioc, usuario[m].usuario, usuario[m].contrasena) == 1) {
				printf("Usuario y Contrasena correctos.\n");
				system("color 2A");
				system("pause");
				saliru = 1;
				break;
			}
		}
		if (saliru == 1) {
			break;
		}
		if (m == NUSUARIOS) {
				printf("El usuario o la contrasena son incorrectos. Tiene %d intentos mas.\n", -i + 2);
				system("color 4C");
				system("pause");
		}
		
	}
	if (i == 3)
		return;
	getchar();
	while (salir == 0) {
		opcion = menu();
		switch (opcion) {
		case 'R':
			printf("Se trata de un coche <C> o una moto <M>?\n");
			getchar();
			scanf_s("%c", &tipov);
			if ((tipov >= 'a') && (tipov <= 'z')) { 
				tipov -= 32;
			}
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
						while (1) {
							scanf_s("%s", aparcamiento[n].mat, 8);
							if (esMatriculaValida(aparcamiento[n].mat) == 1) {
								printf("El vehiculo con matricula [%s] ha sido aparcado en la plaza %d\n", aparcamiento[n].mat, n + 1);
								system("Pause");
								break;
							}
							else {
								printf("La matricula introducida no sigue el formato <NNNNLLL>, introduzca una apropiada: ");
								
							}

						}
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
						while (1) {
							scanf_s("%s", aparcamiento[n].mat, 8);
							if (esMatriculaValida(aparcamiento[n].mat) == 1) {
								printf("El vehiculo con matricula [%s] ha sido aparcado en la plaza %d\n", aparcamiento[n].mat, n + 1);
								system("Pause");
								break;
							}
							else
								printf("La matricula introducida no sigue el formato <NNNNLLL>, introduzca una apropiada: ");
						}
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
			do {
				scanf_s("%s", matB, 8);
				if (esMatriculaValida(matB) == 0) {
					printf("La matricula introducida no sigue el formato <NNNNLLL>, introduzca una apropiada: ");
				}
			} while (esMatriculaValida(matB) == 0);
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
			do {
				scanf_s("%s", matB, 8);
				if (esMatriculaValida(matB) == 0) {
					printf("La matricula introducida no sigue el formato <NNNNLLL>, introduzca una apropiada: ");
				}
			} while (esMatriculaValida(matB) == 0);
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

int existeUsuario(struct usuario *usuarioValido, char username[], char password[]) {
	if (strcmp(username, usuarioValido->usuario) == 0 && strcmp(password, usuarioValido->contrasena) == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

char menu() {
	char opcion;

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
	return opcion;
}

int esDigitoValido(char caracter) {
	if (caracter < '0' || caracter > '9') {
		return 0;
	}
	return 1;
}
int esLetraValida(char caracter) {
	if (caracter < 'A' || caracter > 'Z') {
		return 0;
	}
	return 1;
}

int esMatriculaValida(char matricula[]) {
	int i = 0;
	if (strlen(matricula) != 7) {
		return 0;
	}
	for (i = 0; i < 4; i++) {
		if (esDigitoValido(matricula[i]) == 0) {
			return 0;
		}
	}
	for (i = 4; i < 7; i++) {
		if ((matricula[i] >= 'a') && (matricula[i] <= 'z')) {//Corrige minusculas
			matricula[i] -= 32;
		}
		if (matricula[i] < 'A' || matricula[i] > 'Z') {
			return 0;
		}
	}
	return 1;
}

