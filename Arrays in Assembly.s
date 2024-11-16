.data

IntArray:
.byte 1, 1, 2, 3

result:
    .string "Result of Array Addition: "
.bss
    .lcomm x, 2
.text
.global main
main:
    leaq IntArray, %rdi # load array address
    movq $0, %rsi # initialize counter
    movq $3, %r8 # initialize stop variable
    call addition # calls addition function 
    addq $0x30, x # adjust hexadecimal result after function
    
    movq $4, %rax # cout message
    movq $1, %rbx
    movq $result, %rcx
    movq $0x1A, %rdx
    int $0x80
    
    movq $4, %rax # cout x
    movq $1, %rbx
    movq $x, %rcx
    movq $0x1, %rdx
    int $0x80
    
    movl $1, %eax # exit with return 0   
	movl $0, %ebx 
	int  $0x80   
	ret
    
    addition:
        movl (%rdi, %rsi, 1), %eax # get value in array location
        addl %eax, x # add array value to x
        incq %rsi # update counter
        cmpq %r8, %rsi # check counter
        jle addition # continue if %rsi <= 3
        ret
	