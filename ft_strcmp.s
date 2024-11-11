; rdi	=>	first arg
; rsi	=>	second arg
; rcx	=>	counter
; rax	=>	return value
; al	=> lowest 8 bits register of rax
; r10b	=> lowest 8 bits register of r10b

global	ft_strcmp			; Make ft_strcmp accessible from other files

ft_strcmp:
	mov	rcx, 0				; We initialize our counter

loop:
	mov	al, [rdi + rcx]		; We copy the caracter from rdi into al
	mov	r10b, [rsi + rcx]	; We copy the caracter from rsi into r10b
	cmp	al, r10b			; We compare the caracters
	jne	exit				; We jump to the label `exit` if they're not equal
	cmp	al, 0				; We check if we're at the end of the first string
	je	exit				; We jump to the label `exit` if that's the case
	cmp	r10b, 0				; We check if we're at the end of the second string
	je	exit				; We jump to the label `exit` if that's the case
	inc	rcx					; We increment the counter
	jmp	loop				; We jump back to the label `loop`

exit:
	movzx	rax, al			; We move `al` into `rax`
	movzx	r10, r10b		; We move `r10b` into `r10`
	sub	rax, r10			; We substract the registers, and store the result into `rax`
	ret						; We return it
