; rdi	=>	first arg
; rcx	=>	counter
; rax	=>	return value

global	ft_strlen			; Make ft_strlen accessible from other files

ft_strlen:
	mov rcx, 0				; Initialize the counter to 0

loop:
	cmp	byte [rdi + rcx], 0	; We check if we're at the end of our string
	je	exit				; We jump to the label `exit` if that's the case
	inc	rcx					; We increment our counter if that's not the case
	jmp	loop				; We jump back to the label named `loop`

exit:
	mov	rax, rcx			; We move the result into the return value
	ret						; We return it
