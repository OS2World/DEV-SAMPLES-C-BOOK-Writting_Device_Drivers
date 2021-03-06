;    
;    C startup routine, 4 devices
;
        PUBLIC  _STRAT1
        PUBLIC  _STRAT2
        PUBLIC  _STRAT3
        PUBLIC  _STRAT4
        PUBLIC  __acrtused
        PUBLIC  _INT_HNDLR
        PUBLIC  _TIM_HNDLR
 
        EXTRN   _interrupt_handler:near
        EXTRN   _timer_handler:near
        EXTRN   _main:near

_DATA   segment   word public 'DATA'
_DATA   ends

CONST   segment   word public 'CONST'
CONST   ends

_BSS    segment word public 'BSS'
_BSS    ends

DGROUP  group     CONST, _BSS, _DATA
_TEXT   segment   word public 'CODE'

        assume  cs:_TEXT,ds:DGROUP,es:NOTHING,ss:NOTHING
       .286P
;
_STRAT1 proc   far
__acrtused:              ; satisfy EXTRN modules
;
       push    0
       jmp     start     ;signal device 0

_STRAT1 endp

_STRAT2 proc far
;
       push    1         ;signal second device
       jmp     start

_STRAT2 endp

_STRAT3 proc far
;
       push    2         ;signal third device
       jmp     start

_STRAT3 endp

_STRAT4 proc far
;
       push    3         ;signal fourth device
       jmp     start

;
start:
       push    	es        ;send Request Pkt address
       push    bx
       call    _main     ;call driver mainline
       pop     bx        ;restore es:bx
       pop     es
       add     sp,2      ;clean up stack
       mov     word ptr es:[bx+3],ax ;send completion status
       ret
;
_STRAT4   endp
;
_INT_HNDLR proc    far
;
	 call	   _interrupt_handler ;handle rupts
	 ret               ;bail out
;
_INT_HNDLR endp
;
_TIM_HNDLR proc    far
;
	 pusha
 	 push	   es
	 push	   ds
	 call	   _timer_handler
	 pop	   ds
	 pop	   es
	 popa
	 ret
;
_TIM_HNDLR endp
;
_TEXT  ends
       end



