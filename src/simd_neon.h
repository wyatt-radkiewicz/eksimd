#include <stdint.h>

#define _simdapi static inline __attribute__((always_inline))

// Types
#if __clang__
typedef __attribute__((neon_vector_type(16))) int8_t  simd_i8;
typedef __attribute__((neon_vector_type(16))) uint8_t simd_u8;
typedef __attribute__((neon_vector_type(8))) int16_t  simd_i16;
typedef __attribute__((neon_vector_type(8))) uint16_t simd_u16;
typedef __attribute__((neon_vector_type(4))) int32_t  simd_i32;
typedef __attribute__((neon_vector_type(4))) uint32_t simd_u32;
typedef __attribute__((neon_vector_type(4))) float    simd_f32;
#else
typedef __Int8x16_t   simd_i8;
typedef __Uint8x16_t  simd_u8;
typedef __Int16x8_t   simd_i16;
typedef __Uint16x8_t  simd_u16;
typedef __Int32x4_t   simd_i32;
typedef __Uint32x4_t  simd_u32;
typedef __Float32x4_t simd_f32;
#endif

#define _simd_choose16(                                                        \
	_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,  \
	_name, ...)                                                            \
	_name
#define _simd_choose8(_0, _1, _2, _3, _4, _5, _6, _7, _name, ...) _name
#define _simd_choose4(_0, _1, _2, _3, _name, ...) _name

// Initialization functions
_simdapi simd_i8 simd_i8_dup_n(int8_t val) {
	return (simd_i8){val, val, val, val, val, val, val, val,
			 val, val, val, val, val, val, val, val};
}
_simdapi simd_i8 simd_i8_n(
	int8_t v0, int8_t v1, int8_t v2, int8_t v3, int8_t v4, int8_t v5,
	int8_t v6, int8_t v7, int8_t v8, int8_t v9, int8_t v10, int8_t v11,
	int8_t v12, int8_t v13, int8_t v14, int8_t v15) {
	return (simd_i8){v0, v1, v2,  v3,  v4,	v5,  v6,  v7,
			 v8, v9, v10, v11, v12, v13, v14, v15};
}
#define simd_i8(...)                                                           \
	_simd_choose16(                                                        \
		__VA_ARGS__, simd_i8_n, simd_i8_n, simd_i8_n, simd_i8_n,       \
		simd_i8_n, simd_i8_n, simd_i8_n, simd_i8_n, simd_i8_n,         \
		simd_i8_n, simd_i8_n, simd_i8_n, simd_i8_n, simd_i8_n,         \
		simd_i8_n, simd_i8_dup_n)(__VA_ARGS__)

_simdapi simd_u8 simd_u8_dup_n(uint8_t val) {
	return (simd_u8){val, val, val, val, val, val, val, val,
			 val, val, val, val, val, val, val, val};
}
_simdapi simd_u8 simd_u8_n(
	uint8_t v0, uint8_t v1, uint8_t v2, uint8_t v3, uint8_t v4, uint8_t v5,
	uint8_t v6, uint8_t v7, uint8_t v8, uint8_t v9, uint8_t v10,
	uint8_t v11, uint8_t v12, uint8_t v13, uint8_t v14, uint8_t v15) {
	return (simd_u8){v0, v1, v2,  v3,  v4,	v5,  v6,  v7,
			 v8, v9, v10, v11, v12, v13, v14, v15};
}
#define simd_u8(...)                                                           \
	_simd_choose16(                                                        \
		__VA_ARGS__, simd_u8_n, simd_u8_n, simd_u8_n, simd_u8_n,       \
		simd_u8_n, simd_u8_n, simd_u8_n, simd_u8_n, simd_u8_n,         \
		simd_u8_n, simd_u8_n, simd_u8_n, simd_u8_n, simd_u8_n,         \
		simd_u8_n, simd_u8_dup_n)(__VA_ARGS__)

_simdapi simd_i16 simd_i16_dup_n(int16_t val) {
	return (simd_i16){val, val, val, val, val, val, val, val};
}
_simdapi simd_i16 simd_i16_n(
	int16_t v0, int16_t v1, int16_t v2, int16_t v3, int16_t v4, int16_t v5,
	int16_t v6, int16_t v7) {
	return (simd_i16){v0, v1, v2, v3, v4, v5, v6, v7};
}
#define simd_i16(...)                                                          \
	_simd_choose8(                                                         \
		__VA_ARGS__, simd_i16_n, simd_i16_n, simd_i16_n, simd_i16_n,   \
		simd_i16_n, simd_i16_n, simd_i16_n,                            \
		simd_i16_dup_n)(__VA_ARGS__)

