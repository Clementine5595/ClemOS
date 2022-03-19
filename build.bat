@echo off

set FOL=G:\123\Micro-OS-on-FASM\main\
set BIN=G:\123\Micro-OS-on-FASM\main\bin\
set ASM=G:\123\Micro-OS-on-FASM\main\asm\
set NAS=G:\NASM\nasm.exe
set LDS=C:\Users\Clementine\Desktop\123321\bin\i686-elf-ld.exe
set GCC=C:\Users\Clementine\Desktop\123321\bin\i686-elf-gcc.exe

echo Now assembling, compiling, and linking your kernel:

::%GCC% -g -I main/include -ffreestanding -Wall -Wextra -c %FOL%main.c -o %FOL%bin/main.o
%GCC% -std=gnu99 -ffreestanding -g -c %FOL%main.c -o %FOL%bin/main.o
%NAS% -f elf32 -o %FOL%bin\start.o %ASM%start.asm
rem Remember this spot here: We will add 'gcc' commands here to compile C sources
rem This links all your files. Remember that as you add *.o files, you need to
rem add them after start.o. If you don't add them at all, they won't be in your kernel!
%GCC% -ffreestanding -nostdlib -g -T %ASM%link.ld -o %BIN%kernel.elf %BIN%start.o %BIN%main.o
echo Done!
pause