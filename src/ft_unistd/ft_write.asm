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
	global FN_LABEL(ft_write)		;function name
	extern DEFINE_ERROR

FN_LABEL(ft_write):
	mov		rax, SYS_WRITE			;mov syscall mask in default register
	syscall							;call correct syscall with the mask provided
	ERRNO_MACRO DEFINE_ERROR

.return:
	ret								;return value
