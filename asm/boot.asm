org 7c00h

start:
        cli
        xor ax,ax
        mov ds,ax
        mov es,ax
        mov ss,ax
        mov sp,07C00h
        sti
        mov ax, 0002h 
        int 10h
        mov dx,0h
        call SetCP
        mov bp, msg             
        mov cx, 13
        call Print
        add dh,1
        call SetCP
        mov bp, Con
        mov cx, 23
        call Print
        mov ah,10h
        int 16h
                 
Cont:
        cmp al, 0Dh
        jz Kern
        jmp Cont
                 
Kern:
        mov ax,0000h
        mov es,ax
        mov bx,500h
        mov ch,0
        mov cl,02h
        mov dh,0
;       mov dl,80h
        mov al,01h
        mov ah,02h
        int 13h
        jmp 0000:0500h

Print:
        mov bl,04h
        mov ax,1301h
        int 10h
        ret

SetCP:
        mov ah,2h
        xor bh,bh
        int 10h 
        ret

        msg db 'OS Loading...',0     
        Con db 'Press Enter to Continue',0
  
times(510-($-$$)) db 0
db 55AAh