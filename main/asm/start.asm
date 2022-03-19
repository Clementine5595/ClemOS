extern main
global start

MB_MAGIC      equ   0x1BADB002
MB_FLAGS      equ   (1 << 0) | (1 << 1)
MB_CHECKSUM   equ   (0 - (MB_MAGIC + MB_FLAGS))

SECTION .multiboot
    ALIGN 4
    dd MB_MAGIC
    dd MB_FLAGS
    dd MB_CHECKSUM

SECTION .bss
    ALIGN 16
    stack_bottom:
        resb 4096
    stack_top:

SECTION .text
    start:
        mov esp, stack_top
        call main
    
    hang:
        cli
        hlt
        jmp hang