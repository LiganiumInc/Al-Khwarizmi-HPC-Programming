module bind_c_mod_1vx2z0i44n55_1vx2z0i44n55

  use mod_1vx2z0i44n55_1vx2z0i44n55, only: solve_2d_poisson_pyccel

  use, intrinsic :: ISO_C_Binding, only : f64 => C_DOUBLE , i64 => &
        C_INT64_T
  implicit none

  contains

  !........................................
  function bind_c_solve_2d_poisson_pyccel(n0_p, n1_p, p, n0_pd, n1_pd, &
        pd, n0_b, n1_b, b, nx, ny, nt, dx, dy) bind(c) result(Out_0001)

    implicit none

    integer(i64), value :: n0_p
    integer(i64), value :: n1_p
    real(f64), intent(inout) :: p(0:n1_p - 1_i64,0:n0_p - 1_i64)
    integer(i64), value :: n0_pd
    integer(i64), value :: n1_pd
    real(f64), intent(inout) :: pd(0:n1_pd - 1_i64,0:n0_pd - 1_i64)
    integer(i64), value :: n0_b
    integer(i64), value :: n1_b
    real(f64), intent(inout) :: b(0:n1_b - 1_i64,0:n0_b - 1_i64)
    integer(i64), value :: nx
    integer(i64), value :: ny
    integer(i64), value :: nt
    real(f64), value :: dx
    real(f64), value :: dy
    integer(i64) :: Out_0001

    Out_0001 = solve_2d_poisson_pyccel(p, pd, b, nx, ny, nt, dx, dy)

  end function bind_c_solve_2d_poisson_pyccel
  !........................................

end module bind_c_mod_1vx2z0i44n55_1vx2z0i44n55