_simdapi simd_u16 simd_u16_dup_n(uint16_t val) {
	return (simd_u16){val, val, val, val, val, val, val, val};
}
_simdapi simd_u16 simd_u16_n(
	uint16_t v0, uint16_t v1, uint16_t v2, uint16_t v3, uint16_t v4,
	uint16_t v5, uint16_t v6, uint16_t v7) {
	return (simd_u16){v0, v1, v2, v3, v4, v5, v6, v7};
}
#define simd_u16(...)                                                          \
	_simd_choose8(                                                         \
		__VA_ARGS__, simd_u16_n, simd_u16_n, simd_u16_n, simd_u16_n,   \
		simd_u16_n, simd_u16_n, simd_u16_n,                            \
		simd_u16_dup_n)(__VA_ARGS__)

_simdapi simd_i32 simd_i32_dup_n(int32_t val) {
	return (simd_i32){val, val, val, val};
}
_simdapi simd_i32 simd_i32_n(int32_t v0, int32_t v1, int32_t v2, int32_t v3) {
	return (simd_i32){v0, v1, v2, v3};
}
#define simd_i32(...)                                                          \
	_simd_choose4(                                                         \
		__VA_ARGS__, simd_i32_n, simd_i32_n, simd_i32_n,               \
		simd_i32_dup_n)(__VA_ARGS__)

_simdapi simd_u32 simd_u32_dup_n(uint32_t val) {
	return (simd_u32){val, val, val, val};
}
_simdapi simd_u32
simd_u32_n(uint32_t v0, uint32_t v1, uint32_t v2, uint32_t v3) {
	return (simd_u32){v0, v1, v2, v3};
}
#define simd_u32(...)                                                          \
	_simd_choose4(                                                         \
		__VA_ARGS__, simd_u32_n, simd_u32_n, simd_u32_n,               \
		simd_u32_dup_n)(__VA_ARGS__)

_simdapi simd_f32 simd_f32_dup_n(float val) {
	return (simd_f32){val, val, val, val};
}
_simdapi simd_f32 simd_f32_n(float v0, float v1, float v2, float v3) {
	return (simd_f32){v0, v1, v2, v3};
}
#define simd_f32(...)                                                          \
	_simd_choose4(                                                         \
		__VA_ARGS__, simd_f32_n, simd_f32_n, simd_f32_n,               \
		simd_f32_dup_n)(__VA_ARGS__)

// Getting and setting specific lanes
#ifdef __clang__
# define _simd_lane_cast_type(_simd)                                           \
	 (typeof(_Generic(                                                     \
		 _simd,                                                        \
			 simd_i8: simd_i8(0),                                  \
			 simd_u8: simd_i8(0),                                  \
			 simd_i16: simd_i16(0),                                \
			 simd_u16: simd_i16(0),                                \
			 simd_i32: simd_i32(0),                                \
			 simd_u32: simd_i32(0),                                \
			 simd_f32: simd_f32(0))))
# define simd_i8_get_lane(_simd, _lane)                                        \
	 (int8_t)__builtin_neon_vgetq_lane_i8((simd_i8)_simd, _lane)
# define simd_u8_get_lane(_simd, _lane)                                        \
	 (uint8_t)__builtin_neon_vgetq_lane_i8((simd_u8)_simd, _lane)
# define simd_i16_get_lane(_simd, _lane)                                       \
	 (int16_t)__builtin_neon_vgetq_lane_i16((simd_i16)_simd, _lane)
# define simd_u16_get_lane(_simd, _lane)                                       \
	 (uint16_t)__builtin_neon_vgetq_lane_i16((simd_u16)_simd, _lane)
# define simd_i32_get_lane(_simd, _lane)                                       \
	 (int32_t)__builtin_neon_vgetq_lane_i32((simd_i32)_simd, _lane)
# define simd_u32_get_lane(_simd, _lane)                                       \
	 (uint32_t)__builtin_neon_vgetq_lane_i32((simd_u32)_simd, _lane)
# define simd_f32_get_lane(_simd, _lane)                                       \
	 (float)__builtin_neon_vgetq_lane_f32((simd_f32)_simd, _lane)
# define simd_get_lane(_simd, _lane)                                           \
	 (_simd_lanetype(_simd) _Generic(                                      \
		 _simd,                                                        \
		  simd_i8: __builtin_neon_vgetq_lane_i8,                       \
		  simd_u8: __builtin_neon_vgetq_lane_i8,                       \
		  simd_i16: __builtin_neon_vgetq_lane_i16,                     \
		  simd_u16: __builtin_neon_vgetq_lane_i16,                     \
		  simd_i32: __builtin_neon_vgetq_lane_i32,                     \
		  simd_u32: __builtin_neon_vgetq_lane_i32,                     \
		  simd_f32: __builtin_neon_vgetq_lane_f32)(                    \
		 _simd_lane_cast_type(_simd) _simd, _lane))

