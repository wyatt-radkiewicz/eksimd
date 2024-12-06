#pragma once
#include <stdint.h>

#define simdapi static inline __attribute__((always_inline))
#define simdse(...) __extension__({ __VA_ARGS__; })

#if __aarch64__ // NEON
# if __clang__
typedef __attribute__((neon_vector_type(16))) int8_t  simd_i8;
typedef __attribute__((neon_vector_type(16))) uint8_t simd_u8;
typedef __attribute__((neon_vector_type(8))) int16_t  simd_i16;
typedef __attribute__((neon_vector_type(8))) uint16_t simd_u16;
typedef __attribute__((neon_vector_type(4))) int32_t  simd_i32;
typedef __attribute__((neon_vector_type(4))) uint32_t simd_u32;
typedef __attribute__((neon_vector_type(2))) int64_t  simd_i64;
typedef __attribute__((neon_vector_type(2))) uint64_t simd_u64;
typedef __attribute__((neon_vector_type(4))) float    simd_f32;
typedef __attribute__((neon_vector_type(2))) double   simd_f64;
# elif __GNUC__
#  error not implemented yet
# endif // __clang__ else __GNUC__

# if defined(__clang__) || defined(__GNUC__)
#  define _simd_n16_choose(                                                  \
	    _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14,   \
	    _15, _name, ...)                                                   \
	    _name
#  define _simd_n8_choose(_0, _1, _2, _3, _4, _5, _6, _7, _name, ...) _name
  #  define _simd_n4_choose(_0, _1, _2, _3, _name, ...) _name
  #  define _simd_n2_choose(_0, _1, _name, ...) _name

simdapi simd_i8 simd_dup_n_i8(int8_t n) {
	return (simd_i8){n, n, n, n, n, n, n, n, n, n, n, n, n, n, n, n};
}
simdapi simd_i8 simd_n_i8(
	int8_t n0, int8_t n1, int8_t n2, int8_t n3, int8_t n4, int8_t n5,
	int8_t n6, int8_t n7, int8_t n8, int8_t n9, int8_t n10, int8_t n11,
	int8_t n12, int8_t n13, int8_t n14, int8_t n15) {
	return (simd_i8){n0, n1, n2,  n3,  n4,	n5,  n6,  n7,
			 n8, n9, n10, n11, n12, n13, n14, n15};
}
#  define simd_i8(...)                                                         \
	  _simd_n16_choose(                                                    \
		  __VA_ARGS__, simd_n_i8, simd_n_i8, simd_n_i8, simd_n_i8,     \
		  simd_n_i8, simd_n_i8, simd_n_i8, simd_n_i8, simd_n_i8,       \
		  simd_n_i8, simd_n_i8, simd_n_i8, simd_n_i8, simd_n_i8,       \
		  simd_n_i8, simd_dup_n_i8)(__VA_ARGS__)

simdapi simd_u8 simd_dup_n_u8(int8_t n) {
	return (simd_u8){n, n, n, n, n, n, n, n, n, n, n, n, n, n, n, n};
}
simdapi simd_u8 simd_n_u8(
	uint8_t n0, uint8_t n1, uint8_t n2, uint8_t n3, uint8_t n4, uint8_t n5,
	uint8_t n6, uint8_t n7, uint8_t n8, uint8_t n9, uint8_t n10,
	uint8_t n11, uint8_t n12, uint8_t n13, uint8_t n14, uint8_t n15) {
	return (simd_u8){n0, n1, n2,  n3,  n4,	n5,  n6,  n7,
			 n8, n9, n10, n11, n12, n13, n14, n15};
}
#  define simd_u8(...)                                                         \
	  _simd_n16_choose(                                                    \
		  __VA_ARGS__, simd_n_u8, simd_n_u8, simd_n_u8, simd_n_u8,     \
		  simd_n_u8, simd_n_u8, simd_n_u8, simd_n_u8, simd_n_u8,       \
		  simd_n_u8, simd_n_u8, simd_n_u8, simd_n_u8, simd_n_u8,       \
		  simd_n_u8, simd_dup_n_u8)(__VA_ARGS__)

