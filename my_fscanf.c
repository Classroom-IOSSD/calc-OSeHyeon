#include "my_fscanf.h"
#include <stdarg.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

void my_fscanf(FILE* fp, const char* format, ...) {
        va_list list;
        va_start(list, format);
        
        while(*format) {
                if(*format == '%') {
                        format ++;

                        switch(*format) {
                        case 'd': {
                            int* intPointer = va_arg(list, int*);
                            int intNum = atoi(*intPointer);
                            break;
                        }
                        case 'c': {
                            char* charPointer = va_arg(list, char*);
                            char character = *charPointer;
                            break;
                        }
                        case 's': {
                            char* string;

                            char check = *list;
                            int index = 0;
                            while (check != ' ') {
                                    string[index] = check;
                                    index++;
                                    list++;
                                    list++; check = *list;
                            }
                            for (int i = 0 ; i < index ; ++i)
                                    printf("%c", string[index]);
                            break;
                                  }
                        case 'f': {
                                          char* string;

                                          char check = *list;
                                          int index = 0;
                                          while (check != ' ') {
                                                  string[index] = check; index++;
                                                  list++; check == *list;
                                          }
                                          string[index + 1] = '\0';
                                          double floatNum = atof(*string);
                                          printf("%f", floatNum);
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
