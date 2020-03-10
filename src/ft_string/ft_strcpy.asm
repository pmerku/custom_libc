; **************************************************************************** ;
;                                                                              ;
;    Project: custom_libc                                 ::::::::             ;
;    Members: dvoort, prmerku                           :+:    :+:             ;
;    Copyright: 2020                                   +:+                     ;
;                                                     +#+                      ;
;                                                    +#+                       ;
;                                                   #+#    #+#                 ;
;    while (!(succeed = try()));                   ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

%include "macros.asm"

section .text
	global FN_LABEL(ft_strcpy)

FN_LABEL(ft_strcpy):
	xor		edx, edx				;clear rdx register
	xor		ecx, ecx				;clear rcx register
	cmp		rsi, 0x0				;check if src is NULL
	jz		.return					;return dst in case src is NULL

.loop:
	mov		dl, byte [rsi + rcx]	;copy byte from src to a tmp location
	mov		byte [rdi + rcx], dl	;copy from tmp location to dst byte
	cmp		dl, 0x0					;check if end fo string
	jz		.return					;return if end of string

	inc		rcx						;increment index in string src by 1
	jmp		.loop					;jump back to loop

.return:
	mov		rax, rdi				;move dst to the return register
	ret								;return dst
