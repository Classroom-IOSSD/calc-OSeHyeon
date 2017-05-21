#include "my_fscanf.h"
#include <stdarg.h>
#include <ctype.h>

void my_fscanf(FILE* fp, const char* format, ...) {
        va_list list;
        va_start(list, format);
        
        while(*format) {
                if(*format == '%') {
                        format ++;

                        switch(*format) {
                        case 'd': {
                            int c = getc(list);
                            printf("%d", c);
                            break;
                        }
                        case 'c': {
                            char c = getc(list);
                            printf("%c", c);
                            break;
                        }
                        default: break;
                        }
                }
                else if(*format == ' ') format ++;
                else if(*format == '\0') return 0;
        }
        va_end(list);
}
