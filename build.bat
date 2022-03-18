@echo off

set FOL=G:\123\Micro-OS-on-FASM\main\
set BIN=G:\123\Micro-OS-on-FASM\main\bin\
set ASM=G:\123\Micro-OS-on-FASM\main\asm\
set NAS=G:\NASM\nasm.exe
set LDS=C:\Users\Clementine\Desktop\123321\bin\i686-elf-ld.exe
set GCC=C:\Users\Clementine\Desktop\123321\bin\i686-elf-gcc.exe

echo Now assembling, compiling, and linking your kernel:

%GCC% -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I include -c -o %FOL%bin/main.o %FOL%kernel/main.c

%NAS% -f elf32 -o %ASM%bin\boot.o %ASM%boot.asm
rem Remember this spot here: We will add 'gcc' commands here to compile C sources
rem This links all your files. Remember that as you add *.o files, you need to
rem add them after start.o. If you don't add them at all, they won't be in your kernel!
%LDS% -m elf_i386 -T %ASM%link.ld -o %BIN%kernel.bin %ASM%bin\boot.o
echo Done!
pause