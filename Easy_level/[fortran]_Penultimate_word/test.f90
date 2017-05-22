program test

!     use, intrinsic :: iso_fortran_env, only: iostat_end
    implicit none

    character(128) :: args, penul, line
    integer :: n,n1,n2
    
    call get_command_argument(1,args)
    
    open(1,file=args,form="formatted",action="read")
    
    do
    
       read(1,'(a)',end=10)line
       n1 = 1
       n2 = scan(line," ")

       do while(n2<len_trim(line))
          penul = line(n1:n2)
          n1=n2 +1
          n2=n2+scan(line(n1:128)," ") 
       end do                      
       
       write(*,'(A)')penul
    
    end do
    
    10 continue
    

end program test