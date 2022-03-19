#include <system.h>
#include <stddef.h>
#include <stdint.h>
volatile uint16_t* vga_buffer = (uint16_t*)0xB8000;
const int VGA_COLS = 80;
const int VGA_ROWS = 25;
int term_col = 0;
int term_row = 0;
uint8_t term_color = 0x0F;

void scroll(void) {
    unsigned blank, temp;
    blank = 0x20 | (term_color << 8);
    if(term_row >= 25) {
        temp = term_row - 25 + 1;
        memcpy (vga_buffer, vga_buffer + temp * 80, (25 - temp) * 80 * 2);
        memsetw (vga_buffer + (25 - temp) * 80, blank, 80);
        term_row = 25 - 1;
    }
}

void move_csr(void) {
    unsigned temp;
    temp = term_row * 80 + term_col;
    outportb(0x3D4, 14);
    outportb(0x3D5, temp >> 8);
    outportb(0x3D4, 15);
    outportb(0x3D5, temp);
}

void cls() {
    unsigned blank;
    int i;
    blank = 0x20 | (term_color << 8);
    for(i = 0; i < 25; i++) memsetw (vga_buffer + i * 80, blank, 80);
    term_col = 0;
    term_row = 0;
    move_csr();
}

void putch(unsigned char c) {
    unsigned short *where;
    unsigned att = term_color << 8;
    if(c == 0x08) {
        if(term_col != 0) term_col--;
    } else if (c == 0x09) {
        term_col = (term_col + 8) & ~(8 - 1);
    } else if(c == '\r') {
        term_col = 0;
    } else if(c == '\n') {
        term_col = 0;
        term_row++;
    } else if(c >= ' ') {
        where = vga_buffer + (term_row * 80 + term_col);
        *where = c | att;
        term_col++;
    } 
    if(term_col >= 80) {
        term_col = 0;
        term_row++;
    }
    scroll();
    move_csr();
}

void puts(unsigned char *text) {
    int i;
    for (i = 0; i < strlen(text); i++) {
        putch(text[i]);
    }
}

void settextcolor(unsigned char forecolor, unsigned char backcolor) {
    term_color = (backcolor << 4) | (forecolor & 0x0F);
}

void init_video() {
	for (int col = 0; col < VGA_COLS; col ++) {
		for (int row = 0; row < VGA_ROWS; row ++) {
			const size_t index = (VGA_COLS * row) + col;
			vga_buffer[index] = ((uint16_t)term_color << 8) | ' ';
		}
	}
}