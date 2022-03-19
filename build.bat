@echo off

set FOL=G:\123\Micro-OS-on-FASM\main\
set BIN=G:\123\Micro-OS-on-FASM\main\bin\
set ASM=G:\123\Micro-OS-on-FASM\main\asm\
set NAS=G:\NASM\nasm.exe
set LDS=C:\Users\Clementine\Desktop\123321\bin\i686-elf-ld.exe
set GCC=C:\Users\Clementine\Desktop\123321\bin\i686-elf-gcc.exe

echo Now assembling, compiling, and linking your kernel:

%GCC% -std=gnu99 -ffreestanding -g -c %FOL%main.c -o %FOL%bin/main.o
%GCC% -std=gnu99 -ffreestanding -g -c %FOL%modules/lib/libscr.c -o %FOL%bin/libscr.o

%NAS% -f elf32 -o %FOL%bin\start.o %ASM%start.asm

%GCC% -ffreestanding -nostdlib -g -T %ASM%link.ld -o %BIN%kernel.elf %BIN%start.o %BIN%main.o %BIN%libscr.o
echo Done!
pause