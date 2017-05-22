program test

    implicit none

    character(128) :: args, line
    integer :: i
    logical :: fl
    
    call get_command_argument(1,args)
    
    open(1,file=args,form="formatted",action="read")

    do
       
       read(1,'(a)',end=10)line
       fl = .false.
       do i=1,len_trim(line)
          if(line(i:i)>='A' .and. line(i:i)<='Z')then
            write(*,'(A)',advance='no')achar(ichar(line(i:i))-ichar('A')+ichar('A'))
            fl = .true.
          else if(line(i:i)>='a' .and. line(i:i)<='z')then
            write(*,'(A)',advance='no')line(i:i)
            fl = .true.
          else if(fl)then
            write(*,'(A)',advance='no')' '
            fl=.false.
          end if
       end do     
       write(*,*)
         
    end do
    
    10 continue
    

end program test