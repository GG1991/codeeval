program test

    implicit none

    character(128) :: args, line
    integer :: i, nl, mn, p, j, nc
    
    call get_command_argument(1,args)
    
    open(1,file=args,form="formatted",action="read")
    
    do
       
       read(1,'(a)',end=10)line
       i = 1
       do while(line(i:i)/=',')
          i = i + 1
       end do
       nc = i
       nl = (len_trim(line)+1) / i

       do i=1,nl
          j=(i-1)*nc+1
          do while(line(j:j)=='X')
             j = j + 1
          end do
          p=j
          do while(line(j:j)/='Y')
             j = j + 1
          end do
          if(i==1)then
	    mn = j-p
          else
            if(j-p<mn)then
              mn = j-p
            end if
          end if
       end do
       write(*,*) mn
       
    end do
    
    10 continue
    

end program test