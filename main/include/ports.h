/*
    Copyright (C) Aren Elchinyan 2021-2022. All rights reserved.
    Distributed under terms of the Creative Commons Zero v1.0 Universal License.
*/


#pragma once


#include <stdint.h>


void port_outb(uint16_t port, uint8_t  val);    // Wrapper for outb 
uint8_t port_inb(uint16_t port);                // Wrapper for inb 
void com1_write_char(char a);