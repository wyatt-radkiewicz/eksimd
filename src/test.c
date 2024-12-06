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
