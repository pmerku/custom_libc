; **************************************************************************** ;
;                                                                              ;
;    Project: github_libc                                 ::::::::             ;
;    Members: prmerku                                   :+:    :+:             ;
;    Copyright: 2020                                   +:+                     ;
;                                                     +#+                      ;
;                                                    +#+                       ;
;                                                   #+#    #+#                 ;
;    while (!(succeed = try()));                   ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

%include "macro.s"

section .text
	global FN_LABEL(ft_write)

FN_LABEL(ft_write):
	mov		rax, SYS_WRITE
	syscall
	jnc		.return
	mov		rax, -0x1

.return:
	ret