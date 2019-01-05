	.file	"SDL_comboios.c"
	.text
.Ltext0:
	.comm	debug,1,1
	.globl	g_pWindow
	.bss
	.align 8
	.type	g_pWindow, @object
	.size	g_pWindow, 8
g_pWindow:
	.zero	8
	.globl	g_pRenderer
	.align 8
	.type	g_pRenderer, @object
	.size	g_pRenderer, 8
g_pRenderer:
	.zero	8
	.text
	.globl	PosInicial
	.type	PosInicial, @function
PosInicial:
.LFB3671:
	.file 1 "/media/sf_Prog/ProjetoFinal/SDL_comboios.c"
	.loc 1 8 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	.loc 1 9 0
	movq	-8(%rbp), %rax
	leaq	21(%rax), %rdx
	movq	-8(%rbp), %rax
	leaq	16(%rax), %rcx
	movq	-16(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	procuraID@PLT
	movq	%rax, %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, 48(%rax)
	.loc 1 10 0
	movq	-8(%rbp), %rax
	movq	48(%rax), %rax
	movl	16(%rax), %edx
	movq	-8(%rbp), %rax
	movl	%edx, 28(%rax)
	.loc 1 11 0
	movq	-8(%rbp), %rax
	movq	48(%rax), %rax
	movl	20(%rax), %edx
	movq	-8(%rbp), %rax
	movl	%edx, 32(%rax)
	.loc 1 12 0
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3671:
	.size	PosInicial, .-PosInicial
	.globl	InicComboios
	.type	InicComboios, @function
InicComboios:
.LFB3672:
	.loc 1 13 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	%rdx, -56(%rbp)
	.loc 1 17 0
	movl	$0, -20(%rbp)
	jmp	.L3
.L9:
	.loc 1 18 0
	movl	$4, -16(%rbp)
	.loc 1 19 0
	movl	-20(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	jmp	.L4
.L7:
	.loc 1 20 0
	movq	-8(%rbp), %rax
	movb	$0, 56(%rax)
	.loc 1 21 0
	movq	-56(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	PosInicial
	.loc 1 22 0
	movl	-16(%rbp), %eax
	leal	(%rax,%rax), %edx
	movq	-8(%rbp), %rax
	movl	8(%rax), %eax
	imull	%edx, %eax
	movl	%eax, -12(%rbp)
	jmp	.L5
.L6:
	.loc 1 23 0 discriminator 3
	movq	-56(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	moveCarr
	.loc 1 22 0 discriminator 3
	subl	$1, -12(%rbp)
.L5:
	.loc 1 22 0 is_stmt 0 discriminator 1
	cmpl	$0, -12(%rbp)
	jg	.L6
	.loc 1 25 0 is_stmt 1 discriminator 2
	movq	-8(%rbp), %rax
	movl	12(%rax), %eax
	cltq
	salq	$4, %rax
	movq	%rax, %rdx
	movq	-48(%rbp), %rax
	addq	%rdx, %rax
	movl	12(%rax), %eax
	movzbl	%al, %r8d
	movq	-8(%rbp), %rax
	movl	12(%rax), %eax
	cltq
	salq	$4, %rax
	movq	%rax, %rdx
	movq	-48(%rbp), %rax
	addq	%rdx, %rax
	movl	8(%rax), %eax
	movzbl	%al, %edi
	movq	-8(%rbp), %rax
	movl	12(%rax), %eax
	cltq
	salq	$4, %rax
	movq	%rax, %rdx
	movq	-48(%rbp), %rax
	addq	%rdx, %rax
	movl	4(%rax), %eax
	movzbl	%al, %r9d
	movq	-8(%rbp), %rax
	movl	12(%rax), %eax
	cltq
	salq	$4, %rax
	movq	%rax, %rdx
	movq	-48(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	movzbl	%al, %r10d
	movq	-8(%rbp), %rax
	movl	8(%rax), %eax
	movswl	%ax, %ecx
	movq	-8(%rbp), %rax
	movl	32(%rax), %eax
	movswl	%ax, %edx
	movq	-8(%rbp), %rax
	movl	28(%rax), %eax
	movswl	%ax, %esi
	movq	g_pRenderer(%rip), %rax
	pushq	%r8
	pushq	%rdi
	movl	%r10d, %r8d
	movq	%rax, %rdi
	call	filledCircleRGBA@PLT
	addq	$16, %rsp
	.loc 1 19 0 discriminator 2
	movq	-8(%rbp), %rax
	movq	64(%rax), %rax
	movq	%rax, -8(%rbp)
	subl	$1, -16(%rbp)
.L4:
	.loc 1 19 0 is_stmt 0 discriminator 1
	cmpq	$0, -8(%rbp)
	jne	.L7
	.loc 1 17 0 is_stmt 1 discriminator 2
	addl	$1, -20(%rbp)
.L3:
	.loc 1 17 0 is_stmt 0 discriminator 1
	cmpl	$199, -20(%rbp)
	jg	.L8
	.loc 1 17 0 discriminator 3
	movl	-20(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	testq	%rax, %rax
	jne	.L9
.L8:
	.loc 1 28 0 is_stmt 1
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	verificaColisoes@PLT
	cmpl	$1, %eax
	jne	.L10
	.loc 1 29 0
	movl	$1, %eax
	jmp	.L11
.L10:
	.loc 1 32 0
	movl	$0, %eax
.L11:
	.loc 1 35 0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3672:
	.size	InicComboios, .-InicComboios
	.section	.rodata
.LC0:
	.string	"EST"
	.text
	.globl	moveCarr
	.type	moveCarr, @function
moveCarr:
.LFB3673:
	.loc 1 36 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	.loc 1 39 0
	movq	-40(%rbp), %rax
	movl	40(%rax), %eax
	testl	%eax, %eax
	jne	.L13
	.loc 1 39 0 is_stmt 0 discriminator 1
	movq	-40(%rbp), %rax
	movl	12(%rax), %edx
	movq	-40(%rbp), %rax
	movq	48(%rax), %rax
	movl	24(%rax), %eax
	cmpl	%eax, %edx
	jne	.L13
	.loc 1 39 0 discriminator 2
	movq	-40(%rbp), %rax
	movq	48(%rax), %rax
	addq	$28, %rax
	leaq	.LC0(%rip), %rsi
	movq	%rax, %rdi
	call	strcmp@PLT
	testl	%eax, %eax
	jne	.L13
	.loc 1 41 0 is_stmt 1
	movq	-40(%rbp), %rax
	movl	$8, 12(%rax)
.L13:
	.loc 1 44 0
	movq	-40(%rbp), %rax
	movq	48(%rax), %rax
	movq	48(%rax), %rax
	testq	%rax, %rax
	je	.L14
	.loc 1 45 0
	movq	-40(%rbp), %rax
	movq	48(%rax), %rax
	movl	16(%rax), %eax
	cvtsi2ss	%eax, %xmm0
	movss	%xmm0, -24(%rbp)
	.loc 1 46 0
	movq	-40(%rbp), %rax
	movq	48(%rax), %rax
	movl	20(%rax), %eax
	cvtsi2ss	%eax, %xmm0
	movss	%xmm0, -20(%rbp)
	.loc 1 47 0
	movq	-40(%rbp), %rax
	movq	48(%rax), %rax
	movq	48(%rax), %rax
	movl	16(%rax), %eax
	cvtsi2ss	%eax, %xmm0
	movss	%xmm0, -16(%rbp)
	.loc 1 48 0
	movq	-40(%rbp), %rax
	movq	48(%rax), %rax
	movq	48(%rax), %rax
	movl	20(%rax), %eax
	cvtsi2ss	%eax, %xmm0
	movss	%xmm0, -12(%rbp)
	.loc 1 50 0
	movss	-16(%rbp), %xmm0
	subss	-24(%rbp), %xmm0
	pxor	%xmm1, %xmm1
	ucomiss	%xmm1, %xmm0
	jp	.L26
	pxor	%xmm1, %xmm1
	ucomiss	%xmm1, %xmm0
	je	.L29
.L26:
	.loc 1 51 0
	movss	-12(%rbp), %xmm0
	subss	-20(%rbp), %xmm0
	movss	-16(%rbp), %xmm1
	subss	-24(%rbp), %xmm1
	divss	%xmm1, %xmm0
	movss	%xmm0, -8(%rbp)
	.loc 1 52 0
	movss	-8(%rbp), %xmm0
	mulss	-24(%rbp), %xmm0
	movss	-20(%rbp), %xmm1
	subss	%xmm0, %xmm1
	movaps	%xmm1, %xmm0
	movss	%xmm0, -4(%rbp)
	.loc 1 54 0
	movss	-16(%rbp), %xmm0
	ucomiss	-24(%rbp), %xmm0
	jbe	.L30
	.loc 1 55 0
	movq	-40(%rbp), %rax
	movl	28(%rax), %eax
	leal	1(%rax), %edx
	movq	-40(%rbp), %rax
	movl	%edx, 28(%rax)
	jmp	.L19
.L30:
	.loc 1 57 0
	movq	-40(%rbp), %rax
	movl	28(%rax), %eax
	leal	-1(%rax), %edx
	movq	-40(%rbp), %rax
	movl	%edx, 28(%rax)
.L19:
	.loc 1 58 0
	movq	-40(%rbp), %rax
	movl	28(%rax), %eax
	cvtsi2ss	%eax, %xmm0
	mulss	-8(%rbp), %xmm0
	addss	-4(%rbp), %xmm0
	cvttss2si	%xmm0, %edx
	movq	-40(%rbp), %rax
	movl	%edx, 32(%rax)
	.loc 1 59 0
	movq	-40(%rbp), %rax
	movl	28(%rax), %edx
	movq	-40(%rbp), %rax
	movq	48(%rax), %rax
	movq	48(%rax), %rax
	movl	16(%rax), %eax
	cmpl	%eax, %edx
	jne	.L32
	.loc 1 60 0
	movq	-40(%rbp), %rax
	movq	48(%rax), %rax
	movq	48(%rax), %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, 48(%rax)
	.loc 1 79 0
	jmp	.L32
.L29:
	.loc 1 64 0
	movss	-12(%rbp), %xmm0
	ucomiss	-20(%rbp), %xmm0
	jbe	.L31
	.loc 1 65 0
	movq	-40(%rbp), %rax
	movl	32(%rax), %eax
	leal	1(%rax), %edx
	movq	-40(%rbp), %rax
	movl	%edx, 32(%rax)
	jmp	.L24
.L31:
	.loc 1 67 0
	movq	-40(%rbp), %rax
	movl	32(%rax), %eax
	leal	-1(%rax), %edx
	movq	-40(%rbp), %rax
	movl	%edx, 32(%rax)
.L24:
	.loc 1 69 0
	movq	-40(%rbp), %rax
	movl	32(%rax), %edx
	movq	-40(%rbp), %rax
	movq	48(%rax), %rax
	movq	48(%rax), %rax
	movl	20(%rax), %eax
	cmpl	%eax, %edx
	jne	.L32
	.loc 1 70 0
	movq	-40(%rbp), %rax
	movq	48(%rax), %rax
	movq	48(%rax), %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, 48(%rax)
	.loc 1 79 0
	jmp	.L32
.L14:
	.loc 1 75 0
	movq	-40(%rbp), %rax
	movl	36(%rax), %eax
	leal	-1(%rax), %edx
	movq	-40(%rbp), %rax
	movl	%edx, 36(%rax)
	.loc 1 76 0
	movq	-48(%rbp), %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	PosInicial
.L32:
	.loc 1 79 0
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3673:
	.size	moveCarr, .-moveCarr
	.globl	trajectoriaComb
	.type	trajectoriaComb, @function
trajectoriaComb:
.LFB3674:
	.loc 1 80 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	.loc 1 85 0
	movq	-24(%rbp), %rax
	movq	%rax, -8(%rbp)
	jmp	.L34
.L39:
	.loc 1 86 0
	movq	-8(%rbp), %rax
	movl	12(%rax), %eax
	movl	%eax, -16(%rbp)
	.loc 1 88 0
	movq	-8(%rbp), %rax
	movzbl	56(%rax), %eax
	xorl	$1, %eax
	testb	%al, %al
	je	.L35
	.loc 1 89 0
	movq	-40(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	moveCarr
	jmp	.L36
.L35:
	.loc 1 91 0
	movq	-8(%rbp), %rax
	movl	40(%rax), %eax
	cmpl	$1, %eax
	jne	.L36
	.loc 1 92 0
	call	rand@PLT
	movl	%eax, %edx
	movl	%edx, %eax
	sarl	$31, %eax
	shrl	$31, %eax
	addl	%eax, %edx
	andl	$1, %edx
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, -12(%rbp)
	.loc 1 94 0
	cmpl	$1, -12(%rbp)
	jne	.L36
	.loc 1 95 0
	movq	-8(%rbp), %rax
	movl	$9, 12(%rax)
.L36:
	.loc 1 98 0
	movq	-8(%rbp), %rax
	movl	36(%rax), %eax
	testl	%eax, %eax
	jle	.L37
	.loc 1 99 0
	movq	-8(%rbp), %rax
	movl	12(%rax), %eax
	cltq
	salq	$4, %rax
	movq	%rax, %rdx
	movq	-32(%rbp), %rax
	addq	%rdx, %rax
	movl	12(%rax), %eax
	movzbl	%al, %r8d
	movq	-8(%rbp), %rax
	movl	12(%rax), %eax
	cltq
	salq	$4, %rax
	movq	%rax, %rdx
	movq	-32(%rbp), %rax
	addq	%rdx, %rax
	movl	8(%rax), %eax
	movzbl	%al, %edi
	movq	-8(%rbp), %rax
	movl	12(%rax), %eax
	cltq
	salq	$4, %rax
	movq	%rax, %rdx
	movq	-32(%rbp), %rax
	addq	%rdx, %rax
	movl	4(%rax), %eax
	movzbl	%al, %r9d
	movq	-8(%rbp), %rax
	movl	12(%rax), %eax
	cltq
	salq	$4, %rax
	movq	%rax, %rdx
	movq	-32(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	movzbl	%al, %r10d
	movq	-8(%rbp), %rax
	movl	8(%rax), %eax
	movswl	%ax, %ecx
	movq	-8(%rbp), %rax
	movl	32(%rax), %eax
	movswl	%ax, %edx
	movq	-8(%rbp), %rax
	movl	28(%rax), %eax
	movswl	%ax, %esi
	movq	g_pRenderer(%rip), %rax
	pushq	%r8
	pushq	%rdi
	movl	%r10d, %r8d
	movq	%rax, %rdi
	call	filledCircleRGBA@PLT
	addq	$16, %rsp
	jmp	.L38
.L37:
	.loc 1 103 0
	movq	-8(%rbp), %rax
	movl	$50000, 28(%rax)
	.loc 1 104 0
	movq	-8(%rbp), %rax
	movl	$50000, 32(%rax)
.L38:
	.loc 1 108 0 discriminator 2
	movq	-8(%rbp), %rax
	movl	-16(%rbp), %edx
	movl	%edx, 12(%rax)
	.loc 1 85 0 discriminator 2
	movq	-8(%rbp), %rax
	movq	64(%rax), %rax
	movq	%rax, -8(%rbp)
.L34:
	.loc 1 85 0 is_stmt 0 discriminator 1
	cmpq	$0, -8(%rbp)
	jne	.L39
	.loc 1 110 0 is_stmt 1
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3674:
	.size	trajectoriaComb, .-trajectoriaComb
	.section	.rodata
.LC2:
	.string	"ComboioSim"
	.align 8
.LC3:
	.string	"ERRO, COMBOIOS INICIADOS PARA AL\303\211M DA DIST\303\202NCIA DE SEGURAN\303\207A "
	.text
	.globl	abreJanela
	.type	abreJanela, @function
abreJanela:
.LFB3675:
	.loc 1 111 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	%rcx, -48(%rbp)
	.loc 1 113 0
	movl	$62001, %edi
	call	SDL_Init@PLT
	.loc 1 116 0
	movl	$1, -4(%rbp)
	.loc 1 119 0
	movl	$62001, %edi
	call	SDL_Init@PLT
	testl	%eax, %eax
	js	.L41
	.loc 1 123 0
	movq	-24(%rbp), %rax
	addq	$4, %rax
	.loc 1 122 0
	movl	(%rax), %edx
	movq	-24(%rbp), %rax
	movl	(%rax), %eax
	movl	$4, %r9d
	movl	%edx, %r8d
	movl	%eax, %ecx
	movl	$805240832, %edx
	movl	$805240832, %esi
	leaq	.LC2(%rip), %rdi
	call	SDL_CreateWindow@PLT
	movq	%rax, g_pWindow(%rip)
	.loc 1 125 0
	movq	g_pWindow(%rip), %rax
	testq	%rax, %rax
	je	.L43
	.loc 1 126 0
	movq	g_pWindow(%rip), %rax
	movl	$0, %edx
	movl	$-1, %esi
	movq	%rax, %rdi
	call	SDL_CreateRenderer@PLT
	movq	%rax, g_pRenderer(%rip)
	jmp	.L43
.L41:
	.loc 1 129 0
	movl	$0, %edi
	call	exit@PLT
.L43:
	.loc 1 131 0
	movq	-48(%rbp), %rax
	addq	$144, %rax
	movl	12(%rax), %eax
	movzbl	%al, %edi
	movq	-48(%rbp), %rax
	addq	$144, %rax
	movl	8(%rax), %eax
	movzbl	%al, %ecx
	movq	-48(%rbp), %rax
	addq	$144, %rax
	movl	4(%rax), %eax
	movzbl	%al, %edx
	movq	-48(%rbp), %rax
	addq	$144, %rax
	movl	(%rax), %eax
	movzbl	%al, %esi
	movq	g_pRenderer(%rip), %rax
	movl	%edi, %r8d
	movq	%rax, %rdi
	call	SDL_SetRenderDrawColor@PLT
	.loc 1 133 0
	movq	g_pRenderer(%rip), %rax
	movq	%rax, %rdi
	call	SDL_RenderClear@PLT
	.loc 1 135 0
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	SDL_unepontos
	.loc 1 136 0
	movq	-48(%rbp), %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	SDL_escrevePontos
	.loc 1 137 0
	movq	-40(%rbp), %rdx
	movq	-48(%rbp), %rcx
	movq	-32(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	InicComboios
	cmpl	$1, %eax
	jne	.L44
	.loc 1 138 0
	leaq	.LC3(%rip), %rdi
	call	puts@PLT
	.loc 1 140 0
	movq	g_pRenderer(%rip), %rax
	movq	%rax, %rdi
	call	SDL_DestroyRenderer@PLT
	.loc 1 141 0
	movq	$0, g_pRenderer(%rip)
	.loc 1 143 0
	call	SDL_Quit@PLT
	.loc 1 146 0
	jmp	.L40
.L44:
	.loc 1 149 0
	movq	g_pRenderer(%rip), %rax
	movq	%rax, %rdi
	call	SDL_RenderPresent@PLT
	.loc 1 151 0
	movl	$1000, %edi
	call	SDL_Delay@PLT
.L49:
	.loc 1 155 0
	movq	-48(%rbp), %rax
	addq	$144, %rax
	movl	12(%rax), %eax
	movzbl	%al, %edi
	movq	-48(%rbp), %rax
	addq	$144, %rax
	movl	8(%rax), %eax
	movzbl	%al, %ecx
	movq	-48(%rbp), %rax
	addq	$144, %rax
	movl	4(%rax), %eax
	movzbl	%al, %edx
	movq	-48(%rbp), %rax
	addq	$144, %rax
	movl	(%rax), %eax
	movzbl	%al, %esi
	movq	g_pRenderer(%rip), %rax
	movl	%edi, %r8d
	movq	%rax, %rdi
	call	SDL_SetRenderDrawColor@PLT
	.loc 1 157 0
	movq	g_pRenderer(%rip), %rax
	movq	%rax, %rdi
	call	SDL_RenderClear@PLT
	.loc 1 159 0
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	SDL_desenhaButoesHUD
	.loc 1 160 0
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	SDL_unepontos
	.loc 1 161 0
	movq	-48(%rbp), %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	SDL_escrevePontos
	.loc 1 165 0
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	verificaColisoes@PLT
	.loc 1 166 0
	movl	$0, -8(%rbp)
	jmp	.L46
.L48:
	.loc 1 169 0 discriminator 4
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-32(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movq	-40(%rbp), %rdx
	movq	-48(%rbp), %rcx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	trajectoriaComb
	.loc 1 166 0 discriminator 4
	addl	$1, -8(%rbp)
.L46:
	.loc 1 166 0 is_stmt 0 discriminator 1
	cmpl	$199, -8(%rbp)
	jg	.L47
	.loc 1 166 0 discriminator 3
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-32(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	testq	%rax, %rax
	jne	.L48
.L47:
	.loc 1 177 0 is_stmt 1
	movq	g_pRenderer(%rip), %rax
	movq	%rax, %rdi
	call	SDL_RenderPresent@PLT
	.loc 1 187 0
	cmpl	$0, -4(%rbp)
	jne	.L49
	.loc 1 189 0
	movl	$6000, %edi
	call	SDL_Delay@PLT
	.loc 1 192 0
	movq	g_pRenderer(%rip), %rax
	movq	%rax, %rdi
	call	SDL_DestroyRenderer@PLT
	.loc 1 193 0
	movq	$0, g_pRenderer(%rip)
	.loc 1 195 0
	call	SDL_Quit@PLT
	.loc 1 198 0
	nop
.L40:
	.loc 1 204 0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3675:
	.size	abreJanela, .-abreJanela
	.globl	SDL_unepontos
	.type	SDL_unepontos, @function
SDL_unepontos:
.LFB3676:
	.loc 1 205 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -40(%rbp)
	.loc 1 210 0
	movl	$0, -20(%rbp)
	jmp	.L51
.L53:
	.loc 1 212 0 discriminator 4
	movl	-20(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movq	%rax, -16(%rbp)
	.loc 1 213 0 discriminator 4
	movl	-20(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movq	48(%rax), %rax
	movq	%rax, -8(%rbp)
	.loc 1 215 0 discriminator 4
	movq	-8(%rbp), %rdx
	movq	-16(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	for_pontos
	.loc 1 210 0 discriminator 4
	addl	$1, -20(%rbp)
.L51:
	.loc 1 210 0 is_stmt 0 discriminator 1
	movl	-20(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	testq	%rax, %rax
	je	.L54
	.loc 1 210 0 discriminator 3
	cmpl	$199, -20(%rbp)
	jle	.L53
.L54:
	.loc 1 219 0 is_stmt 1
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3676:
	.size	SDL_unepontos, .-SDL_unepontos
	.globl	SDL_escrevePontos
	.type	SDL_escrevePontos, @function
SDL_escrevePontos:
.LFB3677:
	.loc 1 220 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$240, %rsp
	movq	%rdi, -232(%rbp)
	movq	%rsi, -240(%rbp)
	.loc 1 220 0
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	.loc 1 226 0
	movl	$0, -220(%rbp)
	jmp	.L56
.L61:
	.loc 1 227 0
	movl	-220(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-232(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movq	%rax, %rdx
	leaq	-208(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strcpy@PLT
	.loc 1 229 0
	movl	-220(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-232(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movq	%rax, -216(%rbp)
	jmp	.L57
.L59:
	.loc 1 233 0 discriminator 4
	movq	-216(%rbp), %rax
	movl	24(%rax), %eax
	cltq
	salq	$4, %rax
	movq	%rax, %rdx
	movq	-240(%rbp), %rax
	addq	%rdx, %rax
	movl	12(%rax), %eax
	movzbl	%al, %r8d
	movq	-216(%rbp), %rax
	movl	24(%rax), %eax
	cltq
	salq	$4, %rax
	movq	%rax, %rdx
	movq	-240(%rbp), %rax
	addq	%rdx, %rax
	movl	8(%rax), %eax
	movzbl	%al, %edi
	movq	-216(%rbp), %rax
	movl	24(%rax), %eax
	cltq
	salq	$4, %rax
	movq	%rax, %rdx
	movq	-240(%rbp), %rax
	addq	%rdx, %rax
	movl	4(%rax), %eax
	movzbl	%al, %r9d
	movq	-216(%rbp), %rax
	movl	24(%rax), %eax
	cltq
	salq	$4, %rax
	movq	%rax, %rdx
	movq	-240(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	movzbl	%al, %r10d
	movq	-216(%rbp), %rax
	movl	32(%rax), %eax
	movswl	%ax, %ecx
	movq	-216(%rbp), %rax
	movl	20(%rax), %eax
	movswl	%ax, %edx
	movq	-216(%rbp), %rax
	movl	16(%rax), %eax
	movswl	%ax, %esi
	movq	g_pRenderer(%rip), %rax
	pushq	%r8
	pushq	%rdi
	movl	%r10d, %r8d
	movq	%rax, %rdi
	call	filledCircleRGBA@PLT
	addq	$16, %rsp
	.loc 1 234 0 discriminator 4
	movq	-216(%rbp), %rax
	movl	32(%rax), %eax
	movswl	%ax, %ecx
	movq	-216(%rbp), %rax
	movl	20(%rax), %eax
	movswl	%ax, %edx
	movq	-216(%rbp), %rax
	movl	16(%rax), %eax
	movswl	%ax, %esi
	movq	g_pRenderer(%rip), %rax
	pushq	$255
	pushq	$0
	movl	$0, %r9d
	movl	$0, %r8d
	movq	%rax, %rdi
	call	circleRGBA@PLT
	addq	$16, %rsp
	.loc 1 229 0 discriminator 4
	movq	-216(%rbp), %rax
	movq	48(%rax), %rax
	movq	%rax, -216(%rbp)
.L57:
	.loc 1 229 0 is_stmt 0 discriminator 1
	cmpq	$0, -216(%rbp)
	je	.L58
	.loc 1 229 0 discriminator 3
	movq	-216(%rbp), %rdx
	leaq	-208(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strcmp@PLT
	testl	%eax, %eax
	je	.L59
.L58:
	.loc 1 226 0 is_stmt 1 discriminator 2
	addl	$1, -220(%rbp)
.L56:
	.loc 1 226 0 is_stmt 0 discriminator 1
	cmpl	$199, -220(%rbp)
	jg	.L63
	.loc 1 226 0 discriminator 3
	movl	-220(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-232(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	testq	%rax, %rax
	jne	.L61
.L63:
	.loc 1 242 0 is_stmt 1
	nop
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L62
	call	__stack_chk_fail@PLT
.L62:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3677:
	.size	SDL_escrevePontos, .-SDL_escrevePontos
	.globl	for_pontos
	.type	for_pontos, @function
for_pontos:
.LFB3678:
	.loc 1 243 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$240, %rsp
	movq	%rdi, -232(%rbp)
	movq	%rsi, -240(%rbp)
	.loc 1 243 0
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	.loc 1 247 0
	movq	-232(%rbp), %rdx
	leaq	-208(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strcpy@PLT
	.loc 1 249 0
	jmp	.L65
.L68:
	.loc 1 250 0
	movq	g_pRenderer(%rip), %rax
	movl	$255, %r8d
	movl	$0, %ecx
	movl	$0, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	SDL_SetRenderDrawColor@PLT
	.loc 1 251 0
	movq	-240(%rbp), %rax
	movl	20(%rax), %edi
	movq	-240(%rbp), %rax
	movl	16(%rax), %ecx
	movq	-232(%rbp), %rax
	movl	20(%rax), %edx
	movq	-232(%rbp), %rax
	movl	16(%rax), %esi
	movq	g_pRenderer(%rip), %rax
	movl	%edi, %r8d
	movq	%rax, %rdi
	call	SDL_RenderDrawLine@PLT
	.loc 1 253 0
	movq	-232(%rbp), %rax
	movq	56(%rax), %rax
	testq	%rax, %rax
	je	.L66
	.loc 1 254 0
	movq	-232(%rbp), %rax
	movq	56(%rax), %rax
	movq	%rax, -224(%rbp)
	.loc 1 255 0
	movq	g_pRenderer(%rip), %rax
	movl	$255, %r8d
	movl	$0, %ecx
	movl	$0, %edx
	movl	$255, %esi
	movq	%rax, %rdi
	call	SDL_SetRenderDrawColor@PLT
	.loc 1 256 0
	movq	-224(%rbp), %rax
	movl	20(%rax), %edi
	movq	-224(%rbp), %rax
	movl	16(%rax), %ecx
	movq	-232(%rbp), %rax
	movl	20(%rax), %edx
	movq	-232(%rbp), %rax
	movl	16(%rax), %esi
	movq	g_pRenderer(%rip), %rax
	movl	%edi, %r8d
	movq	%rax, %rdi
	call	SDL_RenderDrawLine@PLT
	.loc 1 258 0
	movq	-224(%rbp), %rdx
	movq	-232(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strcmp@PLT
	testl	%eax, %eax
	jne	.L66
	.loc 1 258 0 is_stmt 0 discriminator 1
	movq	-224(%rbp), %rax
	movq	48(%rax), %rax
	testq	%rax, %rax
	je	.L66
	.loc 1 259 0 is_stmt 1
	movq	-224(%rbp), %rax
	movq	%rax, -216(%rbp)
	.loc 1 260 0
	movq	-224(%rbp), %rax
	movq	48(%rax), %rax
	movq	%rax, -224(%rbp)
	.loc 1 261 0
	movq	-224(%rbp), %rdx
	movq	-216(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	for_pontos
.L66:
	.loc 1 249 0
	movq	-232(%rbp), %rax
	movq	48(%rax), %rax
	movq	%rax, -232(%rbp)
	movq	-240(%rbp), %rax
	movq	48(%rax), %rax
	movq	%rax, -240(%rbp)
.L65:
	.loc 1 249 0 is_stmt 0 discriminator 1
	cmpq	$0, -232(%rbp)
	je	.L70
	.loc 1 249 0 discriminator 2
	cmpq	$0, -240(%rbp)
	je	.L70
	.loc 1 249 0 discriminator 3
	movq	-232(%rbp), %rax
	leaq	-208(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strcmp@PLT
	testl	%eax, %eax
	je	.L68
.L70:
	.loc 1 268 0 is_stmt 1
	nop
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L69
	call	__stack_chk_fail@PLT
.L69:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3678:
	.size	for_pontos, .-for_pontos
	.globl	SDL_desenhaButoesHUD
	.type	SDL_desenhaButoesHUD, @function
SDL_desenhaButoesHUD:
.LFB3679:
	.loc 1 269 0
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$80, %rsp
	movq	%rdi, -72(%rbp)
	.loc 1 269 0
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	.loc 1 272 0
	movq	-72(%rbp), %rax
	movl	(%rax), %eax
	subl	$75, %eax
	movl	%eax, -64(%rbp)
	.loc 1 273 0
	movq	-72(%rbp), %rax
	addq	$4, %rax
	movl	(%rax), %eax
	subl	$45, %eax
	movl	%eax, -60(%rbp)
	.loc 1 274 0
	movl	$40, -56(%rbp)
	.loc 1 275 0
	movl	$20, -52(%rbp)
	.loc 1 278 0
	movq	-72(%rbp), %rax
	movl	(%rax), %eax
	subl	$75, %eax
	movl	%eax, -64(%rbp)
	.loc 1 279 0
	movq	-72(%rbp), %rax
	addq	$4, %rax
	movl	(%rax), %eax
	subl	$75, %eax
	movl	%eax, -60(%rbp)
	.loc 1 280 0
	movl	$40, -56(%rbp)
	.loc 1 281 0
	movl	$20, -52(%rbp)
	.loc 1 284 0
	movq	-72(%rbp), %rax
	movl	(%rax), %eax
	subl	$75, %eax
	movl	%eax, -64(%rbp)
	.loc 1 285 0
	movq	-72(%rbp), %rax
	addq	$4, %rax
	movl	(%rax), %eax
	subl	$105, %eax
	movl	%eax, -60(%rbp)
	.loc 1 286 0
	movl	$40, -56(%rbp)
	.loc 1 287 0
	movl	$20, -52(%rbp)
	.loc 1 289 0
	movq	g_pRenderer(%rip), %rax
	movl	$100, %r8d
	movl	$100, %ecx
	movl	$255, %edx
	movl	$200, %esi
	movq	%rax, %rdi
	call	SDL_SetRenderDrawColor@PLT
	.loc 1 292 0
	movq	g_pRenderer(%rip), %rax
	leaq	-64(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	SDL_RenderDrawRect@PLT
	.loc 1 293 0
	movq	g_pRenderer(%rip), %rax
	leaq	-64(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	SDL_RenderFillRect@PLT
	.loc 1 294 0
	movq	g_pRenderer(%rip), %rax
	leaq	-48(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	SDL_RenderDrawRect@PLT
	.loc 1 295 0
	movq	g_pRenderer(%rip), %rax
	leaq	-48(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	SDL_RenderFillRect@PLT
	.loc 1 296 0
	movq	g_pRenderer(%rip), %rax
	leaq	-32(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	SDL_RenderDrawRect@PLT
	.loc 1 297 0
	movq	g_pRenderer(%rip), %rax
	leaq	-32(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	SDL_RenderFillRect@PLT
	.loc 1 299 0
	nop
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L72
	call	__stack_chk_fail@PLT
.L72:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3679:
	.size	SDL_desenhaButoesHUD, .-SDL_desenhaButoesHUD
.Letext0:
	.file 2 "/usr/lib/gcc/x86_64-linux-gnu/7/include/stddef.h"
	.file 3 "/usr/include/x86_64-linux-gnu/bits/types.h"
	.file 4 "/usr/include/x86_64-linux-gnu/bits/libio.h"
	.file 5 "/usr/include/stdio.h"
	.file 6 "/usr/include/x86_64-linux-gnu/bits/stdint-uintn.h"
	.file 7 "/usr/local/include/SDL2/SDL_stdinc.h"
	.file 8 "/usr/local/include/SDL2/SDL_pixels.h"
	.file 9 "/usr/local/include/SDL2/SDL_rect.h"
	.file 10 "/usr/local/include/SDL2/SDL_video.h"
	.file 11 "/usr/local/include/SDL2/SDL_scancode.h"
	.file 12 "/usr/local/include/SDL2/SDL_messagebox.h"
	.file 13 "/usr/local/include/SDL2/SDL_render.h"
	.file 14 "/usr/include/time.h"
	.file 15 "/media/sf_Prog/ProjetoFinal/comboios.h"
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.long	0x11a0
	.value	0x4
	.long	.Ldebug_abbrev0
	.byte	0x8
	.uleb128 0x1
	.long	.LASF430
	.byte	0xc
	.long	.LASF431
	.long	.LASF432
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.long	.Ldebug_line0
	.uleb128 0x2
	.long	.LASF5
	.byte	0x2
	.byte	0xd8
	.long	0x38
	.uleb128 0x3
	.byte	0x8
	.byte	0x7
	.long	.LASF0
	.uleb128 0x3
	.byte	0x1
	.byte	0x8
	.long	.LASF1
	.uleb128 0x3
	.byte	0x2
	.byte	0x7
	.long	.LASF2
	.uleb128 0x3
	.byte	0x4
	.byte	0x7
	.long	.LASF3
	.uleb128 0x3
	.byte	0x1
	.byte	0x6
	.long	.LASF4
	.uleb128 0x2
	.long	.LASF6
	.byte	0x3
	.byte	0x25
	.long	0x3f
	.uleb128 0x3
	.byte	0x2
	.byte	0x5
	.long	.LASF7
	.uleb128 0x4
	.byte	0x4
	.byte	0x5
	.string	"int"
	.uleb128 0x2
	.long	.LASF8
	.byte	0x3
	.byte	0x29
	.long	0x4d
	.uleb128 0x3
	.byte	0x8
	.byte	0x5
	.long	.LASF9
	.uleb128 0x2
	.long	.LASF10
	.byte	0x3
	.byte	0x8c
	.long	0x7f
	.uleb128 0x2
	.long	.LASF11
	.byte	0x3
	.byte	0x8d
	.long	0x7f
	.uleb128 0x5
	.long	0x6d
	.long	0xac
	.uleb128 0x6
	.long	0x38
	.byte	0x1
	.byte	0
	.uleb128 0x7
	.byte	0x8
	.uleb128 0x8
	.byte	0x8
	.long	0xb4
	.uleb128 0x3
	.byte	0x1
	.byte	0x6
	.long	.LASF12
	.uleb128 0x9
	.long	.LASF42
	.byte	0xd8
	.byte	0x4
	.byte	0xf5
	.long	0x23b
	.uleb128 0xa
	.long	.LASF13
	.byte	0x4
	.byte	0xf6
	.long	0x6d
	.byte	0
	.uleb128 0xa
	.long	.LASF14
	.byte	0x4
	.byte	0xfb
	.long	0xae
	.byte	0x8
	.uleb128 0xa
	.long	.LASF15
	.byte	0x4
	.byte	0xfc
	.long	0xae
	.byte	0x10
	.uleb128 0xa
	.long	.LASF16
	.byte	0x4
	.byte	0xfd
	.long	0xae
	.byte	0x18
	.uleb128 0xa
	.long	.LASF17
	.byte	0x4
	.byte	0xfe
	.long	0xae
	.byte	0x20
	.uleb128 0xa
	.long	.LASF18
	.byte	0x4
	.byte	0xff
	.long	0xae
	.byte	0x28
	.uleb128 0xb
	.long	.LASF19
	.byte	0x4
	.value	0x100
	.long	0xae
	.byte	0x30
	.uleb128 0xb
	.long	.LASF20
	.byte	0x4
	.value	0x101
	.long	0xae
	.byte	0x38
	.uleb128 0xb
	.long	.LASF21
	.byte	0x4
	.value	0x102
	.long	0xae
	.byte	0x40
	.uleb128 0xb
	.long	.LASF22
	.byte	0x4
	.value	0x104
	.long	0xae
	.byte	0x48
	.uleb128 0xb
	.long	.LASF23
	.byte	0x4
	.value	0x105
	.long	0xae
	.byte	0x50
	.uleb128 0xb
	.long	.LASF24
	.byte	0x4
	.value	0x106
	.long	0xae
	.byte	0x58
	.uleb128 0xb
	.long	.LASF25
	.byte	0x4
	.value	0x108
	.long	0x283
	.byte	0x60
	.uleb128 0xb
	.long	.LASF26
	.byte	0x4
	.value	0x10a
	.long	0x289
	.byte	0x68
	.uleb128 0xb
	.long	.LASF27
	.byte	0x4
	.value	0x10c
	.long	0x6d
	.byte	0x70
	.uleb128 0xb
	.long	.LASF28
	.byte	0x4
	.value	0x110
	.long	0x6d
	.byte	0x74
	.uleb128 0xb
	.long	.LASF29
	.byte	0x4
	.value	0x112
	.long	0x86
	.byte	0x78
	.uleb128 0xb
	.long	.LASF30
	.byte	0x4
	.value	0x116
	.long	0x46
	.byte	0x80
	.uleb128 0xb
	.long	.LASF31
	.byte	0x4
	.value	0x117
	.long	0x54
	.byte	0x82
	.uleb128 0xb
	.long	.LASF32
	.byte	0x4
	.value	0x118
	.long	0x28f
	.byte	0x83
	.uleb128 0xb
	.long	.LASF33
	.byte	0x4
	.value	0x11c
	.long	0x29f
	.byte	0x88
	.uleb128 0xb
	.long	.LASF34
	.byte	0x4
	.value	0x125
	.long	0x91
	.byte	0x90
	.uleb128 0xb
	.long	.LASF35
	.byte	0x4
	.value	0x12d
	.long	0xac
	.byte	0x98
	.uleb128 0xb
	.long	.LASF36
	.byte	0x4
	.value	0x12e
	.long	0xac
	.byte	0xa0
	.uleb128 0xb
	.long	.LASF37
	.byte	0x4
	.value	0x12f
	.long	0xac
	.byte	0xa8
	.uleb128 0xb
	.long	.LASF38
	.byte	0x4
	.value	0x130
	.long	0xac
	.byte	0xb0
	.uleb128 0xb
	.long	.LASF39
	.byte	0x4
	.value	0x132
	.long	0x2d
	.byte	0xb8
	.uleb128 0xb
	.long	.LASF40
	.byte	0x4
	.value	0x133
	.long	0x6d
	.byte	0xc0
	.uleb128 0xb
	.long	.LASF41
	.byte	0x4
	.value	0x135
	.long	0x2a5
	.byte	0xc4
	.byte	0
	.uleb128 0x5
	.long	0xb4
	.long	0x24b
	.uleb128 0x6
	.long	0x38
	.byte	0x3
	.byte	0
	.uleb128 0xc
	.long	.LASF433
	.byte	0x4
	.byte	0x9a
	.uleb128 0x9
	.long	.LASF43
	.byte	0x18
	.byte	0x4
	.byte	0xa0
	.long	0x283
	.uleb128 0xa
	.long	.LASF44
	.byte	0x4
	.byte	0xa1
	.long	0x283
	.byte	0
	.uleb128 0xa
	.long	.LASF45
	.byte	0x4
	.byte	0xa2
	.long	0x289
	.byte	0x8
	.uleb128 0xa
	.long	.LASF46
	.byte	0x4
	.byte	0xa6
	.long	0x6d
	.byte	0x10
	.byte	0
	.uleb128 0x8
	.byte	0x8
	.long	0x252
	.uleb128 0x8
	.byte	0x8
	.long	0xbb
	.uleb128 0x5
	.long	0xb4
	.long	0x29f
	.uleb128 0x6
	.long	0x38
	.byte	0
	.byte	0
	.uleb128 0x8
	.byte	0x8
	.long	0x24b
	.uleb128 0x5
	.long	0xb4
	.long	0x2b5
	.uleb128 0x6
	.long	0x38
	.byte	0x13
	.byte	0
	.uleb128 0xd
	.long	.LASF103
	.uleb128 0xe
	.long	.LASF47
	.byte	0x4
	.value	0x13f
	.long	0x2b5
	.uleb128 0xe
	.long	.LASF48
	.byte	0x4
	.value	0x140
	.long	0x2b5
	.uleb128 0xe
	.long	.LASF49
	.byte	0x4
	.value	0x141
	.long	0x2b5
	.uleb128 0xf
	.long	.LASF50
	.byte	0x5
	.byte	0x87
	.long	0x289
	.uleb128 0xf
	.long	.LASF51
	.byte	0x5
	.byte	0x88
	.long	0x289
	.uleb128 0xf
	.long	.LASF52
	.byte	0x5
	.byte	0x89
	.long	0x289
	.uleb128 0x3
	.byte	0x8
	.byte	0x5
	.long	.LASF53
	.uleb128 0x2
	.long	.LASF54
	.byte	0x6
	.byte	0x18
	.long	0x5b
	.uleb128 0x2
	.long	.LASF55
	.byte	0x6
	.byte	0x1a
	.long	0x74
	.uleb128 0x3
	.byte	0x4
	.byte	0x4
	.long	.LASF56
	.uleb128 0x3
	.byte	0x8
	.byte	0x4
	.long	.LASF57
	.uleb128 0x2
	.long	.LASF58
	.byte	0x7
	.byte	0xb3
	.long	0x306
	.uleb128 0x2
	.long	.LASF59
	.byte	0x7
	.byte	0xcb
	.long	0x311
	.uleb128 0x3
	.byte	0x8
	.byte	0x7
	.long	.LASF60
	.uleb128 0x10
	.byte	0x7
	.byte	0x4
	.long	0x4d
	.byte	0x8
	.byte	0x34
	.long	0x39d
	.uleb128 0x11
	.long	.LASF61
	.byte	0
	.uleb128 0x11
	.long	.LASF62
	.byte	0x1
	.uleb128 0x11
	.long	.LASF63
	.byte	0x2
	.uleb128 0x11
	.long	.LASF64
	.byte	0x3
	.uleb128 0x11
	.long	.LASF65
	.byte	0x4
	.uleb128 0x11
	.long	.LASF66
	.byte	0x5
	.uleb128 0x11
	.long	.LASF67
	.byte	0x6
	.uleb128 0x11
	.long	.LASF68
	.byte	0x7
	.uleb128 0x11
	.long	.LASF69
	.byte	0x8
	.uleb128 0x11
	.long	.LASF70
	.byte	0x9
	.uleb128 0x11
	.long	.LASF71
	.byte	0xa
	.uleb128 0x11
	.long	.LASF72
	.byte	0xb
	.byte	0
	.uleb128 0x10
	.byte	0x7
	.byte	0x4
	.long	0x4d
	.byte	0x8
	.byte	0x45
	.long	0x3bd
	.uleb128 0x11
	.long	.LASF73
	.byte	0
	.uleb128 0x11
	.long	.LASF74
	.byte	0x1
	.uleb128 0x11
	.long	.LASF75
	.byte	0x2
	.byte	0
	.uleb128 0x10
	.byte	0x7
	.byte	0x4
	.long	0x4d
	.byte	0x8
	.byte	0x4d
	.long	0x401
	.uleb128 0x11
	.long	.LASF76
	.byte	0
	.uleb128 0x11
	.long	.LASF77
	.byte	0x1
	.uleb128 0x11
	.long	.LASF78
	.byte	0x2
	.uleb128 0x11
	.long	.LASF79
	.byte	0x3
	.uleb128 0x11
	.long	.LASF80
	.byte	0x4
	.uleb128 0x11
	.long	.LASF81
	.byte	0x5
	.uleb128 0x11
	.long	.LASF82
	.byte	0x6
	.uleb128 0x11
	.long	.LASF83
	.byte	0x7
	.uleb128 0x11
	.long	.LASF84
	.byte	0x8
	.byte	0
	.uleb128 0x10
	.byte	0x7
	.byte	0x4
	.long	0x4d
	.byte	0x8
	.byte	0x5d
	.long	0x439
	.uleb128 0x11
	.long	.LASF85
	.byte	0
	.uleb128 0x11
	.long	.LASF86
	.byte	0x1
	.uleb128 0x11
	.long	.LASF87
	.byte	0x2
	.uleb128 0x11
	.long	.LASF88
	.byte	0x3
	.uleb128 0x11
	.long	.LASF89
	.byte	0x4
	.uleb128 0x11
	.long	.LASF90
	.byte	0x5
	.uleb128 0x11
	.long	.LASF91
	.byte	0x6
	.byte	0
	.uleb128 0x10
	.byte	0x7
	.byte	0x4
	.long	0x4d
	.byte	0x8
	.byte	0x69
	.long	0x47d
	.uleb128 0x11
	.long	.LASF92
	.byte	0
	.uleb128 0x11
	.long	.LASF93
	.byte	0x1
	.uleb128 0x11
	.long	.LASF94
	.byte	0x2
	.uleb128 0x11
	.long	.LASF95
	.byte	0x3
	.uleb128 0x11
	.long	.LASF96
	.byte	0x4
	.uleb128 0x11
	.long	.LASF97
	.byte	0x5
	.uleb128 0x11
	.long	.LASF98
	.byte	0x6
	.uleb128 0x11
	.long	.LASF99
	.byte	0x7
	.uleb128 0x11
	.long	.LASF100
	.byte	0x8
	.byte	0
	.uleb128 0x9
	.long	.LASF101
	.byte	0x10
	.byte	0x9
	.byte	0x40
	.long	0x4b2
	.uleb128 0x12
	.string	"x"
	.byte	0x9
	.byte	0x42
	.long	0x6d
	.byte	0
	.uleb128 0x12
	.string	"y"
	.byte	0x9
	.byte	0x42
	.long	0x6d
	.byte	0x4
	.uleb128 0x12
	.string	"w"
	.byte	0x9
	.byte	0x43
	.long	0x6d
	.byte	0x8
	.uleb128 0x12
	.string	"h"
	.byte	0x9
	.byte	0x43
	.long	0x6d
	.byte	0xc
	.byte	0
	.uleb128 0x2
	.long	.LASF101
	.byte	0x9
	.byte	0x44
	.long	0x47d
	.uleb128 0x2
	.long	.LASF102
	.byte	0xa
	.byte	0x5a
	.long	0x4c8
	.uleb128 0xd
	.long	.LASF102
	.uleb128 0x10
	.byte	0x7
	.byte	0x4
	.long	0x4d
	.byte	0xa
	.byte	0x62
	.long	0x570
	.uleb128 0x11
	.long	.LASF104
	.byte	0x1
	.uleb128 0x11
	.long	.LASF105
	.byte	0x2
	.uleb128 0x11
	.long	.LASF106
	.byte	0x4
	.uleb128 0x11
	.long	.LASF107
	.byte	0x8
	.uleb128 0x11
	.long	.LASF108
	.byte	0x10
	.uleb128 0x11
	.long	.LASF109
	.byte	0x20
	.uleb128 0x11
	.long	.LASF110
	.byte	0x40
	.uleb128 0x11
	.long	.LASF111
	.byte	0x80
	.uleb128 0x13
	.long	.LASF112
	.value	0x100
	.uleb128 0x13
	.long	.LASF113
	.value	0x200
	.uleb128 0x13
	.long	.LASF114
	.value	0x400
	.uleb128 0x13
	.long	.LASF115
	.value	0x1001
	.uleb128 0x13
	.long	.LASF116
	.value	0x800
	.uleb128 0x13
	.long	.LASF117
	.value	0x2000
	.uleb128 0x13
	.long	.LASF118
	.value	0x4000
	.uleb128 0x13
	.long	.LASF119
	.value	0x8000
	.uleb128 0x14
	.long	.LASF120
	.long	0x10000
	.uleb128 0x14
	.long	.LASF121
	.long	0x20000
	.uleb128 0x14
	.long	.LASF122
	.long	0x40000
	.uleb128 0x14
	.long	.LASF123
	.long	0x80000
	.uleb128 0x14
	.long	.LASF124
	.long	0x10000000
	.byte	0
	.uleb128 0x8
	.byte	0x8
	.long	0x4bd
	.uleb128 0x10
	.byte	0x7
	.byte	0x4
	.long	0x4d
	.byte	0xb
	.byte	0x2c
	.long	0xb5b
	.uleb128 0x11
	.long	.LASF125
	.byte	0
	.uleb128 0x11
	.long	.LASF126
	.byte	0x4
	.uleb128 0x11
	.long	.LASF127
	.byte	0x5
	.uleb128 0x11
	.long	.LASF128
	.byte	0x6
	.uleb128 0x11
	.long	.LASF129
	.byte	0x7
	.uleb128 0x11
	.long	.LASF130
	.byte	0x8
	.uleb128 0x11
	.long	.LASF131
	.byte	0x9
	.uleb128 0x11
	.long	.LASF132
	.byte	0xa
	.uleb128 0x11
	.long	.LASF133
	.byte	0xb
	.uleb128 0x11
	.long	.LASF134
	.byte	0xc
	.uleb128 0x11
	.long	.LASF135
	.byte	0xd
	.uleb128 0x11
	.long	.LASF136
	.byte	0xe
	.uleb128 0x11
	.long	.LASF137
	.byte	0xf
	.uleb128 0x11
	.long	.LASF138
	.byte	0x10
	.uleb128 0x11
	.long	.LASF139
	.byte	0x11
	.uleb128 0x11
	.long	.LASF140
	.byte	0x12
	.uleb128 0x11
	.long	.LASF141
	.byte	0x13
	.uleb128 0x11
	.long	.LASF142
	.byte	0x14
	.uleb128 0x11
	.long	.LASF143
	.byte	0x15
	.uleb128 0x11
	.long	.LASF144
	.byte	0x16
	.uleb128 0x11
	.long	.LASF145
	.byte	0x17
	.uleb128 0x11
	.long	.LASF146
	.byte	0x18
	.uleb128 0x11
	.long	.LASF147
	.byte	0x19
	.uleb128 0x11
	.long	.LASF148
	.byte	0x1a
	.uleb128 0x11
	.long	.LASF149
	.byte	0x1b
	.uleb128 0x11
	.long	.LASF150
	.byte	0x1c
	.uleb128 0x11
	.long	.LASF151
	.byte	0x1d
	.uleb128 0x11
	.long	.LASF152
	.byte	0x1e
	.uleb128 0x11
	.long	.LASF153
	.byte	0x1f
	.uleb128 0x11
	.long	.LASF154
	.byte	0x20
	.uleb128 0x11
	.long	.LASF155
	.byte	0x21
	.uleb128 0x11
	.long	.LASF156
	.byte	0x22
	.uleb128 0x11
	.long	.LASF157
	.byte	0x23
	.uleb128 0x11
	.long	.LASF158
	.byte	0x24
	.uleb128 0x11
	.long	.LASF159
	.byte	0x25
	.uleb128 0x11
	.long	.LASF160
	.byte	0x26
	.uleb128 0x11
	.long	.LASF161
	.byte	0x27
	.uleb128 0x11
	.long	.LASF162
	.byte	0x28
	.uleb128 0x11
	.long	.LASF163
	.byte	0x29
	.uleb128 0x11
	.long	.LASF164
	.byte	0x2a
	.uleb128 0x11
	.long	.LASF165
	.byte	0x2b
	.uleb128 0x11
	.long	.LASF166
	.byte	0x2c
	.uleb128 0x11
	.long	.LASF167
	.byte	0x2d
	.uleb128 0x11
	.long	.LASF168
	.byte	0x2e
	.uleb128 0x11
	.long	.LASF169
	.byte	0x2f
	.uleb128 0x11
	.long	.LASF170
	.byte	0x30
	.uleb128 0x11
	.long	.LASF171
	.byte	0x31
	.uleb128 0x11
	.long	.LASF172
	.byte	0x32
	.uleb128 0x11
	.long	.LASF173
	.byte	0x33
	.uleb128 0x11
	.long	.LASF174
	.byte	0x34
	.uleb128 0x11
	.long	.LASF175
	.byte	0x35
	.uleb128 0x11
	.long	.LASF176
	.byte	0x36
	.uleb128 0x11
	.long	.LASF177
	.byte	0x37
	.uleb128 0x11
	.long	.LASF178
	.byte	0x38
	.uleb128 0x11
	.long	.LASF179
	.byte	0x39
	.uleb128 0x11
	.long	.LASF180
	.byte	0x3a
	.uleb128 0x11
	.long	.LASF181
	.byte	0x3b
	.uleb128 0x11
	.long	.LASF182
	.byte	0x3c
	.uleb128 0x11
	.long	.LASF183
	.byte	0x3d
	.uleb128 0x11
	.long	.LASF184
	.byte	0x3e
	.uleb128 0x11
	.long	.LASF185
	.byte	0x3f
	.uleb128 0x11
	.long	.LASF186
	.byte	0x40
	.uleb128 0x11
	.long	.LASF187
	.byte	0x41
	.uleb128 0x11
	.long	.LASF188
	.byte	0x42
	.uleb128 0x11
	.long	.LASF189
	.byte	0x43
	.uleb128 0x11
	.long	.LASF190
	.byte	0x44
	.uleb128 0x11
	.long	.LASF191
	.byte	0x45
	.uleb128 0x11
	.long	.LASF192
	.byte	0x46
	.uleb128 0x11
	.long	.LASF193
	.byte	0x47
	.uleb128 0x11
	.long	.LASF194
	.byte	0x48
	.uleb128 0x11
	.long	.LASF195
	.byte	0x49
	.uleb128 0x11
	.long	.LASF196
	.byte	0x4a
	.uleb128 0x11
	.long	.LASF197
	.byte	0x4b
	.uleb128 0x11
	.long	.LASF198
	.byte	0x4c
	.uleb128 0x11
	.long	.LASF199
	.byte	0x4d
	.uleb128 0x11
	.long	.LASF200
	.byte	0x4e
	.uleb128 0x11
	.long	.LASF201
	.byte	0x4f
	.uleb128 0x11
	.long	.LASF202
	.byte	0x50
	.uleb128 0x11
	.long	.LASF203
	.byte	0x51
	.uleb128 0x11
	.long	.LASF204
	.byte	0x52
	.uleb128 0x11
	.long	.LASF205
	.byte	0x53
	.uleb128 0x11
	.long	.LASF206
	.byte	0x54
	.uleb128 0x11
	.long	.LASF207
	.byte	0x55
	.uleb128 0x11
	.long	.LASF208
	.byte	0x56
	.uleb128 0x11
	.long	.LASF209
	.byte	0x57
	.uleb128 0x11
	.long	.LASF210
	.byte	0x58
	.uleb128 0x11
	.long	.LASF211
	.byte	0x59
	.uleb128 0x11
	.long	.LASF212
	.byte	0x5a
	.uleb128 0x11
	.long	.LASF213
	.byte	0x5b
	.uleb128 0x11
	.long	.LASF214
	.byte	0x5c
	.uleb128 0x11
	.long	.LASF215
	.byte	0x5d
	.uleb128 0x11
	.long	.LASF216
	.byte	0x5e
	.uleb128 0x11
	.long	.LASF217
	.byte	0x5f
	.uleb128 0x11
	.long	.LASF218
	.byte	0x60
	.uleb128 0x11
	.long	.LASF219
	.byte	0x61
	.uleb128 0x11
	.long	.LASF220
	.byte	0x62
	.uleb128 0x11
	.long	.LASF221
	.byte	0x63
	.uleb128 0x11
	.long	.LASF222
	.byte	0x64
	.uleb128 0x11
	.long	.LASF223
	.byte	0x65
	.uleb128 0x11
	.long	.LASF224
	.byte	0x66
	.uleb128 0x11
	.long	.LASF225
	.byte	0x67
	.uleb128 0x11
	.long	.LASF226
	.byte	0x68
	.uleb128 0x11
	.long	.LASF227
	.byte	0x69
	.uleb128 0x11
	.long	.LASF228
	.byte	0x6a
	.uleb128 0x11
	.long	.LASF229
	.byte	0x6b
	.uleb128 0x11
	.long	.LASF230
	.byte	0x6c
	.uleb128 0x11
	.long	.LASF231
	.byte	0x6d
	.uleb128 0x11
	.long	.LASF232
	.byte	0x6e
	.uleb128 0x11
	.long	.LASF233
	.byte	0x6f
	.uleb128 0x11
	.long	.LASF234
	.byte	0x70
	.uleb128 0x11
	.long	.LASF235
	.byte	0x71
	.uleb128 0x11
	.long	.LASF236
	.byte	0x72
	.uleb128 0x11
	.long	.LASF237
	.byte	0x73
	.uleb128 0x11
	.long	.LASF238
	.byte	0x74
	.uleb128 0x11
	.long	.LASF239
	.byte	0x75
	.uleb128 0x11
	.long	.LASF240
	.byte	0x76
	.uleb128 0x11
	.long	.LASF241
	.byte	0x77
	.uleb128 0x11
	.long	.LASF242
	.byte	0x78
	.uleb128 0x11
	.long	.LASF243
	.byte	0x79
	.uleb128 0x11
	.long	.LASF244
	.byte	0x7a
	.uleb128 0x11
	.long	.LASF245
	.byte	0x7b
	.uleb128 0x11
	.long	.LASF246
	.byte	0x7c
	.uleb128 0x11
	.long	.LASF247
	.byte	0x7d
	.uleb128 0x11
	.long	.LASF248
	.byte	0x7e
	.uleb128 0x11
	.long	.LASF249
	.byte	0x7f
	.uleb128 0x11
	.long	.LASF250
	.byte	0x80
	.uleb128 0x11
	.long	.LASF251
	.byte	0x81
	.uleb128 0x11
	.long	.LASF252
	.byte	0x85
	.uleb128 0x11
	.long	.LASF253
	.byte	0x86
	.uleb128 0x11
	.long	.LASF254
	.byte	0x87
	.uleb128 0x11
	.long	.LASF255
	.byte	0x88
	.uleb128 0x11
	.long	.LASF256
	.byte	0x89
	.uleb128 0x11
	.long	.LASF257
	.byte	0x8a
	.uleb128 0x11
	.long	.LASF258
	.byte	0x8b
	.uleb128 0x11
	.long	.LASF259
	.byte	0x8c
	.uleb128 0x11
	.long	.LASF260
	.byte	0x8d
	.uleb128 0x11
	.long	.LASF261
	.byte	0x8e
	.uleb128 0x11
	.long	.LASF262
	.byte	0x8f
	.uleb128 0x11
	.long	.LASF263
	.byte	0x90
	.uleb128 0x11
	.long	.LASF264
	.byte	0x91
	.uleb128 0x11
	.long	.LASF265
	.byte	0x92
	.uleb128 0x11
	.long	.LASF266
	.byte	0x93
	.uleb128 0x11
	.long	.LASF267
	.byte	0x94
	.uleb128 0x11
	.long	.LASF268
	.byte	0x95
	.uleb128 0x11
	.long	.LASF269
	.byte	0x96
	.uleb128 0x11
	.long	.LASF270
	.byte	0x97
	.uleb128 0x11
	.long	.LASF271
	.byte	0x98
	.uleb128 0x11
	.long	.LASF272
	.byte	0x99
	.uleb128 0x11
	.long	.LASF273
	.byte	0x9a
	.uleb128 0x11
	.long	.LASF274
	.byte	0x9b
	.uleb128 0x11
	.long	.LASF275
	.byte	0x9c
	.uleb128 0x11
	.long	.LASF276
	.byte	0x9d
	.uleb128 0x11
	.long	.LASF277
	.byte	0x9e
	.uleb128 0x11
	.long	.LASF278
	.byte	0x9f
	.uleb128 0x11
	.long	.LASF279
	.byte	0xa0
	.uleb128 0x11
	.long	.LASF280
	.byte	0xa1
	.uleb128 0x11
	.long	.LASF281
	.byte	0xa2
	.uleb128 0x11
	.long	.LASF282
	.byte	0xa3
	.uleb128 0x11
	.long	.LASF283
	.byte	0xa4
	.uleb128 0x11
	.long	.LASF284
	.byte	0xb0
	.uleb128 0x11
	.long	.LASF285
	.byte	0xb1
	.uleb128 0x11
	.long	.LASF286
	.byte	0xb2
	.uleb128 0x11
	.long	.LASF287
	.byte	0xb3
	.uleb128 0x11
	.long	.LASF288
	.byte	0xb4
	.uleb128 0x11
	.long	.LASF289
	.byte	0xb5
	.uleb128 0x11
	.long	.LASF290
	.byte	0xb6
	.uleb128 0x11
	.long	.LASF291
	.byte	0xb7
	.uleb128 0x11
	.long	.LASF292
	.byte	0xb8
	.uleb128 0x11
	.long	.LASF293
	.byte	0xb9
	.uleb128 0x11
	.long	.LASF294
	.byte	0xba
	.uleb128 0x11
	.long	.LASF295
	.byte	0xbb
	.uleb128 0x11
	.long	.LASF296
	.byte	0xbc
	.uleb128 0x11
	.long	.LASF297
	.byte	0xbd
	.uleb128 0x11
	.long	.LASF298
	.byte	0xbe
	.uleb128 0x11
	.long	.LASF299
	.byte	0xbf
	.uleb128 0x11
	.long	.LASF300
	.byte	0xc0
	.uleb128 0x11
	.long	.LASF301
	.byte	0xc1
	.uleb128 0x11
	.long	.LASF302
	.byte	0xc2
	.uleb128 0x11
	.long	.LASF303
	.byte	0xc3
	.uleb128 0x11
	.long	.LASF304
	.byte	0xc4
	.uleb128 0x11
	.long	.LASF305
	.byte	0xc5
	.uleb128 0x11
	.long	.LASF306
	.byte	0xc6
	.uleb128 0x11
	.long	.LASF307
	.byte	0xc7
	.uleb128 0x11
	.long	.LASF308
	.byte	0xc8
	.uleb128 0x11
	.long	.LASF309
	.byte	0xc9
	.uleb128 0x11
	.long	.LASF310
	.byte	0xca
	.uleb128 0x11
	.long	.LASF311
	.byte	0xcb
	.uleb128 0x11
	.long	.LASF312
	.byte	0xcc
	.uleb128 0x11
	.long	.LASF313
	.byte	0xcd
	.uleb128 0x11
	.long	.LASF314
	.byte	0xce
	.uleb128 0x11
	.long	.LASF315
	.byte	0xcf
	.uleb128 0x11
	.long	.LASF316
	.byte	0xd0
	.uleb128 0x11
	.long	.LASF317
	.byte	0xd1
	.uleb128 0x11
	.long	.LASF318
	.byte	0xd2
	.uleb128 0x11
	.long	.LASF319
	.byte	0xd3
	.uleb128 0x11
	.long	.LASF320
	.byte	0xd4
	.uleb128 0x11
	.long	.LASF321
	.byte	0xd5
	.uleb128 0x11
	.long	.LASF322
	.byte	0xd6
	.uleb128 0x11
	.long	.LASF323
	.byte	0xd7
	.uleb128 0x11
	.long	.LASF324
	.byte	0xd8
	.uleb128 0x11
	.long	.LASF325
	.byte	0xd9
	.uleb128 0x11
	.long	.LASF326
	.byte	0xda
	.uleb128 0x11
	.long	.LASF327
	.byte	0xdb
	.uleb128 0x11
	.long	.LASF328
	.byte	0xdc
	.uleb128 0x11
	.long	.LASF329
	.byte	0xdd
	.uleb128 0x11
	.long	.LASF330
	.byte	0xe0
	.uleb128 0x11
	.long	.LASF331
	.byte	0xe1
	.uleb128 0x11
	.long	.LASF332
	.byte	0xe2
	.uleb128 0x11
	.long	.LASF333
	.byte	0xe3
	.uleb128 0x11
	.long	.LASF334
	.byte	0xe4
	.uleb128 0x11
	.long	.LASF335
	.byte	0xe5
	.uleb128 0x11
	.long	.LASF336
	.byte	0xe6
	.uleb128 0x11
	.long	.LASF337
	.byte	0xe7
	.uleb128 0x13
	.long	.LASF338
	.value	0x101
	.uleb128 0x13
	.long	.LASF339
	.value	0x102
	.uleb128 0x13
	.long	.LASF340
	.value	0x103
	.uleb128 0x13
	.long	.LASF341
	.value	0x104
	.uleb128 0x13
	.long	.LASF342
	.value	0x105
	.uleb128 0x13
	.long	.LASF343
	.value	0x106
	.uleb128 0x13
	.long	.LASF344
	.value	0x107
	.uleb128 0x13
	.long	.LASF345
	.value	0x108
	.uleb128 0x13
	.long	.LASF346
	.value	0x109
	.uleb128 0x13
	.long	.LASF347
	.value	0x10a
	.uleb128 0x13
	.long	.LASF348
	.value	0x10b
	.uleb128 0x13
	.long	.LASF349
	.value	0x10c
	.uleb128 0x13
	.long	.LASF350
	.value	0x10d
	.uleb128 0x13
	.long	.LASF351
	.value	0x10e
	.uleb128 0x13
	.long	.LASF352
	.value	0x10f
	.uleb128 0x13
	.long	.LASF353
	.value	0x110
	.uleb128 0x13
	.long	.LASF354
	.value	0x111
	.uleb128 0x13
	.long	.LASF355
	.value	0x112
	.uleb128 0x13
	.long	.LASF356
	.value	0x113
	.uleb128 0x13
	.long	.LASF357
	.value	0x114
	.uleb128 0x13
	.long	.LASF358
	.value	0x115
	.uleb128 0x13
	.long	.LASF359
	.value	0x116
	.uleb128 0x13
	.long	.LASF360
	.value	0x117
	.uleb128 0x13
	.long	.LASF361
	.value	0x118
	.uleb128 0x13
	.long	.LASF362
	.value	0x119
	.uleb128 0x13
	.long	.LASF363
	.value	0x11a
	.uleb128 0x13
	.long	.LASF364
	.value	0x11b
	.uleb128 0x13
	.long	.LASF365
	.value	0x11c
	.uleb128 0x13
	.long	.LASF366
	.value	0x11d
	.uleb128 0x13
	.long	.LASF367
	.value	0x11e
	.uleb128 0x13
	.long	.LASF368
	.value	0x200
	.byte	0
	.uleb128 0x10
	.byte	0x7
	.byte	0x4
	.long	0x4d
	.byte	0xc
	.byte	0x48
	.long	0xb8d
	.uleb128 0x11
	.long	.LASF369
	.byte	0
	.uleb128 0x11
	.long	.LASF370
	.byte	0x1
	.uleb128 0x11
	.long	.LASF371
	.byte	0x2
	.uleb128 0x11
	.long	.LASF372
	.byte	0x3
	.uleb128 0x11
	.long	.LASF373
	.byte	0x4
	.uleb128 0x11
	.long	.LASF374
	.byte	0x5
	.byte	0
	.uleb128 0x2
	.long	.LASF375
	.byte	0xd
	.byte	0x7a
	.long	0xb98
	.uleb128 0xd
	.long	.LASF375
	.uleb128 0x5
	.long	0xae
	.long	0xbad
	.uleb128 0x6
	.long	0x38
	.byte	0x1
	.byte	0
	.uleb128 0xf
	.long	.LASF376
	.byte	0xe
	.byte	0x9f
	.long	0xb9d
	.uleb128 0xf
	.long	.LASF377
	.byte	0xe
	.byte	0xa0
	.long	0x6d
	.uleb128 0xf
	.long	.LASF378
	.byte	0xe
	.byte	0xa1
	.long	0x7f
	.uleb128 0x9
	.long	.LASF379
	.byte	0x24
	.byte	0xf
	.byte	0x18
	.long	0xc2f
	.uleb128 0xa
	.long	.LASF380
	.byte	0xf
	.byte	0x1a
	.long	0xc2f
	.byte	0
	.uleb128 0xa
	.long	.LASF381
	.byte	0xf
	.byte	0x1b
	.long	0x9c
	.byte	0x8
	.uleb128 0x12
	.string	"cor"
	.byte	0xf
	.byte	0x1c
	.long	0x6d
	.byte	0x10
	.uleb128 0xa
	.long	.LASF382
	.byte	0xf
	.byte	0x1d
	.long	0x23b
	.byte	0x14
	.uleb128 0xa
	.long	.LASF383
	.byte	0xf
	.byte	0x1e
	.long	0x6d
	.byte	0x18
	.uleb128 0xa
	.long	.LASF384
	.byte	0xf
	.byte	0x1f
	.long	0x6d
	.byte	0x1c
	.uleb128 0xa
	.long	.LASF385
	.byte	0xf
	.byte	0x20
	.long	0x6d
	.byte	0x20
	.byte	0
	.uleb128 0x5
	.long	0xb4
	.long	0xc3f
	.uleb128 0x6
	.long	0x38
	.byte	0x4
	.byte	0
	.uleb128 0x2
	.long	.LASF386
	.byte	0xf
	.byte	0x22
	.long	0xbce
	.uleb128 0x9
	.long	.LASF387
	.byte	0x40
	.byte	0xf
	.byte	0x24
	.long	0xc85
	.uleb128 0xa
	.long	.LASF388
	.byte	0xf
	.byte	0x25
	.long	0xc2f
	.byte	0
	.uleb128 0xa
	.long	.LASF389
	.byte	0xf
	.byte	0x26
	.long	0xc3f
	.byte	0x8
	.uleb128 0x12
	.string	"RA"
	.byte	0xf
	.byte	0x27
	.long	0xc85
	.byte	0x30
	.uleb128 0x12
	.string	"RB"
	.byte	0xf
	.byte	0x28
	.long	0xc85
	.byte	0x38
	.byte	0
	.uleb128 0x8
	.byte	0x8
	.long	0xc4a
	.uleb128 0x2
	.long	.LASF390
	.byte	0xf
	.byte	0x29
	.long	0xc4a
	.uleb128 0x9
	.long	.LASF391
	.byte	0x38
	.byte	0xf
	.byte	0x2b
	.long	0xd1b
	.uleb128 0xa
	.long	.LASF392
	.byte	0xf
	.byte	0x2d
	.long	0xd1b
	.byte	0
	.uleb128 0xa
	.long	.LASF393
	.byte	0xf
	.byte	0x2e
	.long	0x6d
	.byte	0x4
	.uleb128 0xa
	.long	.LASF394
	.byte	0xf
	.byte	0x2f
	.long	0x6d
	.byte	0x8
	.uleb128 0x12
	.string	"cor"
	.byte	0xf
	.byte	0x30
	.long	0x6d
	.byte	0xc
	.uleb128 0xa
	.long	.LASF388
	.byte	0xf
	.byte	0x31
	.long	0xc2f
	.byte	0x10
	.uleb128 0xa
	.long	.LASF380
	.byte	0xf
	.byte	0x33
	.long	0xc2f
	.byte	0x15
	.uleb128 0xa
	.long	.LASF395
	.byte	0xf
	.byte	0x34
	.long	0x9c
	.byte	0x1c
	.uleb128 0xa
	.long	.LASF396
	.byte	0xf
	.byte	0x35
	.long	0x6d
	.byte	0x24
	.uleb128 0xa
	.long	.LASF397
	.byte	0xf
	.byte	0x36
	.long	0x6d
	.byte	0x28
	.uleb128 0xa
	.long	.LASF398
	.byte	0xf
	.byte	0x37
	.long	0xd2b
	.byte	0x30
	.byte	0
	.uleb128 0x5
	.long	0xb4
	.long	0xd2b
	.uleb128 0x6
	.long	0x38
	.byte	0x2
	.byte	0
	.uleb128 0x8
	.byte	0x8
	.long	0xc8b
	.uleb128 0x2
	.long	.LASF399
	.byte	0xf
	.byte	0x38
	.long	0xc96
	.uleb128 0x9
	.long	.LASF400
	.byte	0x48
	.byte	0xf
	.byte	0x3a
	.long	0xd6d
	.uleb128 0xa
	.long	.LASF401
	.byte	0xf
	.byte	0x3b
	.long	0xd31
	.byte	0
	.uleb128 0xa
	.long	.LASF402
	.byte	0xf
	.byte	0x3c
	.long	0xd6d
	.byte	0x38
	.uleb128 0xa
	.long	.LASF403
	.byte	0xf
	.byte	0x3d
	.long	0xd74
	.byte	0x40
	.byte	0
	.uleb128 0x3
	.byte	0x1
	.byte	0x2
	.long	.LASF404
	.uleb128 0x8
	.byte	0x8
	.long	0xd3c
	.uleb128 0x2
	.long	.LASF405
	.byte	0xf
	.byte	0x3e
	.long	0xd3c
	.uleb128 0x15
	.long	.LASF406
	.byte	0xf
	.byte	0x58
	.long	0xb4
	.uleb128 0x9
	.byte	0x3
	.quad	debug
	.uleb128 0x15
	.long	.LASF407
	.byte	0x1
	.byte	0x3
	.long	0x570
	.uleb128 0x9
	.byte	0x3
	.quad	g_pWindow
	.uleb128 0x15
	.long	.LASF408
	.byte	0x1
	.byte	0x4
	.long	0xdc4
	.uleb128 0x9
	.byte	0x3
	.quad	g_pRenderer
	.uleb128 0x8
	.byte	0x8
	.long	0xb8d
	.uleb128 0x16
	.long	.LASF409
	.byte	0x1
	.value	0x10d
	.quad	.LFB3679
	.quad	.LFE3679-.LFB3679
	.uleb128 0x1
	.byte	0x9c
	.long	0xe24
	.uleb128 0x17
	.long	.LASF411
	.byte	0x1
	.value	0x10d
	.long	0xe24
	.uleb128 0x3
	.byte	0x91
	.sleb128 -88
	.uleb128 0x18
	.string	"r1"
	.byte	0x1
	.value	0x10e
	.long	0x4b2
	.uleb128 0x3
	.byte	0x91
	.sleb128 -80
	.uleb128 0x18
	.string	"r2"
	.byte	0x1
	.value	0x114
	.long	0x4b2
	.uleb128 0x2
	.byte	0x91
	.sleb128 -64
	.uleb128 0x18
	.string	"r3"
	.byte	0x1
	.value	0x11a
	.long	0x4b2
	.uleb128 0x2
	.byte	0x91
	.sleb128 -48
	.byte	0
	.uleb128 0x8
	.byte	0x8
	.long	0x6d
	.uleb128 0x19
	.long	.LASF410
	.byte	0x1
	.byte	0xf3
	.quad	.LFB3678
	.quad	.LFE3678-.LFB3678
	.uleb128 0x1
	.byte	0x9c
	.long	0xe93
	.uleb128 0x1a
	.long	.LASF412
	.byte	0x1
	.byte	0xf3
	.long	0xd2b
	.uleb128 0x3
	.byte	0x91
	.sleb128 -248
	.uleb128 0x1a
	.long	.LASF413
	.byte	0x1
	.byte	0xf3
	.long	0xd2b
	.uleb128 0x3
	.byte	0x91
	.sleb128 -256
	.uleb128 0x1b
	.long	.LASF414
	.byte	0x1
	.byte	0xf4
	.long	0xd2b
	.uleb128 0x3
	.byte	0x91
	.sleb128 -240
	.uleb128 0x1b
	.long	.LASF415
	.byte	0x1
	.byte	0xf4
	.long	0xd2b
	.uleb128 0x3
	.byte	0x91
	.sleb128 -232
	.uleb128 0x1b
	.long	.LASF388
	.byte	0x1
	.byte	0xf5
	.long	0xe93
	.uleb128 0x3
	.byte	0x91
	.sleb128 -224
	.byte	0
	.uleb128 0x5
	.long	0xb4
	.long	0xea3
	.uleb128 0x6
	.long	0x38
	.byte	0xc7
	.byte	0
	.uleb128 0x19
	.long	.LASF416
	.byte	0x1
	.byte	0xdc
	.quad	.LFB3677
	.quad	.LFE3677-.LFB3677
	.uleb128 0x1
	.byte	0x9c
	.long	0xf0a
	.uleb128 0x1a
	.long	.LASF417
	.byte	0x1
	.byte	0xdc
	.long	0xf0a
	.uleb128 0x3
	.byte	0x91
	.sleb128 -248
	.uleb128 0x1a
	.long	.LASF418
	.byte	0x1
	.byte	0xdc
	.long	0xf20
	.uleb128 0x3
	.byte	0x91
	.sleb128 -256
	.uleb128 0x1c
	.string	"i"
	.byte	0x1
	.byte	0xdd
	.long	0x6d
	.uleb128 0x3
	.byte	0x91
	.sleb128 -236
	.uleb128 0x1b
	.long	.LASF388
	.byte	0x1
	.byte	0xde
	.long	0xe93
	.uleb128 0x3
	.byte	0x91
	.sleb128 -224
	.uleb128 0x1b
	.long	.LASF419
	.byte	0x1
	.byte	0xdf
	.long	0xd2b
	.uleb128 0x3
	.byte	0x91
	.sleb128 -232
	.byte	0
	.uleb128 0x8
	.byte	0x8
	.long	0xd2b
	.uleb128 0x5
	.long	0x6d
	.long	0xf20
	.uleb128 0x6
	.long	0x38
	.byte	0x3
	.byte	0
	.uleb128 0x8
	.byte	0x8
	.long	0xf10
	.uleb128 0x19
	.long	.LASF420
	.byte	0x1
	.byte	0xcd
	.quad	.LFB3676
	.quad	.LFE3676-.LFB3676
	.uleb128 0x1
	.byte	0x9c
	.long	0xf7a
	.uleb128 0x1a
	.long	.LASF417
	.byte	0x1
	.byte	0xcd
	.long	0xf0a
	.uleb128 0x2
	.byte	0x91
	.sleb128 -56
	.uleb128 0x1c
	.string	"i"
	.byte	0x1
	.byte	0xce
	.long	0x6d
	.uleb128 0x2
	.byte	0x91
	.sleb128 -36
	.uleb128 0x1b
	.long	.LASF412
	.byte	0x1
	.byte	0xcf
	.long	0xd2b
	.uleb128 0x2
	.byte	0x91
	.sleb128 -32
	.uleb128 0x1b
	.long	.LASF413
	.byte	0x1
	.byte	0xcf
	.long	0xd2b
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.byte	0
	.uleb128 0x19
	.long	.LASF421
	.byte	0x1
	.byte	0x6f
	.quad	.LFB3675
	.quad	.LFE3675-.LFB3675
	.uleb128 0x1
	.byte	0x9c
	.long	0xfea
	.uleb128 0x1a
	.long	.LASF411
	.byte	0x1
	.byte	0x6f
	.long	0xe24
	.uleb128 0x2
	.byte	0x91
	.sleb128 -40
	.uleb128 0x1a
	.long	.LASF422
	.byte	0x1
	.byte	0x6f
	.long	0xfea
	.uleb128 0x2
	.byte	0x91
	.sleb128 -48
	.uleb128 0x1a
	.long	.LASF417
	.byte	0x1
	.byte	0x6f
	.long	0xf0a
	.uleb128 0x2
	.byte	0x91
	.sleb128 -56
	.uleb128 0x1a
	.long	.LASF418
	.byte	0x1
	.byte	0x6f
	.long	0xf20
	.uleb128 0x2
	.byte	0x91
	.sleb128 -64
	.uleb128 0x1b
	.long	.LASF423
	.byte	0x1
	.byte	0x74
	.long	0x6d
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0x1c
	.string	"i"
	.byte	0x1
	.byte	0x75
	.long	0x6d
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.byte	0
	.uleb128 0x8
	.byte	0x8
	.long	0xff0
	.uleb128 0x8
	.byte	0x8
	.long	0xd7a
	.uleb128 0x19
	.long	.LASF424
	.byte	0x1
	.byte	0x50
	.quad	.LFB3674
	.quad	.LFE3674-.LFB3674
	.uleb128 0x1
	.byte	0x9c
	.long	0x1068
	.uleb128 0x1a
	.long	.LASF425
	.byte	0x1
	.byte	0x50
	.long	0xff0
	.uleb128 0x2
	.byte	0x91
	.sleb128 -40
	.uleb128 0x1a
	.long	.LASF418
	.byte	0x1
	.byte	0x50
	.long	0xf20
	.uleb128 0x2
	.byte	0x91
	.sleb128 -48
	.uleb128 0x1a
	.long	.LASF417
	.byte	0x1
	.byte	0x50
	.long	0xf0a
	.uleb128 0x2
	.byte	0x91
	.sleb128 -56
	.uleb128 0x1b
	.long	.LASF426
	.byte	0x1
	.byte	0x51
	.long	0x6d
	.uleb128 0x2
	.byte	0x91
	.sleb128 -32
	.uleb128 0x1b
	.long	.LASF427
	.byte	0x1
	.byte	0x51
	.long	0x6d
	.uleb128 0x2
	.byte	0x91
	.sleb128 -28
	.uleb128 0x1b
	.long	.LASF428
	.byte	0x1
	.byte	0x53
	.long	0xff0
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.byte	0
	.uleb128 0x19
	.long	.LASF429
	.byte	0x1
	.byte	0x24
	.quad	.LFB3673
	.quad	.LFE3673-.LFB3673
	.uleb128 0x1
	.byte	0x9c
	.long	0x10ee
	.uleb128 0x1a
	.long	.LASF428
	.byte	0x1
	.byte	0x24
	.long	0xff0
	.uleb128 0x2
	.byte	0x91
	.sleb128 -56
	.uleb128 0x1a
	.long	.LASF417
	.byte	0x1
	.byte	0x24
	.long	0xf0a
	.uleb128 0x2
	.byte	0x91
	.sleb128 -64
	.uleb128 0x1c
	.string	"X1"
	.byte	0x1
	.byte	0x25
	.long	0x31c
	.uleb128 0x2
	.byte	0x91
	.sleb128 -40
	.uleb128 0x1c
	.string	"X2"
	.byte	0x1
	.byte	0x25
	.long	0x31c
	.uleb128 0x2
	.byte	0x91
	.sleb128 -32
	.uleb128 0x1c
	.string	"Y1"
	.byte	0x1
	.byte	0x25
	.long	0x31c
	.uleb128 0x2
	.byte	0x91
	.sleb128 -36
	.uleb128 0x1c
	.string	"Y2"
	.byte	0x1
	.byte	0x25
	.long	0x31c
	.uleb128 0x2
	.byte	0x91
	.sleb128 -28
	.uleb128 0x1c
	.string	"m"
	.byte	0x1
	.byte	0x25
	.long	0x31c
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0x1c
	.string	"b"
	.byte	0x1
	.byte	0x25
	.long	0x31c
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.byte	0
	.uleb128 0x1d
	.long	.LASF434
	.byte	0x1
	.byte	0xd
	.long	0x6d
	.quad	.LFB3672
	.quad	.LFE3672-.LFB3672
	.uleb128 0x1
	.byte	0x9c
	.long	0x116d
	.uleb128 0x1a
	.long	.LASF422
	.byte	0x1
	.byte	0xd
	.long	0xfea
	.uleb128 0x2
	.byte	0x91
	.sleb128 -56
	.uleb128 0x1a
	.long	.LASF418
	.byte	0x1
	.byte	0xd
	.long	0xf20
	.uleb128 0x2
	.byte	0x91
	.sleb128 -64
	.uleb128 0x1a
	.long	.LASF417
	.byte	0x1
	.byte	0xd
	.long	0xf0a
	.uleb128 0x3
	.byte	0x91
	.sleb128 -72
	.uleb128 0x1c
	.string	"i"
	.byte	0x1
	.byte	0xe
	.long	0x6d
	.uleb128 0x2
	.byte	0x91
	.sleb128 -36
	.uleb128 0x1c
	.string	"d"
	.byte	0x1
	.byte	0xe
	.long	0x6d
	.uleb128 0x2
	.byte	0x91
	.sleb128 -32
	.uleb128 0x1c
	.string	"z"
	.byte	0x1
	.byte	0xe
	.long	0x6d
	.uleb128 0x2
	.byte	0x91
	.sleb128 -28
	.uleb128 0x1b
	.long	.LASF428
	.byte	0x1
	.byte	0xf
	.long	0xff0
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.byte	0
	.uleb128 0x1e
	.long	.LASF435
	.byte	0x1
	.byte	0x8
	.quad	.LFB3671
	.quad	.LFE3671-.LFB3671
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0x1a
	.long	.LASF428
	.byte	0x1
	.byte	0x8
	.long	0xff0
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0x1a
	.long	.LASF417
	.byte	0x1
	.byte	0x8
	.long	0xf0a
	.uleb128 0x2
	.byte	0x91
	.sleb128 -32
	.byte	0
	.byte	0
	.section	.debug_abbrev,"",@progbits
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1b
	.uleb128 0xe
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x10
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0x13
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xc
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xd
	.uleb128 0x13
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0xe
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0xf
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x10
	.uleb128 0x4
	.byte	0x1
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x11
	.uleb128 0x28
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1c
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x12
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x13
	.uleb128 0x28
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1c
	.uleb128 0x5
	.byte	0
	.byte	0
	.uleb128 0x14
	.uleb128 0x28
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1c
	.uleb128 0x6
	.byte	0
	.byte	0
	.uleb128 0x15
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x16
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x17
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x18
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x19
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x1a
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x1b
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x1c
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x1d
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x1e
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_aranges,"",@progbits
	.long	0x2c
	.value	0x2
	.long	.Ldebug_info0
	.byte	0x8
	.byte	0
	.value	0
	.value	0
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.quad	0
	.quad	0
	.section	.debug_line,"",@progbits
.Ldebug_line0:
	.section	.debug_str,"MS",@progbits,1
.LASF179:
	.string	"SDL_SCANCODE_CAPSLOCK"
.LASF435:
	.string	"PosInicial"
.LASF233:
	.string	"SDL_SCANCODE_F20"
.LASF234:
	.string	"SDL_SCANCODE_F21"
.LASF310:
	.string	"SDL_SCANCODE_KP_DBLVERTICALBAR"
.LASF236:
	.string	"SDL_SCANCODE_F23"
.LASF406:
	.string	"debug"
.LASF32:
	.string	"_shortbuf"
.LASF433:
	.string	"_IO_lock_t"
.LASF77:
	.string	"SDL_PACKEDORDER_XRGB"
.LASF235:
	.string	"SDL_SCANCODE_F22"
.LASF308:
	.string	"SDL_SCANCODE_KP_DBLAMPERSAND"
.LASF237:
	.string	"SDL_SCANCODE_F24"
.LASF257:
	.string	"SDL_SCANCODE_INTERNATIONAL4"
.LASF348:
	.string	"SDL_SCANCODE_COMPUTER"
.LASF52:
	.string	"stderr"
.LASF117:
	.string	"SDL_WINDOW_ALLOW_HIGHDPI"
.LASF428:
	.string	"temp"
.LASF398:
	.string	"linha_actual"
.LASF98:
	.string	"SDL_PACKEDLAYOUT_8888"
.LASF387:
	.string	"ferrolinha"
.LASF412:
	.string	"head1"
.LASF313:
	.string	"SDL_SCANCODE_KP_SPACE"
.LASF414:
	.string	"head3"
.LASF431:
	.string	"/media/sf_Prog/ProjetoFinal/SDL_comboios.c"
.LASF19:
	.string	"_IO_write_end"
.LASF3:
	.string	"unsigned int"
.LASF102:
	.string	"SDL_Window"
.LASF425:
	.string	"todo"
.LASF372:
	.string	"SDL_MESSAGEBOX_COLOR_BUTTON_BACKGROUND"
.LASF13:
	.string	"_flags"
.LASF383:
	.string	"Dimensao"
.LASF381:
	.string	"coord"
.LASF353:
	.string	"SDL_SCANCODE_AC_STOP"
.LASF356:
	.string	"SDL_SCANCODE_BRIGHTNESSDOWN"
.LASF28:
	.string	"_flags2"
.LASF371:
	.string	"SDL_MESSAGEBOX_COLOR_BUTTON_BORDER"
.LASF405:
	.string	"COMBOIO"
.LASF29:
	.string	"_old_offset"
.LASF224:
	.string	"SDL_SCANCODE_POWER"
.LASF275:
	.string	"SDL_SCANCODE_CLEAR"
.LASF7:
	.string	"short int"
.LASF163:
	.string	"SDL_SCANCODE_ESCAPE"
.LASF427:
	.string	"randoma"
.LASF21:
	.string	"_IO_buf_end"
.LASF358:
	.string	"SDL_SCANCODE_DISPLAYSWITCH"
.LASF424:
	.string	"trajectoriaComb"
.LASF318:
	.string	"SDL_SCANCODE_KP_MEMCLEAR"
.LASF244:
	.string	"SDL_SCANCODE_UNDO"
.LASF209:
	.string	"SDL_SCANCODE_KP_PLUS"
.LASF407:
	.string	"g_pWindow"
.LASF194:
	.string	"SDL_SCANCODE_PAUSE"
.LASF334:
	.string	"SDL_SCANCODE_RCTRL"
.LASF248:
	.string	"SDL_SCANCODE_FIND"
.LASF99:
	.string	"SDL_PACKEDLAYOUT_2101010"
.LASF365:
	.string	"SDL_SCANCODE_APP2"
.LASF354:
	.string	"SDL_SCANCODE_AC_REFRESH"
.LASF430:
	.string	"GNU C99 7.3.0 -mtune=generic -march=x86-64 -g -g -std=c99 -fstack-protector-strong"
.LASF320:
	.string	"SDL_SCANCODE_KP_MEMSUBTRACT"
.LASF378:
	.string	"__timezone"
.LASF116:
	.string	"SDL_WINDOW_FOREIGN"
.LASF167:
	.string	"SDL_SCANCODE_MINUS"
.LASF360:
	.string	"SDL_SCANCODE_KBDILLUMDOWN"
.LASF239:
	.string	"SDL_SCANCODE_HELP"
.LASF416:
	.string	"SDL_escrevePontos"
.LASF366:
	.string	"SDL_SCANCODE_AUDIOREWIND"
.LASF59:
	.string	"Uint32"
.LASF47:
	.string	"_IO_2_1_stdin_"
.LASF176:
	.string	"SDL_SCANCODE_COMMA"
.LASF311:
	.string	"SDL_SCANCODE_KP_COLON"
.LASF55:
	.string	"uint32_t"
.LASF363:
	.string	"SDL_SCANCODE_SLEEP"
.LASF284:
	.string	"SDL_SCANCODE_KP_00"
.LASF124:
	.string	"SDL_WINDOW_VULKAN"
.LASF51:
	.string	"stdout"
.LASF58:
	.string	"Uint8"
.LASF24:
	.string	"_IO_save_end"
.LASF302:
	.string	"SDL_SCANCODE_KP_XOR"
.LASF110:
	.string	"SDL_WINDOW_MINIMIZED"
.LASF362:
	.string	"SDL_SCANCODE_EJECT"
.LASF280:
	.string	"SDL_SCANCODE_OPER"
.LASF253:
	.string	"SDL_SCANCODE_KP_EQUALSAS400"
.LASF326:
	.string	"SDL_SCANCODE_KP_BINARY"
.LASF370:
	.string	"SDL_MESSAGEBOX_COLOR_TEXT"
.LASF314:
	.string	"SDL_SCANCODE_KP_AT"
.LASF328:
	.string	"SDL_SCANCODE_KP_DECIMAL"
.LASF402:
	.string	"PARACOMBOIO"
.LASF335:
	.string	"SDL_SCANCODE_RSHIFT"
.LASF105:
	.string	"SDL_WINDOW_OPENGL"
.LASF434:
	.string	"InicComboios"
.LASF382:
	.string	"TipoDePonto"
.LASF397:
	.string	"locomotiva"
.LASF339:
	.string	"SDL_SCANCODE_AUDIONEXT"
.LASF293:
	.string	"SDL_SCANCODE_KP_RIGHTBRACE"
.LASF60:
	.string	"long long unsigned int"
.LASF330:
	.string	"SDL_SCANCODE_LCTRL"
.LASF42:
	.string	"_IO_FILE"
.LASF316:
	.string	"SDL_SCANCODE_KP_MEMSTORE"
.LASF288:
	.string	"SDL_SCANCODE_CURRENCYUNIT"
.LASF419:
	.string	"head"
.LASF347:
	.string	"SDL_SCANCODE_CALCULATOR"
.LASF290:
	.string	"SDL_SCANCODE_KP_LEFTPAREN"
.LASF243:
	.string	"SDL_SCANCODE_AGAIN"
.LASF118:
	.string	"SDL_WINDOW_MOUSE_CAPTURE"
.LASF12:
	.string	"char"
.LASF34:
	.string	"_offset"
.LASF222:
	.string	"SDL_SCANCODE_NONUSBACKSLASH"
.LASF195:
	.string	"SDL_SCANCODE_INSERT"
.LASF245:
	.string	"SDL_SCANCODE_CUT"
.LASF333:
	.string	"SDL_SCANCODE_LGUI"
.LASF169:
	.string	"SDL_SCANCODE_LEFTBRACKET"
.LASF254:
	.string	"SDL_SCANCODE_INTERNATIONAL1"
.LASF255:
	.string	"SDL_SCANCODE_INTERNATIONAL2"
.LASF27:
	.string	"_fileno"
.LASF35:
	.string	"__pad1"
.LASF258:
	.string	"SDL_SCANCODE_INTERNATIONAL5"
.LASF259:
	.string	"SDL_SCANCODE_INTERNATIONAL6"
.LASF260:
	.string	"SDL_SCANCODE_INTERNATIONAL7"
.LASF261:
	.string	"SDL_SCANCODE_INTERNATIONAL8"
.LASF262:
	.string	"SDL_SCANCODE_INTERNATIONAL9"
.LASF223:
	.string	"SDL_SCANCODE_APPLICATION"
.LASF393:
	.string	"nCarruagens"
.LASF340:
	.string	"SDL_SCANCODE_AUDIOPREV"
.LASF396:
	.string	"nservico"
.LASF374:
	.string	"SDL_MESSAGEBOX_COLOR_MAX"
.LASF92:
	.string	"SDL_PACKEDLAYOUT_NONE"
.LASF295:
	.string	"SDL_SCANCODE_KP_BACKSPACE"
.LASF281:
	.string	"SDL_SCANCODE_CLEARAGAIN"
.LASF89:
	.string	"SDL_ARRAYORDER_BGR"
.LASF9:
	.string	"long int"
.LASF31:
	.string	"_vtable_offset"
.LASF25:
	.string	"_markers"
.LASF332:
	.string	"SDL_SCANCODE_LALT"
.LASF411:
	.string	"dimJanela"
.LASF16:
	.string	"_IO_read_base"
.LASF404:
	.string	"_Bool"
.LASF287:
	.string	"SDL_SCANCODE_DECIMALSEPARATOR"
.LASF197:
	.string	"SDL_SCANCODE_PAGEUP"
.LASF380:
	.string	"pident"
.LASF206:
	.string	"SDL_SCANCODE_KP_DIVIDE"
.LASF114:
	.string	"SDL_WINDOW_MOUSE_FOCUS"
.LASF249:
	.string	"SDL_SCANCODE_MUTE"
.LASF364:
	.string	"SDL_SCANCODE_APP1"
.LASF367:
	.string	"SDL_SCANCODE_AUDIOFASTFORWARD"
.LASF44:
	.string	"_next"
.LASF388:
	.string	"lident"
.LASF46:
	.string	"_pos"
.LASF175:
	.string	"SDL_SCANCODE_GRAVE"
.LASF100:
	.string	"SDL_PACKEDLAYOUT_1010102"
.LASF327:
	.string	"SDL_SCANCODE_KP_OCTAL"
.LASF250:
	.string	"SDL_SCANCODE_VOLUMEUP"
.LASF395:
	.string	"PosiNoGraf"
.LASF265:
	.string	"SDL_SCANCODE_LANG3"
.LASF342:
	.string	"SDL_SCANCODE_AUDIOPLAY"
.LASF272:
	.string	"SDL_SCANCODE_ALTERASE"
.LASF216:
	.string	"SDL_SCANCODE_KP_6"
.LASF269:
	.string	"SDL_SCANCODE_LANG7"
.LASF329:
	.string	"SDL_SCANCODE_KP_HEXADECIMAL"
.LASF219:
	.string	"SDL_SCANCODE_KP_9"
.LASF171:
	.string	"SDL_SCANCODE_BACKSLASH"
.LASF186:
	.string	"SDL_SCANCODE_F7"
.LASF221:
	.string	"SDL_SCANCODE_KP_PERIOD"
.LASF368:
	.string	"SDL_NUM_SCANCODES"
.LASF359:
	.string	"SDL_SCANCODE_KBDILLUMTOGGLE"
.LASF303:
	.string	"SDL_SCANCODE_KP_POWER"
.LASF49:
	.string	"_IO_2_1_stderr_"
.LASF204:
	.string	"SDL_SCANCODE_UP"
.LASF297:
	.string	"SDL_SCANCODE_KP_B"
.LASF40:
	.string	"_mode"
.LASF377:
	.string	"__daylight"
.LASF300:
	.string	"SDL_SCANCODE_KP_E"
.LASF247:
	.string	"SDL_SCANCODE_PASTE"
.LASF43:
	.string	"_IO_marker"
.LASF83:
	.string	"SDL_PACKEDORDER_ABGR"
.LASF154:
	.string	"SDL_SCANCODE_3"
.LASF14:
	.string	"_IO_read_ptr"
.LASF156:
	.string	"SDL_SCANCODE_5"
.LASF120:
	.string	"SDL_WINDOW_SKIP_TASKBAR"
.LASF108:
	.string	"SDL_WINDOW_BORDERLESS"
.LASF158:
	.string	"SDL_SCANCODE_7"
.LASF322:
	.string	"SDL_SCANCODE_KP_MEMDIVIDE"
.LASF91:
	.string	"SDL_ARRAYORDER_ABGR"
.LASF174:
	.string	"SDL_SCANCODE_APOSTROPHE"
.LASF62:
	.string	"SDL_PIXELTYPE_INDEX1"
.LASF63:
	.string	"SDL_PIXELTYPE_INDEX4"
.LASF321:
	.string	"SDL_SCANCODE_KP_MEMMULTIPLY"
.LASF64:
	.string	"SDL_PIXELTYPE_INDEX8"
.LASF54:
	.string	"uint8_t"
.LASF400:
	.string	"comboio"
.LASF101:
	.string	"SDL_Rect"
.LASF127:
	.string	"SDL_SCANCODE_B"
.LASF325:
	.string	"SDL_SCANCODE_KP_CLEARENTRY"
.LASF113:
	.string	"SDL_WINDOW_INPUT_FOCUS"
.LASF208:
	.string	"SDL_SCANCODE_KP_MINUS"
.LASF241:
	.string	"SDL_SCANCODE_SELECT"
.LASF432:
	.string	"/media/sf_Prog/ProjetoFinal/tfinal"
.LASF252:
	.string	"SDL_SCANCODE_KP_COMMA"
.LASF199:
	.string	"SDL_SCANCODE_END"
.LASF177:
	.string	"SDL_SCANCODE_PERIOD"
.LASF173:
	.string	"SDL_SCANCODE_SEMICOLON"
.LASF341:
	.string	"SDL_SCANCODE_AUDIOSTOP"
.LASF309:
	.string	"SDL_SCANCODE_KP_VERTICALBAR"
.LASF170:
	.string	"SDL_SCANCODE_RIGHTBRACKET"
.LASF17:
	.string	"_IO_write_base"
.LASF143:
	.string	"SDL_SCANCODE_R"
.LASF53:
	.string	"long long int"
.LASF386:
	.string	"PONTOS"
.LASF48:
	.string	"_IO_2_1_stdout_"
.LASF22:
	.string	"_IO_save_base"
.LASF352:
	.string	"SDL_SCANCODE_AC_FORWARD"
.LASF422:
	.string	"todos"
.LASF198:
	.string	"SDL_SCANCODE_DELETE"
.LASF202:
	.string	"SDL_SCANCODE_LEFT"
.LASF178:
	.string	"SDL_SCANCODE_SLASH"
.LASF307:
	.string	"SDL_SCANCODE_KP_AMPERSAND"
.LASF306:
	.string	"SDL_SCANCODE_KP_GREATER"
.LASF390:
	.string	"FERROVIA"
.LASF76:
	.string	"SDL_PACKEDORDER_NONE"
.LASF112:
	.string	"SDL_WINDOW_INPUT_GRABBED"
.LASF106:
	.string	"SDL_WINDOW_SHOWN"
.LASF69:
	.string	"SDL_PIXELTYPE_ARRAYU16"
.LASF389:
	.string	"pont"
.LASF349:
	.string	"SDL_SCANCODE_AC_SEARCH"
.LASF85:
	.string	"SDL_ARRAYORDER_NONE"
.LASF192:
	.string	"SDL_SCANCODE_PRINTSCREEN"
.LASF283:
	.string	"SDL_SCANCODE_EXSEL"
.LASF286:
	.string	"SDL_SCANCODE_THOUSANDSSEPARATOR"
.LASF122:
	.string	"SDL_WINDOW_TOOLTIP"
.LASF121:
	.string	"SDL_WINDOW_UTILITY"
.LASF23:
	.string	"_IO_backup_base"
.LASF119:
	.string	"SDL_WINDOW_ALWAYS_ON_TOP"
.LASF61:
	.string	"SDL_PIXELTYPE_UNKNOWN"
.LASF165:
	.string	"SDL_SCANCODE_TAB"
.LASF238:
	.string	"SDL_SCANCODE_EXECUTE"
.LASF361:
	.string	"SDL_SCANCODE_KBDILLUMUP"
.LASF36:
	.string	"__pad2"
.LASF37:
	.string	"__pad3"
.LASF38:
	.string	"__pad4"
.LASF39:
	.string	"__pad5"
.LASF417:
	.string	"todas"
.LASF409:
	.string	"SDL_desenhaButoesHUD"
.LASF294:
	.string	"SDL_SCANCODE_KP_TAB"
.LASF384:
	.string	"nEntradas"
.LASF323:
	.string	"SDL_SCANCODE_KP_PLUSMINUS"
.LASF355:
	.string	"SDL_SCANCODE_AC_BOOKMARKS"
.LASF125:
	.string	"SDL_SCANCODE_UNKNOWN"
.LASF415:
	.string	"headtemp"
.LASF95:
	.string	"SDL_PACKEDLAYOUT_1555"
.LASF2:
	.string	"short unsigned int"
.LASF240:
	.string	"SDL_SCANCODE_MENU"
.LASF196:
	.string	"SDL_SCANCODE_HOME"
.LASF193:
	.string	"SDL_SCANCODE_SCROLLLOCK"
.LASF350:
	.string	"SDL_SCANCODE_AC_HOME"
.LASF317:
	.string	"SDL_SCANCODE_KP_MEMRECALL"
.LASF5:
	.string	"size_t"
.LASF212:
	.string	"SDL_SCANCODE_KP_2"
.LASF8:
	.string	"__uint32_t"
.LASF213:
	.string	"SDL_SCANCODE_KP_3"
.LASF111:
	.string	"SDL_WINDOW_MAXIMIZED"
.LASF215:
	.string	"SDL_SCANCODE_KP_5"
.LASF161:
	.string	"SDL_SCANCODE_0"
.LASF152:
	.string	"SDL_SCANCODE_1"
.LASF153:
	.string	"SDL_SCANCODE_2"
.LASF86:
	.string	"SDL_ARRAYORDER_RGB"
.LASF155:
	.string	"SDL_SCANCODE_4"
.LASF1:
	.string	"unsigned char"
.LASF157:
	.string	"SDL_SCANCODE_6"
.LASF274:
	.string	"SDL_SCANCODE_CANCEL"
.LASF159:
	.string	"SDL_SCANCODE_8"
.LASF160:
	.string	"SDL_SCANCODE_9"
.LASF242:
	.string	"SDL_SCANCODE_STOP"
.LASF15:
	.string	"_IO_read_end"
.LASF126:
	.string	"SDL_SCANCODE_A"
.LASF251:
	.string	"SDL_SCANCODE_VOLUMEDOWN"
.LASF128:
	.string	"SDL_SCANCODE_C"
.LASF129:
	.string	"SDL_SCANCODE_D"
.LASF130:
	.string	"SDL_SCANCODE_E"
.LASF131:
	.string	"SDL_SCANCODE_F"
.LASF132:
	.string	"SDL_SCANCODE_G"
.LASF133:
	.string	"SDL_SCANCODE_H"
.LASF134:
	.string	"SDL_SCANCODE_I"
.LASF135:
	.string	"SDL_SCANCODE_J"
.LASF136:
	.string	"SDL_SCANCODE_K"
.LASF137:
	.string	"SDL_SCANCODE_L"
.LASF138:
	.string	"SDL_SCANCODE_M"
.LASF139:
	.string	"SDL_SCANCODE_N"
.LASF140:
	.string	"SDL_SCANCODE_O"
.LASF141:
	.string	"SDL_SCANCODE_P"
.LASF142:
	.string	"SDL_SCANCODE_Q"
.LASF289:
	.string	"SDL_SCANCODE_CURRENCYSUBUNIT"
.LASF144:
	.string	"SDL_SCANCODE_S"
.LASF145:
	.string	"SDL_SCANCODE_T"
.LASF146:
	.string	"SDL_SCANCODE_U"
.LASF147:
	.string	"SDL_SCANCODE_V"
.LASF148:
	.string	"SDL_SCANCODE_W"
.LASF149:
	.string	"SDL_SCANCODE_X"
.LASF150:
	.string	"SDL_SCANCODE_Y"
.LASF151:
	.string	"SDL_SCANCODE_Z"
.LASF65:
	.string	"SDL_PIXELTYPE_PACKED8"
.LASF84:
	.string	"SDL_PACKEDORDER_BGRA"
.LASF81:
	.string	"SDL_PACKEDORDER_XBGR"
.LASF346:
	.string	"SDL_SCANCODE_MAIL"
.LASF90:
	.string	"SDL_ARRAYORDER_BGRA"
.LASF345:
	.string	"SDL_SCANCODE_WWW"
.LASF68:
	.string	"SDL_PIXELTYPE_ARRAYU8"
.LASF66:
	.string	"SDL_PIXELTYPE_PACKED16"
.LASF82:
	.string	"SDL_PACKEDORDER_BGRX"
.LASF97:
	.string	"SDL_PACKEDLAYOUT_565"
.LASF104:
	.string	"SDL_WINDOW_FULLSCREEN"
.LASF93:
	.string	"SDL_PACKEDLAYOUT_332"
.LASF164:
	.string	"SDL_SCANCODE_BACKSPACE"
.LASF343:
	.string	"SDL_SCANCODE_AUDIOMUTE"
.LASF103:
	.string	"_IO_FILE_plus"
.LASF6:
	.string	"__uint8_t"
.LASF391:
	.string	"carr"
.LASF337:
	.string	"SDL_SCANCODE_RGUI"
.LASF401:
	.string	"cart"
.LASF71:
	.string	"SDL_PIXELTYPE_ARRAYF16"
.LASF109:
	.string	"SDL_WINDOW_RESIZABLE"
.LASF79:
	.string	"SDL_PACKEDORDER_ARGB"
.LASF115:
	.string	"SDL_WINDOW_FULLSCREEN_DESKTOP"
.LASF410:
	.string	"for_pontos"
.LASF20:
	.string	"_IO_buf_base"
.LASF162:
	.string	"SDL_SCANCODE_RETURN"
.LASF256:
	.string	"SDL_SCANCODE_INTERNATIONAL3"
.LASF88:
	.string	"SDL_ARRAYORDER_ARGB"
.LASF421:
	.string	"abreJanela"
.LASF166:
	.string	"SDL_SCANCODE_SPACE"
.LASF33:
	.string	"_lock"
.LASF94:
	.string	"SDL_PACKEDLAYOUT_4444"
.LASF408:
	.string	"g_pRenderer"
.LASF394:
	.string	"DimBOLAS"
.LASF0:
	.string	"long unsigned int"
.LASF282:
	.string	"SDL_SCANCODE_CRSEL"
.LASF413:
	.string	"head2"
.LASF305:
	.string	"SDL_SCANCODE_KP_LESS"
.LASF50:
	.string	"stdin"
.LASF285:
	.string	"SDL_SCANCODE_KP_000"
.LASF70:
	.string	"SDL_PIXELTYPE_ARRAYU32"
.LASF56:
	.string	"float"
.LASF324:
	.string	"SDL_SCANCODE_KP_CLEAR"
.LASF403:
	.string	"prox"
.LASF331:
	.string	"SDL_SCANCODE_LSHIFT"
.LASF418:
	.string	"cores"
.LASF319:
	.string	"SDL_SCANCODE_KP_MEMADD"
.LASF201:
	.string	"SDL_SCANCODE_RIGHT"
.LASF45:
	.string	"_sbuf"
.LASF273:
	.string	"SDL_SCANCODE_SYSREQ"
.LASF379:
	.string	"pontoslinha"
.LASF172:
	.string	"SDL_SCANCODE_NONUSHASH"
.LASF336:
	.string	"SDL_SCANCODE_RALT"
.LASF423:
	.string	"end_game"
.LASF200:
	.string	"SDL_SCANCODE_PAGEDOWN"
.LASF180:
	.string	"SDL_SCANCODE_F1"
.LASF181:
	.string	"SDL_SCANCODE_F2"
.LASF182:
	.string	"SDL_SCANCODE_F3"
.LASF183:
	.string	"SDL_SCANCODE_F4"
.LASF184:
	.string	"SDL_SCANCODE_F5"
.LASF185:
	.string	"SDL_SCANCODE_F6"
.LASF376:
	.string	"__tzname"
.LASF187:
	.string	"SDL_SCANCODE_F8"
.LASF188:
	.string	"SDL_SCANCODE_F9"
.LASF67:
	.string	"SDL_PIXELTYPE_PACKED32"
.LASF107:
	.string	"SDL_WINDOW_HIDDEN"
.LASF18:
	.string	"_IO_write_ptr"
.LASF357:
	.string	"SDL_SCANCODE_BRIGHTNESSUP"
.LASF277:
	.string	"SDL_SCANCODE_RETURN2"
.LASF75:
	.string	"SDL_BITMAPORDER_1234"
.LASF232:
	.string	"SDL_SCANCODE_F19"
.LASF369:
	.string	"SDL_MESSAGEBOX_COLOR_BACKGROUND"
.LASF80:
	.string	"SDL_PACKEDORDER_RGBA"
.LASF210:
	.string	"SDL_SCANCODE_KP_ENTER"
.LASF225:
	.string	"SDL_SCANCODE_KP_EQUALS"
.LASF73:
	.string	"SDL_BITMAPORDER_NONE"
.LASF72:
	.string	"SDL_PIXELTYPE_ARRAYF32"
.LASF123:
	.string	"SDL_WINDOW_POPUP_MENU"
.LASF312:
	.string	"SDL_SCANCODE_KP_HASH"
.LASF87:
	.string	"SDL_ARRAYORDER_RGBA"
.LASF420:
	.string	"SDL_unepontos"
.LASF189:
	.string	"SDL_SCANCODE_F10"
.LASF292:
	.string	"SDL_SCANCODE_KP_LEFTBRACE"
.LASF191:
	.string	"SDL_SCANCODE_F12"
.LASF78:
	.string	"SDL_PACKEDORDER_RGBX"
.LASF10:
	.string	"__off_t"
.LASF399:
	.string	"CARRUAGEM"
.LASF229:
	.string	"SDL_SCANCODE_F16"
.LASF4:
	.string	"signed char"
.LASF278:
	.string	"SDL_SCANCODE_SEPARATOR"
.LASF315:
	.string	"SDL_SCANCODE_KP_EXCLAM"
.LASF220:
	.string	"SDL_SCANCODE_KP_0"
.LASF211:
	.string	"SDL_SCANCODE_KP_1"
.LASF344:
	.string	"SDL_SCANCODE_MEDIASELECT"
.LASF279:
	.string	"SDL_SCANCODE_OUT"
.LASF214:
	.string	"SDL_SCANCODE_KP_4"
.LASF74:
	.string	"SDL_BITMAPORDER_4321"
.LASF338:
	.string	"SDL_SCANCODE_MODE"
.LASF217:
	.string	"SDL_SCANCODE_KP_7"
.LASF218:
	.string	"SDL_SCANCODE_KP_8"
.LASF96:
	.string	"SDL_PACKEDLAYOUT_5551"
.LASF392:
	.string	"cident"
.LASF373:
	.string	"SDL_MESSAGEBOX_COLOR_BUTTON_SELECTED"
.LASF296:
	.string	"SDL_SCANCODE_KP_A"
.LASF429:
	.string	"moveCarr"
.LASF298:
	.string	"SDL_SCANCODE_KP_C"
.LASF299:
	.string	"SDL_SCANCODE_KP_D"
.LASF426:
	.string	"corTemp"
.LASF301:
	.string	"SDL_SCANCODE_KP_F"
.LASF57:
	.string	"double"
.LASF205:
	.string	"SDL_SCANCODE_NUMLOCKCLEAR"
.LASF190:
	.string	"SDL_SCANCODE_F11"
.LASF276:
	.string	"SDL_SCANCODE_PRIOR"
.LASF226:
	.string	"SDL_SCANCODE_F13"
.LASF227:
	.string	"SDL_SCANCODE_F14"
.LASF228:
	.string	"SDL_SCANCODE_F15"
.LASF26:
	.string	"_chain"
.LASF230:
	.string	"SDL_SCANCODE_F17"
.LASF231:
	.string	"SDL_SCANCODE_F18"
.LASF246:
	.string	"SDL_SCANCODE_COPY"
.LASF168:
	.string	"SDL_SCANCODE_EQUALS"
.LASF351:
	.string	"SDL_SCANCODE_AC_BACK"
.LASF263:
	.string	"SDL_SCANCODE_LANG1"
.LASF264:
	.string	"SDL_SCANCODE_LANG2"
.LASF385:
	.string	"nSaidas"
.LASF266:
	.string	"SDL_SCANCODE_LANG4"
.LASF267:
	.string	"SDL_SCANCODE_LANG5"
.LASF268:
	.string	"SDL_SCANCODE_LANG6"
.LASF375:
	.string	"SDL_Renderer"
.LASF270:
	.string	"SDL_SCANCODE_LANG8"
.LASF271:
	.string	"SDL_SCANCODE_LANG9"
.LASF207:
	.string	"SDL_SCANCODE_KP_MULTIPLY"
.LASF30:
	.string	"_cur_column"
.LASF203:
	.string	"SDL_SCANCODE_DOWN"
.LASF11:
	.string	"__off64_t"
.LASF41:
	.string	"_unused2"
.LASF304:
	.string	"SDL_SCANCODE_KP_PERCENT"
.LASF291:
	.string	"SDL_SCANCODE_KP_RIGHTPAREN"
	.ident	"GCC: (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0"
	.section	.note.GNU-stack,"",@progbits
