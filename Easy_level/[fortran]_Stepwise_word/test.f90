program test

    implicit none

    character(528) :: args, line, word
    integer :: i, mx, n1, n2, j
    logical :: fl
    
    call get_command_argument(1,args)
    
    open(1,file=args,form="formatted",action="read")
    
    do
       
       read(1,'(a)',end=10)line
       fl = .true.
       n1 = 1
       n2 = scan(line,' ')      
       do while(n2<=len_trim(line)+1)               
          if(fl)then
	    mx = n2 - n1
	    word=line(n1:n2-1)
	    fl = .false.
	  else if(mx < n2 - n1)then
	       mx = n2 - n1
	       word=line(n1:n2-1)    
          end if  
          n1 = n2 + 1
          n2 = n2 + scan(line(n2+1:),' ')            
       end do
       do i=1,mx
          do j=1,i-1
             write(*,'(a)',advance='no')'*'    
          end do
          write(*,'(a)',advance='no')word(i:i)
          write(*,'(a)',advance='no')' '
       end do
       write(*,*) 
       
    end do
    
    10 continue
    

end program test