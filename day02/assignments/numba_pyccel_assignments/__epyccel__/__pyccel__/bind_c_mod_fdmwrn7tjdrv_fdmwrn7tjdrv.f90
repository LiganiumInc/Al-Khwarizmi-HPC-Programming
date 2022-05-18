module bind_c_mod_fdmwrn7tjdrv_fdmwrn7tjdrv

  use mod_fdmwrn7tjdrv_fdmwrn7tjdrv, only: solve_2d_linearconv_pyccel

  use, intrinsic :: ISO_C_Binding, only : i64 => C_INT64_T , f64 => &
        C_DOUBLE
  implicit none

  contains

  !........................................
  function bind_c_solve_2d_linearconv_pyccel(n0_u, n1_u, u, n0_un, n1_un &
        , un, nt, dt, dx, dy, c) bind(c) result(Out_0001)

    implicit none

    integer(i64), value :: n0_u
    integer(i64), value :: n1_u
    real(f64), intent(inout) :: u(0:n1_u - 1_i64,0:n0_u - 1_i64)
    integer(i64), value :: n0_un
    integer(i64), value :: n1_un
    real(f64), intent(inout) :: un(0:n1_un - 1_i64,0:n0_un - 1_i64)
    integer(i64), value :: nt
    real(f64), value :: dt
    real(f64), value :: dx
    real(f64), value :: dy
    integer(i64), value :: c
    integer(i64) :: Out_0001

    Out_0001 = solve_2d_linearconv_pyccel(u, un, nt, dt, dx, dy, c)

  end function bind_c_solve_2d_linearconv_pyccel
  !........................................

end module bind_c_mod_fdmwrn7tjdrv_fdmwrn7tjdrv
