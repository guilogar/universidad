/*******************************************/
/*             BUSQUEDA.C                  */
/*                                         */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "puzle.h"
#include "nodo.h"
#include "listaia.h"
#include "busquedaAlum.h"

#include "puzleAlum.c"
#include "listaia.c"

int heuristica = 1;
int contador_estados_visit = 0;
int busq_voraz = 0;

void dispCamino(tNodo *nodo)
{
   if (nodo->padre == NULL)
   {
      printf("\n\nInicio:\n");
      dispEstado(nodo->estado);
   }
   else
   {
      dispCamino(nodo->padre);
      dispOperador(nodo->operador);
      dispEstado(nodo->estado);
      printf("\n");
   }
}


void dispSolucion(tNodo *nodo, Lista l, Lista n)
{
   dispCamino(nodo);
   printf("Profundidad=%d\n",nodo->profundidad);
   printf("Coste=%d\n",nodo->costeCamino);
   printf("El numero de estados visitados es => %d.\n", contador_estados_visit);
   printf("El numero de nodos abiertos es => %d.\n", n->Nelem);
   printf("El numero de nodos cerrados es => %d.\n", l->Nelem);
}


/* Crea el nodo raiz. */
tNodo *nodoInicial()
{
   tNodo *inicial=(tNodo *) malloc(sizeof(tNodo));

   inicial->estado=estadoInicial();
   inicial->padre=NULL;
   inicial->costeCamino=0;
   inicial->profundidad=0;
   inicial->num_veces_visitado = 1;
   return inicial;
}

int heuristica_est(tEstado *t) {
    int total = 0;
    tEstado *s = estadoObjetivo();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if(t->celdas[i][j] != s->celdas[i][j])
                total++;
        }
    }
    return total;
}

int obtener_fila(int valor, tEstado *t) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if(t->celdas[i][j] == valor)
                return i;
        }
    }
    return -1;
}
int obtener_columna(int valor, tEstado *t) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if(t->celdas[i][j] == valor)
                return j;
        }
    }
    return -1;
}
int heuristica_man(tEstado *t) {
    int total = 0;
    tEstado *s = estadoObjetivo();
    for(int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int f = obtener_fila(k, t) - obtener_fila(k, s);
                int g = obtener_columna(k, t) - obtener_columna(k, s);
                total += abs(f) + abs(g);
            }
        }
    }
    return total;
}

Lista insertar_orden(Lista abiertos, tNodo *n) {
    
    int n_insert = 0;
    int i = abiertos->inicio;
    Lista aux = (Lista) CrearLista(MAXI);
    while(i != abiertos->fin) {
        if(i == abiertos->Lmax) {
            i = 0;
        }
        tNodo *nod = (tNodo*) malloc(sizeof(tNodo));
        nod = (void *) ExtraerElem(abiertos, i);
        
        if(nod->valHeuristica > n->valHeuristica && !n_insert) {
            InsertarUltimo((void *) n, aux);
            n_insert = 1;
        }
        InsertarUltimo((void *) nod, aux);
        i++;
    }
    return aux;
}

Lista a_estrella(Lista abiertos, Lista sucesores) {
    
    if(ListaVacia(abiertos) && !ListaVacia(sucesores)) {
        InsertarUltimo(ExtraerPrimero(sucesores), abiertos);
        EliminarPrimero(sucesores);
    }
    
    while(!ListaVacia(sucesores)) {
        tNodo *n = (tNodo *) ExtraerPrimero(sucesores);
        EliminarPrimero(sucesores);
        abiertos = insertar_orden(abiertos, n);
    }
    return abiertos;
}
Lista voraz(Lista abiertos, Lista sucesores) {
    
    if(ListaVacia(abiertos) && !ListaVacia(sucesores)) {
        InsertarUltimo(ExtraerPrimero(sucesores), abiertos);
        EliminarPrimero(sucesores);
    }
    
    if(!ListaVacia(sucesores)) {
        tNodo *n = (tNodo *) ExtraerPrimero(sucesores);
        EliminarPrimero(sucesores);
        abiertos = insertar_orden(abiertos, n);
    }
    return abiertos;
}

