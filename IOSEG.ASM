; Version 1.0 16 December 1991
; IOPL segment for VDD I/O
;
; by: Steve Mastrianni
;     290 Brookfield Street
;     South Windsor, CT 06074
;     (203) 644-0723
;
;
        PUBLIC	_outp
        PUBLIC  _inp

        .386

DGROUP	GROUP	_DATA
_DATA   SEGMENT WORD PUBLIC 'DATA'
_DATA   ENDS

_IOSEG	segment	word public 'CODE'

	assume	CS: _IOSEG, DS: DGROUP, SS: DGROUP
;
_inp    proc	far
;
        push    bp              ;set up stack frame
        mov     bp,sp           ;save bp
        push    dx              ;save dx
	mov     dx,[bp+6]       ;get port address
        in      ax,dx           ;do input
        pop     dx              ;restore regs
        pop     bp              ;return in ax
	ret     2               ;remove from IOPL stack
;
_inp    endp

_outp   proc	far
;
        push    bp              ;set up stack frame
        mov     bp,sp           ;save it
        push    ax              ;save ax
        push    dx              ;and dx
	mov     ax,[bp+6]       ;get data
        mov     dx,[bp+8]       ;get port
        out     dx,al           ;do output
        pop     dx              ;restore regs
        pop     ax
        pop     bp
	ret     4               ;remove off local stack
;
_outp   endp

_IOSEG   ends
	 end 
