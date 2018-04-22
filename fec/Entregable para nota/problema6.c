#include <stdarg.h>
#include <stdio.h>
#include <string.h>

int myprintf(char s[], int count, ...)
{
    va_list list;
    int i = 0;
    
    va_start(list, count);
    for(i = 0; i < strlen(s); i++) {
        if(s[i] == '%' && count > 0) {
            switch (s[i+1]) {
                case 's': printf("%s", va_arg(list, char*)); break;
                case 'c': printf("%c", va_arg(list, int)); break;
                case 'i': printf("%i", va_arg(list, int)); break;
                case 'd': printf("%lf", va_arg(list, double)); break;
            }
            count--;
            i++;
        } else {
            printf("%c", s[i]);
        }
    }
    va_end(list);
    
    return count;
}

int main(int argc, const char *argv[])
{
    myprintf("abc%c %s %d %ajsdbjbdf", 3, 'd', "holi", 456.56);
    return 0;
}
