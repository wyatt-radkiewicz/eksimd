#include "test.h"
#include "simd_common.h"

test(init_i8) {
	simd_i8 one_typed = simd_i8_dup_n(0);
	simd_i8 all_typed =
		simd_i8_n(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
	simd_i8 one = simd_i8(0);
	simd_i8 all =
		simd_i8(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
	pass;
}

test(init_u8) {
	simd_u8 one_typed = simd_u8_dup_n(0);
	simd_u8 all_typed =
		simd_u8_n(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
	simd_u8 one = simd_u8(0);
	simd_u8 all =
		simd_u8(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
	pass;
}

test(init_i16) {
	simd_i16 one_typed = simd_i16_dup_n(0);
	simd_i16 all_typed = simd_i16_n(0, 1, 2, 3, 4, 5, 6, 7);
	simd_i16 one = simd_i16(0);
	simd_i16 all = simd_i16(0, 1, 2, 3, 4, 5, 6, 7);
	pass;
}

test(init_u16) {
	simd_u16 one_typed = simd_u16_dup_n(0);
	simd_u16 all_typed = simd_u16_n(0, 1, 2, 3, 4, 5, 6, 7);
	simd_u16 one = simd_u16(0);
	simd_u16 all = simd_u16(0, 1, 2, 3, 4, 5, 6, 7);
	pass;
}

test(init_i32) {
	simd_i32 one_typed = simd_i32_dup_n(0);
	simd_i32 all_typed = simd_i32_n(0, 1, 2, 3);
	simd_i32 one = simd_i32(0);
	simd_i32 all = simd_i32(0, 1, 2, 3);
	pass;
}

test(init_u32) {
	simd_u32 one_typed = simd_u32_dup_n(0);
	simd_u32 all_typed = simd_u32_n(0, 1, 2, 3);
	simd_u32 one = simd_u32(0);
	simd_u32 all = simd_u32(0, 1, 2, 3);
	pass;
}

test(init_f32) {
	simd_f32 one_typed = simd_f32_dup_n(0);
	simd_f32 all_typed = simd_f32_n(0, 1, 2, 3);
	simd_f32 one = simd_f32(0);
	simd_f32 all = simd_f32(0, 1, 2, 3);
	pass;
}

test(get_lane_i8) {
	assert(simd_i8_get_lane(
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
	assert(simd_u8_get_lane(
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
	assert(simd_i16_get_lane(simd_i16(0, 1, 2, 3, 4, 5, 6, 7), 3) == 3);
	assert(simd_get_lane(simd_i16(0, 1, 2, 3, 4, 5, 6, 7), 3) == 3);
	pass;
}

test(get_lane_u16) {
	assert(simd_u16_get_lane(simd_u16(0, 1, 2, 3, 4, 5, 6, 7), 3) == 3);
	assert(simd_get_lane(simd_u16(0, 1, 2, 3, 4, 5, 6, 7), 3) == 3);
	pass;
}

test(get_lane_i32) {
	assert(simd_i32_get_lane(simd_i32(0, 1, 2, 3), 2) == 2);
	assert(simd_get_lane(simd_i32(0, 1, 2, 3), 2) == 2);
	pass;
}

test(get_lane_u32) {
	assert(simd_u32_get_lane(simd_u32(0, 1, 2, 3), 2) == 2);
	assert(simd_get_lane(simd_u32(0, 1, 2, 3), 2) == 2);
	pass;
}

test(get_lane_f32) {
	assert(simd_f32_get_lane(simd_f32(0, 1, 2, 3), 2) == 2);
	assert(simd_get_lane(simd_f32(0, 1, 2, 3), 2) == 2);
	pass;
}

test(set_lane_i8) {
	simd_i8 x =
		simd_i8(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
	x = simd_i8_set_lane(10, x, 1);
	x = simd_set_lane(20, x, 2);
	assert(simd_get_lane(x, 1) == 10);
	assert(simd_get_lane(x, 2) == 20);
	pass;
}

test(set_lane_u8) {
	simd_u8 x =
		simd_u8(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
	x = simd_u8_set_lane(10, x, 1);
	x = simd_set_lane(20, x, 2);
	assert(simd_get_lane(x, 1) == 10);
	assert(simd_get_lane(x, 2) == 20);
	pass;
}

test(set_lane_i16) {
	simd_i16 x = simd_i16(0, 1, 2, 3, 4, 5, 6, 7);
	x = simd_i16_set_lane(10, x, 1);
	x = simd_set_lane(20, x, 2);
	assert(simd_get_lane(x, 1) == 10);
	assert(simd_get_lane(x, 2) == 20);
	pass;
}

test(set_lane_u16) {
	simd_u16 x = simd_u16(0, 1, 2, 3, 4, 5, 6, 7);
	x = simd_u16_set_lane(10, x, 1);
	x = simd_set_lane(20, x, 2);
	assert(simd_get_lane(x, 1) == 10);
	assert(simd_get_lane(x, 2) == 20);
	pass;
}

test(set_lane_i32) {
	simd_i32 x = simd_i32(0, 1, 2, 3);
	x = simd_i32_set_lane(10, x, 1);
	x = simd_set_lane(20, x, 2);
	assert(simd_get_lane(x, 1) == 10);
	assert(simd_get_lane(x, 2) == 20);
	pass;
}

test(set_lane_u32) {
	simd_u32 x = simd_u32(0, 1, 2, 3);
	x = simd_u32_set_lane(10, x, 1);
	x = simd_set_lane(20, x, 2);
	assert(simd_get_lane(x, 1) == 10);
	assert(simd_get_lane(x, 2) == 20);
	pass;
}

test(set_lane_f32) {
	simd_f32 x = simd_f32(0, 1, 2, 3);
	x = simd_f32_set_lane(10, x, 1);
	x = simd_set_lane(20, x, 2);
	assert(simd_get_lane(x, 1) == 10);
	assert(simd_get_lane(x, 2) == 20);
	pass;
}

test(i8_cvt_u8) {
	simd_i8 from = simd_i8(-1);
	simd_u8 to_typed = simd_i8_cvt_u8(from);
	simd_u8 to = simd_cvt(from, simd_u8);
	assert(simd_get_lane(to_typed, 0) == 255);
	assert(simd_get_lane(to, 0) == 255);
	pass;
}

test(u8_cvt_i8) {
	simd_u8 from = simd_u8(255);
	simd_i8 to_typed = simd_u8_cvt_i8(from);
	simd_i8 to = simd_cvt(from, simd_i8);
	assert(simd_get_lane(to_typed, 0) == -1);
	assert(simd_get_lane(to, 0) == -1);
	pass;
}

test(i16_cvt_u16) {
	simd_i16 from = simd_i16(-1);
	simd_u16 to_typed = simd_i16_cvt_u16(from);
	simd_u16 to = simd_cvt(from, simd_u16);
	assert(simd_get_lane(to_typed, 0) == 65535);
	assert(simd_get_lane(to, 0) == 65535);
	pass;
}

test(u16_cvt_i16) {
	simd_u16 from = simd_u16(65535);
	simd_i16 to_typed = simd_u16_cvt_i16(from);
	simd_i16 to = simd_cvt(from, simd_i16);
	assert(simd_get_lane(to_typed, 0) == -1);
	assert(simd_get_lane(to, 0) == -1);
	pass;
}

test(i32_cvt_u32) {
	simd_i32 from = simd_i32(-1);
	simd_u32 to_typed = simd_i32_cvt_u32(from);
	simd_u32 to = simd_cvt(from, simd_u32);
	assert(simd_get_lane(to_typed, 0) == 4294967295);
	assert(simd_get_lane(to, 0) == 4294967295);
	pass;
}

test(i32_cvt_f32) {
	simd_i32 from = simd_i32(-1);
	simd_f32 to_typed = simd_i32_cvt_f32(from);
	simd_f32 to = simd_cvt(from, simd_f32);
	assert(simd_get_lane(to_typed, 0) == -1);
	assert(simd_get_lane(to, 0) == -1);
	pass;
}

test(u32_cvt_i32) {
	simd_u32 from = simd_u32(4294967295);
	simd_i32 to_typed = simd_u32_cvt_i32(from);
	simd_i32 to = simd_cvt(from, simd_i32);
	assert(simd_get_lane(to_typed, 0) == -1);
	assert(simd_get_lane(to, 0) == -1);
	pass;
}

test(u32_cvt_f32) {
	simd_u32 from = simd_u32(1);
	simd_f32 to_typed = simd_u32_cvt_f32(from);
	simd_f32 to = simd_cvt(from, simd_f32);
	assert(simd_get_lane(to_typed, 0) == 1);
	assert(simd_get_lane(to, 0) == 1);
	pass;
}

test(f32_cvt_i32) {
	simd_f32 from = simd_f32(-5.5);
	simd_i32 to_typed = simd_f32_cvt_i32(from);
	simd_i32 to = simd_cvt(from, simd_i32);
	assert(simd_get_lane(to_typed, 0) == -5);
	assert(simd_get_lane(to, 0) == -5);
	pass;
}

test(f32_cvt_u32) {
	simd_f32 from = simd_f32(5.5);
	simd_u32 to_typed = simd_f32_cvt_u32(from);
	simd_u32 to = simd_cvt(from, simd_u32);
	assert(simd_get_lane(to_typed, 0) == 5);
	assert(simd_get_lane(to, 0) == 5);
	pass;
}

test(rbit_i8) {
	assert(simd_get_lane(
		       simd_rbit(simd_i8(
			       0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F,
			       0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F)),
		       0)
	       == (int8_t)0xF0);
	pass;
}

test(rbit_u8) {
	assert(simd_get_lane(
		       simd_rbit(simd_u8(
			       0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F,
			       0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F)),
		       0)
	       == 0xF0);
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

