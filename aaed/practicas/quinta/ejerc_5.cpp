#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <curses.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

#include "pila.h"

using namespace std;

// Post condicion: Devuelve el codigo de la key arrow presionada o 0 si ha pulsado escape.
int kbhit(void)
{
    int key_code = 0;
    bool fin_programa = false;
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
        
        if((SpecialKeyCode = getchar()) != EOF)
        {
            if(SpecialKeyCode == 91)
            {
                // Sequence code found, now next code will inform us
                // regarding the arrow key pressed (65,66,67,68) 
                system("clear");
                if ((arrow_code = getchar()) != EOF) {
                   switch(arrow_code) {
                       case 67: key_code = 1; break;
                       case 68: key_code = 2; break;
                   }
                }
            }
        } else {
            //There isn't new code, this mean 27 came from ESC key pression
            key_code = 10;
        }
        tcsetattr(STDIN_FILENO, TCSANOW, &original_ts);
    }
    system ("/bin/stty cooked");
    return key_code;
}

int main() {
    
    return 0;
    
}
