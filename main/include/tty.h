/*
    Copyright (C) Aren Elchinyan 2021-2022. All rights reserved.
    Distributed under terms of the Creative Commons Zero v1.0 Universal License.
*/


#pragma once


#include <stdint.h>
#include <stddef.h>


#define COLS 80                                 // Screen width
#define ROWS 25                                 // Screen height
#define SCREEN_SIZE COLS * ROWS                 // Screen height


extern int col, row;


enum COLORS {
    COLOR_BLACK = 0,
    COLOR_BLUE = 1,
    COLOR_GREEN = 2,
    COLOR_CYAN = 3,
    COLOR_RED = 4,
    COLOR_PURPLE = 5,
    COLOR_BROWN = 6,
    COLOR_GRAY = 7,
    COLOR_DARK_GRAY = 8,
    COLOR_LIGHT_BLUE = 9,
    COLOR_LIGHT_GREEN = 10,
    COLOR_LIGHT_CYAN = 11,
    COLOR_LIGHT_RED = 12,
    COLOR_LIGHT_PURPLE = 13,
    COLOR_YELLOW = 14,
    COLOR_WHITE = 15
};


void update_cursor(size_t row, size_t col);     // Move cursor function
void clean_screen();                            // Clean screen function
void backspace();                            // backspace
void set_color(uint8_t new_color);              // Change terminal color function
void putchar(const char c);                     // Write a char function
void puts(const char c[]);                      // Write a string function
void putsln(const char c[]);                      // Write a string function
void putint(const int i);                       // Write an integer function
void log_puts(const char c[]);                  // Write a string to log function
void log_putsln(const char c[]);                  // Write a string to log function
void video_scroll();