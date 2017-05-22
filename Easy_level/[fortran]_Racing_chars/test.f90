program test

    implicit none

    character(128) :: args, line
    integer :: i, N=12, pos_old, pos_new
    logical :: fs = .true., skip_under
    
    call get_command_argument(1,args)
    
    open(1,file=args,form="formatted",action="read")
    
    do
       read(1,'(a)',end=10)line
    
       if( fs )then  
       
          skip_under=.false.
          
          do i=1,12          
            if(line(i:i)=='C')then
              skip_under=.true.
            end if          
          end do

          if(skip_under)then
   
            do i=1,12          
              if(line(i:i)=='C')then
                write(*,'(a)',advance='no')'|'
                pos_old = i
              else
                write(*,'(a)',advance='no')line(i:i)
              end if          
            end do
          
          else
          
             do i=1,12          
              if(line(i:i)=='_')then
                write(*,'(a)',advance='no')'|'
                pos_old = i
              else
                write(*,'(a)',advance='no')line(i:i)
              end if          
            end do
          
          end if
          
          fs = .false.
!           write(*,*) pos_old
       
       else
       
          skip_under=.false.
          
          do i=1,12          
              if(line(i:i)=='C')then
                if(pos_old-1 <= i .or. pos_old-1 >= i )then
                  pos_new=i
                  skip_under=.true.
                end if     
              end if
          end do   
          if(.not.skip_under)then
             do i=1,12          
                 if(line(i:i)=='_')then
                   if(pos_old-1 <= i .or. pos_old-1 >= i )then
                     pos_new=i
                     skip_under=.true.
                   end if     
                 end if
             end do 
          end if
          
          do i=1,12          
            if(i==pos_new)then
              if(pos_new==pos_old+1)  write(*,'(a)',advance='no')'\'
              if(pos_new==pos_old+0)  write(*,'(a)',advance='no')'|'
              if(pos_new==pos_old-1)  write(*,'(a)',advance='no')'/'
              pos_old = pos_new
            else
              write(*,'(a)',advance='no')line(i:i)
            end if       
          end do         
          
       
       end if
       write(*,*) 
       
         
    end do
    
    10 continue
    

end program test