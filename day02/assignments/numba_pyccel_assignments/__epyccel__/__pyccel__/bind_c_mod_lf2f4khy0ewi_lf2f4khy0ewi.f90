module bind_c_mod_lf2f4khy0ewi_lf2f4khy0ewi

  use mod_lf2f4khy0ewi_lf2f4khy0ewi, only: solve_2d_diff_pyccel

  use, intrinsic :: ISO_C_Binding, only : f64 => C_DOUBLE , i64 => &
        C_INT64_T
  implicit none

  contains

  !........................................
  function bind_c_solve_2d_diff_pyccel(n0_u, n1_u, u, n0_un, n1_un, un, &
        nt, dt, dx, dy, nu) bind(c) result(Out_0001)

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
    real(f64), value :: nu
    integer(i64) :: Out_0001

    Out_0001 = solve_2d_diff_pyccel(u, un, nt, dt, dx, dy, nu)

  end function bind_c_solve_2d_diff_pyccel
  !........................................

end module bind_c_mod_lf2f4khy0ewi_lf2f4khy0ewi
