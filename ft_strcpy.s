; rdi	=>	first arg
; rsi	=>	second arg
; rcx	=>	counter
; rax	=>	return value

global	ft_strcpy			; Make ft_strcpy accessible from other files

ft_strcpy:
	mov	rcx, 0				; Initialize the counter to 0

loop:
	mov	al, [rsi + rcx]		; Copy the caracter into `al`
	mov	[rdi + rcx], al		; Copy the caracter into the destination
	inc	rcx					; Increment the counter
	cmp	al, 0				; Check if we've copied all the string (null-terminating byte included)
	jne	loop				; Jump back to label `loop` if that's not the case

exit:
	mov	rax, rdi			; We move the destination string into the return value
	ret						; We return it
	