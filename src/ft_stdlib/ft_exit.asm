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
	global FN_LABEL(ft_exit)		;tell the assembler the name of the function

FN_LABEL(ft_exit):
	mov		rax, SYS_EXIT			;mov syscall mask in default register
	syscall							;call correct syscall with the mask provided

.return:
	ret								;return value
