/*
    Copyright (C) Aren Elchinyan 2021-2022. All rights reserved.
    Distributed under terms of the Creative Commons Zero v1.0 Universal License.
*/



#include <stdint.h>
#include <stddef.h>
#include <libk/string.h>
#include <libk/stdlib.h>
#include <io/tty.h>
#include <io/ports.h>
#ifndef KBD_H
#define KBD_H

#define KEYBOARD_DATA_PORT 0x60
#define KEYBOARD_STATUS_PORT 0x64

#define ENTER_KEY_CODE 0x1C

extern unsigned char keyboard_map[128];
extern int input_type;
void kb_init(void);
void keyboard_handler(/* struct regs *r */);
void keyboard_handler_main(void);
char getchar();

#endif