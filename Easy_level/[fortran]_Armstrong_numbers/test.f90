program test

    implicit none

    character(128) :: args, line
    integer :: i, power, num, suma, digit
    
    call get_command_argument(1,args)
    
    open(1,file=args,form="formatted",action="read")
    
    do
       
       read(1,'(a)',end=10)line
       read(line,'(i5)')num 
       power = len_trim(line)
       suma = 0
       do i=1,power
          read(line(i:i),'(i5)')digit
          suma = suma + digit**power
       end do
       if(suma == num)then
         write(*,'(a)')'True'
       else
         write(*,'(a)')'False'
       end if
    end do
    
    10 continue
    

end program test