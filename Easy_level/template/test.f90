program test

    implicit none

    character(128) :: args, line
    integer :: i
    
    call get_command_argument(1,args)
    
    open(1,file=args,form="formatted",action="read")
    
    do
       
       read(1,'(a)',end=10)line
         
    end do
    
    10 continue
    

end program test