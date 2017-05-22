program test

    implicit none
    
    interface 
       function is_numeric (string)
          CHARACTER(len=*), INTENT(IN) :: string
       end function is_numeric
    end interface
    logical :: is_numeric
    
    character(256) :: args, line
    character(32)  :: words(100),numbers(100)                                  
    integer :: i, nw, nn, n1, n2
    
    
    call get_command_argument(1,args)
    
    open(1,file=args,form="formatted",action="read")
    
    do
              
       read(1,'(a)',end=10)line
       
       nw = 0
       nn = 0
       n1 = 1
       n2 = scan(trim(line),",")
       
       do while (n2<=len_trim(line)+1 .and. n1<=n2)
          if (is_numeric(line(n1:n2-1))) then 
             nn = nn + 1
             numbers(nn) = line(n1:n2-1)
          else
             nw = nw + 1
             words(nw) = line(n1:n2-1)
          end if
          n1 = n2 + 1
          n2 = n2 + scan(trim(line(n1:)),",") 
       end do
       
       n2 = len_trim(line)
       if (is_numeric(line(n1:n2))) then 
          nn = nn + 1
          numbers(nn) = line(n1:n2)          
       else
          nw = nw + 1
          words(nw) = line(n1:n2)
       end if
       
       do i=1,nw 
          write(*,'(a)',advance='no') trim(words(i)) 
          if (i/=nw) then
             write(*,'(a)',advance='no') ','
          else
             if(nn/=0)then
              write(*,'(a)',advance='no') '|'
             else
              write(*,*) 
             end if
          end if
       end do
       do i=1,nn 
          write(*,'(a)',advance='no') trim(numbers(i)) 
          if (i/=nn) then
             write(*,'(a)',advance='no') ','
          else
             write(*,*) 
          end if
       end do
        
    end do
    
    10 continue
    
end program test


function is_numeric(string)
  ! Returns .true. if string is a word and .false. if it is a number
  implicit none
  character(len=*), intent(in) :: string
  logical :: is_numeric
  real :: x
  integer :: e
  read(string,*,iostat=e) x
  is_numeric = e == 0
end function is_numeric  