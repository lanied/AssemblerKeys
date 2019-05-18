;-----------------------------------------------------------------
;Equipo 10                                              22/05/2019
;Proyecto 'Piano Leonardo'
;Ensamblador 8086 & Arduino AtMegau32u4
;-----------------------------------------------------------------
INCLUDE emu8086.inc  

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
        DB '            PRESIONE ESC PARA SALIR'           ,13,10 
        DB '  --------------------------------------------',13,10,'$'



ENDS



CODE SEGMENT
    assume SS:STACK,CS:CODE,DS:DATA  
        
    START PROC
        MOV AX, DATA
        MOV DS, AX
        
        CALL MENSAJE;imprime mensaje 
        CALL SPEAKER 
 
    START ENDP    
        
CODE ENDS  

INCLUDE librerias.lib

     END START       
