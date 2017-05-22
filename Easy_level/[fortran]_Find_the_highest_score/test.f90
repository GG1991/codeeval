program test

    implicit none

    character(1028) :: args, line
    integer :: i, j, n1, n2, n3, mx, table(10,20), np, nd
    logical :: exit_, first_time
    call get_command_argument(1,args)
    
    open(1,file=args,form="formatted",action="read")
    
    do       
       read(1,'(a)',end=10)line
       n1 = 1
       n2 = 1
       n3 = 1
       first_time=.true.
       exit_=.false.
       np = 1
       
       do
         if(first_time)then
           n1 = n3
           first_time = .false.
         else
           n1 = n3 + 1
         end if
         if(scan(line(n3:),"|") /= 0)then
          n3 = n3 + scan(line(n3:),"|") - 1 
         else
          n3 = len_trim(line)+2
          exit_=.true.
         end if
         
         nd = 1
         do while (n2<n3-1)
            n2 = n1 + scan(line(n1:)," ") - 1
            read(line(n1:n2),'(i10)') table(np,nd)
            nd = nd + 1
            n1 = n2 + 1
         end do
         
         n3 = n3 + 1
         if(exit_)then
            goto 100
         end if
         
         np = np + 1
       
       end do
       
       100 continue
       
       nd = nd - 1
       do j=1,nd
         mx=table(1,j)
         do i=2,np
            if(mx<table(i,j))then
              mx=table(i,j)
            end if
         end do
         write(*,'(i0)',advance='no')mx
         write(*,'(a)',advance='no') ' '
       end do
       write(*,*)
    end do
    
    10 continue
    

end program test