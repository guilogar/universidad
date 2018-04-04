#include <stdio.h>
#include <string.h>

void miprintf(char* msg, char* cad, int num)
{
    char aux;
    do
    {
        aux = *msg;
        
        if (aux == '$')
        {
            puts(cad);
        }
        else
        {
            if(aux == '#')
            {
                printf("%d", num);
            }
            else
            {
                printf("%c", aux);
            }
        }
        msg++;
    } while (aux != '\0');
}

int main(int argc, const char *argv[])
{
    char ciudad[] = "Cádiz";
    int poblacion = 121000;
    char msg[] = "La ciudad de $ tiene # habitantes.";
    
    miprintf(msg, ciudad, poblacion);
    
    return 0;
}

/*
 *void pepe(int )
 *{
 *    return a;
 *}
 */
