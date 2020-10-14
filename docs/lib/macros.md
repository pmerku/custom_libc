---
layout: default
title: Macros
parent: Home
nav_order: 1
---

## %include "macros.asm"
{: .no_toc }

## Table of contents
{: .no_toc .text-delta }

1. TOC
{:toc}

---

### macros.asm
Macros for x64 assembly portability between Linux and MacOSx.
The macro will expand to the chosen OS depending if the `.asm` was compiled with `elf64` or `macho64` format flag.

### Example use
```assembly
%include "macros.asm"

section .text
	global FN_LABEL(<function-name>)

FN_LABEL(<function-name>):
```
On Linux `FN_LABLE` macro will expand to nothing and on MacOSx will prefix the <function-name> with an `_`.
