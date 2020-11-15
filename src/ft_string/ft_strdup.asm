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
	global	FN_LABEL(ft_strdup)
	extern	FN_LABEL(ft_strlen)
	extern	FN_LABEL(ft_malloc)
	extern	FN_LABEL(ft_strcpy)

FN_LABEL(ft_strdup):
	xor		eax, eax
	cmp		rdi, 0x0
	jz		.return

	call	FN_LABEL(ft_strlen)
	inc		rax
	push	rdi
	mov		rdi, rax

    push    rbp
	mov     rbp, rsp
	and		rsp, -0x10
	call	FN_LABEL(ft_malloc)
	jc		.return_pop
    mov     rsp, rbp
    pop     rbp
    pop		rdi

	mov		rsi, rdi
	mov		rdi, rax
    call	FN_LABEL(ft_strcpy)
    jmp		.return

.return_pop:
	pop		rdi

.return:
	ret
