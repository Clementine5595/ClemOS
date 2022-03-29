/*
    (C) Арен Елчинян 2021-2022. Все права защищены.
    Распространяется по лицензии Apache-2.0.
*/


#pragma once


#include <stddef.h>

int strcmp(const char *str1, const char *str2);
int memcmp(const void *s1, const void *s2, size_t n);
size_t str_bksp(char *str, char c);