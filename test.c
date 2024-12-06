#include "test.h"
#include "simd.h"
#include <tgmath.h>

test(manipulation, init) {
	simd_i8 one_i8 = simd_i8(0);
	simd_i8 all_i8 =
		simd_i8(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
	one_i8 = simd_dup_n_i8(0);
	one_i8 =
		simd_n_i8(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);

	simd_u8 one_u8 = simd_u8(0);
	simd_u8 all_u8 =
		simd_u8(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
	one_u8 = simd_dup_n_u8(0);
	one_u8 =
		simd_n_u8(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);

	simd_i16 one_i16 = simd_i16(0);
	simd_i16 all_i16 = simd_i16(0, 1, 2, 3, 4, 5, 6, 7);
	one_i16 = simd_dup_n_i16(0);
	one_i16 = simd_n_i16(0, 1, 2, 3, 4, 5, 6, 7);

	simd_u16 one_u16 = simd_u16(0);
	simd_u16 all_u16 = simd_u16(0, 1, 2, 3, 4, 5, 6, 7);
	one_u16 = simd_dup_n_u16(0);
	one_u16 = simd_n_u16(0, 1, 2, 3, 4, 5, 6, 7);

	simd_i32 one_i32 = simd_i32(0);
	simd_i32 all_i32 = simd_i32(0, 1, 2, 3);
	one_i32 = simd_dup_n_i32(0);
	one_i32 = simd_n_i32(0, 1, 2, 3);

	simd_u32 one_u32 = simd_u32(0);
	simd_u32 all_u32 = simd_u32(0, 1, 2, 3);
	one_u32 = simd_dup_n_u32(0);
	one_u32 = simd_n_u32(0, 1, 2, 3);

	simd_i64 one_i64 = simd_i64(0);
	simd_i64 all_i64 = simd_i64(0, 1);
	one_i64 = simd_dup_n_i64(0);
	one_i64 = simd_n_i64(0, 1);

	simd_u64 one_u64 = simd_u64(0);
	simd_u64 all_u64 = simd_u64(0, 1);
	one_u64 = simd_dup_n_u64(0);
	one_u64 = simd_n_u64(0, 1);

	simd_f32 one_f32 = simd_f32(0);
	simd_f32 all_f32 = simd_f32(0, 1, 2, 3);
	one_f32 = simd_dup_n_f32(0);
	one_f32 = simd_n_f32(0, 1, 2, 3);

	simd_f64 one_f64 = simd_f64(0);
	simd_f64 all_f64 = simd_f64(0, 1);
	one_f64 = simd_dup_n_f64(0);
	one_f64 = simd_n_f64(0, 1);
	pass;
}
test(manipulation, get_lane) {
	if (simd_getlane_i8(
		    simd_i8(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
			    15),
		    5)
	    != 5)
		fail;
	if (simd_getlane(
		    simd_i8(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
			    15),
		    5)
	    != 5)
		fail;
	if (simd_getlane_u8(
		    simd_u8(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
			    15),
		    5)
	    != 5)
		fail;
	if (simd_getlane(
		    simd_u8(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
			    15),
		    5)
	    != 5)
		fail;

	if (simd_getlane_i16(simd_i16(0, 1, 2, 3, 4, 5, 6, 7), 5) != 5) fail;
	if (simd_getlane(simd_i16(0, 1, 2, 3, 4, 5, 6, 7), 5) != 5) fail;
	if (simd_getlane_u16(simd_u16(0, 1, 2, 3, 4, 5, 6, 7), 5) != 5) fail;
	if (simd_getlane(simd_u16(0, 1, 2, 3, 4, 5, 6, 7), 5) != 5) fail;

	if (simd_getlane_i32(simd_i32(0, 1, 2, 3), 2) != 2) fail;
	if (simd_getlane(simd_i32(0, 1, 2, 3), 2) != 2) fail;
	if (simd_getlane_u32(simd_u32(0, 1, 2, 3), 2) != 2) fail;
	if (simd_getlane(simd_u32(0, 1, 2, 3), 2) != 2) fail;

	if (simd_getlane_i64(simd_i64(0, 1), 1) != 1) fail;
	if (simd_getlane(simd_i64(0, 1), 1) != 1) fail;
	if (simd_getlane_u64(simd_u64(0, 1), 1) != 1) fail;
	if (simd_getlane(simd_u64(0, 1), 1) != 1) fail;

	if (simd_getlane_f32(simd_f32(0, 1, 2, 3), 2) != 2) fail;
	if (simd_getlane(simd_f32(0, 1, 2, 3), 2) != 2) fail;
	if (simd_getlane_f64(simd_f64(0, 1), 1) != 1) fail;
	if (simd_getlane(simd_f64(0, 1), 1) != 1) fail;
	pass;
}
