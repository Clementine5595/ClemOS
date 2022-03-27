#include <stdint.h>

extern const int col = 80;
extern const int row = 25;
extern volatile uint16_t* vga_buffer = (uint16_t*)0xB8000;
extern int term_col = 0;
extern int term_row = 0;
extern uint8_t term_color = 0x0F;