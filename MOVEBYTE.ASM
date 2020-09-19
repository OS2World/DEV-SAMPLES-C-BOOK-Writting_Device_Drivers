;  movebyte.asm  OS/2 Version 2.0
;
;  this routine transfers data to and from the device driver
;
;  C Calling Sequence:
;  if (MoveBytes(virt &From,virt &To,USHORT Lenth))  err
;
     .286
	include	drvlib.inc
	public	MOVEBYTES
	extrn	_ DevHlp:dword
	assume  CS:_TEXT
_TEXT	segment word public 'CODE'

MOVEBYTES proc near

	push	bp
	mov	bp,sp
	pushf			; save flags
	push	di		; save segment regs
	push	si		; and others we use
	push	es
	push	ds
	mov	cx,[bp+4]	; length
	or	cx,cx		; exit if zero 
	mov   	ax,1        	; set for bad parameter
	jz	get_out
	lds	si,[bp+10]	; from
	les	di,[bp+6]	; to
	cld
	test  	cx,1        	; if even number of bytes, save a
	jz	wordmove    	; little time by doing a word move
	rep	movsb
	jmp	short finish; done

wordmove:

      shr   cx,1        	; half the number of bytes
      rep   movsw

finish:
	xor	ax,ax

get_out:
	pop	ds
	pop	es
	pop	si          	; restore regs
	pop	di
	popf			;restore flags
	pop	bp
	ret	10          	; fix up stack

MOVEBYTES endp
_TEXT	ends
	end


