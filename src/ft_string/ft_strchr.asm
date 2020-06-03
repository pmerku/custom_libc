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
	global FN_LABEL(ft_strchr)				;function name

FN_LABEL(ft_strchr):
	xor		eax, eax						;clear rax register
	xor		edx, edx						;clear rdx register
	cmp		rdi, 0x0
	jz		.null

.loop:
	mov		dl, byte [rdi]
	cmp		dl, sil							;compare string byte with the character byte
	je		.return							;if true return
	test	dl, dl							;test if character is '\0'
	jz		.null							;if true return
	inc		rdi								;string++;
	jmp		.loop							;jump back to the start of the loop

.null:
	ret										;return NULL

.return:
	mov		rax, rdi						;move pointer of the string to rax
	ret										;return position of the character