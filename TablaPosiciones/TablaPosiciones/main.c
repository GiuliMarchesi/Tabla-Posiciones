// Tabla de Posiciones

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TERM_C '\0'
#define TERM_I -100
#define F 50
#define C 50

void menuPrincipal(void);

char validarEnter(void);

char validarSalida(void);

int menu(void);

void cargarMatriz(char matrizTitulos[F][C], char matrizEquipos[F][C], int matrizDatos[F][C]);

int leerArchTitulos (char matrizTitulos[F][C]);

int leerArchEquipos (char matrizEquipos[F][C]);

int leerArchDatos (int matrizDatos[F][C]);

void imprimirTitulo(char matrizTitulos [F][C]);

void imprimirEquipo(char matrizEquipos [F][C], int f);

void imprimirDato(int matrizDatos [F][C], int f);

void imprimirContenido(char matrizEquipos [F][C], int matrizDatos [F][C]);

void ordenarPor(char matrizEquipos [F][C], int matrizDatos [F][C], int columna);

/**<---------------------------------------Main------------------------------------------------------------------>*/

int main(int argc, const char * argv[]) {
    menuPrincipal();
    return 0;
}

/**<---------------------------------------Main------------------------------------------------------------------>*/

/**<---------------------------------------Menú principal-------------------------------------------------------->*/
void menuPrincipal(void){
    char matrizTitulo[F][C]={0}, matrizEquipo[F][C]={0}, enter, opcion = '\0';
    int matrizDato[F][C]={0}, validar = 0, validar1 = 0;
    enter = validarEnter();
    if (enter == '\n'){
        opcion = menu();
        while(opcion>='1' && opcion<='6'){
            if (opcion=='1'){
                cargarMatriz(matrizTitulo, matrizEquipo, matrizDato);
                validar = 1;
                opcion = menu();
            }
            else if (opcion=='2'){
                if (validar == 0){
                    printf("\nNo se cargó la tabla.\n");
                    opcion = menu();
                }
                else{
                    printf("\n");
                    imprimirTitulo(matrizTitulo);
                    imprimirContenido(matrizEquipo, matrizDato);
                    validar1 = 1;
                    opcion = menu();
                }
                }
            else if (opcion=='3'){
                if (validar == 0 || validar1 == 0){
                    printf("\nSe debe cargar la tabla y mostrarla previamente para ordenarla.\n");
                    opcion = menu();
                }
                else{
                    ordenarPor(matrizEquipo, matrizDato, 0);
                    printf("\nTabla ordenada por PTS: \n");
                    imprimirTitulo(matrizTitulo);
                    imprimirContenido(matrizEquipo, matrizDato);
                    opcion = menu();
                    }
            }
            else if (opcion == '4'){
                if (validar == 0 || validar1 == 0){
                    printf("\nSe debe cargar la tabla previamente para ordenarla.\n");
                    opcion = menu();
                }
                else{
                    ordenarPor(matrizEquipo, matrizDato, 7);
                    printf("\nTabla ordenada por DIF: \n");
                    imprimirTitulo(matrizTitulo);
                    imprimirContenido(matrizEquipo, matrizDato);
                    opcion = menu();
                    }
            }
            else if (opcion == '5'){
                if (validar == 0 || validar1 == 0){
                    printf("\nSe debe cargar la tabla previamente para ordenarla.\n");
                    opcion = menu();
                }
                else{
                    ordenarPor(matrizEquipo, matrizDato, 7);
                    ordenarPor(matrizEquipo, matrizDato, 0);
                    printf("\nTabla ordenada por PTS y DIF: \n");
                    imprimirTitulo(matrizTitulo);
                    imprimirContenido(matrizEquipo, matrizDato);
                    opcion = menu();
                    }
            }
            else if (opcion == '6'){
                opcion = validarSalida();
            }
            else if (opcion == '7'){
                printf("\nHa salido del programa.\n");
            }
        }
    }
    else{
        printf("\nLa opción ingresada no es válida. Ha salido del programa.\n");
        }
    }
/**<---------------------------------------Menú principal-------------------------------------------------------->*/

