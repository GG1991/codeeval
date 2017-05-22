program test
   
   use, intrinsic :: iso_fortran_env, only: iostat_end
   implicit none
   
   integer :: nargs, i, io_status, A, B, n1, n2, counter
   integer :: board(256,256)
   logical :: flag
   character(len=64) :: args
   character(len=64) :: line
   character(len=16), dimension(3) :: str
   
   call get_command_argument(1,args)
   
   open(1,file=args,form="formatted",action="read")
   
   board = 0
   
   do
      
      n1=1
      read(1,'(a)',end=10) line
      n2 = scan(line," ") 
      
      if ( line(n1:n2) == 'SetCol' ) then
         n1 = n2
         n2 = n2 + scan(line(n1+1:len(line)),' ')
         read(line(n1:n2),'(I5)') A
         n1 = n2
         n2 = n2 + scan(line(n1+1:len(line)),' ')
         read(line(n1:n2),'(I5)') B
         do i = 1, 256
            board(i,A+1) = B 
         end do
      else if ( line(n1:n2) == 'SetRow' ) then
         n1 = n2
         n2 = n2 + scan(line(n1+1:len(line)),' ')
         read(line(n1:n2),'(I5)') A
         n1 = n2
         n2 = n2 + scan(line(n1+1:len(line)),' ')
         read(line(n1:n2),'(I5)') B
         do i = 1, 256
            board(A+1,i) = B 
         end do
      else if ( line(n1:n2) == 'QueryCol' ) then
         counter = 0
         n1 = n2
         n2 = n2 + scan(line(n1+1:len(line)),' ')
         read(line(n1:n2),'(I5)') A
         
         do i = 1, 256
            counter = counter + board(i,A+1)  
         end do
         write(*,'(I0)') counter
      else if ( line(n1:n2) == 'QueryRow' ) then
         counter = 0
         n1 = n2
         n2 = n2 + scan(line(n1+1:len(line)),' ')
         read(line(n1:n2),'(I5)') A
         
         do i = 1, 256
            counter = counter + board(A+1,i)  
         end do
         write(*,'(I0)') counter
      end if
      
   end do   
   
   10 continue   
  
   close(1)

end program test