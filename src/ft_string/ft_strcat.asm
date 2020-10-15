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
	global FN_LABEL(ft_strcat)
	extern FN_LABEL(ft_strlen)
	extern FN_LABEL(ft_strcpy)

FN_LABEL(ft_strcat):
	push		rdi
	push		rsi

	call		FN_LABEL(ft_strlen)

	pop			rsi
	pop			rdi

	add			rdi, rax

	jmp			FN_LABEL(ft_strcpy)
