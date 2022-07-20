module bind_c_mod_ygbv3fcu5rs0_ygbv3fcu5rs0

  use mod_ygbv3fcu5rs0_ygbv3fcu5rs0, only: pressure_poisson_cel

  use, intrinsic :: ISO_C_Binding, only : i64 => C_INT64_T , f64 => &
        C_DOUBLE
  implicit none

  contains

  !........................................
  subroutine bind_c_pressure_poisson_cel(n0_p, n1_p, p, dx, dy, n0_b, &
        n1_b, b, nit) bind(c)

    implicit none

    integer(i64), value :: n0_p
    integer(i64), value :: n1_p
    real(f64), intent(inout) :: p(0:n1_p - 1_i64,0:n0_p - 1_i64)
    real(f64), value :: dx
    real(f64), value :: dy
    integer(i64), value :: n0_b
    integer(i64), value :: n1_b
    real(f64), intent(in) :: b(0:n1_b - 1_i64,0:n0_b - 1_i64)
    integer(i64), value :: nit

    call pressure_poisson_cel(p, dx, dy, b, nit)

  end subroutine bind_c_pressure_poisson_cel
  !........................................

end module bind_c_mod_ygbv3fcu5rs0_ygbv3fcu5rs0
