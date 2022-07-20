module bind_c_mod_zcwku48mcgaz_zcwku48mcgaz

  use mod_zcwku48mcgaz_zcwku48mcgaz, only: build_up_b_cel

  use, intrinsic :: ISO_C_Binding, only : i64 => C_INT64_T , f64 => &
        C_DOUBLE
  implicit none

  contains

  !........................................
  subroutine bind_c_build_up_b_cel(n0_b, n1_b, b, rho, dt, n0_u, n1_u, u &
        , n0_v, n1_v, v, dx, dy) bind(c)

    implicit none

    integer(i64), value :: n0_b
    integer(i64), value :: n1_b
    real(f64), intent(inout) :: b(0:n1_b - 1_i64,0:n0_b - 1_i64)
    real(f64), value :: rho
    real(f64), value :: dt
    integer(i64), value :: n0_u
    integer(i64), value :: n1_u
    real(f64), intent(in) :: u(0:n1_u - 1_i64,0:n0_u - 1_i64)
    integer(i64), value :: n0_v
    integer(i64), value :: n1_v
    real(f64), intent(in) :: v(0:n1_v - 1_i64,0:n0_v - 1_i64)
    real(f64), value :: dx
    real(f64), value :: dy

    call build_up_b_cel(b, rho, dt, u, v, dx, dy)

  end subroutine bind_c_build_up_b_cel
  !........................................

end module bind_c_mod_zcwku48mcgaz_zcwku48mcgaz
