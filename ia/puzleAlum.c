/*******************************************/
/* 		      PUZLE.C                      */
/*						                   */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "puzle.h"

int i = 0, j = 0, coste_total = 0;

int obtener_i(tEstado *estado) {
    int i = 0, j = 0;
    
    for (i = 0; i < Ncol; i++) {
        for (j = 0; j < Nfil; j++) {
            if(estado->celdas[i][j] == 1) {
                return i;
            }
        }
    }
    return i;
}

int obtener_j(tEstado *estado) {
    int i = 0, j = 0;
    
    for (i = 0; i < Ncol; i++) {
        for (j = 0; j < Nfil; j++) {
            if(estado->celdas[i][j] == 1) {
                return j;
            }
        }
    }
    return j;
}

tEstado *crearEstado(int celdas[Ncol][Nfil])
{
    tEstado *estado = (tEstado *) malloc(sizeof(tEstado));
    int i, j, ficha;

    for (i=0;i<Ncol;i++) {
        for (j=0;j<Nfil;j++) {
           ficha = celdas[i][j];
           estado->celdas[i][j] = ficha;
           /*estado->fila[ficha]=i;*/
           /*estado->col[ficha]=j;*/
        }
    }
    
    return estado;
}


tEstado *estadoInicial()
{
   return crearEstado(caja_inicial);
}


tEstado *estadoObjetivo()
{
   return crearEstado(caja_final);
}

int coste(unsigned op, tEstado *estado)
{
    int i = obtener_i(estado);
    int j = obtener_j(estado);
    int coste = 0;
    switch (op) {
        case ARRIBA:
            coste += estado->celdas[i - 1][j];
            break;
        case ABAJO:
            coste += estado->celdas[i + 1][j];
            break;
        case IZQUIERDA:
            coste += estado->celdas[i][j - 1];
            break;
        case DERECHA:
            coste += estado->celdas[i][j + 1];
            break;
        default:
            puts("por defecto.");
    }
    coste_total += coste;
    return coste;
}

/* VISUALIZACIÓN DE ESTADOS Y OPERADORES*/


void dispEstado(tEstado *estado)
{
    int i, j, k;
    for (i = 0; i < Ncol; i++) {
        if(i % 2 == 0) {
            printf(ANSI_COLOR_GREEN);
            printf("|   ");
            printf(ANSI_COLOR_RESET);
            printf("%d   ", estado->celdas[i][0]);
            for(j = 1; j < Nfil; j += 2) {
                printf(ANSI_COLOR_GREEN);
                int res = estado->celdas[i][j] / 100;
                if(res == 1) {
                    printf("|   ");
                }
                if(res == 2) {
                    printf("||  ");
                }
                if(res == 3) {
                    printf("||| ");
                }
                printf(ANSI_COLOR_RESET);
                printf("%d   ", estado->celdas[i][j+1]);
            }
            printf(ANSI_COLOR_GREEN);
            printf("|");
            printf(ANSI_COLOR_RESET);
            puts("");
            /*printf("i => %d, j => %d.\n", i, j);*/
        } else {
            int mayor_k = 0;
            for(j = 0; j < Nfil; j += 2) {
                int res = estado->celdas[i][j] / 100;
                if (res > mayor_k)
                    mayor_k = res;
            }
            
            for (k = 1; k <= mayor_k; k++) {
                for(j = 0; j < Nfil; j += 2) {
                    printf(ANSI_COLOR_GREEN);
                    int res = estado->celdas[i][j] / 100;
                    if(res - k >= 0)
                        printf("--------");
                    else
                        printf("        ");
                }
                puts("");
            }
        }
    }
}


void dispOperador(unsigned op)
{
   switch(op)
   {
      case ARRIBA:    printf("Movimiento ARRIBA:\n"); break;
      case ABAJO:     printf("Movimiento ABAJO:\n"); break;
      case IZQUIERDA: printf("Movimiento IZQUIERDA:\n"); break;
      case DERECHA:   printf("Movimiento DERECHA:\n"); break;
   }
}

// FUNCIONES QUE SE HAN DE IMPLEMENTAR EN LA PRACTICA 1

// Función auxiliar para comprobar si dos puzles tienen las fichas colocadas en el mismo orden en el tablero
int iguales(tEstado *s, tEstado *t)  //
{
    int i, j = Nfil;
    
    for (i = 0; i < Ncol; i++) {
        for (j = 0; j < Nfil; j++) {
            if(s->celdas[i][j] != t->celdas[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}


int testObjetivo(tEstado *estado)
{
    
    return iguales(estado, estadoObjetivo());
}


int esValido(unsigned op, tEstado *estado)
{
    int esValido = 0;
    int i = obtener_i(estado);
    int j = obtener_j(estado);
    i++;
    j++;
    switch (op) {
        case ARRIBA:
            if(i > 0) {
                puts("Se puede mover arriba.");
                esValido = 1;
            }
            break;
        case ABAJO:
            if(i < Ncol) {
                puts("Se puede mover abajo.");
                esValido = 1;
            }
            break;
        case IZQUIERDA:
            if(j > 0) {
                puts("Se puede mover a la izquierda.");
                esValido = 1;
            }
            break;
        case DERECHA:
            if(j < Nfil) {
                puts("Se puede mover a la derecha.");
                esValido = 1;
            }
            break;
        default:
            puts("Operador Invalido.");
    }
    return esValido;
}

tEstado *aplicaOperador(unsigned op, tEstado *estado)
{
    tEstado *nuevo = (tEstado *) malloc(sizeof(tEstado));
    memcpy(nuevo, estado, sizeof(tEstado));  // Hace una copia del estado
    
    int aux;
    if(esValido(op, nuevo)) {
        printf("El coste en esta operacion es => %d.\n", coste(op, nuevo));
        printf("El coste total es => %d.\n", coste_total);
        
        switch (op) {
            case ARRIBA:
                nuevo->celdas[i][j] = nuevo->celdas[i-2][j];
                i-=2;
                nuevo->celdas[i][j] = 1;
                break;
            case ABAJO:
                nuevo->celdas[i][j] = nuevo->celdas[i+2][j];
                i+=2;
                nuevo->celdas[i][j] = 1;
                break;
            case IZQUIERDA:
                nuevo->celdas[i][j] = nuevo->celdas[i][j-2];
                j-=2;
                nuevo->celdas[i][j] = 1;
                break;
            case DERECHA:
                nuevo->celdas[i][j] = nuevo->celdas[i][j+2];
                j+=2;
                nuevo->celdas[i][j] = 1;
                break;
            default:
                puts("por defecto.");
        }
    } else {
        puts("Error, no se puede mover hacia este lado.");
    }
    
    dispEstado(nuevo);
    return nuevo;
}

int main(void) {
    
    /*iguales(estadoInicial(), estadoObjetivo());*/
    
    tEstado *estado = estadoInicial();
    
    dispEstado(estado);
    estado = aplicaOperador(2, estado);
    estado = aplicaOperador(4, estado);
    estado = aplicaOperador(4, estado);
    estado = aplicaOperador(4, estado);
    estado = aplicaOperador(2, estado);
    estado = aplicaOperador(2, estado);
    
    return 0;
}


