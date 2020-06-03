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
	global FN_LABEL(ft_read)		;tell the assembler the name of the function
	extern DEFINE_ERROR

FN_LABEL(ft_read):
	mov		rax, SYS_READ			;mov syscall mask in default register
	syscall							;call correct syscall with the mask provided
	ERRNO_MACRO DEFINE_ERROR

.return:
	ret								;return value
