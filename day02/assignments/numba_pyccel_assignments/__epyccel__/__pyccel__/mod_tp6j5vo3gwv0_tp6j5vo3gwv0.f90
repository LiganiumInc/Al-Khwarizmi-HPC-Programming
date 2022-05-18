module mod_tp6j5vo3gwv0_tp6j5vo3gwv0


  use, intrinsic :: ISO_C_Binding, only : f64 => C_DOUBLE , i64 => &
        C_INT64_T
  implicit none

  contains

  !........................................
  function solve_2d_burger_pyccel(u, un, v, vn, nt, dt, dx, dy, nu) &
        result(Out_0001)

    implicit none

    integer(i64) :: Out_0001
    real(f64), intent(inout) :: u(0:,0:)
    real(f64), intent(in) :: un(0:,0:)
    real(f64), intent(inout) :: v(0:,0:)
    real(f64), intent(in) :: vn(0:,0:)
    integer(i64), value :: nt
    real(f64), value :: dt
    real(f64), value :: dx
    real(f64), value :: dy
    real(f64), value :: nu
    integer(i64) :: row
    integer(i64) :: col
    integer(i64) :: n

    !##Assign initial conditions
    !#set hat function I.C. : u(.5<=x<=1 && .5<=y<=1 ) is 2
    u(Int(0.5_f64 / dx, i64):Int(1_i64 / dx + 1_i64, i64) - 1_i64, Int( &
          0.5_f64 / dy, i64):Int(1_i64 / dy + 1_i64, i64) - 1_i64) = &
          2_i64
    !#set hat function I.C. : u(.5<=x<=1 && .5<=y<=1 ) is 2
    v(Int(0.5_f64 / dx, i64):Int(1_i64 / dx + 1_i64, i64) - 1_i64, Int( &
          0.5_f64 / dy, i64):Int(1_i64 / dy + 1_i64, i64) - 1_i64) = &
          2_i64
    row = size(u, 2_i64, i64)
    col = size(u, 1_i64, i64)
    !fill the update of u and v
    do n = 0_i64, nt + 1_i64 - 1_i64, 1_i64
      u(1_i64:size(u, 1_i64, i64) - 1_i64 - 1_i64, 1_i64:size(u, 2_i64, &
            i64) - 1_i64 - 1_i64) = un(1_i64:size(un, 1_i64, i64) - &
            1_i64 - 1_i64, 1_i64:size(un, 2_i64, i64) - 1_i64 - 1_i64) &
            - dt / dx * un(1_i64:size(un, 1_i64, i64) - 1_i64 - 1_i64, &
            1_i64:size(un, 2_i64, i64) - 1_i64 - 1_i64) * (un(1_i64: &
            size(un, 1_i64, i64) - 1_i64 - 1_i64, 1_i64:size(un, 2_i64, &
            i64) - 1_i64 - 1_i64) - un(1_i64:size(un, 1_i64, i64) - &
            1_i64 - 1_i64, 0_i64:size(un, 2_i64, i64) - 2_i64 - 1_i64 &
            )) - dt / dy * vn(1_i64:size(vn, 1_i64, i64) - 1_i64 - &
            1_i64, 1_i64:size(vn, 2_i64, i64) - 1_i64 - 1_i64) * (un( &
            1_i64:size(un, 1_i64, i64) - 1_i64 - 1_i64, 1_i64:size(un, &
            2_i64, i64) - 1_i64 - 1_i64) - un(0_i64:size(un, 1_i64, i64 &
            ) - 2_i64 - 1_i64, 1_i64:size(un, 2_i64, i64) - 1_i64 - &
            1_i64)) + nu * dt / dx ** 2_i64 * (un(1_i64:size(un, 1_i64, &
            i64) - 1_i64 - 1_i64, 2_i64:) - 2_i64 * un(1_i64:size(un, &
            1_i64, i64) - 1_i64 - 1_i64, 1_i64:size(un, 2_i64, i64) - &
            1_i64 - 1_i64) + un(1_i64:size(un, 1_i64, i64) - 1_i64 - &
            1_i64, 0_i64:size(un, 2_i64, i64) - 2_i64 - 1_i64)) + nu * &
            dt / dy ** 2_i64 * (un(2_i64:, 1_i64:size(un, 2_i64, i64) - &
            1_i64 - 1_i64) - 2_i64 * un(1_i64:size(un, 1_i64, i64) - &
            1_i64 - 1_i64, 1_i64:size(un, 2_i64, i64) - 1_i64 - 1_i64) &
            + un(0_i64:size(un, 1_i64, i64) - 2_i64 - 1_i64, 1_i64:size &
            (un, 2_i64, i64) - 1_i64 - 1_i64))
      v(1_i64:size(v, 1_i64, i64) - 1_i64 - 1_i64, 1_i64:size(v, 2_i64, &
            i64) - 1_i64 - 1_i64) = vn(1_i64:size(vn, 1_i64, i64) - &
            1_i64 - 1_i64, 1_i64:size(vn, 2_i64, i64) - 1_i64 - 1_i64) &
            - dt / dx * un(1_i64:size(un, 1_i64, i64) - 1_i64 - 1_i64, &
            1_i64:size(un, 2_i64, i64) - 1_i64 - 1_i64) * (vn(1_i64: &
            size(vn, 1_i64, i64) - 1_i64 - 1_i64, 1_i64:size(vn, 2_i64, &
            i64) - 1_i64 - 1_i64) - vn(1_i64:size(vn, 1_i64, i64) - &
            1_i64 - 1_i64, 0_i64:size(vn, 2_i64, i64) - 2_i64 - 1_i64 &
            )) - dt / dy * vn(1_i64:size(vn, 1_i64, i64) - 1_i64 - &
            1_i64, 1_i64:size(vn, 2_i64, i64) - 1_i64 - 1_i64) * (vn( &
            1_i64:size(vn, 1_i64, i64) - 1_i64 - 1_i64, 1_i64:size(vn, &
            2_i64, i64) - 1_i64 - 1_i64) - vn(0_i64:size(vn, 1_i64, i64 &
            ) - 2_i64 - 1_i64, 1_i64:size(vn, 2_i64, i64) - 1_i64 - &
            1_i64)) + nu * dt / dx ** 2_i64 * (vn(1_i64:size(vn, 1_i64, &
            i64) - 1_i64 - 1_i64, 2_i64:) - 2_i64 * vn(1_i64:size(vn, &
            1_i64, i64) - 1_i64 - 1_i64, 1_i64:size(vn, 2_i64, i64) - &
            1_i64 - 1_i64) + vn(1_i64:size(vn, 1_i64, i64) - 1_i64 - &
            1_i64, 0_i64:size(vn, 2_i64, i64) - 2_i64 - 1_i64)) + nu * &
            dt / dy ** 2_i64 * (vn(2_i64:, 1_i64:size(vn, 2_i64, i64) - &
            1_i64 - 1_i64) - 2_i64 * vn(1_i64:size(vn, 1_i64, i64) - &
            1_i64 - 1_i64, 1_i64:size(vn, 2_i64, i64) - 1_i64 - 1_i64) &
            + vn(0_i64:size(vn, 1_i64, i64) - 2_i64 - 1_i64, 1_i64:size &
            (vn, 2_i64, i64) - 1_i64 - 1_i64))
      u(:, 0_i64) = 1_i64
      u(:, size(u, 2_i64, i64) - 1_i64) = 1_i64
      u(0_i64, :) = 1_i64
      u(size(u, 1_i64, i64) - 1_i64, :) = 1_i64
      v(:, 0_i64) = 1_i64
      v(:, size(v, 2_i64, i64) - 1_i64) = 1_i64
      v(0_i64, :) = 1_i64
      v(size(v, 1_i64, i64) - 1_i64, :) = 1_i64
    end do
    Out_0001 = 0_i64
    return

  end function solve_2d_burger_pyccel
  !........................................

end module mod_tp6j5vo3gwv0_tp6j5vo3gwv0
