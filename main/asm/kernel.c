/*
    Copyright (C) Aren Elchinyan 2021-2022. All rights reserved.
    Distributed under terms of the Creative Commons Zero v1.0 Universal License.

    Clementine: "Арен прости меня..................."
*/


#include <kernel.h>


int alive = 1;


/*
    kernel_main is the main function of the kernel. 
    It initializes the core modules and the main cycle has been declared.
*/
void kernel_main() {
    clean_screen();
    
    set_color(COLOR_LIGHT_RED);
    putsln("ClemOS 0.0.1, Copyright (C) Dmitry Clementine 2022. All rights reserved.");
    putsln("");

    
    gdt_init();
    idt_init();
    kb_init();

    set_color(COLOR_LIGHT_CYAN);
    puts("kernel > ");
    set_color(COLOR_GREEN);

    //lang0x42_eval(",.[,.]");

    while(alive) {
        keyboard_handler_main();
    }
}