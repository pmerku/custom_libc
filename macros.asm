; **************************************************************************** ;
;                                                                              ;
;    Project: minishell                                   ::::::::             ;
;    Members: dvoort, prmerku                           :+:    :+:             ;
;    Copyright: 2020                                   +:+                     ;
;                                                     +#+                      ;
;                                                    +#+                       ;
;                                                   #+#    #+#                 ;
;    while (!(succeed = try()));                   ########   odam.nl          ;
;                                                                              ;
; **************************************************************************** ;

%ifndef MACROS_ASM
	%define MACROS_ASM
		%define SSE42_EQUAL_EACH 1000b
		%ifidn __OUTPUT_FORMAT__, elf64
				%define SYS_READ 0
				%define SYS_WRITE 1
				%define SYS_EXIT 60
				%define LABEL_PREFIX(prefix)
				%define DEFINE_ERROR __errno_location
				%macro ERRNO_MACRO 1
					cmp		rax, 0x0
					jge		%%skip
					mov		r8, rax
					neg		r8
					call	%1
					mov		[rax], r8
					mov		rax, -0x1
				%%skip:
				%endmacro
		%elifidn __OUTPUT_FORMAT__, macho64
				%define SYS_READ 0x2000003
				%define SYS_WRITE 0x2000004
				%define SYS_EXIT 0x2000001
				%define LABEL_PREFIX(prefix) _
				%define DEFINE_ERROR ___error
				%macro ERRNO_MACRO 1
					jnc		%%skip
					mov		r8, rax
					call	%1
					mov		[rax], r8
					mov		rax, -0x1
				%%skip:
				%endmacro
		%endif
	%define FN_LABEL(name) LABEL_PREFIX(0)name
%endif