simdapi simd_i16 simd_dup_n_i16(int16_t n) {
	return (simd_i16){n, n, n, n, n, n, n, n};
}
simdapi simd_i16 simd_n_i16(
	int16_t n0, int16_t n1, int16_t n2, int16_t n3, int16_t n4, int16_t n5,
	int16_t n6, int16_t n7) {
	return (simd_i16){n0, n1, n2, n3, n4, n5, n6, n7};
}
#  define simd_i16(...)                                                        \
	  _simd_n8_choose(                                                     \
		  __VA_ARGS__, simd_n_i16, simd_n_i16, simd_n_i16, simd_n_i16, \
		  simd_n_i16, simd_n_i16, simd_n_i16,                          \
		  simd_dup_n_i16)(__VA_ARGS__)

simdapi simd_u16 simd_dup_n_u16(uint16_t n) {
	return (simd_u16){n, n, n, n, n, n, n, n};
}
simdapi simd_u16 simd_n_u16(
	uint16_t n0, uint16_t n1, uint16_t n2, uint16_t n3, uint16_t n4,
	uint16_t n5, uint16_t n6, uint16_t n7) {
	return (simd_u16){n0, n1, n2, n3, n4, n5, n6, n7};
}
#  define simd_u16(...)                                                        \
	  _simd_n8_choose(                                                     \
		  __VA_ARGS__, simd_n_u16, simd_n_u16, simd_n_u16, simd_n_u16, \
		  simd_n_u16, simd_n_u16, simd_n_u16,                          \
		  simd_dup_n_u16)(__VA_ARGS__)

simdapi simd_i32 simd_dup_n_i32(int32_t n) { return (simd_i32){n, n, n, n}; }
simdapi simd_i32 simd_n_i32(int32_t n0, int32_t n1, int32_t n2, int32_t n3) {
	return (simd_i32){n0, n1, n2, n3};
}
#  define simd_i32(...)                                                        \
	  _simd_n4_choose(                                                     \
		  __VA_ARGS__, simd_n_i32, simd_n_i32, simd_n_i32,             \
		  simd_dup_n_i32)(__VA_ARGS__)

simdapi simd_u32 simd_dup_n_u32(uint32_t n) { return (simd_u32){n, n, n, n}; }
simdapi simd_u32 simd_n_u32(uint32_t n0, uint32_t n1, uint32_t n2, uint32_t n3) {
	return (simd_u32){n0, n1, n2, n3};
}
#  define simd_u32(...)                                                        \
	  _simd_n4_choose(                                                     \
		  __VA_ARGS__, simd_n_u32, simd_n_u32, simd_n_u32,             \
		  simd_dup_n_u32)(__VA_ARGS__)

simdapi simd_i64 simd_dup_n_i64(int64_t n) { return (simd_i64){n, n}; }
simdapi simd_i64 simd_n_i64(int64_t n0, int64_t n1) {
	return (simd_i64){n0, n1};
}
#  define simd_i64(...)                                                        \
	  _simd_n2_choose(__VA_ARGS__, simd_n_i64, simd_dup_n_i64)(__VA_ARGS__)

simdapi simd_u64 simd_dup_n_u64(uint64_t n) { return (simd_u64){n, n}; }
simdapi simd_u64 simd_n_u64(uint64_t n0, uint64_t n1) {
	return (simd_u64){n0, n1};
}
#  define simd_u64(...)                                                        \
	  _simd_n2_choose(__VA_ARGS__, simd_n_u64, simd_dup_n_u64)(__VA_ARGS__)

simdapi simd_f32 simd_dup_n_f32(float n) { return (simd_f32){n, n, n, n}; }
simdapi simd_f32 simd_n_f32(float n0, float n1, float n2, float n3) {
	return (simd_f32){n0, n1, n2, n3};
}
#  define simd_f32(...)                                                        \
	  _simd_n4_choose(                                                     \
		  __VA_ARGS__, simd_n_f32, simd_n_f32, simd_n_f32,             \
		  simd_dup_n_f32)(__VA_ARGS__)

