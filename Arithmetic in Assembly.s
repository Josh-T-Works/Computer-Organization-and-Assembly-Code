.data # All Messages Used
MsgX:
    .string "Enter x: "
MsgY:
    .string "\nEnter y: "
nl:
    .string "\n"
plus:
    .string " + "
minus:
    .string " - "
multiply:
    .string " * "
equals:
    .string " = "
.bss
    .lcomm x, 2
    .lcomm y, 2
    .lcomm z, 2
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
    
    # All Calls to Procedures
    call addition
    call subtraction
    call multiplication
    
    # exit with return 0
    movl $1, %eax #sys_exit   
	movl $0, %ebx #return value
	int  $0x80   
	ret
	
	# Procedure to Add x + y
	addition:
	    
	    # New Line
	    movq $4, %rax
        movq $1, %rbx
        movq $nl, %rcx
        movq $0x1, %rdx
        int $0x80
	    
	    # x + y
	    movq x, %rax
	    movq y, %rbx
	    addq %rax, %rbx
	    sub $'0', %rbx
	    movq %rbx, z
	    int $0x80
	    
	    # Output Message vv
	    movq $4, %rax
        movq $1, %rbx
        movq $x, %rcx
        movq $0x1, %rdx
        int $0x80
        
        movq $4, %rax
        movq $1, %rbx
        movq $plus, %rcx
        movq $0x3, %rdx
        int $0x80
        
        movq $4, %rax
        movq $1, %rbx
        movq $y, %rcx
        movq $0x1, %rdx
        int $0x80
        
        movq $4, %rax
        movq $1, %rbx
        movq $equals, %rcx
        movq $0x3, %rdx
        int $0x80
        
        movq $4, %rax
        movq $1, %rbx
        movq $z, %rcx
        movq $0x1, %rdx
        int $0x80
        ret
    
    # Procedure to Subtract x - y
    subtraction:
    
        # New Line
        movq $4, %rax
        movq $1, %rbx
        movq $nl, %rcx
        movq $0x1, %rdx
        int $0x80
	
	    # x - y
	    movq x, %rax
	    movq y, %rbx
	    subq %rbx, %rax
	    add $'0', %rax
	    movq %rax, z
	    int $0x80
	    
	    # Output Message vv
	    movq $4, %rax
        movq $1, %rbx
        movq $x, %rcx
        movq $0x1, %rdx
        int $0x80
        
        movq $4, %rax
        movq $1, %rbx
        movq $minus, %rcx
        movq $0x3, %rdx
        int $0x80
        
        movq $4, %rax
        movq $1, %rbx
        movq $y, %rcx
        movq $0x1, %rdx
        int $0x80
        
        movq $4, %rax
        movq $1, %rbx
        movq $equals, %rcx
        movq $0x3, %rdx
        int $0x80
        
        movq $4, %rax
        movq $1, %rbx
        movq $z, %rcx
        movq $0x1, %rdx
        int $0x80
        ret
     
    # Procedure to Multiple x * y    
    multiplication:
    
        # New Line
        movq $4, %rax
        movq $1, %rbx
        movq $nl, %rcx
        movq $0x1, %rdx
        int $0x80
	
	    # x * y
	    movq x, %rax
	    movq y, %rbx
	    sub $'0', %rax
	    sub $'0', %rbx
	    imul %rax, %rbx
	    add $'0', %rbx
	    movq %rbx, z
	    int $0x80
	    
	    # Output Message vv
	    movq $4, %rax
        movq $1, %rbx
        movq $x, %rcx
        movq $0x1, %rdx
        int $0x80
        
        movq $4, %rax
        movq $1, %rbx
        movq $multiply, %rcx
        movq $0x3, %rdx
        int $0x80
        
        movq $4, %rax
        movq $1, %rbx
        movq $y, %rcx
        movq $0x1, %rdx
        int $0x80
        
        movq $4, %rax
        movq $1, %rbx
        movq $equals, %rcx
        movq $0x3, %rdx
        int $0x80
        
        movq $4, %rax
        movq $1, %rbx
        movq $z, %rcx
        movq $0x1, %rdx
        int $0x80
        ret
      