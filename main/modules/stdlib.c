/*
    (C) Арен Елчинян 2021-2022. Все права защищены.
    Распространяется по лицензии Apache-2.0.
*/


#include <libk/stdlib.h>
#include <libk/string.h>


/*
    strver is used to reverse the order of characters in a string

    str is input string
 */
void strver(char *str) {
    char c;
    int j = strlen(str) - 1;

    for (int i = 0; i < j; i++) {
        c = str[i];
        str[i] = str[j];
        str[j] = c;
        j--;
    }
}


/*
    itoa is used to write a number in string representation

    n is the original number
    buffer is a buffer for writing
 */
int itoa(int n, char *buffer) {
    int length = n < 0;
    
    if (length) {
        n = -n;
        *buffer = '-';
    }
    
    do {
        buffer[length++] = (n % 10) + '0';
        n /= 10;
    } while (n > 0);

    buffer[length] = '\0';
    strver(buffer);
    
    return length;
}