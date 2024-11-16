.data
MsgM:
    .string "Enter m:"
MsgX:
    .string "\nEnter x:"
MsgB:
    .string "\nEnter b:"
MsgRes:
    .string "\nThe value of mx + b is: "
.bss # Uninitialized Variables
    .lcomm m, 5
    .lcomm x, 5
    .lcomm b, 5
    .lcomm r, 5
    
.text
.global main
main:            
# Request m
    movq $4, %rax # sys_write
    movq $1, %rbx # cout
    movq $MsgM, %rcx # message
    movq $0x8, %rdx # size
    int $0x80 # interrupt kernel
# read & store m
    movq $3, %rax # sys_read
    movq $0, %rbx # cin
    movq $m, %rcx # variable
    movq $0x1, %rdx
    int $0x80

# Request x
    movq $4, %rax
    movq $1, %rbx
    movq $MsgX, %rcx
    movq $0x9, %rdx
    int $0x80
# read & store x
    movq $3, %rax
    movq $0, %rbx
    movq $x, %rcx 
    movq $0x1, %rdx
    int $0x80
    
# Request b
    movq $4, %rax
    movq $1, %rbx
    movq $MsgB, %rcx
    movq $0x9, %rdx
    int $0x80
# read & store b
    movq $3, %rax
    movq $0, %rbx
    movq $b, %rcx 
    movq $0x1, %rdx
    int $0x80
    
# calculation
    movq m, %rsi
    movq x, %rdi
    movq b, %rdx
    
    sub $'0', %rsi # rewrite ascii as decimal numbers to calculate
    sub $'0', %rdi 
    sub $'0', %rdx

    imulq %rsi, %rdi # multiply m * x
    addq %rdx, %rdi # add m*x + b
    add $'0', %rdi # add back ascii value to result
    movq %rdi, r

# Output message
    movq $4, %rax
    movq $1, %rbx
    movq $MsgRes, %rcx
    movq $0x19, %rdx
    int $0x80
    
# Return mx + b
    movq $4, %rax
    movq $1, %rbx
    movq $r, %rcx
    movq $0x1, %rdx
    int $0x80

# Exit with return 0    
	movl $1, %eax    
	movl $0, %ebx    
	int  $0x80   
	ret
