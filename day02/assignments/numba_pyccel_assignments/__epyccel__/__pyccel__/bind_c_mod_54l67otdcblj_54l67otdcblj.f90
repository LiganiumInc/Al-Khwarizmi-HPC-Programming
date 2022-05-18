module bind_c_mod_54l67otdcblj_54l67otdcblj

  use mod_54l67otdcblj_54l67otdcblj, only: solve_1d_diff_pyccel

  use, intrinsic :: ISO_C_Binding, only : f64 => C_DOUBLE , i64 => &
        C_INT64_T
  implicit none

  contains

  !........................................
  function bind_c_solve_1d_diff_pyccel(n0_u, u, n0_un, un, nt, nx, dt, &
        dx, nu) bind(c) result(Out_0001)

    implicit none

    integer(i64), value :: n0_u
    real(f64), intent(inout) :: u(0:n0_u - 1_i64)
    integer(i64), value :: n0_un
    real(f64), intent(inout) :: un(0:n0_un - 1_i64)
    integer(i64), value :: nt
    integer(i64), value :: nx
    real(f64), value :: dt
    real(f64), value :: dx
    real(f64), value :: nu
    integer(i64) :: Out_0001

    Out_0001 = solve_1d_diff_pyccel(u, un, nt, nx, dt, dx, nu)

  end function bind_c_solve_1d_diff_pyccel
  !........................................

end module bind_c_mod_54l67otdcblj_54l67otdcblj