/**<---------------------------------------Menú------------------------------------------------------------------->*/
int menu(void){
    char opcionMenu, res = '\0';
    int intentos = 0;
    printf("\nMENÚ PRINCIPAL\n");
    printf("1. Cargar Tabla.\n");
    printf("2. Mostrar Tabla.\n");
    printf("3. Ordenar por PTS.\n");
    printf("4. Ordenar por DIF.\n");
    printf("5. Ordenar por PTS y por DIF.\n");
    printf("6. Salir del programa.\n");
    printf("\nIngrese opción -> ");
    fflush(stdin);
    opcionMenu = getchar();
    while ((opcionMenu < '1' || opcionMenu > '6') && intentos < 2) {
        printf("\nLa opción ingresada no fue valida.\n");
        printf("\nIngrese otra opción -> ");
        fflush(stdin);
        opcionMenu = getchar();
        intentos++;
    }
    if (opcionMenu >= '1' && opcionMenu <= '6'){
        res = opcionMenu;
    }
    else{
        res = '6';
    }
    return res;
}
/**<---------------------------------------Menú---------------------------------------------------------------------->*/

/**<---------------------------------------Validar Enter------------------------------------------------------------->*/
char validarEnter(void){
    int intentos=0;
    char enter;
    printf("\nIngrese enter para ir al MENÚ PRINCIPAL -> ");
    fflush(stdin);
    enter = getchar();
    while (enter != '\n' && intentos<2) {
        printf("\nNo ingreso enter.\n");
        printf("\nIngrese enter para entrar al MENÚ PRINCIPAL -> ");
        fflush(stdin);
        enter = getchar();
        intentos++;
    }
    return enter;
}
/**<---------------------------------------Validar Enter------------------------------------------------------------->*/

/**<---------------------------------------Validar Salida------------------------------------------------------------->*/
char validarSalida(void){
    int intentos=0;
    char salida, res;
    printf("\nDesea salir del programa? (S/N) -> ");
    fflush(stdin);
    salida = getchar();
    while (((salida != 'S') && (salida != 's') && (salida != 'N') && (salida != 'n')) && intentos <2) {
        printf("\nNo ingreso la opción correcta.\n");
        printf("\nDesea salir del programa? (S/N) -> ");
        fflush(stdin);
        salida = getchar();
        intentos++;
    }
    if ((salida == 'S') || (salida == 's')){
        res = '7';
    }
    else{
        res = menu();
    }
    return res;
}
/**<---------------------------------------Validar Salida------------------------------------------------------------->*/

/**<---------------------------------------Carga y lectura matrices----------------------------------------------->*/
void cargarMatriz(char matrizTitulos[F][C], char matrizEquipos[F][C], int matrizDatos[F][C]){
    if (leerArchTitulos(matrizTitulos) == -1 || leerArchEquipos(matrizEquipos) == -2 || leerArchDatos(matrizDatos) == -3){
        if (leerArchTitulos(matrizTitulos) == -1) {
            printf("-\nError en la carga del archivo de Titulos.\n");
        }
        if (leerArchEquipos(matrizEquipos) == -2) {
            printf("-\nError en la carga del archivo de Equipos.\n");
        }
        if (leerArchDatos(matrizDatos) == -3) {
            printf("-\nError en la carga del archivo de Datos.\n");
        }
    }
    else{
        printf("\nLa tabla se cargó correctamente\n");
    }
}

int leerArchTitulos (char matrizTitulos[F][C]){
    FILE* archivoTitulos = fopen("/Users/giulimarchesi/Desktop/Datos/títulos.txt", "r");
    if (archivoTitulos!=NULL){
        int c, i = 0;
        c=fscanf(archivoTitulos, "%[a-z A-Z 0-9] ", matrizTitulos[i]);
        while (c!= EOF){
            i++;
            c=fscanf(archivoTitulos, "%[a-z A-Z 0-9] ", matrizTitulos[i]);
    }
        matrizTitulos[i+1][0] = TERM_C;
        fclose(archivoTitulos);
        return 0;
    }
    else {
        return -1;
    }
}

int leerArchEquipos (char matrizEquipos[F][C]){
    FILE* archivoEquipos = fopen("/Users/giulimarchesi/Desktop/Datos/equipos.txt", "r");
    if (archivoEquipos!=NULL){
        int c, i = 0;
        c=fscanf(archivoEquipos, "%[a-z A-Z 0-9] ", matrizEquipos[i]);
        while (c!= EOF){
            i++;
            c=fscanf(archivoEquipos, "%[a-z A-Z 0-9] ", matrizEquipos[i]);
    }
        matrizEquipos[i+1][0] = TERM_C;
        fclose(archivoEquipos);
        return 0;
    }
    else {
        return -2;
    }
}

