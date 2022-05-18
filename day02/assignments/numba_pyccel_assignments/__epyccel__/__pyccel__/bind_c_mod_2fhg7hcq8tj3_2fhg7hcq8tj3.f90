module bind_c_mod_2fhg7hcq8tj3_2fhg7hcq8tj3

  use mod_2fhg7hcq8tj3_2fhg7hcq8tj3, only: solve_1d_linearconv_pyccel

  use, intrinsic :: ISO_C_Binding, only : i64 => C_INT64_T , f64 => &
        C_DOUBLE
  implicit none

  contains

  !........................................
  function bind_c_solve_1d_linearconv_pyccel(n0_u, u, n0_un, un, nt, nx, &
        dt, dx, c) bind(c) result(Out_0001)

    implicit none

    integer(i64), value :: n0_u
    real(f64), intent(inout) :: u(0:n0_u - 1_i64)
    integer(i64), value :: n0_un
    real(f64), intent(inout) :: un(0:n0_un - 1_i64)
    integer(i64), value :: nt
    integer(i64), value :: nx
    real(f64), value :: dt
    real(f64), value :: dx
    real(f64), value :: c
    integer(i64) :: Out_0001

    Out_0001 = solve_1d_linearconv_pyccel(u, un, nt, nx, dt, dx, c)

  end function bind_c_solve_1d_linearconv_pyccel
  !........................................

end module bind_c_mod_2fhg7hcq8tj3_2fhg7hcq8tj3
