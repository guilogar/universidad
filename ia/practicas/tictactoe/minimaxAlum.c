/*******************************************/
/* 		    minimaxAlum.c                  */
/*       Estrategia MiniMax                */
/*						                   */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tictactoe.h"

#define LIMITE 5
/*
 *tNodo *PSEUDOminimax(tNodo *t) {
 *     int mejorJugada = -1;
 *     int puntos = -2;
 *     int i, temp;
 *     tNodo *intento=malloc(sizeof(tNodo));
 *     printf("\n Mi turno: \n");
 *     for(i = 0; i < N; ++i){
 *      if (esValida(t,i)) {
 *            intento=aplicaJugada(t,1,i); //Intenta jugada
 *            temp = terminal(intento,-1); // Calcula el valor minimax
 *            if(temp > puntos) {
 *              puntos = temp;
 *              mejorJugada = i;
 *            }
 *      }} //for
 *      t=aplicaJugada(t,1,mejorJugada);
 *      return t;
 *}
 */

int heuristica(tNodo *nodo) {
    unsigned opciones[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    int i=0,res=0, contador_maquina = 0, contador_humano = 0;
    
    /*
     *while (res == 0 && i < 8) {
     *  
     *    if(nodo->celdas[opciones[i][0]] != 0 &&
     *       nodo->celdas[opciones[i][0]] == nodo->celdas[opciones[i][1]] &&
     *       nodo->celdas[opciones[i][0]] == nodo->celdas[opciones[i][2]])
     *       res = nodo->celdas[opciones[i][2]];
     *  i++;
     *}
     */
    
    /*
     *for (i = 0; i < N; i++) {
     *    if(nodo->celdas[i] == 1) {
     *        contador_maquina++;
     *    }
     *    if(nodo->celdas[i] == -1) {
     *        contador_humano++;
     *    }
     *}
     */
    return (contador_maquina - contador_humano);
}

int min(int i, int j) {
    if(j < i) {
        i = j;
    }
    return i;
}

int max(int i, int j) {
    if(j > i) {
        i = j;
    }
    return i;
}

int valorMin(tNodo *nodo, int profundidad) {
    int valor_min, jugada, jugador = -1;
    if(profundidad < LIMITE) {
        if(nodo->vacias == 0 || terminal(nodo)) {
            valor_min = terminal(nodo);
        } else {
            valor_min = 100000;
            for (jugada = 0; jugada < N; jugada++) {
                if(esValida(nodo, jugada)) {
                    valor_min = min(valor_min, valorMax(aplicaJugada(nodo, jugador, jugada), ++profundidad));
                }
            }
        }
    }
    return valor_min;
}

int valorMax(tNodo *nodo, int profundidad) {
    int valor_max, jugada, jugador = 1;
    if(profundidad < LIMITE) {
        if(nodo->vacias == 0 || terminal(nodo)) {
            valor_max = terminal(nodo);
        } else {
            valor_max = -100000;
            for (jugada = 0; jugada < N; jugada++) {
                if(esValida(nodo, jugada)) {
                    valor_max = max(valor_max, valorMin(aplicaJugada(nodo, jugador, jugada), ++profundidad));
                }
            }
        }
    }
    return valor_max;
}

tNodo *jugadaAdversario(tNodo *t) {
     int jugada = 0;
     printf("\nJugada ([0..8])?: ");
     scanf("%d", &jugada);
     while (!esValida(t,jugada))
     {
        printf("\n Intenta otra posicion del tablero \n");
        printf("\n");
        printf("\nJugada ([0..8])?: ");
        scanf("%d", &jugada);
     }
     t=aplicaJugada(t,-1,jugada);
     return t;
}

tNodo* minimax(tNodo *nodo, int jugador) {
    int max, max_actual, jugada, mejorJugada, i, profundidad = 0;
    tNodo *intento = malloc(sizeof(tNodo));
    
    max = -10000;
    for (jugada = 0; jugada < N; jugada++) {
        if(esValida(nodo, jugada)) {
            intento = aplicaJugada(nodo, jugador, jugada);
            max_actual = valorMin(intento, profundidad);
            if(max_actual > max) {
                max = max_actual;
                mejorJugada = jugada;
            }
        }
    }
    nodo = aplicaJugada(nodo, jugador, mejorJugada);
    return nodo;
}

tNodo* poda_ab(tNodo *nodo, int jugador) {
    int alfa, beta, jugada, mejorJugada, prof, v;
    tNodo *intento = malloc(sizeof(tNodo));
    
    alfa = -10000;
    beta = +10000;
    prof = 1;
    jugada = 1;
    
    while(jugada <= N) {
        if(esValida(nodo, jugada)) {
            intento = aplicaJugada(nodo, jugador, jugada);
            v = valorMin_ab(intento, opuesto(jugador), prof+1, alfa, beta);
            if(v > alfa) {
                alfa = v;
                mejorJugada = jugada;
            }
        }
        jugada++;
    }
    if(esValida(nodo, mejorJugada)) {
        nodo = aplicaJugada(nodo, jugador, mejorJugada);
    }
    return nodo;
}

int valorMax_ab(tNodo *nodo, int jugador, int prof, int alfa, int beta) {
    int vmax, jugada;
    tNodo *intento = malloc(sizeof(tNodo));
    
    if(nodo->vacias == 0 || terminal(nodo)) {
        vmax = terminal(nodo);
    } else if (prof == LIMITE) {
        vmax = heuristica(nodo);
    } else {
        jugada = 1;
        while(jugada <= N && alfa < beta) {
            if(esValida(nodo, jugada)) {
                intento = aplicaJugada(nodo, jugador, jugada);
                alfa = max(alfa, valorMin_ab(intento, opuesto(jugador), prof+1, alfa, beta));
            }
            jugada++;
        }
        vmax = alfa;
    }
    return vmax;
}

int valorMin_ab(tNodo * nodo, int jugador, int prof, int alfa, int beta) {
    int vmin, jugada;
    tNodo *intento = malloc(sizeof(tNodo));
    
    if(nodo->vacias == 0 || terminal(nodo)) {
        vmin = terminal(nodo);
    } else if (prof == LIMITE) {
        vmin = heuristica(nodo);
    } else {
        jugada = 1;
        while(jugada <= N && alfa < beta) {
            if(esValida(nodo, jugada)) {
                intento = aplicaJugada(nodo, jugador, jugada);
                beta = min(beta, valorMax_ab(intento, opuesto(jugador), prof+1, alfa, beta));
            }
            jugada++;
        }
        vmin = beta;
    }
    return vmin;
}
