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
	global FN_LABEL(ft_strlen)

FN_LABEL(ft_strlen):
	mov			rax,		-16
	mov			rcx,		rdi
	pxor		xmm0,		xmm0

.loop:
	add			rax,		16
	pcmpistri	xmm0,		[rdi + rax],	SSE42_EQUAL_EACH
	jnz			.loop

	add			rax,		rcx
	ret
