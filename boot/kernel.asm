org 500h
message:
    mov ax, 0002h
    int 10h
         
    mov dx,0h
    call SetCP
    mov bp, line
    mov cx, 20
    mov bl,04h                  
    xor bh,bh
    mov ax,1301h
    int 10h     
    add dh,2
    call SetCP
    mov si,0
         
Com: 
    mov ah,10h
    int 16h
    cmp ah, 0Eh
    jz Del_sym
    cmp al, 0Dh
    jz Inp_Com
    mov [ramem+si],al
    inc si
    mov ah,09h
    mov bx,0004h
    mov cx,1
    int 10h
    add dl,1
    call SetCP
    jmp Com
         
Inp_Com:
    mov ax,cs
    mov ds,ax
    mov es,ax
    mov di,STR
    push si
    mov si,WRIT
    mov cx,5
    rep cmpsb
    je wrt
    pop si
    jmp Com
         
Del_sym:
    cmp dl,0
    jz Com
    sub dl,1
    call SetCP
    mov al,20h
    mov [ramem + si],al
    mov ah,09h
    mov bx,0004h
    mov cx,1
    int 10h
    dec si
    jmp Com
         
wrt:    mov ax,0000h
        mov es,ax
        mov bx,700h         
        mov ch,0
        mov cl,03h
        mov dh,0
        mov dl,80h
        mov al,01h
        mov ah,02h
        int 13h
    jmp 0000:0700h
 
SetCP:
        mov ah,2h
        xor bh,bh
        int 10h 
        ret
 
line db 'kernel > ',0
comm db 'calc',0
ramem db 4 dup(?)