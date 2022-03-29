/*
    Copyright (C) Aren Elchinyan 2021-2022. All rights reserved.
    Distributed under terms of the Creative Commons Zero v1.0 Universal License.
*/

#include <system.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>


uint16_t* terminal_buffer = (uint16_t*) 0xC03FF000; // Text based output using MMIO

int col, row;
uint8_t color = COLOR_WHITE;



/*
    update_cursor is used to move cursor

    row - current row
    col - current column
*/
void update_cursor(size_t row, size_t col) {
    unsigned short position = (row * COLS) + col + 1;

    // cursor LOW port to vga INDEX register
    outportb(0x3D4, 0x0F);
    outportb(0x3D5, (unsigned char)(position & 0xFF));

    // cursor HIGH port to vga INDEX register
    outportb(0x3D4, 0x0E);
    outportb(0x3D5, (unsigned char)((position >> 8) & 0xFF));
}


/*
    clear_screen is used to clear the screen
*/
void clear_screen() {
    memset(terminal_buffer, 0, SCREEN_SIZE);

    col = -1;
    row = 0;

    update_cursor(0, 0);
}


/*
    clear_screen is used to clear the screen
*/
void backspace() {
    const size_t index = row * 80 + col;
    terminal_buffer[index] = (uint16_t) ' ' | (uint16_t) color << 8;

	if (col == 0) {
		if (row > 0) {
			row--;
            col = 79;
		}
	} else {
		col--;
	}

	update_cursor(row, col);
}



/*
    set_color is used to change output color

    color - a color for text
*/
void set_color(uint8_t new_color) {
    color = new_color;
}


/*
    putchar is used to print char

    c - a symbol that must be displayed on the screen.
*/
void putchar(const char c) {
    if (++col == 81){
        col = -1;
        row++;
        video_scroll();
    }

    const size_t index = row * 80 + col;
    terminal_buffer[index] = (uint16_t) c | (uint16_t) color << 8;

    update_cursor(row, col);
    
}


/*
    putsln is used to print string with newline

    c - a string that must be displayed on the screen.
*/
void putsln(const char c[]) {
    for (size_t i = 0; i < strlen(c); i++) {
        putchar(c[i]);
    }

    col = -1;
    row++;
    video_scroll();
}


/*
    putsln is used to print string

    c - a string that must be displayed on the screen.
*/
void puts(const char c[]) {
    for (size_t i = 0; i < strlen(c); i++) {
        putchar(c[i]);
    }
}


/*
    putint is used to print integer

    i - a integer that must be displayed on the screen.
*/
void putint(const int i) {
    char res[32];
    if (i < 0) {
        putchar('-');
    }
    puts(res);
    
}

void video_scroll() {
    if (row > 24){
        for (int i = 0*80; i < 24*80; i++) {
            terminal_buffer[i] = terminal_buffer[i + 80];
        }

        // The last line should now be blank. Do this by writing
        // 80 spaces to it.
        for (int i = 24 * 80; i < 25 * 80; i++) {
            terminal_buffer[i] = (uint16_t) ' ' | (uint16_t) color << 8;
        }
        // The cursor should now be on the last line.
        row = 24;
    }
    update_cursor(row, col);
}