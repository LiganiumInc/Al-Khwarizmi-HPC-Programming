module mod_2ob7bey2cceh_2ob7bey2cceh


  use, intrinsic :: ISO_C_Binding, only : i64 => C_INT64_T , f64 => &
        C_DOUBLE
  implicit none

  contains

  !........................................
  subroutine pressure_poisson_cel(p, dx, dy, b, nit) 

    implicit none

    real(f64), intent(inout) :: p(0:,0:)
    real(f64), value :: dx
    real(f64), value :: dy
    real(f64), intent(in) :: b(0:,0:)
    integer(i64), value :: nit
    real(f64), allocatable :: pn(:,:)
    integer(i64) :: row
    integer(i64) :: col
    integer(i64) :: i
    integer(i64) :: j
    integer(i64) :: q

    allocate(pn(0:size(p, 1_i64, i64) - 1_i64, 0:size(p, 2_i64, i64) - &
          1_i64))
    row = size(p, 2_i64, i64)
    col = size(p, 1_i64, i64)
    !pn = np.empty_like(p)
    do i = 0_i64, row - 1_i64, 1_i64
      do j = 0_i64, col - 1_i64, 1_i64
        pn(j, i) = p(j, i)
      end do
    end do
    !fill the update of p
    do q = 0_i64, nit - 1_i64, 1_i64
      do i = 0_i64, row - 1_i64, 1_i64
        do j = 0_i64, col - 1_i64, 1_i64
          pn(j, i) = p(j, i)
        end do
      end do
      p(1_i64:size(p, 1_i64, i64) - 1_i64 - 1_i64, 1_i64:size(p, 2_i64, &
            i64) - 1_i64 - 1_i64) = ((pn(2_i64:, 1_i64:size(pn, 2_i64, &
            i64) - 1_i64 - 1_i64) + pn(0_i64:size(pn, 1_i64, i64) - &
            2_i64 - 1_i64, 1_i64:size(pn, 2_i64, i64) - 1_i64 - 1_i64 &
            )) * (dy * dy) + (pn(1_i64:size(pn, 1_i64, i64) - 1_i64 - &
            1_i64, 2_i64:) + pn(1_i64:size(pn, 1_i64, i64) - 1_i64 - &
            1_i64, 0_i64:size(pn, 2_i64, i64) - 2_i64 - 1_i64)) * (dx * &
            dx)) / (2_i64 * (dx * dx + dy * dy)) - dx * dx * (dy * dy) &
            / (2_i64 * (dx * dx + dy * dy)) * b(1_i64:size(b, 1_i64, &
            i64) - 1_i64 - 1_i64, 1_i64:size(b, 2_i64, i64) - 1_i64 - &
            1_i64)
      p(size(p, 1_i64, i64) - 1_i64, :) = p(size(p, 1_i64, i64) - 2_i64, &
            :)
      p(:, 0_i64) = p(:, 1_i64)
      p(0_i64, :) = p(1_i64, :)
      p(:, size(p, 2_i64, i64) - 1_i64) = 0_i64
    end do
    if (allocated(pn)) then
      deallocate(pn)
    end if

  end subroutine pressure_poisson_cel
  !........................................

end module mod_2ob7bey2cceh_2ob7bey2cceh