simdapi simd_f64 simd_dup_n_f64(double n) { return (simd_f64){n, n}; }
simdapi simd_f64 simd_n_f64(double n0, double n1) { return (simd_f64){n0, n1}; }
#  define simd_f64(...)                                                        \
	  _simd_n2_choose(__VA_ARGS__, simd_n_f64, simd_dup_n_f64)(__VA_ARGS__)

#  define _simd_lanetype(_simd)                                                \
	  (typeof(_Generic(                                                    \
		  _simd,                                                       \
			  simd_i8: (int8_t)0,                                  \
			  simd_u8: (uint8_t)0,                                 \
			  simd_i16: (int16_t)0,                                \
			  simd_u16: (uint16_t)0,                               \
			  simd_i32: (int32_t)0,                                \
			  simd_u32: (uint32_t)0,                               \
			  simd_i64: (int64_t)0,                                \
			  simd_u64: (uint64_t)0,                               \
			  simd_f32: (float)0,                                  \
			  simd_f64: (double)0)))
# endif // __clang__ || __GNUC__

# if __clang__
#  define simd_getlane_i8(_val, _lane)                                         \
	  simdse((int8_t)__builtin_neon_vgetq_lane_i8(_val, _lane))
#  define simd_getlane_u8(_val, _lane)                                         \
	  simdse((uint8_t)__builtin_neon_vgetq_lane_i8((simd_i8)_val, _lane))
#  define simd_getlane_i16(_val, _lane)                                        \
	  simdse((int16_t)__builtin_neon_vgetq_lane_i16(_val, _lane))
#  define simd_getlane_u16(_val, _lane)                                        \
	  simdse((uint16_t)__builtin_neon_vgetq_lane_i16((simd_i16)_val, _lane))
#  define simd_getlane_i32(_val, _lane)                                        \
	  simdse((int32_t)__builtin_neon_vgetq_lane_i32(_val, _lane))
#  define simd_getlane_u32(_val, _lane)                                        \
	  simdse((uint32_t)__builtin_neon_vgetq_lane_i32((simd_i32)_val, _lane))
#  define simd_getlane_i64(_val, _lane)                                        \
	  simdse((int64_t)__builtin_neon_vgetq_lane_i64(_val, _lane))
#  define simd_getlane_u64(_val, _lane)                                        \
	  simdse((uint64_t)__builtin_neon_vgetq_lane_i64((simd_i64)_val, _lane))
#  define simd_getlane_f32(_val, _lane)                                        \
	  simdse((float)__builtin_neon_vgetq_lane_f32(_val, _lane))
#  define simd_getlane_f64(_val, _lane)                                        \
	  simdse((double)__builtin_neon_vgetq_lane_f64(_val, _lane))
#  define simd_getlane(_val, _lane)                                            \
	  simdse(_simd_lanetype(_val)(                                         \
		  _Generic(                                                    \
			  _val,                                                \
			  simd_i8: __builtin_neon_vgetq_lane_i8,               \
			  simd_u8: __builtin_neon_vgetq_lane_i8,               \
			  simd_i16: __builtin_neon_vgetq_lane_i16,             \
			  simd_u16: __builtin_neon_vgetq_lane_i16,             \
			  simd_i32: __builtin_neon_vgetq_lane_i32,             \
			  simd_u32: __builtin_neon_vgetq_lane_i32,             \
			  simd_i64: __builtin_neon_vgetq_lane_i64,             \
			  simd_u64: __builtin_neon_vgetq_lane_i64,             \
			  simd_f32: __builtin_neon_vgetq_lane_f32,             \
			  simd_f64: __builtin_neon_vgetq_lane_f64)(            \
			  _val, _lane)))
# elif __GNUC__

# endif // __clang__ else __GNUC__

#endif	// __aarch64__