# define simd_i8_set_lane(_val, _simd, _lane)                                  \
	 (simd_i8) __builtin_neon_vsetq_lane_i8(_val, (simd_i8)_simd, _lane)
# define simd_u8_set_lane(_val, _simd, _lane)                                  \
	 (simd_u8) __builtin_neon_vsetq_lane_i8(_val, (simd_u8)_simd, _lane)
# define simd_i16_set_lane(_val, _simd, _lane)                                 \
	 (simd_i16) __builtin_neon_vsetq_lane_i16(_val, (simd_i16)_simd, _lane)
# define simd_u16_set_lane(_val, _simd, _lane)                                 \
	 (simd_u16) __builtin_neon_vsetq_lane_i16(_val, (simd_u16)_simd, _lane)
# define simd_i32_set_lane(_val, _simd, _lane)                                 \
	 (simd_i32) __builtin_neon_vsetq_lane_i32(_val, (simd_i32)_simd, _lane)
# define simd_u32_set_lane(_val, _simd, _lane)                                 \
	 (simd_u32) __builtin_neon_vsetq_lane_i32(_val, (simd_u32)_simd, _lane)
# define simd_f32_set_lane(_val, _simd, _lane)                                 \
	 (simd_f32) __builtin_neon_vsetq_lane_f32(_val, (simd_f32)_simd, _lane)
# define simd_set_lane(_val, _simd, _lane)                                     \
	 ((typeof(_simd))_Generic(                                      \
		 _simd,                                                        \
		  simd_i8: __builtin_neon_vsetq_lane_i8,                       \
		  simd_u8: __builtin_neon_vsetq_lane_i8,                       \
		  simd_i16: __builtin_neon_vsetq_lane_i16,                     \
		  simd_u16: __builtin_neon_vsetq_lane_i16,                     \
		  simd_i32: __builtin_neon_vsetq_lane_i32,                     \
		  simd_u32: __builtin_neon_vsetq_lane_i32,                     \
		  simd_f32: __builtin_neon_vsetq_lane_f32)(                    \
		 _val, _simd_lane_cast_type(_simd) _simd, _lane))
#else
# define __simd_num_lanes(__v) (sizeof(__v) / sizeof(__v[0]))
# define __simd_lane_check(__vec, __idx)                                       \
	 __builtin_aarch64_im_lane_boundsi(                                    \
		 sizeof(__vec), sizeof(__vec[0]), __idx)
# define __simd_get_lane_any(__vec, __index)                                   \
	 __extension__({                                                       \
	  __simd_lane_check(__vec, __index);                                   \
	  __vec[__index];                                                      \
	 })
# define __simd_set_lane_any(__elem, __vec, __index)                           \
	 __extension__({                                                       \
	  __simd_lane_check(__vec, __index);                                   \
	  __vec[__index] = __elem;                                             \
	  __vec;                                                               \
	 })
# define simd_i8_get_lane(_simd, _lane) __simd_get_lane_any(_simd, _lane)
# define simd_u8_get_lane(_simd, _lane) __simd_get_lane_any(_simd, _lane)
# define simd_i16_get_lane(_simd, _lane) __simd_get_lane_any(_simd, _lane)
# define simd_u16_get_lane(_simd, _lane) __simd_get_lane_any(_simd, _lane)
# define simd_i32_get_lane(_simd, _lane) __simd_get_lane_any(_simd, _lane)
# define simd_u32_get_lane(_simd, _lane) __simd_get_lane_any(_simd, _lane)
# define simd_f32_get_lane(_simd, _lane) __simd_get_lane_any(_simd, _lane)
# define simd_get_lane(_simd, _lane) __simd_get_lane_any(_simd, _lane)

# define simd_i8_set_lane(_val, _simd, _lane)                                  \
	 __simd_set_lane_any(_val, _simd, _lane)
# define simd_u8_set_lane(_val, _simd, _lane)                                  \
	 __simd_set_lane_any(_val, _simd, _lane)
# define simd_i16_set_lane(_val, _simd, _lane)                                  \
	 __simd_set_lane_any(_val, _simd, _lane)
# define simd_u16_set_lane(_val, _simd, _lane)                                  \
	 __simd_set_lane_any(_val, _simd, _lane)
# define simd_i32_set_lane(_val, _simd, _lane)                                  \
	 __simd_set_lane_any(_val, _simd, _lane)
# define simd_u32_set_lane(_val, _simd, _lane)                                  \
	 __simd_set_lane_any(_val, _simd, _lane)
# define simd_f32_set_lane(_val, _simd, _lane)                                  \
	 __simd_set_lane_any(_val, _simd, _lane)
# define simd_set_lane(_val, _simd, _lane) __simd_set_lane_any(_val, _simd, _lane)
#endif
