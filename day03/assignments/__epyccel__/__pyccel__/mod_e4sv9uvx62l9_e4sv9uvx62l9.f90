module mod_e4sv9uvx62l9_e4sv9uvx62l9


  use, intrinsic :: ISO_C_Binding, only : i64 => C_INT64_T , f64 => &
        C_DOUBLE
  implicit none

  contains

  !........................................
  subroutine build_up_b_cel(b, rho, dt, u, v, dx, dy) 

    implicit none

    real(f64), intent(inout) :: b(0:,0:)
    real(f64), value :: rho
    real(f64), value :: dt
    real(f64), intent(in) :: u(0:,0:)
    real(f64), intent(in) :: v(0:,0:)
    real(f64), value :: dx
    real(f64), value :: dy

    !row, col = p.shape
    !fill the update of b
    b(1_i64:size(b, 1_i64, i64) - 1_i64 - 1_i64, 1_i64:size(b, 2_i64, &
          i64) - 1_i64 - 1_i64) = rho * (1_i64 / dt * ((u(2_i64:, 1_i64 &
          :size(u, 2_i64, i64) - 1_i64 - 1_i64) - u(0_i64:size(u, 1_i64 &
          , i64) - 2_i64 - 1_i64, 1_i64:size(u, 2_i64, i64) - 1_i64 - &
          1_i64)) / (2_i64 * dx) + (v(1_i64:size(v, 1_i64, i64) - 1_i64 &
          - 1_i64, 2_i64:) - v(1_i64:size(v, 1_i64, i64) - 1_i64 - &
          1_i64, 0_i64:size(v, 2_i64, i64) - 2_i64 - 1_i64)) / (2_i64 * &
          dy)) - ((u(2_i64:, 1_i64:size(u, 2_i64, i64) - 1_i64 - 1_i64 &
          ) - u(0_i64:size(u, 1_i64, i64) - 2_i64 - 1_i64, 1_i64:size(u &
          , 2_i64, i64) - 1_i64 - 1_i64)) / (2_i64 * dx)) ** 2_i64 - &
          2_i64 * ((u(1_i64:size(u, 1_i64, i64) - 1_i64 - 1_i64, 2_i64: &
          ) - u(1_i64:size(u, 1_i64, i64) - 1_i64 - 1_i64, 0_i64:size(u &
          , 2_i64, i64) - 2_i64 - 1_i64)) / (2_i64 * dy) * (v(2_i64:, &
          1_i64:size(v, 2_i64, i64) - 1_i64 - 1_i64) - v(0_i64:size(v, &
          1_i64, i64) - 2_i64 - 1_i64, 1_i64:size(v, 2_i64, i64) - &
          1_i64 - 1_i64)) / (2_i64 * dx)) - ((v(1_i64:size(v, 1_i64, &
          i64) - 1_i64 - 1_i64, 2_i64:) - v(1_i64:size(v, 1_i64, i64) - &
          1_i64 - 1_i64, 0_i64:size(v, 2_i64, i64) - 2_i64 - 1_i64)) / &
          (2_i64 * dy)) ** 2_i64)
    !return b

  end subroutine build_up_b_cel
  !........................................

end module mod_e4sv9uvx62l9_e4sv9uvx62l9
