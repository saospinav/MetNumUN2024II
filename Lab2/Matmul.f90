program matrix_multiplication
  implicit none
  integer, parameter :: m = 600
  integer, parameter :: n = 100
  integer, parameter :: p = 600
  real(8) :: randa(m,n), randb(n,p), mult(m,p)
  real(8) :: start_time, end_time, time_sum
  integer :: i, j, k

  call random_matrix(randa, m, n)
  call random_matrix(randb, n, p)

  time_sum = 0.0
  do i = 1, 10
    call cpu_time(start_time)
    call matmul(randa, randb, mult, m, n, p)
    call cpu_time(end_time)
    time_sum = time_sum + (end_time - start_time)
  end do

  print *, time_sum / 10.0
contains

  subroutine random_matrix(matrix, rows, cols)
    real(8), intent(out) :: matrix(:,:)
    integer, intent(in) :: rows, cols
    integer :: i, j
    do i = 1, rows
      do j = 1, cols
        call random_number(matrix(i, j))
      end do
    end do
  end subroutine random_matrix

  subroutine matmul(A, B, C, m, n, p)
    real(8), intent(in) :: A(m, n), B(n, p)
    real(8), intent(out) :: C(m, p)
    integer, intent(in) :: m, n, p
    integer :: i, j, k
    C = 0.0
    do i = 1, m
      do j = 1, p
        do k = 1, n
          C(i, j) = C(i, j) + A(i, k) * B(k, j)
        end do
      end do
    end do
  end subroutine matmul

end program matrix_multiplication
