program test

    implicit none

    character(128) :: args, line
    integer :: i, n1, n2, op, a, b
    
    call get_command_argument(1,args)
    
    open(1,file=args,form="formatted",action="read")
    
    do
       
       read(1,'(a)',end=10)line
       n1=scan(line,' ')
       if(scan(line,'+') > scan(line,'-')) then
         n2 = scan(line,'+')
         op = 1
       else
         n2 = scan(line,'-')
         op = -1
       end if
!        write(*,*) n1, n2, line(1:n1), line(1:n2-n1-1), " ",line(n2-n1:n1)
       read(line(1:n2-n1-1),'(i10)') a
       read(line(n2-n1:n1),'(i10)') b
       write(*,*) a + op*b       
       
    end do
    
    10 continue
    

end program test