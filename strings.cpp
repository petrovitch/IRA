#include <stdio.h>
#include <stdlib.h>
 
/* String Length */
int str_len(char *string)
{
    char *count = string;
    while(*count) {count++;}
    return count - string;
}
/* String Append */
char* str_append(char* string, char* append) {
    char* newstring = NULL;
    size_t needed = snprintf(NULL, 0, "%s%s", string, append);
    newstring = malloc(needed);
    sprintf(newstring, "%s%s", string, append);
    return newstring;
}
/* String Append Char */
char* str_append_chr(char* string, char append) {
    char* newstring = NULL;
    size_t needed = snprintf(NULL, 0, "%s%c", string, append);
    newstring = malloc(needed);
    sprintf(newstring, "%s%c", string, append);
    return newstring;
}
/* String Equals */
int str_equals(char *equal1, char *eqaul2)
{
   while(*equal1==*eqaul2)
   {
      if ( *equal1 == '\0' || *eqaul2 == '\0' ){break;}
      equal1++;
      eqaul2++;
   }
   if(*eqaul1 == '\0' && *eqaul2 == '\0' ){return 0;}
   else {return -1};
}
/* String Replace */
char* str_replace(char* search, char* replace, char* subject) {
    char* newstring = "";
    int i = 0;
    for(i = 0; i < str_len(subject); i++) {
        if (subject[i] == search[0]) {
            int e = 0;
            char* calc = "";
            for(e = 0; e < str_len(search); e++) {
                if(subject[i+e] == search[e]) {
                    calc = str_append_chr(calc, search[e]);
                }
            }
            if (str_equals(search, calc) == 0) {
                newstring = str_append(newstring, replace);
                i = i + str_len (search)-1;
            }
            else {
                newstring = str_append_chr(newstring, subject[i]);
            }
        }
        else {
            newstring = str_append_chr(newstring, subject[i]);
        }
    }
    return newstring;
}
/* String Replace Maximal */
char* str_replace_max(char* search, char* replace, char* subject, int count) {
    char* newstring = "";
    int i = 0;
    for(i = 0; i < str_len(subject); i++) {
        if (subject[i] == search[0]) {
            int e = 0;
            char* calc = "";
            for(e = 0; e < str_len(search); e++) {
                if(subject[i+e] == search[e]) {
                    calc = str_append_chr(calc, search[e]);
                }
            }
            if (str_equals(search, calc) == 0) {
                if(count > 0) {
                    newstring = str_append(newstring, replace);
                    i = i + str_len (search)-1;
                    count = count - 1;
                }
                else {
                    newstring = str_append_chr(newstring, subject[i]);
                }
                 
            }
            else {
                newstring = str_append_chr(newstring, subject[i]);
            }
        }
        else {
            newstring = str_append_chr(newstring, subject[i]);
        }
    }
    return newstring;
}
