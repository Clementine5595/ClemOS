#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>

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

extern void *memcpy(unsigned char *dest, const unsigned char *src, size_t count);
extern void *memset(unsigned char *dest, unsigned char val, size_t count);
extern unsigned short *memsetw(unsigned short *dest, unsigned short val, size_t count);
extern size_t strlen(const char *str);
extern unsigned char inportb (unsigned short _port);
extern void outportb (unsigned short _port, unsigned char _data);
extern void update_cursor(size_t row, size_t col);     // Move cursor function
extern void clear_screen();                            // Clean screen function
extern void backspace();                               // backspace
extern void set_color(uint8_t new_color);              // Change terminal color function
extern void putchar(const char c);                     // Write a char function
extern void puts(const char c[]);                      // Write a string function
extern void putsln(const char c[]);                    // Write a string function
extern void putint(const int i);                       // Write an integer function
extern void video_scroll();