.data
MsgX:
    .string "Enter x: "
MsgY:
    .string "\nEnter y: "
MsgIf:
    .string " > "
MsgElse:
    .string " <= "
nl:
    .string "\n"
.bss
    .lcomm x, 5
    .lcomm y, 5
.text
.global main
main:
    # Enter x 
    movq $4, %rax   #sys_write
    movq $1, %rbx   #cout
    movq $MsgX, %rcx    #x msg
    movq $0x8, %rdx #size
    int $0x80   #kernel interrupt
    
    # Read x
    movq $3, %rax   #sys_read
    movq $0, %rbx   #cin
    movq $x, %rcx   #x
    movq $0x1, %rdx
    int $0x80
    
    # Enter y 
    movq $4, %rax   #sys_write
    movq $1, %rbx   #cout
    movq $MsgY, %rcx    #y msg
    movq $0x9, %rdx #size
    int $0x80   #kernel interrupt
    
    # Read y
    movq $3, %rax   #sys_read
    movq $0, %rbx   #cin
    movq $y, %rcx   #y
    movq $0x1, %rdx
    int $0x80
    
    # compare x and y
    mov x, %rdi
    mov y, %rsi
    cmpq %rsi, %rdi
    jle .L1 # jump if x <= y
    
    # print "\n"
    movq $4, %rax
    movq $1, %rbx
    movq $nl, %rcx
    movq $0x1, %rdx
    int $0x80
    
    # print "x"
    movq $4, %rax
    movq $1, %rbx
    movq $x, %rcx
    movq $0x1, %rdx
    int $0x80
    
    # print ">"
    movq $4, %rax
    movq $1, %rbx
    movq $MsgIf, %rcx
    movq $0x3, %rdx
    int $0x80
    
    # print "y"
    movq $4, %rax
    movq $1, %rbx
    movq $y, %rcx
    movq $0x1, %rdx
    int $0x80
    
    # exit with return 0
    movl $1, %eax #sys_exit   
	movl $0, %ebx #return value
	int  $0x80   
	ret
    
.L1: # jump statement

    # print "\n"
    movq $4, %rax
    movq $1, %rbx
    movq $nl, %rcx
    movq $0x1, %rdx
    int $0x80
    
    # print "x"
    movq $4, %rax
    movq $1, %rbx
    movq $x, %rcx
    movq $0x1, %rdx
    int $0x80
    
    # print "<="
    movq $4, %rax
    movq $1, %rbx
    movq $MsgElse, %rcx
    movq $0x4, %rdx
    int $0x80
    
    # print "y"
    movq $4, %rax
    movq $1, %rbx
    movq $y, %rcx
    movq $0x1, %rdx
    int $0x80
    
    # exit with return 0
    movl $1, %eax    
	movl $0, %ebx    
	int  $0x80   
	ret
      