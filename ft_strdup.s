; rdi	=>	first arg
; rsi	=>	second arg
; rax	=>	return value

extern	ft_strlen				; Declare external function ft_strlen
extern	ft_strcpy				; Declare external function ft_strcpy
extern	malloc					; Declare external function malloc

global	ft_strdup				; Make ft_strdup accessible from other files
ft_strdup:
	call	ft_strlen			; Call the ft_strlen function
	push	rdi					; Saving the string to copy on the stack
	inc	rax						; Increment the return value of ft_strlen by one
	mov	rdi, rax				; Move the result from ft_strlen in `rdi` to pass it to malloc
	call	malloc wrt ..plt	; Calling malloc
	cmp	rax, 0					; Check the return value of malloc
	je	malloc_fail				; Jump to label `malloc_fail` if call to malloc failed
	pop	rsi						; Getting the value in the stack in `rsi`
	mov	rdi, rax				; Passing the returned value of malloc to `rdi`
	call	ft_strcpy			; Calling ft_strcpy
	ret							; Returning the new string

malloc_fail:
	pop	rdi						; Getting the value in the stack in rdi
	ret							; Returning NULL