/* Expande un nodo. */
Lista expandir(tNodo *nodo)
{
   unsigned op;
   Lista sucesores=CrearLista(MAXI);
   for (op=1;op<=NUM_OPERADORES;op++)
   {
      if (esValido(op,nodo->estado))
      {
         tNodo *nuevo=(tNodo *) malloc(sizeof(tNodo));
         tEstado *s=(tEstado *) malloc(sizeof(tEstado));
         s=aplicaOperador(op,nodo->estado);
         nuevo=(tNodo *) malloc(sizeof(tNodo));
         nuevo->estado=s;
         nuevo->padre=nodo;
         nuevo->operador=op;
         nuevo->costeCamino=nodo->costeCamino + coste(op,nodo->estado);
         nuevo->profundidad=nodo->profundidad + 1;
         nuevo->valHeuristica = (heuristica) ? heuristica_est(s) : heuristica_man(s);

         contador_estados_visit++;

         if (!ListaLlena(sucesores)){
              InsertarUltimo((void *) nuevo,sucesores);
         }
      }
  }
  return sucesores;
}


int busqueda()
{
   int objetivo = 0;
   int repetido = 0;
   tNodo *Actual=(tNodo*) malloc(sizeof(tNodo));

   tNodo *Inicial=nodoInicial();
   //tEstado *Final=estadoObjetivo();

   Lista Abiertos = (Lista) CrearLista(MAXI);
   Lista Cerrados = (Lista) CrearLista(MAXI);
   Lista Sucesores;

   InsertarUltimo((void *) Inicial, Abiertos);

   while (!ListaVacia(Abiertos) && !objetivo)
   {
      Actual = (void *) ExtraerPrimero(Abiertos);
      printf("\n ACTUAL: \n");
      dispEstado(Actual->estado);

      // Esto pa el linux, la calidad suprema.
      /*printf("Press 'Enter' to continue: ... ");*/
      /*while ( getchar() != '\n');*/

      EliminarPrimero(Abiertos);
      objetivo = testObjetivo(Actual->estado);

      repetido = buscaRepe(Actual->estado, Cerrados);
      if(!ListaLlena(Cerrados)) {
          InsertarUltimo((void *) Actual, Cerrados);
      } else {
          puts(ANSI_COLOR_RED);
          puts("ERROR: NO HAY SUFICIENTE MEMORIA.");
          puts(ANSI_COLOR_RESET);
      }

      if (!objetivo && !repetido)
      {
         Sucesores = expandir(Actual);
         /*Abiertos = Concatenar(Abiertos, Sucesores);*/
         if(busq_voraz)
             Abiertos = a_estrella(Abiertos, Sucesores);
         else
            Abiertos = voraz(Abiertos, Sucesores);
      }
   }
   dispSolucion(Actual, Cerrados, Abiertos);
   return objetivo;
}

int buscaRepe(tEstado *s, Lista l1) {
    int i = l1->inicio;
    while(i != l1->fin) {
        if(i == l1->Lmax) {
            i = 0;
        }
        tNodo *nod = (tNodo*) malloc(sizeof(tNodo));
        nod = (void *) ExtraerElem(l1, i);
        if(iguales(nod->estado, s)) {
            puts(ANSI_COLOR_YELLOW);
            puts("--Atención-- NODO REPETIDO.");
            puts(ANSI_COLOR_RESET);
            return 1;
        }
        i++;
    }
    return 0;
}

int main(void) {

    /*iguales(estadoInicial(), estadoObjetivo());*/
    /*esValido(3, estadoInicial());*/
    busq_voraz = 1;
    busqueda();
    return 0;
}
