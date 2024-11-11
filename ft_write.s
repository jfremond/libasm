; rdi	=>	first arg
; rsi	=>	second arg
; rdx	=>	third arg
; rax	=>	return value

extern	__errno_location				; Declare external function __errno_location
global	ft_write						; Make ft_write accessible from other files

ft_write:
	mov	rax, 1							; System call number for write
	syscall
	cmp	rax, 0							; We check if the call to write was a success
	jl	error							; We jump to the label `error` if there was an error
	ret									; We return `rax` otherwise
error:									; Where we deal with errors
	neg	rax								; This equals -errno and we want a positive value
	mov	r10, rax						; We save the value of `rax` before calling errno 
	call	__errno_location wrt ..plt	; We get the address of errno
	mov	[rax], r10						; We store the error code at the address of errno
	mov	rax, -1							; We set the good return value
	ret									; We return it
