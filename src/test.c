#include "simd_common.h"
#include "test.h"

test(init_i8) {
	simd_i8 one_typed = simd_init_n_i8(0);
	simd_i8 all_typed = simd_init_i8(
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
	simd_i8 one = simd_i8(0);
	simd_i8 all =
		simd_i8(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
	pass;
}

test(init_u8) {
	simd_u8 one_typed = simd_init_n_u8(0);
	simd_u8 all_typed = simd_init_u8(
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
	simd_u8 one = simd_u8(0);
	simd_u8 all =
		simd_u8(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
	pass;
}

test(init_i16) {
	simd_i16 one_typed = simd_init_n_i16(0);
	simd_i16 all_typed = simd_init_i16(0, 1, 2, 3, 4, 5, 6, 7);
	simd_i16 one = simd_i16(0);
	simd_i16 all = simd_i16(0, 1, 2, 3, 4, 5, 6, 7);
	pass;
}

test(init_u16) {
	simd_u16 one_typed = simd_init_n_u16(0);
	simd_u16 all_typed = simd_init_u16(0, 1, 2, 3, 4, 5, 6, 7);
	simd_u16 one = simd_u16(0);
	simd_u16 all = simd_u16(0, 1, 2, 3, 4, 5, 6, 7);
	pass;
}

test(init_i32) {
	simd_i32 one_typed = simd_init_n_i32(0);
	simd_i32 all_typed = simd_init_i32(0, 1, 2, 3);
	simd_i32 one = simd_i32(0);
	simd_i32 all = simd_i32(0, 1, 2, 3);
	pass;
}

test(init_u32) {
	simd_u32 one_typed = simd_init_n_u32(0);
	simd_u32 all_typed = simd_init_u32(0, 1, 2, 3);
	simd_u32 one = simd_u32(0);
	simd_u32 all = simd_u32(0, 1, 2, 3);
	pass;
}

test(init_f32) {
	simd_f32 one_typed = simd_init_n_f32(0);
	simd_f32 all_typed = simd_init_f32(0, 1, 2, 3);
	simd_f32 one = simd_f32(0);
	simd_f32 all = simd_f32(0, 1, 2, 3);
	pass;
}

test(get_lane_i8) {
	assert(simd_get_lane_i8(
		       simd_i8(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
			       15),
		       8)
	       == 8);
	assert(simd_get_lane(
		       simd_i8(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
			       15),
		       8)
	       == 8);
	pass;
}

test(get_lane_u8) {
	assert(simd_get_lane_u8(
		       simd_u8(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
			       15),
		       8)
	       == 8);
	assert(simd_get_lane(
		       simd_u8(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
			       15),
		       8)
	       == 8);
	pass;
}

test(get_lane_i16) {
	assert(simd_get_lane_i16(simd_i16(0, 1, 2, 3, 4, 5, 6, 7), 3) == 3);
	assert(simd_get_lane(simd_i16(0, 1, 2, 3, 4, 5, 6, 7), 3) == 3);
	pass;
}

test(get_lane_u16) {
	assert(simd_get_lane_u16(simd_u16(0, 1, 2, 3, 4, 5, 6, 7), 3) == 3);
	assert(simd_get_lane(simd_u16(0, 1, 2, 3, 4, 5, 6, 7), 3) == 3);
	pass;
}

test(get_lane_i32) {
	assert(simd_get_lane_i32(simd_i32(0, 1, 2, 3), 2) == 2);
	assert(simd_get_lane(simd_i32(0, 1, 2, 3), 2) == 2);
	pass;
}

test(get_lane_u32) {
	assert(simd_get_lane_u32(simd_u32(0, 1, 2, 3), 2) == 2);
	assert(simd_get_lane(simd_u32(0, 1, 2, 3), 2) == 2);
	pass;
}

test(get_lane_f32) {
	assert(simd_get_lane_f32(simd_f32(0, 1, 2, 3), 2) == 2);
	assert(simd_get_lane(simd_f32(0, 1, 2, 3), 2) == 2);
	pass;
}

test(set_lane_i8) {
	simd_i8 x =
		simd_i8(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
	x = simd_set_lane_i8(10, x, 1);
	x = simd_set_lane(20, x, 2);
	assert(simd_get_lane(x, 1) == 10);
	assert(simd_get_lane(x, 2) == 20);
	pass;
}

test(set_lane_u8) {
	simd_u8 x =
		simd_u8(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
	x = simd_set_lane_u8(10, x, 1);
	x = simd_set_lane(20, x, 2);
	assert(simd_get_lane(x, 1) == 10);
	assert(simd_get_lane(x, 2) == 20);
	pass;
}

test(set_lane_i16) {
	simd_i16 x = simd_i16(0, 1, 2, 3, 4, 5, 6, 7);
	x = simd_set_lane_i16(10, x, 1);
	x = simd_set_lane(20, x, 2);
	assert(simd_get_lane(x, 1) == 10);
	assert(simd_get_lane(x, 2) == 20);
	pass;
}

test(set_lane_u16) {
	simd_u16 x = simd_u16(0, 1, 2, 3, 4, 5, 6, 7);
	x = simd_set_lane_u16(10, x, 1);
	x = simd_set_lane(20, x, 2);
	assert(simd_get_lane(x, 1) == 10);
	assert(simd_get_lane(x, 2) == 20);
	pass;
}

test(set_lane_i32) {
	simd_i32 x = simd_i32(0, 1, 2, 3);
	x = simd_set_lane_i32(10, x, 1);
	x = simd_set_lane(20, x, 2);
	assert(simd_get_lane(x, 1) == 10);
	assert(simd_get_lane(x, 2) == 20);
	pass;
}

test(set_lane_u32) {
	simd_u32 x = simd_u32(0, 1, 2, 3);
	x = simd_set_lane_u32(10, x, 1);
	x = simd_set_lane(20, x, 2);
	assert(simd_get_lane(x, 1) == 10);
	assert(simd_get_lane(x, 2) == 20);
	pass;
}

test(set_lane_f32) {
	simd_f32 x = simd_f32(0, 1, 2, 3);
	x = simd_set_lane_f32(10, x, 1);
	x = simd_set_lane(20, x, 2);
	assert(simd_get_lane(x, 1) == 10);
	assert(simd_get_lane(x, 2) == 20);
	pass;
}

test(u8_cvt_i8) {
	simd_i8 from = simd_i8(-1);
	simd_u8 to_typed = simd_u8_cvt_i8(from);
	simd_u8 to = simd_cvt(simd_u8, from);
	assert(simd_get_lane(to_typed, 0) == 255);
	assert(simd_get_lane(to, 0) == 255);
	pass;
}

test(i8_cvt_u8) {
	simd_u8 from = simd_u8(255);
	simd_i8 to_typed = simd_i8_cvt_u8(from);
	simd_i8 to = simd_cvt(simd_i8, from);
	assert(simd_get_lane(to_typed, 0) == -1);
	assert(simd_get_lane(to, 0) == -1);
	pass;
}

test(u16_cvt_i16) {
	simd_i16 from = simd_i16(-1);
	simd_u16 to_typed = simd_u16_cvt_i16(from);
	simd_u16 to = simd_cvt(simd_u16, from);
	assert(simd_get_lane(to_typed, 0) == 65535);
	assert(simd_get_lane(to, 0) == 65535);
	pass;
}

test(i16_cvt_u16) {
	simd_u16 from = simd_u16(65535);
	simd_i16 to_typed = simd_i16_cvt_u16(from);
	simd_i16 to = simd_cvt(simd_i16, from);
	assert(simd_get_lane(to_typed, 0) == -1);
	assert(simd_get_lane(to, 0) == -1);
	pass;
}

test(u32_cvt_i32) {
	simd_i32 from = simd_i32(-1);
	simd_u32 to_typed = simd_u32_cvt_i32(from);
	simd_u32 to = simd_cvt(simd_u32, from);
	assert(simd_get_lane(to_typed, 0) == 4294967295);
	assert(simd_get_lane(to, 0) == 4294967295);
	pass;
}

test(f32_cvt_i32) {
	simd_i32 from = simd_i32(-1);
	simd_f32 to_typed = simd_f32_cvt_i32(from);
	simd_f32 to = simd_cvt(simd_f32, from);
	assert(simd_get_lane(to_typed, 0) == -1);
	assert(simd_get_lane(to, 0) == -1);
	pass;
}

test(i32_cvt_u32) {
	simd_u32 from = simd_u32(4294967295);
	simd_i32 to_typed = simd_i32_cvt_u32(from);
	simd_i32 to = simd_cvt(simd_i32, from);
	assert(simd_get_lane(to_typed, 0) == -1);
	assert(simd_get_lane(to, 0) == -1);
	pass;
}

test(f32_cvt_u32) {
	simd_u32 from = simd_u32(1);
	simd_f32 to_typed = simd_f32_cvt_u32(from);
	simd_f32 to = simd_cvt(simd_f32, from);
	assert(simd_get_lane(to_typed, 0) == 1);
	assert(simd_get_lane(to, 0) == 1);
	pass;
}

test(i32_cvt_f32) {
	simd_f32 from = simd_f32(-5.5);
	simd_i32 to_typed = simd_i32_cvt_f32(from);
	simd_i32 to = simd_cvt(simd_i32, from);
	assert(simd_get_lane(to_typed, 0) == -5);
	assert(simd_get_lane(to, 0) == -5);
	pass;
}

test(u32_cvt_f32) {
	simd_f32 from = simd_f32(5.5);
	simd_u32 to_typed = simd_u32_cvt_f32(from);
	simd_u32 to = simd_cvt(simd_u32, from);
	assert(simd_get_lane(to_typed, 0) == 5);
	assert(simd_get_lane(to, 0) == 5);
	pass;
}

test(u32_reinterpret_f32) {
	simd_f32 from = simd_f32(1.0);
	simd_u32 to = simd_reinterpret(simd_u32, from);
	assert(simd_get_lane(to, 0) == 0x3F800000);
	pass;
}

test(rev_i8) {
	simd_i8 rev = simd_rev(
		simd_i8(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15));
	assert(simd_get_lane(rev, 0) == 15);
	assert(simd_get_lane(rev, 5) == 10);
	assert(simd_get_lane(rev, 10) == 5);
	assert(simd_get_lane(rev, 15) == 0);
	pass;
}

test(rev_u8) {
	simd_u8 rev = simd_rev(
		simd_u8(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15));
	assert(simd_get_lane(rev, 0) == 15);
	assert(simd_get_lane(rev, 5) == 10);
	assert(simd_get_lane(rev, 10) == 5);
	assert(simd_get_lane(rev, 15) == 0);
	pass;
}

test(rev_i16) {
	simd_i16 rev = simd_rev(simd_i16(0, 1, 2, 3, 4, 5, 6, 7));
	assert(simd_get_lane(rev, 0) == 7);
	assert(simd_get_lane(rev, 1) == 6);
	assert(simd_get_lane(rev, 6) == 1);
	assert(simd_get_lane(rev, 7) == 0);
	pass;
}

test(rev_u16) {
	simd_u16 rev = simd_rev(simd_u16(0, 1, 2, 3, 4, 5, 6, 7));
	assert(simd_get_lane(rev, 0) == 7);
	assert(simd_get_lane(rev, 1) == 6);
	assert(simd_get_lane(rev, 6) == 1);
	assert(simd_get_lane(rev, 7) == 0);
	pass;
}

test(rev_i32) {
	simd_i32 rev = simd_rev(simd_i32(0, 1, 2, 3));
	assert(simd_get_lane(rev, 0) == 3);
	assert(simd_get_lane(rev, 1) == 2);
	assert(simd_get_lane(rev, 2) == 1);
	assert(simd_get_lane(rev, 3) == 0);
	pass;
}

test(rev_u32) {
	simd_u32 rev = simd_rev(simd_u32(0, 1, 2, 3));
	assert(simd_get_lane(rev, 0) == 3);
	assert(simd_get_lane(rev, 1) == 2);
	assert(simd_get_lane(rev, 2) == 1);
	assert(simd_get_lane(rev, 3) == 0);
	pass;
}

test(rev_f32) {
	simd_f32 rev = simd_rev(simd_f32(0, 1, 2, 3));
	assert(simd_get_lane(rev, 0) == 3);
	assert(simd_get_lane(rev, 1) == 2);
	assert(simd_get_lane(rev, 2) == 1);
	assert(simd_get_lane(rev, 3) == 0);
	pass;
}

test(shuffle_i8) {
	simd_i8 shuffled = simd_shuffle(
		simd_i8(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15),
		0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3);
	assert(simd_get_lane(shuffled, 0) == 0);
	assert(simd_get_lane(shuffled, 4) == 1);
	assert(simd_get_lane(shuffled, 8) == 2);
	assert(simd_get_lane(shuffled, 12) == 3);
	pass;
}

test(shl_lane_u32) {
	simd_u32 shifted = simd_shl_lane(simd_u32(1, 2, 3, 4), 1);
	assert(simd_get_lane(shifted, 0) == 0);
	assert(simd_get_lane(shifted, 1) == 1);
	assert(simd_get_lane(shifted, 2) == 2);
	assert(simd_get_lane(shifted, 3) == 3);

	shifted = simd_shl_lane(simd_u32(1, 2, 3, 4), 0);
	assert(simd_get_lane(shifted, 0) == 1);
	assert(simd_get_lane(shifted, 1) == 2);
	assert(simd_get_lane(shifted, 2) == 3);
	assert(simd_get_lane(shifted, 3) == 4);

	shifted = simd_shl_lane(simd_u32(1, 2, 3, 4), 4);
	assert(simd_get_lane(shifted, 0) == 0);
	assert(simd_get_lane(shifted, 1) == 0);
	assert(simd_get_lane(shifted, 2) == 0);
	assert(simd_get_lane(shifted, 3) == 0);
	pass;
}

test(shl_lane_f32) {
	simd_f32 shifted = simd_shl_lane(simd_f32(1.5, 2.5, 3.5, 4.5), 1);
	assert(simd_get_lane(shifted, 0) == 0);
	assert(simd_get_lane(shifted, 1) == 1.5);
	assert(simd_get_lane(shifted, 2) == 2.5);
	assert(simd_get_lane(shifted, 3) == 3.5);
	pass;
}

test(shr_lane_u32) {
	simd_u32 shifted = simd_shr_lane(simd_u32(1, 2, 3, 4), 1);
	assert(simd_get_lane(shifted, 0) == 2);
	assert(simd_get_lane(shifted, 1) == 3);
	assert(simd_get_lane(shifted, 2) == 4);
	assert(simd_get_lane(shifted, 3) == 0);

	shifted = simd_shr_lane(simd_u32(1, 2, 3, 4), 0);
	assert(simd_get_lane(shifted, 0) == 1);
	assert(simd_get_lane(shifted, 1) == 2);
	assert(simd_get_lane(shifted, 2) == 3);
	assert(simd_get_lane(shifted, 3) == 4);

	shifted = simd_shr_lane(simd_u32(1, 2, 3, 4), 4);
	assert(simd_get_lane(shifted, 0) == 0);
	assert(simd_get_lane(shifted, 1) == 0);
	assert(simd_get_lane(shifted, 2) == 0);
	assert(simd_get_lane(shifted, 3) == 0);
	pass;
}

test(u32_ld) {
	simd_u32 x = simd_ld_u32((uint32_t[4]){1, 3, 3, 7});
	assert(simd_get_lane(x, 0) == 1);
	assert(simd_get_lane(x, 1) == 3);
	assert(simd_get_lane(x, 2) == 3);
	assert(simd_get_lane(x, 3) == 7);
	pass;
}

test(u32_st) {
	uint32_t arr[4];
	simd_st(arr, simd_u32(0, 1, 2, 3));
	assert(arr[0] == 0);
	assert(arr[1] == 1);
	assert(arr[2] == 2);
	assert(arr[3] == 3);
	pass;
}

test(widen_lo_i8) {
	simd_i16 x = simd_widen_lo(
		simd_i8(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15));
	assert(simd_get_lane(x, 0) == 0);
	pass;
}

test(widen_hi_i8) {
	simd_i16 x = simd_widen_hi(
		simd_i8(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15));
	assert(simd_get_lane(x, 0) == 8);
	pass;
}

test(widen_lo_i16) {
	simd_i32 x = simd_widen_lo(simd_i16(0, 1, 2, 3, 4, 5, 6, 7));
	assert(simd_get_lane(x, 0) == 0);
	pass;
}

test(widen_hi_i16) {
	simd_i32 x = simd_widen_hi(simd_i16(0, 1, 2, 3, 4, 5, 6, 7));
	assert(simd_get_lane(x, 0) == 4);
	pass;
}

test(narrow_lo_i32) {
	simd_i16 x = simd_narrow_lo(simd_i32(0, 1, 2, 3));
	int16_t	 arr[8] = {0, 1, 2, 3, 0, 0, 0, 0};
	int16_t	 out[8];
	simd_st(out, x);
	assert(memcmp(arr, out, sizeof(arr)) == 0);
	pass;
}

test(narrow_hi_i32) {
	simd_i16 x = simd_narrow_hi(simd_i32(0, 1, 2, 3));
	int16_t	 arr[8] = {0, 0, 0, 0, 0, 1, 2, 3};
	int16_t	 out[8];
	simd_st(out, x);
	assert(memcmp(arr, out, sizeof(arr)) == 0);
	pass;
}

test(shl_n_u32) {
	simd_u32 a = simd_shl(simd_u32(0x0F), 4);
	assert(simd_get_lane(a, 0) == 0xF0);
	pass;
}

test(shr_n_i32) {
	simd_i32 a = simd_shr(simd_i32(0xF0000000), 28);
	assert(simd_get_lane(a, 0) == 0xFFFFFFFF);
	pass;
}

test(shr_n_u32) {
	simd_u32 a = simd_shr(simd_u32(0xF0000000), 28);
	assert(simd_get_lane(a, 0) == 0x0F);
	pass;
}

test(shr_i32) {
	simd_i32 a = simd_shr(simd_i32(0xF0000000), simd_i32(28));
	assert(simd_get_lane(a, 0) == 0xFFFFFFFF);
	pass;
}

test(shr_u32) {
	simd_u32 a = simd_shr(simd_u32(0xF0000000), simd_i32(28));
	assert(simd_get_lane(a, 0) == 0x0F);
	pass;
}
