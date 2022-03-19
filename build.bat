@echo off

set FOL=main\
set BIN=main\bin\
set ASM=main\asm\
set OUT=main\output\
set MOD=main\modules\
set GCC=i686-elf-gcc
set CCF=-g -I main\include -ffreestanding -Wall -Wextra 
set LDF=%CCFLAGS% -nostdlib -lgcc

echo Now assembling, compiling, and linking your kernel:

%GCC% %CCF% -c %MOD%kernel.c -o %BIN%kernel.o
%GCC% %CCF% -c %MOD%libscr.c -o %BIN%libscr.o
%GCC% %CCF% -c %MOD%system.c -o %BIN%system.o

nasm -f elf32 -o %BIN%start.o %ASM%start.asm

%GCC% %LDF% -T link.ld -o %OUT%kernel.elf %BIN%start.o %BIN%kernel.o %BIN%libscr.o %BIN%system.o
echo Done!
pause