int leerArchDatos (int matrizDatos[F][C]){
    FILE* archivoDatos = fopen("/Users/giulimarchesi/Desktop/Datos/datos.txt", "r");
    if (archivoDatos!=NULL){
        int c, i = 0;
        c = fscanf(archivoDatos, "%d,%d,%d,%d,%d,%d,%d ", &matrizDatos[i][0], &matrizDatos[i][1], &matrizDatos[i][2], &matrizDatos[i][3], &matrizDatos[i][4], &matrizDatos[i][5], &matrizDatos[i][6]);
        matrizDatos[i][8] = TERM_I;
        while (c!= EOF){
            i++;
            c = fscanf(archivoDatos, "%d,%d,%d,%d,%d,%d,%d ", &matrizDatos[i][0], &matrizDatos[i][1], &matrizDatos[i][2], &matrizDatos[i][3], &matrizDatos[i][4], &matrizDatos[i][5], &matrizDatos[i][6]);
            matrizDatos[i][8] = TERM_I;
    }
        matrizDatos[i+1][0] = TERM_I;
        fclose(archivoDatos);
        return 0;
    }
    else {
        return -3;
    }
}

/**<---------------------------------------Carga y lectura matrices---------------------------------------------->*/

/**<---------------------------------------Impresion Matrices----------------------------------------------------->*/
void imprimirTitulo(char matrizTitulos [F][C]){
    int f = 0;
    for (f=0; matrizTitulos[f][0]!=TERM_C ;f++){
        if (f==0){
            printf("%-21s", matrizTitulos[0]);
        }
        else{
            printf("%6s", matrizTitulos[f]);
        }
    }
    printf("\n---------------------------------------------------------------------\n");
}

void imprimirEquipo(char matrizEquipos [F][C], int f){
    printf("%-21s", matrizEquipos[f]);
}

void imprimirDato(int matrizDatos [F][C], int f){
    int c = 0, dif = 0;
    for(c=0; matrizDatos[f][c+1]!= TERM_I ; c++){
        printf("%6d", matrizDatos[f][c]);
    }
    dif = matrizDatos[f][c-2] - matrizDatos[f][c-1];
    if (dif>0){
        matrizDatos[f][c] = dif;
        printf("%5c%d", '+', matrizDatos[f][c]);
    }
    else{
        matrizDatos[f][c] = dif;
        printf("%6d", matrizDatos[f][c]);
    }
}

void imprimirContenido(char matrizEquipos [F][C], int matrizDatos [F][C]){
    int f = 0;
    for(f=0 ; matrizEquipos[f][0] != TERM_C ; f++){
        imprimirEquipo(matrizEquipos, f);
        imprimirDato(matrizDatos, f);
        printf("\n");
    }
}
/**<---------------------------------------Impresion Matrices----------------------------------------------------->*/

/**<---------------------------------------Ordenamiento---------------------------------------------------------->*/
void ordenarPor(char matrizEquipos [F][C], int matrizDatos [F][C], int columna) {
    int fa, fb, c, tamEquipos, aux = 0;
    char auxC[C] = {0};
    for(tamEquipos = 0; matrizEquipos[tamEquipos][0] != TERM_C; tamEquipos++);
    for(fa = 0; fa < tamEquipos - 1 ; fa++) {
        for(fb = fa + 1; fb < tamEquipos; fb++) {
            if(matrizDatos[fa][columna] > matrizDatos[fb][columna]) {
                strcpy(auxC, matrizEquipos[fa]);
                strcpy(matrizEquipos[fa], matrizEquipos[fb]);
                strcpy(matrizEquipos[fb], auxC);
                for (c = 0 ; matrizDatos [fa][c+1] != TERM_I; c++) {
                    aux = matrizDatos[fa][c];
                    matrizDatos[fa][c] = matrizDatos[fb][c];
                    matrizDatos[fb][c] = aux;
                }
            }
        }
    }
}

/**<---------------------------------------Ordenamiento---------------------------------------------------------->*/
