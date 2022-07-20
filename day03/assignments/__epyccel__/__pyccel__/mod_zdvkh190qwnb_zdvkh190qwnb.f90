module mod_zdvkh190qwnb_zdvkh190qwnb


  use, intrinsic :: ISO_C_Binding, only : i64 => C_INT64_T , f64 => &
        C_DOUBLE
  implicit none

  contains

  !........................................
  function solve_2d_nonlinearconv_pyccel(u, un, v, vn, nt, dt, dx, dy, c &
        ) result(Out_0001)

    implicit none

    integer(i64) :: Out_0001
    real(f64), intent(inout) :: u(0:,0:)
    real(f64), intent(inout) :: un(0:,0:)
    real(f64), intent(inout) :: v(0:,0:)
    real(f64), intent(inout) :: vn(0:,0:)
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

    !##Assign initial conditions
    !#set hat function I.C. : u(.5<=x<=1 && .5<=y<=1 ) is 2
    u(Int(0.5_f64 / dx, i64):Int(1_i64 / dx + 1_i64, i64) - 1_i64, Int( &
          0.5_f64 / dy, i64):Int(1_i64 / dy + 1_i64, i64) - 1_i64) = &
          2_i64
    !#set hat function I.C. : v(.5<=x<=1 && .5<=y<=1 ) is 2
    v(Int(0.5_f64 / dx, i64):Int(1_i64 / dx + 1_i64, i64) - 1_i64, Int( &
          0.5_f64 / dy, i64):Int(1_i64 / dy + 1_i64, i64) - 1_i64) = &
          2_i64
    row = size(u, 2_i64, i64)
    col = size(u, 1_i64, i64)
    !fill the update of u and v
    !$omp parallel num_threads(32)
    !$omp do
    do n = 0_i64, nt + 1_i64 - 1_i64, 1_i64
      !$omp do collapse(2)
      do i = 0_i64, row - 1_i64, 1_i64
        do j = 0_i64, col - 1_i64, 1_i64
          un(j, i) = u(j, i)
          vn(j, i) = v(j, i)
        end do
      end do
      !$omp end do
      u(1_i64:, 1_i64:) = un(1_i64:, 1_i64:) - un(1_i64:, 1_i64:) * dt / &
            dx * (un(1_i64:, 1_i64:) - un(1_i64:, 0_i64:size(un, 2_i64, &
            i64) - 1_i64 - 1_i64)) - vn(1_i64:, 1_i64:) * dt / dy * (un &
            (1_i64:, 1_i64:) - un(0_i64:size(un, 1_i64, i64) - 1_i64 - &
            1_i64, 1_i64:))
      v(1_i64:, 1_i64:) = vn(1_i64:, 1_i64:) - un(1_i64:, 1_i64:) * dt / &
            dx * (vn(1_i64:, 1_i64:) - vn(1_i64:, 0_i64:size(vn, 2_i64, &
            i64) - 1_i64 - 1_i64)) - vn(1_i64:, 1_i64:) * dt / dy * (vn &
            (1_i64:, 1_i64:) - vn(0_i64:size(vn, 1_i64, i64) - 1_i64 - &
            1_i64, 1_i64:))
      u(:, 0_i64) = 1_i64
      u(:, size(u, 2_i64, i64) - 1_i64) = 1_i64
      u(0_i64, :) = 1_i64
      u(size(u, 1_i64, i64) - 1_i64, :) = 1_i64
      v(:, 0_i64) = 1_i64
      v(:, size(v, 2_i64, i64) - 1_i64) = 1_i64
      v(0_i64, :) = 1_i64
      v(size(v, 1_i64, i64) - 1_i64, :) = 1_i64
    end do
    !$omp end do
    !$omp end parallel
    Out_0001 = 0_i64
    return

  end function solve_2d_nonlinearconv_pyccel
  !........................................

end module mod_zdvkh190qwnb_zdvkh190qwnb
