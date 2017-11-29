#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <curses.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <string>

#include "pila.h"

//===================================
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

using namespace std;

void printf_info(Pila<char> p, Pila<char> t, string modo) {
    string before;
    cout << "Modo del editor: " << modo << endl;
    while(!p.vacia()) {
        before += p.tope();
        p.pop();
    }
    for (int i = before.length() - 1; i >= 0; i--) {
        cout << before[i];
    }
    cout << ANSI_COLOR_RED << "|" << ANSI_COLOR_RESET;
    while(!t.vacia()) {
        cout << t.tope();
        t.pop();
    }
}

// Post condicion: Devuelve el codigo de la key arrow presionada o 0 si ha pulsado escape.
int kbhit(void)
{
    int key_code = 0;
    system ("/bin/stty raw");
    
    unsigned int character = getchar();
    key_code = character;
    if(character == 27) {
        struct termios original_ts, nowait_ts;
        unsigned int SpecialKeyCode;
        unsigned int arrow_code;

        tcgetattr(STDIN_FILENO, &original_ts);
        nowait_ts = original_ts;
        nowait_ts.c_lflag &= ~ISIG;
        nowait_ts.c_cc[VMIN]  = 0;
        nowait_ts.c_cc[VTIME] = 0;
        tcsetattr(STDIN_FILENO, TCSANOW, &nowait_ts);
        
        usleep(100*1000);
        
        if((SpecialKeyCode = getchar()) != EOF) {
            if(SpecialKeyCode == 91) {
                // Sequence code found, now next code will inform us
                // regarding the arrow key pressed (65,66,67,68) 
                //system("clear");
                if ((arrow_code = getchar()) != EOF) {
                    //cout << "El caracter es => " << arrow_code;
                    switch(arrow_code) {
                        case 67: key_code = -1; break; // Derecha
                        case 68: key_code = -2; break; // Izquierda
                        case 70: key_code = -3; break; // Fin texto
                        case 72: key_code = -4; break; // Principio texto
                    }
                }
            }
        } else {
            //There isn't new code, this mean 27 came from ESC key pression
            key_code = -100;
        }
        tcsetattr(STDIN_FILENO, TCSANOW, &original_ts);
    }
    system ("/bin/stty cooked");
    return key_code;
}

Pila<char> introduce_texto_pila(string texto) {
    Pila<char> p;
    for (int i = 0; i < texto.length(); i++) {
        p.push(texto[i]);
    }
    return p;
}

void move_cursor_to_left(Pila<char> &p, Pila<char> &t) {
    if(!p.vacia()) {
        char c = p.tope();
        p.pop();
        t.push(c);
    }
}
void move_cursor_to_right(Pila<char> &p, Pila<char> &t) {
    if(!t.vacia()) {
        char c = t.tope();
        t.pop();
        p.push(c);
    }
}
void move_cursor_to_begin(Pila<char> &p, Pila<char> &t) {
    while(!p.vacia())
        move_cursor_to_left(p, t);
}
void move_cursor_to_end(Pila<char> &p, Pila<char> &t) {
    while(!t.vacia())
        move_cursor_to_right(p, t);
}

void create_editor(bool read_mode, bool fin_programa, 
                   bool reemplace, bool movements) {
    int c;
    string texto;
    Pila<char> before_cursor;
    Pila<char> after_cursor;
    
    cout << "Escriba algo: " << endl;
    getline(cin, texto);
    before_cursor = introduce_texto_pila(texto);
    
    system("clear");
    printf_info(before_cursor, after_cursor, (read_mode) ? "Lectura" : "Edición");
    
    while(!fin_programa && (c = kbhit())) {
        movements = true;
        if(!read_mode && c > 0) {
            if(c == 127) {
                before_cursor.pop();
            } else {
                before_cursor.push(c);
            }
        }
        if (read_mode && reemplace && !before_cursor.vacia() && 
            c != 127 && c > 0) {
            before_cursor.pop();
            before_cursor.push(c);
            reemplace = false;
            movements = false;
        }
        switch(c) {
            case -100: {
                        read_mode = true;
                       }; break;
            case -1: move_cursor_to_right(before_cursor, after_cursor); break;
            case -2: move_cursor_to_left(before_cursor, after_cursor); break;
            case -3: move_cursor_to_end(before_cursor, after_cursor); break;
            case -4: move_cursor_to_begin(before_cursor, after_cursor); break;
            case 97: {
                      read_mode = false;
                     }; break;
            case 113: {
                       if(read_mode) {
                           fin_programa = true;
                       }
                     }; break;
            case 120: {
                       if(read_mode && !before_cursor.vacia()) {
                           before_cursor.pop();
                       }
                     }; break;
            case 105: {
                       if(!before_cursor.vacia()) {
                           char p = before_cursor.tope();
                           before_cursor.pop();
                           if(!before_cursor.vacia()) {
                               before_cursor.pop();
                               before_cursor.push(p);
                           }
                       }
                     }; break;
            case 114: {
                       if(read_mode && movements) {
                           reemplace = true;
                       }
                     }; break;
        }
        system("clear");
        printf_info(before_cursor, after_cursor, (read_mode) ? "Lectura" : "Edición");
    }
}

int main() {
    bool read_mode = true, fin_programa = false;
    bool reemplace = false, movements = false;
    
    create_editor(read_mode, fin_programa, reemplace, movements);
    cout << endl << endl << "Fin del programa." << endl;
    
    return 0;
}
