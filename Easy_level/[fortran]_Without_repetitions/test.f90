program test

    implicit none

    character(528) :: args, line
    integer :: i
    
    call get_command_argument(1,args)
    
    open(1,file=args,form="formatted",action="read")
    
    do       
       read(1,'(a)',end=10)line
       write(*,'(a)',advance='no')line(1:1)
       do i=2,len_trim(line)
          if(line(i:i)/=line(i-1:i-1))then
	    write(*,'(a)',advance='no')line(i:i)
          end if           
       end do
       write(*,*)
         
    end do
    
    10 continue
    

end program test