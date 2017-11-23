/*******************************************/
/* 		      PUZLE.H                      */
/*						                   */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/

#define ARRIBA 1
#define ABAJO 2
#define IZQUIERDA 3
#define DERECHA 4
#define NUM_OPERADORES 4
#define Ncol 7
#define Nfil 5

//===================================
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#ifndef _tEstado_
#define _tEstado_
   typedef struct {
        int celdas[Ncol][Nfil];
   } tEstado;
#endif


static int caja_inicial[Ncol][Nfil]=
{
  {1, 100, 0, 100, 0},
  {100, 0, 100, 0, 100},
  {0, 200, 0, 100, 0},
  {200, 0, 100, 0, 200},
  {0, 100, 0, 100, 0},
  {300, 0, 300, 0, 300},
  {0, 100, 0, 300, 0}
};


static int caja_final[Ncol][Nfil]=
{
  {0, 100, 0, 100, 0},
  {100, 0, 100, 0, 100},
  {0, 200, 0, 100, 0},
  {200, 0, 100, 0, 200},
  {0, 100, 0, 100, 0},
  {300, 0, 300, 0, 300},
  {0, 100, 0, 300, 1}
};

tEstado *crearEstado(int celdas[Ncol][Nfil]);
tEstado *estadoInicial();
int coste(unsigned op, tEstado *estado);
void dispEstado(tEstado *estado);
void dispOperador(unsigned op);
tEstado *estadoObjetivo();
int esValido(unsigned op, tEstado* estado);
tEstado *aplicaOperador(unsigned op, tEstado *estado);
int iguales(tEstado *s, tEstado *t);
int testObjetivo(tEstado *estado);

int obtener_i(tEstado *estado);
int obtener_j(tEstado *estado);
