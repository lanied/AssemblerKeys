;-----------------------------------------------------------------
;Equipo 10                                              22/05/2019
;Proyecto 'Piano Leonardo'
;Ensamblador 8086 & Arduino AtMegau32u4
;-----------------------------------------------------------------
STACK SEGMENT
    DW   128  DUP(0)
ENDS   

DATA SEGMENT  

MsgMain DB '                PROYECTO PIANO EDUARDO',13,10
        DB 13,10
        DB '                 INGRESE LAS NOTAS',13,10  
        DB '     _______________________________________  ',13,10
        DB '    |  | | | |  |  | | | | | |  |  | | | |  | ',13,10
        DB '    |  | | | |  |  | | | | | |  |  | | | |  | ',13,10
        DB '    |  | | | |  |  | | | | | |  |  | | | |  | ',13,10
        DB '    |  |_| |_|  |  |_| |_| |_|  |  |_| |_|  | ',13,10
        DB '    |   |   |   |   |   |   |   |   |   |   | ',13,10
        DB '    |   |   |   |   |   |   |   |   |   |   | ',13,10
        DB '    |___|___|___|___|___|___|___|___|___|___| ',13,10
        DB '                                              ',13,10
        DB '  --------------------------------------------',13,10

        DB '            PRESIONE ESC PARA SALIR','$'

ENDS



CODE SEGMENT
    assume SS:STACK,CS:CODE,DS:DATA  
        
    START PROC
        MOV AX, DATA
        MOV DS, AX
        
        CALL MENSAJE;imprime mensaje
        
        MOV AX, 4CH ; terminar programa
        INT 21H 
           
    START ENDP    
        
CODE ENDS  

;-------------------Procedimientos--------------------------------    
MENSAJE PROC ;imprimir mensaje principal
    
        MOV AH,6        ;Modo de video
        XOR AL,AL
        XOR CX,CX
        MOV DX,184FH    ;pintar toda la pantalla
        MOV BH,0F2H     ;color fondo blanco letras verdes
        INT 10H         ;int video     
        LEA DX, MsgMain ;offset mensaje
        MOV AH, 9       ; imprimir mensaje
        INT 21H       
        
        ;MOV AH, 1
        ;INT 21H
        
        RET 
        
MENSAJE ENDP

     END START       
