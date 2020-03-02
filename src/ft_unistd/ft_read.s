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

%include "macros.s"

section .text
	global FN_LABEL(ft_read)

FN_LABEL(ft_read):
	mov		rax, SYS_READ
	syscall
	jnc		.return
	mov		rax, -0x1

.return:
	ret
