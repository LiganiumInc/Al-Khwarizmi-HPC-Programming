module bind_c_mod_vd166r18fy57_vd166r18fy57

  use mod_vd166r18fy57_vd166r18fy57, only: solve_2d_burger_pyccel

  use, intrinsic :: ISO_C_Binding, only : f64 => C_DOUBLE , i64 => &
        C_INT64_T
  implicit none

  contains

  !........................................
  function bind_c_solve_2d_burger_pyccel(n0_u, n1_u, u, n0_un, n1_un, un &
        , n0_v, n1_v, v, n0_vn, n1_vn, vn, nt, dt, dx, dy, nu) bind(c) &
        result(Out_0001)

    implicit none

    integer(i64), value :: n0_u
    integer(i64), value :: n1_u
    real(f64), intent(inout) :: u(0:n1_u - 1_i64,0:n0_u - 1_i64)
    integer(i64), value :: n0_un
    integer(i64), value :: n1_un
    real(f64), intent(in) :: un(0:n1_un - 1_i64,0:n0_un - 1_i64)
    integer(i64), value :: n0_v
    integer(i64), value :: n1_v
    real(f64), intent(inout) :: v(0:n1_v - 1_i64,0:n0_v - 1_i64)
    integer(i64), value :: n0_vn
    integer(i64), value :: n1_vn
    real(f64), intent(in) :: vn(0:n1_vn - 1_i64,0:n0_vn - 1_i64)
    integer(i64), value :: nt
    real(f64), value :: dt
    real(f64), value :: dx
    real(f64), value :: dy
    real(f64), value :: nu
    integer(i64) :: Out_0001

    Out_0001 = solve_2d_burger_pyccel(u, un, v, vn, nt, dt, dx, dy, nu)

  end function bind_c_solve_2d_burger_pyccel
  !........................................

end module bind_c_mod_vd166r18fy57_vd166r18fy57
