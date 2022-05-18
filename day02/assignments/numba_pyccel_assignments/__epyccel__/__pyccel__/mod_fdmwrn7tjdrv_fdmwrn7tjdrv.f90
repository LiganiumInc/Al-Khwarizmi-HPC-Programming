module mod_fdmwrn7tjdrv_fdmwrn7tjdrv


  use, intrinsic :: ISO_C_Binding, only : i64 => C_INT64_T , f64 => &
        C_DOUBLE
  implicit none

  contains

  !........................................
  function solve_2d_linearconv_pyccel(u, un, nt, dt, dx, dy, c) result( &
        Out_0001)

    implicit none

    integer(i64) :: Out_0001
    real(f64), intent(inout) :: u(0:,0:)
    real(f64), intent(inout) :: un(0:,0:)
    integer(i64), value :: nt
    real(f64), value :: dt
    real(f64), value :: dx
    real(f64), value :: dy
    integer(i64), value :: c
    integer(i64) :: row
    integer(i64) :: col
    integer(i64) :: n
    integer(i64) :: i
    integer(i64) :: j

    row = size(u, 2_i64, i64)
    col = size(u, 1_i64, i64)
    !fill the update of u and v
    do n = 0_i64, nt + 1_i64 - 1_i64, 1_i64
      do i = 0_i64, row - 1_i64, 1_i64
        do j = 0_i64, col - 1_i64, 1_i64
          un(j, i) = u(j, i)
        end do
      end do
      do i = 1_i64, row - 1_i64, 1_i64
        do j = 1_i64, col - 1_i64, 1_i64
          u(j, i) = un(j, i) - c * dt / dx * (un(j, i) - un(j, i - 1_i64 &
                )) - c * dt / dy * (un(j, i) - un(j - 1_i64, i))
          u(:, 0_i64) = 1_i64
          u(:, size(u, 2_i64, i64) - 1_i64) = 1_i64
          u(0_i64, :) = 1_i64
          u(size(u, 1_i64, i64) - 1_i64, :) = 1_i64
        end do
      end do
    end do
    Out_0001 = 0_i64
    return

  end function solve_2d_linearconv_pyccel
  !........................................

end module mod_fdmwrn7tjdrv_fdmwrn7tjdrv
