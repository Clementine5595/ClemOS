    use16
    org 0x7c00
    start:
      xor ax,ax       ;обнуляем регистр ах
      mov ds,ax       ;настраиваем сегмент данных на нулевой адрес
      mov es,ax       ;настраиваем сегмент es на нулевой адрес
      mov ss,ax       ;настраиваем сегмент стека на нулевой адрес
      mov sp,07C00h 
     
     mov ax,0x1100 ;адрес буфера
     mov es,ax
     mov bx,0 ;адрес буфера
     mov ah,2 ;функция
     mov dl,1 ;то с чего считываем
     mov dh,0 ;номер головки  
     mov cl,2 ;номер сектора
     mov ch,0 ;номер дорожки
     mov al,14 ;количество секторов
     int 0x13
     
     mov ax,0x1300
     mov es,ax
     mov bx,0
     mov ah,2
     mov dl,1 
     mov dh,0   
     mov cl,16
     mov ch,0  
     mov al,5
     int 0x13

     mov ecx, 1
     call PRINT
 PRINT:
     mov ax, 0x0003;очищаем экран
     int 0x10
     
     mov ah, 0x0e
     call print
    
     mov ah,0
     int 16h
     
     cmp al, 'r'
     jz NEXT
     cmp al, 'w'
     jz UP
     cmp al, 's'
     jz DOWN
 
 UP:
   inc ecx
   cmp ecx, 7
   jz NULL
   jmp PRINT  
DOWN:
   dec ecx
   cmp ecx, 0
   jz MAX
   jmp PRINT
NULL:
   mov ecx, 1
   jmp PRINT
MAX:
   mov ecx, 6
   jmp PRINT
print:
   cmp ecx, 1
   jz mes1
   cmp ecx, 2
   jz mes2
   cmp ecx, 3
   jz mes3
   cmp ecx, 4
   jz mes4
   cmp ecx, 5
   jz mes5
   cmp ecx, 6
   jz mes6
   ret
mes1:
 mov al, 'b'
 int 0x10 
 mov al, 'l'
 int 0x10
 mov al, 'u'
 int 0x10
 mov al, 'e'
 int 0x10
 ret
mes2:
 mov al, 'g'
 int 0x10 
 mov al, 'r'
 int 0x10
 mov al, 'e'
 int 0x10
 mov al, 'e'
 int 0x10
 mov al, 'n'
 int 0x10
 ret
mes3:
 mov al, 'w'
 int 0x10 
 mov al, 'h'
 int 0x10
 mov al, 'i'
 int 0x10
 mov al, 't'
 int 0x10
 mov al, 'e'
 int 0x10
 ret
mes4:
 mov al, 'r'
 int 0x10 
 mov al, 'e'
 int 0x10
 mov al, 'd'
 int 0x10
 ret
mes5:
 mov al, 'p'
 int 0x10 
 mov al, 'i'
 int 0x10
 mov al, 'n'
 int 0x10
 mov al, 'k'
 int 0x10
 ret
mes6:
 mov al, 'o'
 int 0x10 
 mov al, 'r'
 int 0x10
 mov al, 'a'
 int 0x10
 mov al, 'n'
 int 0x10
 mov al, 'g'
 int 0x10
 mov al, 'e'
 int 0x10
 ret

 NEXT:    
    ;открыть A20
      in  al, 0x92
      or  al, 2
      out 0x92, al
     
    ;Загрузить адрес и размер GDT в GDTR
      lgdt  [gdt_info]
    ;Запретить прерывания
      cli
     
    ;Переключиться в защищенный режим
      mov  eax, cr0
      or   al, 1
      mov  cr0, eax
     
    ;Загрузить в CS:EIP точку входа в защищенный режим
      jmp 0x8:protected_mode
     
    ;32-битная адресация
    use32
    ;Точка входа в защищенный режим
    protected_mode:
    ;Загрузить сегментные регистры (кроме SS)
      mov ax, 0x10 
      mov es, ax 
      mov ds, ax 
      mov ss, ax
      
      ;mov ecx, 3 
      call KERNEL

  KERNEL: 
    call 0x11000
    ;Глобальная таблица дескрипторов.
    ;Нулевой дескриптор использовать нельзя!
    gdt:  ; Нулевой дескриптор  
    db 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
 
 ; Сегмент кода: base=0, size=4Gb, P=1, DPL=0, S=1(user),   ; Type=1(code), Access=00A, G=1, B=32bit  
    db 0xff, 0xff, 0x00, 0x00, 0x00, 0x9A, 0xCF, 0x00  
 
 ; Сегмент данных: base=0, size=4Gb, P=1, DPL=0, S=1(user),   ; Type=0(data), Access=0W0, G=1, B=32bit  
    db 0xff, 0xff, 0x00, 0x00, 0x00, 0x92, 0xCF, 0x00 
 
gdt_info: ; Данные о таблице GDT (размер, положение в памяти)  
dw gdt_info - gdt   ; Размер таблицы (2 байта)  
dw gdt, 0           ; 32-битный физический адрес таб
     
times (510 - ($ - start)) db 0 
db 0x55, 0xAA