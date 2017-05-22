program test

    implicit none

    character(528) :: args, line, word
    integer :: i, j, k, n
    logical :: fl
    
    call get_command_argument(1,args)
    
    open(1,file=args,form="formatted",action="read")
    
    do
       
       read(1,'(a)',end=10)line
       do i=1,len_trim(line)
          
          fl = .true.
          
          do j=1,i
             word(j:j)=line(j:j)
          end do
          
          do j=1,len_trim(line)/i
	     do k=1,i
	        if(word(k:k)/=line((j-1)*i+k:(j-1)*i+k))then
	           fl = .false.
	        end if
	     end do
          end do
          
          if(fl .eqv. .true.)then
             do k=1,mod(len_trim(line),i)
	           if(word(k:k)/=line((j-1)*i+k:(j-1)*i+k))then
	              fl = .false.
	           end if
	     end do
	  end if
          
          if(fl.eqv..true.)then
            write(*,'(i0)')i
            goto 200
!           else if(j==i)then
!             write(*,'(i0)')len_trim(line)
          end if
          
       end do
       200 continue
       
       
    end do
    
    10 continue
    

end program test