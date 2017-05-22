program test

    implicit none

    character(128) :: args, line
    integer :: num, n1, n2, i, ps
    integer :: ls(9)
    
    call get_command_argument(1,args)
    
    open(1,file=args,form="formatted",action="read")
    
    do
       
       read(1,'(a)',end=10)line
       ls = 0
       n1 = 1       
       n2 = scan(line(n1:128)," ")
       
       do while(n2<=len_trim(line)+1)
          read(line(n1:n2),'(I5)') num
          if(ls(num)<2) then
            ls(num)=ls(num)+1
          end if
          n1=n2+1
          n2=n2+scan(line(n1:128)," ") 
       end do 
       
       i = 1
       do while( (ls(i) /= 1) .and. (i /= 10) )
          i = i + 1
       end do
              
       if(i==10)then
         write(*,'(I0)') 0
       else
         ps = 1
         n1 = 1       
         n2 = scan(line(n1:128)," ")
       
         do while(n2<=len_trim(line)+1)
            read(line(n1:n2),'(I5)') num
            if(i == num) then
              write(*,'(I0)') ps
              goto 5
            end if
            ps = ps + 1
            n1 = n2 + 1
            n2=n2+scan(line(n1:128)," ")
         end do           
        
       end if
       
       5 continue
         
    end do
    
    10 continue
    

end program test