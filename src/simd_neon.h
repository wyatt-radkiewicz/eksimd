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

// Gets the number of lanes in a simd object
#define simd_num_lanes(_simd)                                                  \
	_Generic(                                                              \
		(typeof(_simd)){0},                                            \
		simd_i8: 16,                                                   \
		simd_u8: 16,                                                   \
		simd_i16: 8,                                                   \
		simd_u16: 8,                                                   \
		simd_i32: 4,                                                   \
		simd_u32: 4,                                                   \
		simd_f32: 4)

#define _simd_choose16(                                                        \
	_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15,  \
	_name, ...)                                                            \
	_name
#define _simd_choose8(_0, _1, _2, _3, _4, _5, _6, _7, _name, ...) _name
#define _simd_choose4(_0, _1, _2, _3, _name, ...) _name

#define _simd_lane_cast_type(_simd)                                            \
	(typeof(_Generic(                                                      \
		_simd,                                                         \
			simd_i8: simd_i8(0),                                   \
			simd_u8: simd_i8(0),                                   \
			simd_i16: simd_i16(0),                                 \
			simd_u16: simd_i16(0),                                 \
			simd_i32: simd_i32(0),                                 \
			simd_u32: simd_i32(0),                                 \
			simd_f32: simd_f32(0))))
#define _simd_lane_cast_type2(_simd)                                           \
	typeof(_Generic(                                                       \
		_simd,                                                         \
		       simd_i8: simd_u8(0),                                    \
		       simd_u8: simd_u8(0),                                    \
		       simd_i16: simd_u16(0),                                  \
		       simd_u16: simd_u16(0),                                  \
		       simd_i32: simd_u32(0),                                  \
		       simd_u32: simd_u32(0),                                  \
		       simd_f32: simd_u32(0)))
#define _simd_index_type(_simd)                                                \
	(typeof(_Generic(                                                      \
		_simd,                                                         \
			simd_i8: simd_u8(0),                                   \
			simd_u8: simd_u8(0),                                   \
			simd_i16: simd_u16(0),                                 \
			simd_u16: simd_u16(0),                                 \
			simd_i32: simd_u32(0),                                 \
			simd_u32: simd_u32(0),                                 \
			simd_f32: simd_u32(0))))

// Initialization functions
_simdapi simd_i8 simd_init_n_i8(int8_t val) {
	return (simd_i8){val, val, val, val, val, val, val, val,
			 val, val, val, val, val, val, val, val};
}
_simdapi simd_i8 simd_init_i8(
	int8_t v0, int8_t v1, int8_t v2, int8_t v3, int8_t v4, int8_t v5,
	int8_t v6, int8_t v7, int8_t v8, int8_t v9, int8_t v10, int8_t v11,
	int8_t v12, int8_t v13, int8_t v14, int8_t v15) {
	return (simd_i8){v0, v1, v2,  v3,  v4,	v5,  v6,  v7,
			 v8, v9, v10, v11, v12, v13, v14, v15};
}
#define simd_i8(...)                                                           \
	_simd_choose16(                                                        \
		__VA_ARGS__, simd_init_i8, simd_init_i8, simd_init_i8,         \
		simd_init_i8, simd_init_i8, simd_init_i8, simd_init_i8,        \
		simd_init_i8, simd_init_i8, simd_init_i8, simd_init_i8,        \
		simd_init_i8, simd_init_i8, simd_init_i8, simd_init_i8,        \
		simd_init_n_i8)(__VA_ARGS__)

_simdapi simd_u8 simd_init_n_u8(uint8_t val) {
	return (simd_u8){val, val, val, val, val, val, val, val,
			 val, val, val, val, val, val, val, val};
}
_simdapi simd_u8 simd_init_u8(
	uint8_t v0, uint8_t v1, uint8_t v2, uint8_t v3, uint8_t v4, uint8_t v5,
	uint8_t v6, uint8_t v7, uint8_t v8, uint8_t v9, uint8_t v10,
	uint8_t v11, uint8_t v12, uint8_t v13, uint8_t v14, uint8_t v15) {
	return (simd_u8){v0, v1, v2,  v3,  v4,	v5,  v6,  v7,
			 v8, v9, v10, v11, v12, v13, v14, v15};
}
#define simd_u8(...)                                                           \
	_simd_choose16(                                                        \
		__VA_ARGS__, simd_init_u8, simd_init_u8, simd_init_u8,         \
		simd_init_u8, simd_init_u8, simd_init_u8, simd_init_u8,        \
		simd_init_u8, simd_init_u8, simd_init_u8, simd_init_u8,        \
		simd_init_u8, simd_init_u8, simd_init_u8, simd_init_u8,        \
		simd_init_n_u8)(__VA_ARGS__)

_simdapi simd_i16 simd_init_n_i16(int16_t val) {
	return (simd_i16){val, val, val, val, val, val, val, val};
}
_simdapi simd_i16 simd_init_i16(
	int16_t v0, int16_t v1, int16_t v2, int16_t v3, int16_t v4, int16_t v5,
	int16_t v6, int16_t v7) {
	return (simd_i16){v0, v1, v2, v3, v4, v5, v6, v7};
}
#define simd_i16(...)                                                          \
	_simd_choose8(                                                         \
		__VA_ARGS__, simd_init_i16, simd_init_i16, simd_init_i16,      \
		simd_init_i16, simd_init_i16, simd_init_i16, simd_init_i16,    \
		simd_init_n_i16)(__VA_ARGS__)

_simdapi simd_u16 simd_init_n_u16(uint16_t val) {
	return (simd_u16){val, val, val, val, val, val, val, val};
}
_simdapi simd_u16 simd_init_u16(
	uint16_t v0, uint16_t v1, uint16_t v2, uint16_t v3, uint16_t v4,
	uint16_t v5, uint16_t v6, uint16_t v7) {
	return (simd_u16){v0, v1, v2, v3, v4, v5, v6, v7};
}
#define simd_u16(...)                                                          \
	_simd_choose8(                                                         \
		__VA_ARGS__, simd_init_u16, simd_init_u16, simd_init_u16,      \
		simd_init_u16, simd_init_u16, simd_init_u16, simd_init_u16,    \
		simd_init_n_u16)(__VA_ARGS__)

_simdapi simd_i32 simd_init_n_i32(int32_t val) {
	return (simd_i32){val, val, val, val};
}
_simdapi simd_i32 simd_init_i32(int32_t v0, int32_t v1, int32_t v2, int32_t v3) {
	return (simd_i32){v0, v1, v2, v3};
}
#define simd_i32(...)                                                          \
	_simd_choose4(                                                         \
		__VA_ARGS__, simd_init_i32, simd_init_i32, simd_init_i32,      \
		simd_init_n_i32)(__VA_ARGS__)

_simdapi simd_u32 simd_init_n_u32(uint32_t val) {
	return (simd_u32){val, val, val, val};
}
_simdapi simd_u32
simd_init_u32(uint32_t v0, uint32_t v1, uint32_t v2, uint32_t v3) {
	return (simd_u32){v0, v1, v2, v3};
}
#define simd_u32(...)                                                          \
	_simd_choose4(                                                         \
		__VA_ARGS__, simd_init_u32, simd_init_u32, simd_init_u32,      \
		simd_init_n_u32)(__VA_ARGS__)

_simdapi simd_f32 simd_init_n_f32(float val) {
	return (simd_f32){val, val, val, val};
}
_simdapi simd_f32 simd_init_f32(float v0, float v1, float v2, float v3) {
	return (simd_f32){v0, v1, v2, v3};
}
#define simd_f32(...)                                                          \
	_simd_choose4(                                                         \
		__VA_ARGS__, simd_init_f32, simd_init_f32, simd_init_f32,      \
		simd_init_n_f32)(__VA_ARGS__)

// Getting and setting specific lanes
#ifdef __clang__
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
# define simd_get_lane_i8 simd_get_lane
# define simd_get_lane_u8 simd_get_lane
# define simd_get_lane_i16 simd_get_lane
# define simd_get_lane_u16 simd_get_lane
# define simd_get_lane_i32 simd_get_lane
# define simd_get_lane_u32 simd_get_lane
# define simd_get_lane_f32 simd_get_lane

# define simd_set_lane(_val, _simd, _lane)                                     \
	 ((typeof(_simd))_Generic(                                             \
		 _simd,                                                        \
		  simd_i8: __builtin_neon_vsetq_lane_i8,                       \
		  simd_u8: __builtin_neon_vsetq_lane_i8,                       \
		  simd_i16: __builtin_neon_vsetq_lane_i16,                     \
		  simd_u16: __builtin_neon_vsetq_lane_i16,                     \
		  simd_i32: __builtin_neon_vsetq_lane_i32,                     \
		  simd_u32: __builtin_neon_vsetq_lane_i32,                     \
		  simd_f32: __builtin_neon_vsetq_lane_f32)(                    \
		 _val, _simd_lane_cast_type(_simd) _simd, _lane))
# define simd_set_lane_i8 simd_set_lane
# define simd_set_lane_u8 simd_set_lane
# define simd_set_lane_i16 simd_set_lane
# define simd_set_lane_u16 simd_set_lane
# define simd_set_lane_i32 simd_set_lane
# define simd_set_lane_u32 simd_set_lane
# define simd_set_lane_f32 simd_set_lane
#else
# define __simd_lane_check(__vec, __idx)                                       \
	 __builtin_aarch64_im_lane_boundsi(                                    \
		 sizeof(__vec), sizeof(__vec[0]), __idx)
# define __simd_get_lane_any(__vec, __index)                                   \
	 __extension__({                                                       \
	  __simd_lane_check(__vec, __index);                                   \
	  __vec[__index];                                                      \
	 })
# define __simd_set_lane_any(__val, __simd, __lane)                            \
	 __extension__({                                                       \
	  __simd_lane_check(__simd, __lane);                                   \
	  __simd[__lane] = __val;                                              \
	  __simd;                                                              \
	 })
# define simd_get_lane_i8 __simd_get_lane_any
# define simd_get_lane_u8 __simd_get_lane_any
# define simd_get_lane_i16 __simd_get_lane_any
# define simd_get_lane_u16 __simd_get_lane_any
# define simd_get_lane_i32 __simd_get_lane_any
# define simd_get_lane_u32 __simd_get_lane_any
# define simd_get_lane_f32 __simd_get_lane_any
# define simd_get_lane __simd_get_lane_any

# define simd_set_lane_i8 __simd_set_lane_any
# define simd_set_lane_u8 __simd_set_lane_any
# define simd_set_lane_i16 __simd_set_lane_any
# define simd_set_lane_u16 __simd_set_lane_any
# define simd_set_lane_i32 __simd_set_lane_any
# define simd_set_lane_u32 __simd_set_lane_any
# define simd_set_lane_f32 __simd_set_lane_any
# define simd_set_lane __simd_set_lane_any
#endif

// Casts
_simdapi simd_i8  simd_i8_cvt_i8(simd_i8 val) { return val; }
_simdapi simd_u8  simd_u8_cvt_i8(simd_i8 val) { return (simd_u8)val; }
_simdapi simd_i16 simd_i16_cvt_i16(simd_i16 val) { return val; }
_simdapi simd_u16 simd_u16_cvt_i16(simd_i16 val) { return (simd_u16)val; }
_simdapi simd_i32 simd_i32_cvt_i32(simd_i32 val) { return val; }
_simdapi simd_u32 simd_u32_cvt_i32(simd_i32 val) { return (simd_u32)val; }
_simdapi simd_i8  simd_i8_cvt_u8(simd_u8 val) { return (simd_i8)val; }
_simdapi simd_u8  simd_u8_cvt_u8(simd_u8 val) { return val; }
_simdapi simd_i16 simd_i16_cvt_u16(simd_u16 val) { return (simd_i16)val; }
_simdapi simd_u16 simd_u16_cvt_u16(simd_u16 val) { return val; }
_simdapi simd_i32 simd_i32_cvt_u32(simd_u32 val) { return (simd_i32)val; }
_simdapi simd_u32 simd_u32_cvt_u32(simd_u32 val) { return val; }
_simdapi simd_f32 simd_f32_cvt_f32(simd_f32 val) { return val; }

#if __clang__
_simdapi simd_i32 simd_i32_cvt_f32(simd_f32 val) {
	return __builtin_neon_vcvtq_s32_v((simd_i8)val, 34);
}
_simdapi simd_u32 simd_u32_cvt_f32(simd_f32 val) {
	return __builtin_neon_vcvtq_u32_v((simd_i8)val, 50);
}
_simdapi simd_f32 simd_f32_cvt_i32(simd_i32 val) {
	return __builtin_neon_vcvtq_f32_v((simd_i8)val, 34);
}
_simdapi simd_f32 simd_f32_cvt_u32(simd_u32 val) {
	return __builtin_neon_vcvtq_f32_v((simd_i8)val, 50);
}
#else
_simdapi simd_i32 simd_i32_cvt_f32(simd_f32 val) {
	return __builtin_aarch64_lbtruncv4sfv4si(val);
}
_simdapi simd_u32 simd_u32_cvt_f32(simd_f32 val) {
	return __builtin_aarch64_lbtruncuv4sfv4si_us(val);
}
_simdapi simd_f32 simd_f32_cvt_i32(simd_i32 val) {
	return __builtin_aarch64_floatv4siv4sf(val);
}
_simdapi simd_f32 simd_f32_cvt_u32(simd_u32 val) {
	return __builtin_aarch64_floatunsv4siv4sf((simd_i32)val);
}
#endif // __clang__ else __GNUC__
#define simd_cvt(_toty, _simd)                                                 \
	(_Generic(                                                             \
		_simd,                                                         \
		 simd_i8: _Generic(                                            \
			 (_toty){},                                            \
			 simd_i8: simd_i8_cvt_i8,                              \
			 simd_u8: simd_u8_cvt_i8,                              \
			 simd_i16: NULL,                                       \
			 simd_u16: NULL,                                       \
			 simd_i32: NULL,                                       \
			 simd_u32: NULL,                                       \
			 simd_f32: NULL),                                      \
		 simd_u8: _Generic(                                            \
			 (_toty){},                                            \
			 simd_i8: simd_i8_cvt_u8,                              \
			 simd_u8: simd_u8_cvt_u8,                              \
			 simd_i16: NULL,                                       \
			 simd_u16: NULL,                                       \
			 simd_i32: NULL,                                       \
			 simd_u32: NULL,                                       \
			 simd_f32: NULL),                                      \
		 simd_i16: _Generic(                                           \
			 (_toty){},                                            \
			 simd_i8: NULL,                                        \
			 simd_u8: NULL,                                        \
			 simd_i16: simd_i16_cvt_i16,                           \
			 simd_u16: simd_u16_cvt_i16,                           \
			 simd_i32: NULL,                                       \
			 simd_u32: NULL,                                       \
			 simd_f32: NULL),                                      \
		 simd_u16: _Generic(                                           \
			 (_toty){},                                            \
			 simd_i8: NULL,                                        \
			 simd_u8: NULL,                                        \
			 simd_i16: simd_i16_cvt_u16,                           \
			 simd_u16: simd_u16_cvt_u16,                           \
			 simd_i32: NULL,                                       \
			 simd_u32: NULL,                                       \
			 simd_f32: NULL),                                      \
		 simd_i32: _Generic(                                           \
			 (_toty){},                                            \
			 simd_i8: NULL,                                        \
			 simd_u8: NULL,                                        \
			 simd_i16: NULL,                                       \
			 simd_u16: NULL,                                       \
			 simd_i32: simd_i32_cvt_i32,                           \
			 simd_u32: simd_u32_cvt_i32,                           \
			 simd_f32: simd_f32_cvt_i32),                          \
		 simd_u32: _Generic(                                           \
			 (_toty){},                                            \
			 simd_i8: NULL,                                        \
			 simd_u8: NULL,                                        \
			 simd_i16: NULL,                                       \
			 simd_u16: NULL,                                       \
			 simd_i32: simd_i32_cvt_u32,                           \
			 simd_u32: simd_u32_cvt_u32,                           \
			 simd_f32: simd_f32_cvt_u32),                          \
		 simd_f32: _Generic(                                           \
			 (_toty){},                                            \
			 simd_i8: NULL,                                        \
			 simd_u8: NULL,                                        \
			 simd_i16: NULL,                                       \
			 simd_u16: NULL,                                       \
			 simd_i32: simd_i32_cvt_f32,                           \
			 simd_u32: simd_u32_cvt_f32,                           \
			 simd_f32: simd_f32_cvt_f32))(_simd))

// Reinterpret Cast
#define simd_reinterpret(_toty, _simd) ((_toty)(_simd))

// Shuffle builtin on clang and GCC
#if __clang__
# define _simd_shuffle(_simd0, _simd1, ...)                                    \
	 __builtin_shufflevector(_simd0, _simd1, __VA_ARGS__)
#else
# define _simd_shuffle(_simd0, _simd1, ...)                                    \
	 __builtin_shuffle(                                                    \
		 _simd0, _simd1, _simd_index_type(_simd0){__VA_ARGS__})
#endif

// Reverse vector elements
_simdapi simd_i8 simd_rev_i8(simd_i8 val) {
	return _simd_shuffle(
		val, val, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0);
}
_simdapi simd_u8 simd_rev_u8(simd_u8 val) {
	return _simd_shuffle(
		val, val, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0);
}
_simdapi simd_i16 simd_rev_i16(simd_i16 val) {
	return _simd_shuffle(val, val, 7, 6, 5, 4, 3, 2, 1, 0);
}
_simdapi simd_u16 simd_rev_u16(simd_u16 val) {
	return _simd_shuffle(val, val, 7, 6, 5, 4, 3, 2, 1, 0);
}
_simdapi simd_i32 simd_rev_i32(simd_i32 val) {
	return _simd_shuffle(val, val, 3, 2, 1, 0);
}
_simdapi simd_u32 simd_rev_u32(simd_u32 val) {
	return _simd_shuffle(val, val, 3, 2, 1, 0);
}
_simdapi simd_f32 simd_rev_f32(simd_f32 val) {
	return _simd_shuffle(val, val, 3, 2, 1, 0);
}
#define simd_rev(_simd)                                                        \
	(_Generic(                                                             \
		_simd,                                                         \
		 simd_i8: simd_rev_i8,                                         \
		 simd_u8: simd_rev_u8,                                         \
		 simd_i16: simd_rev_i16,                                       \
		 simd_u16: simd_rev_u16,                                       \
		 simd_i32: simd_rev_i32,                                       \
		 simd_u32: simd_rev_u32,                                       \
		 simd_f32: simd_rev_f32)(_simd))

// Shuffle
#define simd_shuffle_i8(_simd, ...) _simd_shuffle(_simd, _simd, __VA_ARGS__)
#define simd_shuffle_u8(_simd, ...) _simd_shuffle(_simd, _simd, __VA_ARGS__)
#define simd_shuffle_i16(_simd, ...) _simd_shuffle(_simd, _simd, __VA_ARGS__)
#define simd_shuffle_u16(_simd, ...) _simd_shuffle(_simd, _simd, __VA_ARGS__)
#define simd_shuffle_i32(_simd, ...) _simd_shuffle(_simd, _simd, __VA_ARGS__)
#define simd_shuffle_u32(_simd, ...) _simd_shuffle(_simd, _simd, __VA_ARGS__)
#define simd_shuffle_f32(_simd, ...) _simd_shuffle(_simd, _simd, __VA_ARGS__)
#define simd_shuffle(_simd, ...) _simd_shuffle(_simd, _simd, __VA_ARGS__)

// Shift vector elements left
#if __clang__
# define simd_shl_lane(_simd, _lanes)                                          \
	 (_lanes == 0                                                          \
		  ? _simd                                                      \
		  : ((typeof(_simd))__builtin_neon_vextq_v(                    \
			    (typeof(_simd)){0},                                \
			    _simd_lane_cast_type(_simd) _simd,                 \
			    simd_num_lanes(_simd) - _lanes - (_lanes == 0),    \
			    _Generic(                                          \
				    _simd,                                     \
				    simd_i8: 36,                               \
				    simd_u8: 36,                               \
				    simd_i16: 49,                              \
				    simd_u16: 49,                              \
				    simd_i32: 50,                              \
				    simd_u32: 50,                              \
				    simd_f32: 50))))
# define simd_shl_lane_i8 simd_shl_lane
# define simd_shl_lane_u8 simd_shl_lane
# define simd_shl_lane_i16 simd_shl_lane
# define simd_shl_lane_u16 simd_shl_lane
# define simd_shl_lane_i32 simd_shl_lane
# define simd_shl_lane_u32 simd_shl_lane
# define simd_shl_lane_f32 simd_shl_lane
#else
_simdapi simd_i8 simd_shl_lane_i8(simd_i8 val, const int lanes) {
	const int bias = 4 - lanes;
	return _simd_shuffle(
		simd_i8(0), val, bias, bias + 1, bias + 2, bias + 3, bias + 4,
		bias + 5, bias + 6, bias + 7, bias + 8, bias + 9, bias + 10,
		bias + 11, bias + 12, bias + 13, bias + 14, bias + 15);
}
_simdapi simd_u8 simd_shl_lane_u8(simd_u8 val, const int lanes) {
	const int bias = 4 - lanes;
	return _simd_shuffle(
		simd_u8(0), val, bias, bias + 1, bias + 2, bias + 3, bias + 4,
		bias + 5, bias + 6, bias + 7, bias + 8, bias + 9, bias + 10,
		bias + 11, bias + 12, bias + 13, bias + 14, bias + 15);
}
_simdapi simd_i16 simd_shl_lane_i16(simd_i16 val, const int lanes) {
	const int bias = 4 - lanes;
	return _simd_shuffle(
		simd_i16(0), val, bias, bias + 1, bias + 2, bias + 3, bias + 4,
		bias + 5, bias + 6, bias + 7);
}
_simdapi simd_u16 simd_shl_lane_u16(simd_u16 val, const int lanes) {
	const int bias = 4 - lanes;
	return _simd_shuffle(
		simd_u16(0), val, bias, bias + 1, bias + 2, bias + 3, bias + 4,
		bias + 5, bias + 6, bias + 7);
}
_simdapi simd_i32 simd_shl_lane_i32(simd_i32 val, const int lanes) {
	const int bias = 4 - lanes;
	return _simd_shuffle(
		simd_i32(0), val, bias, bias + 1, bias + 2, bias + 3);
}
_simdapi simd_u32 simd_shl_lane_u32(simd_u32 val, const int lanes) {
	const int bias = 4 - lanes;
	return _simd_shuffle(
		simd_u32(0), val, bias, bias + 1, bias + 2, bias + 3);
}
_simdapi simd_f32 simd_shl_lane_f32(simd_f32 val, const int lanes) {
	const int bias = 4 - lanes;
	return _simd_shuffle(
		simd_f32(0), val, bias, bias + 1, bias + 2, bias + 3);
}
# define simd_shl_lane(_simd, _lanes)                                          \
	 (_Generic(                                                            \
		 _simd,                                                        \
		  simd_i8: simd_shl_lane_i8,                                   \
		  simd_u8: simd_shl_lane_u8,                                   \
		  simd_i16: simd_shl_lane_i16,                                 \
		  simd_u16: simd_shl_lane_u16,                                 \
		  simd_i32: simd_shl_lane_i32,                                 \
		  simd_u32: simd_shl_lane_u32,                                 \
		  simd_f32: simd_shl_lane_f32)(_simd, _lanes))
#endif

// Shift vector elements right
#if __clang__
# define simd_shr_lane(_simd, _lanes)                                          \
	 (_lanes == simd_num_lanes(_simd)                                      \
		  ? (typeof(_simd)){0}                                         \
		  : ((typeof(_simd))__builtin_neon_vextq_v(                    \
			    _simd_lane_cast_type(_simd) _simd,                 \
			    (typeof(_simd)){0},                                \
			    _lanes - (_lanes == simd_num_lanes(_simd)),        \
			    _Generic(                                          \
				    _simd,                                     \
				    simd_i8: 36,                               \
				    simd_u8: 36,                               \
				    simd_i16: 49,                              \
				    simd_u16: 49,                              \
				    simd_i32: 50,                              \
				    simd_u32: 50,                              \
				    simd_f32: 50))))
# define simd_shr_lane_i8 simd_shr_lane
# define simd_shr_lane_u8 simd_shr_lane
# define simd_shr_lane_i16 simd_shr_lane
# define simd_shr_lane_u16 simd_shr_lane
# define simd_shr_lane_i32 simd_shr_lane
# define simd_shr_lane_u32 simd_shr_lane
# define simd_shr_lane_f32 simd_shr_lane
#else
_simdapi simd_i8 simd_shr_lane_i8(simd_i8 val, const int lanes) {
	return _simd_shuffle(
		val, simd_i8(0), lanes, lanes + 1, lanes + 2, lanes + 3,
		lanes + 4, lanes + 5, lanes + 6, lanes + 7, lanes + 8,
		lanes + 9, lanes + 10, lanes + 11, lanes + 12, lanes + 13,
		lanes + 14, lanes + 15);
}
_simdapi simd_u8 simd_shr_lane_u8(simd_u8 val, const int lanes) {
	return _simd_shuffle(
		val, simd_u8(0), lanes, lanes + 1, lanes + 2, lanes + 3,
		lanes + 4, lanes + 5, lanes + 6, lanes + 7, lanes + 8,
		lanes + 9, lanes + 10, lanes + 11, lanes + 12, lanes + 13,
		lanes + 14, lanes + 15);
}
_simdapi simd_i16 simd_shr_lane_i16(simd_i16 val, const int lanes) {
	return _simd_shuffle(
		val, simd_i16(0), lanes, lanes + 1, lanes + 2, lanes + 3,
		lanes + 4, lanes + 5, lanes + 6, lanes + 7);
}
_simdapi simd_u16 simd_shr_lane_u16(simd_u16 val, const int lanes) {
	return _simd_shuffle(
		val, simd_u16(0), lanes, lanes + 1, lanes + 2, lanes + 3,
		lanes + 4, lanes + 5, lanes + 6, lanes + 7);
}
_simdapi simd_i32 simd_shr_lane_i32(simd_i32 val, const int lanes) {
	return _simd_shuffle(
		val, simd_i32(0), lanes, lanes + 1, lanes + 2, lanes + 3);
}
_simdapi simd_u32 simd_shr_lane_u32(simd_u32 val, const int lanes) {
	return _simd_shuffle(
		val, simd_u32(0), lanes, lanes + 1, lanes + 2, lanes + 3);
}
_simdapi simd_f32 simd_shr_lane_f32(simd_f32 val, const int lanes) {
	return _simd_shuffle(
		val, simd_f32(0), lanes, lanes + 1, lanes + 2, lanes + 3);
}
# define simd_shr_lane(_simd, _lanes)                                          \
	 (_Generic(                                                            \
		 _simd,                                                        \
		  simd_i8: simd_shr_lane_i8,                                   \
		  simd_u8: simd_shr_lane_u8,                                   \
		  simd_i16: simd_shr_lane_i16,                                 \
		  simd_u16: simd_shr_lane_u16,                                 \
		  simd_i32: simd_shr_lane_i32,                                 \
		  simd_u32: simd_shr_lane_u32,                                 \
		  simd_f32: simd_shr_lane_f32)(_simd, _lanes))
#endif

// Load
#if __clang__
_simdapi simd_i8 simd_ld_i8(const void *ptr) {
	return __builtin_neon_vld1q_v(ptr, 32);
}
_simdapi simd_u8 simd_ld_u8(const void *ptr) {
	return __builtin_neon_vld1q_v(ptr, 48);
}
_simdapi simd_i16 simd_ld_i16(const void *ptr) {
	return __builtin_neon_vld1q_v(ptr, 33);
}
_simdapi simd_u16 simd_ld_u16(const void *ptr) {
	return __builtin_neon_vld1q_v(ptr, 49);
}
_simdapi simd_i32 simd_ld_i32(const void *ptr) {
	return __builtin_neon_vld1q_v(ptr, 34);
}
_simdapi simd_u32 simd_ld_u32(const void *ptr) {
	return __builtin_neon_vld1q_v(ptr, 50);
}
_simdapi simd_f32 simd_ld_f32(const void *ptr) {
	return __builtin_neon_vld1q_v(ptr, 41);
}
#else
_simdapi simd_i8 simd_ld_i8(const void *ptr) {
	return __builtin_aarch64_ld1v16qi(ptr);
}
_simdapi simd_u8 simd_ld_u8(const void *ptr) {
	return __builtin_aarch64_ld1v16qi_us(ptr);
}
_simdapi simd_i16 simd_ld_i16(const void *ptr) {
	return __builtin_aarch64_ld1v8hi(ptr);
}
_simdapi simd_u16 simd_ld_u16(const void *ptr) {
	return __builtin_aarch64_ld1v8hi_us(ptr);
}
_simdapi simd_i32 simd_ld_i32(const void *ptr) {
	return __builtin_aarch64_ld1v4si(ptr);
}
_simdapi simd_u32 simd_ld_u32(const void *ptr) {
	return __builtin_aarch64_ld1v4si_us(ptr);
}
_simdapi simd_f32 simd_ld_f32(const void *ptr) {
	return __builtin_aarch64_ld1v4sf(ptr);
}
#endif

// Store
#if __clang__
_simdapi void simd_st_i8(void *to, simd_i8 val) {
	__builtin_neon_vst1q_v(to, (simd_i8)val, 32);
}
_simdapi void simd_st_u8(void *to, simd_u8 val) {
	__builtin_neon_vst1q_v(to, (simd_i8)val, 48);
}
_simdapi void simd_st_i16(void *to, simd_i16 val) {
	__builtin_neon_vst1q_v(to, (simd_i8)val, 33);
}
_simdapi void simd_st_u16(void *to, simd_u16 val) {
	__builtin_neon_vst1q_v(to, (simd_i8)val, 49);
}
_simdapi void simd_st_i32(void *to, simd_i32 val) {
	__builtin_neon_vst1q_v(to, (simd_i8)val, 34);
}
_simdapi void simd_st_u32(void *to, simd_u32 val) {
	__builtin_neon_vst1q_v(to, (simd_i8)val, 50);
}
_simdapi void simd_st_f32(void *to, simd_f32 val) {
	__builtin_neon_vst1q_v(to, (simd_i8)val, 41);
}
#else
_simdapi void simd_st_i8(void *to, simd_i8 val) {
	__builtin_aarch64_st1v16qi(to, val);
}
_simdapi void simd_st_u8(void *to, simd_u8 val) {
	__builtin_aarch64_st1v16qi_su(to, val);
}
_simdapi void simd_st_i16(void *to, simd_i16 val) {
	__builtin_aarch64_st1v8hi(to, val);
}
_simdapi void simd_st_u16(void *to, simd_u16 val) {
	__builtin_aarch64_st1v8hi_su(to, val);
}
_simdapi void simd_st_i32(void *to, simd_i32 val) {
	__builtin_aarch64_st1v4si(to, val);
}
_simdapi void simd_st_u32(void *to, simd_u32 val) {
	__builtin_aarch64_st1v4si_su(to, val);
}
_simdapi void simd_st_f32(void *to, simd_f32 val) {
	__builtin_aarch64_st1v4sf(to, val);
}
#endif
#define simd_st(_to, _simd)                                                    \
	(_Generic(                                                             \
		_simd,                                                         \
		 simd_i8: simd_st_i8,                                          \
		 simd_u8: simd_st_u8,                                          \
		 simd_i16: simd_st_i16,                                        \
		 simd_u16: simd_st_u16,                                        \
		 simd_i32: simd_st_i32,                                        \
		 simd_u32: simd_st_u32,                                        \
		 simd_f32: simd_st_f32)(_to, _simd))

// Widen
#if __clang__
_simdapi simd_i16 simd_widen_lo_i8(simd_i8 val) {
	return (simd_i16)__builtin_neon_vmovl_v(
		_simd_shuffle(val, val, 0, 1, 2, 3, 4, 5, 6, 7), 33);
}
_simdapi simd_i16 simd_widen_hi_i8(simd_i8 val) {
	return (simd_i16)__builtin_neon_vshll_n_v(
		_simd_shuffle(val, val, 8, 9, 10, 11, 12, 13, 14, 15), 0, 33);
}
_simdapi simd_u16 simd_widen_lo_u8(simd_u8 val) {
	return (simd_i16)__builtin_neon_vmovl_v(
		_simd_shuffle(val, val, 0, 1, 2, 3, 4, 5, 6, 7), 49);
}
_simdapi simd_u16 simd_widen_hi_u8(simd_u8 val) {
	return (simd_i16)__builtin_neon_vshll_n_v(
		_simd_shuffle(val, val, 8, 9, 10, 11, 12, 13, 14, 15), 0, 49);
}
_simdapi simd_i32 simd_widen_lo_i16(simd_i16 val) {
	return (simd_i32)__builtin_neon_vmovl_v(
		_simd_shuffle(val, val, 0, 1, 2, 3), 34);
}
_simdapi simd_i32 simd_widen_hi_i16(simd_i16 val) {
	return (simd_i32)__builtin_neon_vshll_n_v(
		_simd_shuffle(val, val, 4, 5, 6, 7), 0, 34);
}
_simdapi simd_u32 simd_widen_lo_u16(simd_u16 val) {
	return (simd_i32)__builtin_neon_vmovl_v(
		_simd_shuffle(val, val, 0, 1, 2, 3), 50);
}
_simdapi simd_u32 simd_widen_hi_u16(simd_u16 val) {
	return (simd_i32)__builtin_neon_vshll_n_v(
		_simd_shuffle(val, val, 4, 5, 6, 7), 0, 50);
}
#else
_simdapi simd_i16 simd_widen_lo_i8(simd_i8 val) {
	return __builtin_aarch64_sxtlv8hi(__builtin_aarch64_get_lowv16qi(val));
}
_simdapi simd_i16 simd_widen_hi_i8(simd_i8 val) {
	return __builtin_aarch64_vec_unpacks_hi_v16qi(val);
}
_simdapi simd_u16 simd_widen_lo_u8(simd_u8 val) {
	return __builtin_aarch64_uxtlv8hi_uu(
		(__Uint8x8_t)__builtin_aarch64_get_lowv16qi((simd_i8)val));
}
_simdapi simd_u16 simd_widen_hi_u8(simd_u8 val) {
	return __builtin_aarch64_vec_unpacku_hi_v16qi_uu(val);
}
_simdapi simd_i32 simd_widen_lo_i16(simd_i16 val) {
	return __builtin_aarch64_sxtlv4si(__builtin_aarch64_get_lowv8hi(val));
}
_simdapi simd_i32 simd_widen_hi_i16(simd_i16 val) {
	return __builtin_aarch64_vec_unpacks_hi_v8hi(val);
}
_simdapi simd_u32 simd_widen_lo_u16(simd_u16 val) {
	return __builtin_aarch64_uxtlv4si_uu(
		(__Uint16x4_t)__builtin_aarch64_get_lowv8hi((simd_i16)val));
}
_simdapi simd_u32 simd_widen_hi_u16(simd_u16 val) {
	return __builtin_aarch64_vec_unpacku_hi_v8hi_uu(val);
}
#endif
#define simd_widen_lo(_simd)                                                   \
	(_Generic(                                                             \
		_simd,                                                         \
		 simd_i8: simd_widen_lo_i8,                                    \
		 simd_u8: simd_widen_lo_u8,                                    \
		 simd_i16: simd_widen_lo_i16,                                  \
		 simd_u16: simd_widen_lo_u16)(_simd))
#define simd_widen_hi(_simd)                                                   \
	(_Generic(                                                             \
		_simd,                                                         \
		 simd_i8: simd_widen_hi_i8,                                    \
		 simd_u8: simd_widen_hi_u8,                                    \
		 simd_i16: simd_widen_hi_i16,                                  \
		 simd_u16: simd_widen_hi_u16)(_simd))

// Narrow
#if __clang__
_simdapi simd_i8 simd_narrow_lo_i16(simd_i16 val) {
	return _simd_shuffle(
		(__attribute__((neon_vector_type(8))) int8_t)
			__builtin_neon_vmovn_v((simd_i8)val, 0),
		(__attribute__((neon_vector_type(8))) int8_t){0}, 0, 1, 2, 3, 4,
		5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
}
_simdapi simd_i8 simd_narrow_hi_i16(simd_i16 val) {
	return _simd_shuffle(
		(__attribute__((neon_vector_type(8))) int8_t){0},
		(__attribute__((neon_vector_type(8))) int8_t)
			__builtin_neon_vmovn_v((simd_i8)val, 0),
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
}
_simdapi simd_u8 simd_narrow_lo_u16(simd_u16 val) {
	return _simd_shuffle(
		(__attribute__((neon_vector_type(8))) uint8_t)
			__builtin_neon_vmovn_v((simd_i8)val, 16),
		(__attribute__((neon_vector_type(8))) uint8_t){0}, 0, 1, 2, 3,
		4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
}
_simdapi simd_i8 simd_narrow_hi_u16(simd_u16 val) {
	return _simd_shuffle(
		(__attribute__((neon_vector_type(8))) uint8_t){0},
		(__attribute__((neon_vector_type(8))) uint8_t)
			__builtin_neon_vmovn_v((simd_i8)val, 16),
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
}
_simdapi simd_i16 simd_narrow_lo_i32(simd_i32 val) {
	return _simd_shuffle(
		(__attribute__((neon_vector_type(4))) int16_t)
			__builtin_neon_vmovn_v((simd_i8)val, 1),
		(__attribute__((neon_vector_type(4))) int16_t){0}, 0, 1, 2, 3,
		4, 5, 6, 7);
}
_simdapi simd_i16 simd_narrow_hi_i32(simd_i32 val) {
	return _simd_shuffle(
		(__attribute__((neon_vector_type(4))) int16_t){0},
		(__attribute__((neon_vector_type(4))) int16_t)
			__builtin_neon_vmovn_v((simd_i8)val, 1),
		0, 1, 2, 3, 4, 5, 6, 7);
}
_simdapi simd_u16 simd_narrow_lo_u32(simd_u32 val) {
	return _simd_shuffle(
		(__attribute__((neon_vector_type(4))) uint16_t)
			__builtin_neon_vmovn_v((simd_i8)val, 17),
		(__attribute__((neon_vector_type(4))) uint16_t){0}, 0, 1, 2, 3,
		4, 5, 6, 7);
}
_simdapi simd_i16 simd_narrow_hi_u32(simd_u32 val) {
	return _simd_shuffle(
		(__attribute__((neon_vector_type(4))) uint16_t){0},
		(__attribute__((neon_vector_type(4))) uint16_t)
			__builtin_neon_vmovn_v((simd_i8)val, 17),
		0, 1, 2, 3, 4, 5, 6, 7);
}
#else
_simdapi simd_i8 simd_narrow_lo_i16(simd_i16 val) {
	return __builtin_aarch64_combinev8qi(
		__builtin_aarch64_xtnv8hi(val), (__Int8x8_t){0});
}
_simdapi simd_i8 simd_narrow_hi_i16(simd_i16 val) {
	return __builtin_aarch64_combinev8qi(
		(__Int8x8_t){0}, __builtin_aarch64_xtnv8hi(val));
}
_simdapi simd_u8 simd_narrow_lo_u16(simd_u16 val) {
	return __builtin_aarch64_combinev8qi_uuu(
		__builtin_aarch64_xtnv8hi_uu(val), (__Uint8x8_t){0});
}
_simdapi simd_u8 simd_narrow_hi_u16(simd_u16 val) {
	return __builtin_aarch64_combinev8qi_uuu(
		(__Uint8x8_t){0}, __builtin_aarch64_xtnv8hi_uu(val));
}
_simdapi simd_i16 simd_narrow_lo_i32(simd_i32 val) {
	return __builtin_aarch64_combinev4hi(
		__builtin_aarch64_xtnv4si(val), (__Int16x4_t){0});
}
_simdapi simd_i16 simd_narrow_hi_i32(simd_i32 val) {
	return __builtin_aarch64_combinev4hi(
		(__Int16x4_t){0}, __builtin_aarch64_xtnv4si(val));
}
_simdapi simd_u16 simd_narrow_lo_u32(simd_u32 val) {
	return __builtin_aarch64_combinev4hi_uuu(
		__builtin_aarch64_xtnv4si_uu(val), (__Uint16x4_t){0});
}
_simdapi simd_u16 simd_narrow_hi_u32(simd_u32 val) {
	return __builtin_aarch64_combinev4hi_uuu(
		(__Uint16x4_t){0}, __builtin_aarch64_xtnv4si_uu(val));
}
#endif
#define simd_narrow_lo(_simd)                                                  \
	(_Generic(                                                             \
		_simd,                                                         \
		 simd_i16: simd_narrow_lo_i16,                                 \
		 simd_u16: simd_narrow_lo_u16,                                 \
		 simd_i32: simd_narrow_lo_i32,                                 \
		 simd_u32: simd_narrow_lo_u32)(_simd))
#define simd_narrow_hi(_simd)                                                  \
	(_Generic(                                                             \
		_simd,                                                         \
		 simd_i16: simd_narrow_hi_i16,                                 \
		 simd_u16: simd_narrow_hi_u16,                                 \
		 simd_i32: simd_narrow_hi_i32,                                 \
		 simd_u32: simd_narrow_hi_u32)(_simd))

// Addition
#define simd_add(_lhs, _rhs) (_lhs - _rhs)
#define simd_add_i8 simd_add
#define simd_add_u8 simd_add
#define simd_add_i16 simd_add
#define simd_add_u16 simd_add
#define simd_add_i32 simd_add
#define simd_add_u32 simd_add
#define simd_add_f32 simd_add

// Subtract
#define simd_sub(_lhs, _rhs) (_lhs - _rhs)
#define simd_sub_i8 simd_sub
#define simd_sub_u8 simd_sub
#define simd_sub_i16 simd_sub
#define simd_sub_u16 simd_sub
#define simd_sub_i32 simd_sub
#define simd_sub_u32 simd_sub
#define simd_sub_f32 simd_sub

// Multiply
#define simd_mul(_lhs, _rhs) (_lhs * _rhs)
#define simd_mul_i8 simd_mul
#define simd_mul_u8 simd_mul
#define simd_mul_i16 simd_mul
#define simd_mul_u16 simd_mul
#define simd_mul_i32 simd_mul
#define simd_mul_u32 simd_mul
#define simd_mul_f32 simd_mul

// Division
#define simd_div(_lhs, _rhs) (_lhs / _rhs)
#define simd_div_i8 simd_div
#define simd_div_u8 simd_div
#define simd_div_i16 simd_div
#define simd_div_u16 simd_div
#define simd_div_i32 simd_div
#define simd_div_u32 simd_div
#define simd_div_f32 simd_div

// Reciprocal Estimate
#if __clang__
_simdapi simd_f32 simd_recp_f32(simd_f32 val) {
	return (simd_f32)__builtin_neon_vrecpeq_v((simd_i8)val, 41);
}
#else
_simdapi simd_f32 simd_recp_f32(simd_f32 val) {
	return __builtin_aarch64_frecpev4sf(val);
}
#endif
#define simd_recp simd_recp_f32

// Reciprocal Square Root Estimate
#if __clang__
_simdapi simd_f32 simd_sqrt_recp__f32(simd_f32 val) {
	return (simd_f32)__builtin_neon_vrsqrteq_v((simd_i8)val, 41);
}
#else
_simdapi simd_f32 simd_sqrt_recp_f32(simd_f32 val) {
	return __builtin_aarch64_rsqrtev4sf(val);
}
#endif
#define simd_recp_sqrt simd_recp_sqrt_f32

// Absolute
#if __clang__
_simdapi simd_i8 simd_abs_i8(simd_i8 val) {
	return (simd_i8)__builtin_neon_vabsq_v((simd_i8)val, 32);
}
_simdapi simd_i16 simd_abs_i16(simd_i16 val) {
	return (simd_i16)__builtin_neon_vabsq_v((simd_i8)val, 33);
}
_simdapi simd_i32 simd_abs_i32(simd_i32 val) {
	return (simd_i32)__builtin_neon_vabsq_v((simd_i8)val, 34);
}
_simdapi simd_f32 simd_abs_f32(simd_f32 val) {
	return (simd_f32)__builtin_neon_vabsq_v((simd_i8)val, 41);
}
#else
_simdapi simd_i8 simd_abs_i8(simd_i8 val) {
	return __builtin_aarch64_absv16qi(val);
}
_simdapi simd_i16 simd_abs_i16(simd_i16 val) {
	return __builtin_aarch64_absv8hi(val);
}
_simdapi simd_i32 simd_abs_i32(simd_i32 val) {
	return __builtin_aarch64_absv4si(val);
}
_simdapi simd_f32 simd_abs_f32(simd_f32 val) {
	return __builtin_aarch64_absv4sf(val);
}
#endif
#define simd_abs(_simd)                                                        \
	(_Generic(                                                             \
		_simd,                                                         \
		 simd_i8: simd_abs_i8,                                         \
		 simd_i16: simd_abs_i16,                                       \
		 simd_i32: simd_abs_i32,                                       \
		 simd_f32: simd_abs_f32)(_simd))

// Maximum
#if __clang__
_simdapi simd_i8 simd_max_i8(simd_i8 a, simd_i8 b) {
	return (simd_i8)__builtin_neon_vmaxq_v((simd_i8)a, (simd_i8)b, 32);
}
_simdapi simd_u8 simd_max_u8(simd_u8 a, simd_u8 b) {
	return (simd_u8)__builtin_neon_vmaxq_v((simd_i8)a, (simd_i8)b, 48);
}
_simdapi simd_i16 simd_max_i16(simd_i16 a, simd_i16 b) {
	return (simd_i16)__builtin_neon_vmaxq_v((simd_i8)a, (simd_i8)b, 33);
}
_simdapi simd_u16 simd_max_u16(simd_u16 a, simd_u16 b) {
	return (simd_u16)__builtin_neon_vmaxq_v((simd_i8)a, (simd_i8)b, 49);
}
_simdapi simd_i32 simd_max_i32(simd_i32 a, simd_i32 b) {
	return (simd_i32)__builtin_neon_vmaxq_v((simd_i8)a, (simd_i8)b, 34);
}
_simdapi simd_u32 simd_max_u32(simd_u32 a, simd_u32 b) {
	return (simd_u32)__builtin_neon_vmaxq_v((simd_i8)a, (simd_i8)b, 50);
}
_simdapi simd_f32 simd_max_f32(simd_u32 a, simd_u32 b) {
	return (simd_f32)__builtin_neon_vmaxq_v((simd_i8)a, (simd_i8)b, 41);
}
#else
_simdapi simd_i8 simd_max_i8(simd_i8 a, simd_i8 b) {
	return __builtin_aarch64_smaxv16qi(a, b);
}
_simdapi simd_u8 simd_max_u8(simd_u8 a, simd_u8 b) {
	return (simd_u8)__builtin_aarch64_umaxv16qi((simd_i8)a, (simd_i8)b);
}
_simdapi simd_i16 simd_max_i16(simd_i16 a, simd_i16 b) {
	return __builtin_aarch64_smaxv8hi(a, b);
}
_simdapi simd_u16 simd_max_u16(simd_u16 a, simd_u16 b) {
	return (simd_u16)__builtin_aarch64_umaxv8hi((simd_i16)a, (simd_i16)b);
}
_simdapi simd_i32 simd_max_i32(simd_i32 a, simd_i32 b) {
	return __builtin_aarch64_smaxv4si(a, b);
}
_simdapi simd_u32 simd_max_u32(simd_u32 a, simd_u32 b) {
	return (simd_u32)__builtin_aarch64_umaxv4si((simd_i32)a, (simd_i32)b);
}
_simdapi simd_f32 simd_max_f32(simd_f32 a, simd_f32 b) {
	return (simd_f32)__builtin_aarch64_fmax_nanv4sf(a, b);
}
#endif
#define simd_max(_a, _b)                                                       \
	(_Generic(                                                             \
		_a,                                                            \
		 simd_i8: simd_max_i8,                                         \
		 simd_u8: simd_max_u8,                                         \
		 simd_i16: simd_max_i16,                                       \
		 simd_u16: simd_max_u16,                                       \
		 simd_i32: simd_max_i32,                                       \
		 simd_u32: simd_max_u32,                                       \
		 simd_f32: simd_max_f32)(_a, _b))

// Minimum
#if __clang__
_simdapi simd_i8 simd_min_i8(simd_i8 a, simd_i8 b) {
	return (simd_i8)__builtin_neon_vminq_v((simd_i8)a, (simd_i8)b, 32);
}
_simdapi simd_u8 simd_min_u8(simd_u8 a, simd_u8 b) {
	return (simd_u8)__builtin_neon_vminq_v((simd_i8)a, (simd_i8)b, 48);
}
_simdapi simd_i16 simd_min_i16(simd_i16 a, simd_i16 b) {
	return (simd_i16)__builtin_neon_vminq_v((simd_i8)a, (simd_i8)b, 33);
}
_simdapi simd_u16 simd_min_u16(simd_u16 a, simd_u16 b) {
	return (simd_u16)__builtin_neon_vminq_v((simd_i8)a, (simd_i8)b, 49);
}
_simdapi simd_i32 simd_min_i32(simd_i32 a, simd_i32 b) {
	return (simd_i32)__builtin_neon_vminq_v((simd_i8)a, (simd_i8)b, 34);
}
_simdapi simd_u32 simd_min_u32(simd_u32 a, simd_u32 b) {
	return (simd_u32)__builtin_neon_vminq_v((simd_i8)a, (simd_i8)b, 50);
}
_simdapi simd_f32 simd_min_f32(simd_u32 a, simd_u32 b) {
	return (simd_f32)__builtin_neon_vminq_v((simd_i8)a, (simd_i8)b, 41);
}
#else
_simdapi simd_i8 simd_min_i8(simd_i8 a, simd_i8 b) {
	return __builtin_aarch64_sminv16qi(a, b);
}
_simdapi simd_u8 simd_min_u8(simd_u8 a, simd_u8 b) {
	return (simd_u8)__builtin_aarch64_uminv16qi((simd_i8)a, (simd_i8)b);
}
_simdapi simd_i16 simd_min_i16(simd_i16 a, simd_i16 b) {
	return __builtin_aarch64_sminv8hi(a, b);
}
_simdapi simd_u16 simd_min_u16(simd_u16 a, simd_u16 b) {
	return (simd_u16)__builtin_aarch64_uminv8hi((simd_i16)a, (simd_i16)b);
}
_simdapi simd_i32 simd_min_i32(simd_i32 a, simd_i32 b) {
	return __builtin_aarch64_sminv4si(a, b);
}
_simdapi simd_u32 simd_min_u32(simd_u32 a, simd_u32 b) {
	return (simd_u32)__builtin_aarch64_uminv4si((simd_i32)a, (simd_i32)b);
}
_simdapi simd_f32 simd_min_f32(simd_f32 a, simd_f32 b) {
	return (simd_f32)__builtin_aarch64_fmin_nanv4sf(a, b);
}
#endif
#define simd_min(_a, _b)                                                       \
	(_Generic(                                                             \
		_a,                                                            \
		 simd_i8: simd_min_i8,                                         \
		 simd_u8: simd_min_u8,                                         \
		 simd_i16: simd_min_i16,                                       \
		 simd_u16: simd_min_u16,                                       \
		 simd_i32: simd_min_i32,                                       \
		 simd_u32: simd_min_u32,                                       \
		 simd_f32: simd_min_f32)(_a, _b))

// Square Root
#if __clang__
_simdapi simd_f32 simd_rnd_f32(simd_f32 val) {
	return (simd_f32)__builtin_neon_vsqrtq_v((simd_i8)val, 41);
}
#else
_simdapi simd_f32 simd_rnd_f32(simd_f32 val) {
	return __builtin_aarch64_sqrtv4sf(val);
}
#endif
#define simd_rnd simd_rnd_f32

// Pairwise Addition
#if __clang__
_simdapi simd_i8 simd_padd_i8(simd_i8 a, simd_i8 b) {
	return (simd_i8)__builtin_neon_vpaddq_v((simd_i8)a, (simd_i8)b, 32);
}
_simdapi simd_u8 simd_padd_u8(simd_u8 a, simd_u8 b) {
	return (simd_u8)__builtin_neon_vpaddq_v((simd_i8)a, (simd_i8)b, 48);
}
_simdapi simd_i16 simd_padd_i16(simd_i16 a, simd_i16 b) {
	return (simd_i16)__builtin_neon_vpaddq_v((simd_i8)a, (simd_i8)b, 33);
}
_simdapi simd_u16 simd_padd_u16(simd_u16 a, simd_u16 b) {
	return (simd_u16)__builtin_neon_vpaddq_v((simd_i8)a, (simd_i8)b, 49);
}
_simdapi simd_i32 simd_padd_i32(simd_i32 a, simd_i32 b) {
	return (simd_i32)__builtin_neon_vpaddq_v((simd_i8)a, (simd_i8)b, 34);
}
_simdapi simd_u32 simd_padd_u32(simd_u32 a, simd_u32 b) {
	return (simd_u32)__builtin_neon_vpaddq_v((simd_i8)a, (simd_i8)b, 50);
}
_simdapi simd_f32 simd_padd_f32(simd_f32 a, simd_f32 b) {
	return (simd_f32)__builtin_neon_vpaddq_v((simd_i8)a, (simd_i8)b, 41);
}
#else
_simdapi simd_i8 simd_padd_i8(simd_i8 a, simd_i8 b) {
	return __builtin_aarch64_addpv16qi(a, b);
}
_simdapi simd_u8 simd_padd_u8(simd_u8 a, simd_u8 b) {
	return __builtin_aarch64_addpv16qi_uuu(a, b);
}
_simdapi simd_i16 simd_padd_i16(simd_i16 a, simd_i16 b) {
	return __builtin_aarch64_addpv8hi(a, b);
}
_simdapi simd_u16 simd_padd_u16(simd_u16 a, simd_u16 b) {
	return __builtin_aarch64_addpv8hi_uuu(a, b);
}
_simdapi simd_i32 simd_padd_i32(simd_i32 a, simd_i32 b) {
	return __builtin_aarch64_addpv4si(a, b);
}
_simdapi simd_u32 simd_padd_u32(simd_u32 a, simd_u32 b) {
	return __builtin_aarch64_addpv4si_uuu(a, b);
}
_simdapi simd_f32 simd_padd_f32(simd_f32 a, simd_f32 b) {
	return __builtin_aarch64_faddpv4sf(a, b);
}
#endif
#define simd_padd(_a, _b)                                                      \
	(_Generic(                                                             \
		_a,                                                            \
		 simd_i8: simd_padd_i8,                                        \
		 simd_u8: simd_padd_u8,                                        \
		 simd_i16: simd_padd_i16,                                      \
		 simd_u16: simd_padd_u16,                                      \
		 simd_i32: simd_padd_i32,                                      \
		 simd_u32: simd_padd_u32,                                      \
		 simd_f32: simd_padd_f32)(_a, _b))

// Pairwise Addition with Widen
#if __clang__
_simdapi simd_i16 simd_padd_widen_i8(simd_i8 val) {
	return (simd_i16)__builtin_neon_vpaddlq_v(val, 33);
}
_simdapi simd_u16 simd_padd_widen_u8(simd_u8 val) {
	return (simd_u16)__builtin_neon_vpaddlq_v(val, 49);
}
_simdapi simd_i32 simd_padd_widen_i16(simd_i16 val) {
	return (simd_i32)__builtin_neon_vpaddlq_v(val, 34);
}
_simdapi simd_u32 simd_padd_widen_u16(simd_u16 val) {
	return (simd_u32)__builtin_neon_vpaddlq_v(val, 50);
}
#else
_simdapi simd_i16 simd_padd_widen_i8(simd_i8 val) {
	return __builtin_aarch64_saddlpv16qi(val);
}
_simdapi simd_u16 simd_padd_widen_u8(simd_u8 val) {
	return __builtin_aarch64_uaddlpv16qi_uu(val);
}
_simdapi simd_i32 simd_padd_widen_i16(simd_i16 val) {
	return __builtin_aarch64_saddlpv8hi(val);
}
_simdapi simd_u32 simd_padd_widen_u16(simd_u16 val) {
	return __builtin_aarch64_uaddlpv8hi_uu(val);
}
#endif
#define simd_padd_widen(_simd)                                                 \
	(_Generic(                                                             \
		_simd,                                                         \
		 simd_i8: simd_padd_widen_i8,                                  \
		 simd_u8: simd_padd_widen_u8,                                  \
		 simd_i16: simd_padd_widen_i16,                                \
		 simd_u16: simd_padd_widen_u16)(_simd))

// Multiply Addition
#if __clang__
_simdapi simd_i8 simd_mla_i8(simd_i8 acc, simd_i8 mul0, simd_i8 mul1) {
	return acc + mul0 * mul1;
}
_simdapi simd_u8 simd_mla_u8(simd_u8 acc, simd_u8 mul0, simd_u8 mul1) {
	return acc + mul0 * mul1;
}
_simdapi simd_i16 simd_mla_i16(simd_i16 acc, simd_i16 mul0, simd_i16 mul1) {
	return acc + mul0 * mul1;
}
_simdapi simd_u16 simd_mla_u16(simd_u16 acc, simd_u16 mul0, simd_u16 mul1) {
	return acc + mul0 * mul1;
}
_simdapi simd_i32 simd_mla_i32(simd_i32 acc, simd_i32 mul0, simd_i32 mul1) {
	return acc + mul0 * mul1;
}
_simdapi simd_u32 simd_mla_u32(simd_u32 acc, simd_u32 mul0, simd_u32 mul1) {
	return acc + mul0 * mul1;
}
_simdapi simd_f32 simd_mla_f32(simd_f32 acc, simd_f32 mul0, simd_f32 mul1) {
	return acc + mul0 * mul1;
}
#else
_simdapi simd_i8 simd_mla_i8(simd_i8 acc, simd_i8 mul0, simd_i8 mul1) {
	return __builtin_aarch64_mlav16qi(acc, mul0, mul1);
}
_simdapi simd_u8 simd_mla_u8(simd_u8 acc, simd_u8 mul0, simd_u8 mul1) {
	return __builtin_aarch64_mlav16qi_uuuu(acc, mul0, mul1);
}
_simdapi simd_i16 simd_mla_i16(simd_i16 acc, simd_i16 mul0, simd_i16 mul1) {
	return __builtin_aarch64_mlav8hi(acc, mul0, mul1);
}
_simdapi simd_u16 simd_mla_u16(simd_u16 acc, simd_u16 mul0, simd_u16 mul1) {
	return __builtin_aarch64_mlav8hi_uuuu(acc, mul0, mul1);
}
_simdapi simd_i32 simd_mla_i32(simd_i32 acc, simd_i32 mul0, simd_i32 mul1) {
	return __builtin_aarch64_mlav4si(acc, mul0, mul1);
}
_simdapi simd_u32 simd_mla_u32(simd_u32 acc, simd_u32 mul0, simd_u32 mul1) {
	return __builtin_aarch64_mlav4si_uuuu(acc, mul0, mul1);
}
_simdapi simd_f32 simd_mla_f32(simd_f32 acc, simd_f32 mul0, simd_f32 mul1) {
	return __builtin_aarch64_float_mlav4sf(acc, mul0, mul1);
}
#endif
#define simd_mla(_acc, _mul0, _mul1)                                           \
	(_Generic(                                                             \
		_acc,                                                          \
		 simd_i8: simd_mla_i8,                                         \
		 simd_u8: simd_mla_u8,                                         \
		 simd_i16: simd_mla_i16,                                       \
		 simd_u16: simd_mla_u16,                                       \
		 simd_i32: simd_mla_i32,                                       \
		 simd_u32: simd_mla_u32,                                       \
		 simd_f32: simd_mla_f32)(_acc, _mul0, _mul1))

// Shift left
#if __clang__
# define simd_shl(_simd, _shiftby)                                             \
	 ((typeof(_simd))_Generic(                                             \
		 _shiftby,                                                     \
		  simd_i8: __builtin_neon_vshlq_v,                             \
		  simd_u8: __builtin_neon_vshlq_v,                             \
		  simd_i16: __builtin_neon_vshlq_v,                            \
		  simd_u16: __builtin_neon_vshlq_v,                            \
		  simd_i32: __builtin_neon_vshlq_v,                            \
		  simd_u32: __builtin_neon_vshlq_v,                            \
		  default: __builtin_neon_vshlq_n_v)(                          \
		 _simd, _shiftby,                                              \
		 _Generic(                                                     \
			 _simd,                                                \
			 simd_i8: 32,                                          \
			 simd_u8: 48,                                          \
			 simd_i16: 33,                                         \
			 simd_u16: 49,                                         \
			 simd_i32: 34,                                         \
			 simd_u32: 50)))
#else
# define simd_shl(_simd, _shiftby)                                             \
	 ((typeof(_simd))_Generic(                                             \
		 _simd,                                                        \
		  simd_i8: _Generic(                                           \
			  _shiftby,                                            \
			  simd_i8: __builtin_aarch64_sshlv16qi,                \
			  simd_u8: __builtin_aarch64_sshlv16qi,                \
			  default: __builtin_aarch64_ashlv16qi),               \
		  simd_u8: _Generic(                                           \
			  _shiftby,                                            \
			  simd_i8: __builtin_aarch64_ushlv16qi_uus,            \
			  simd_u8: __builtin_aarch64_ushlv16qi_uus,            \
			  default: __builtin_aarch64_ashlv16qi),               \
		  simd_i16: _Generic(                                          \
			  _shiftby,                                            \
			  simd_i16: __builtin_aarch64_sshlv8hi,                \
			  simd_u16: __builtin_aarch64_sshlv8hi,                \
			  default: __builtin_aarch64_ashlv8hi),                \
		  simd_u16: _Generic(                                          \
			  _shiftby,                                            \
			  simd_i16: __builtin_aarch64_ushlv8hi_uus,            \
			  simd_u16: __builtin_aarch64_ushlv8hi_uus,            \
			  default: __builtin_aarch64_ashlv8hi),                \
		  simd_i32: _Generic(                                          \
			  _shiftby,                                            \
			  simd_i32: __builtin_aarch64_sshlv4si,                \
			  simd_u32: __builtin_aarch64_sshlv4si,                \
			  default: __builtin_aarch64_ashlv4si),                \
		  simd_u32: _Generic(                                          \
			  _shiftby,                                            \
			  simd_i32: __builtin_aarch64_ushlv4si_uus,            \
			  simd_u32: __builtin_aarch64_ushlv4si_uus,            \
			  default: __builtin_aarch64_ashlv4si))(               \
		 _simd_lane_cast_type(_simd) _simd, _shiftby))
#endif
#define simd_shl_i8 simd_shl
#define simd_shl_n_i8 simd_shl
#define simd_shl_i16 simd_shl
#define simd_shl_n_i16 simd_shl
#define simd_shl_i32 simd_shl
#define simd_shl_n_i32 simd_shl
#define simd_shl_u8 simd_shl
#define simd_shl_n_u8 simd_shl
#define simd_shl_u16 simd_shl
#define simd_shl_n_u16 simd_shl
#define simd_shl_u32 simd_shl
#define simd_shl_n_u32 simd_shl

// Shift right
#if __clang__
# define simd_shr(_simd, _shiftby)                                             \
	 ((typeof(_simd))_Generic(                                             \
		 _shiftby,                                                     \
		  simd_i8: __builtin_neon_vshlq_v,                             \
		  simd_u8: __builtin_neon_vshlq_v,                             \
		  simd_i16: __builtin_neon_vshlq_v,                            \
		  simd_u16: __builtin_neon_vshlq_v,                            \
		  simd_i32: __builtin_neon_vshlq_v,                            \
		  simd_u32: __builtin_neon_vshlq_v,                            \
		  default: __builtin_neon_vshrq_n_v)(                          \
		 _simd,                                                        \
		 _Generic(                                                     \
			 _shiftby,                                             \
			 simd_i8: -_shiftby,                                   \
			 simd_u8: -_shiftby,                                   \
			 simd_i16: -_shiftby,                                  \
			 simd_u16: -_shiftby,                                  \
			 simd_i32: -_shiftby,                                  \
			 simd_u32: -_shiftby,                                  \
			 default: _shiftby),                                   \
		 _Generic(                                                     \
			 _simd,                                                \
			 simd_i8: 32,                                          \
			 simd_u8: 48,                                          \
			 simd_i16: 33,                                         \
			 simd_u16: 49,                                         \
			 simd_i32: 34,                                         \
			 simd_u32: 50)))
#else
# define simd_shr(_simd, _shiftby)                                             \
	 ((typeof(_simd))_Generic(                                             \
		 _simd,                                                        \
		  simd_i8: _Generic(                                           \
			  _shiftby,                                            \
			  simd_i8: __builtin_aarch64_sshlv16qi,                \
			  simd_u8: __builtin_aarch64_sshlv16qi,                \
			  default: __builtin_aarch64_ashrv16qi),               \
		  simd_u8: _Generic(                                           \
			  _shiftby,                                            \
			  simd_i8: __builtin_aarch64_lshrv16qi_uus,            \
			  simd_u8: __builtin_aarch64_lshrv16qi_uus,            \
			  default: __builtin_aarch64_lshrv16qi_uus),           \
		  simd_i16: _Generic(                                          \
			  _shiftby,                                            \
			  simd_i16: __builtin_aarch64_sshlv8hi,                \
			  simd_u16: __builtin_aarch64_sshlv8hi,                \
			  default: __builtin_aarch64_ashrv8hi),                \
		  simd_u16: _Generic(                                          \
			  _shiftby,                                            \
			  simd_i16: __builtin_aarch64_ushlv8hi_uus,            \
			  simd_u16: __builtin_aarch64_ushlv8hi_uus,            \
			  default: __builtin_aarch64_lshrv8hi_uus),            \
		  simd_i32: _Generic(                                          \
			  _shiftby,                                            \
			  simd_i32: __builtin_aarch64_sshlv4si,                \
			  simd_u32: __builtin_aarch64_sshlv4si,                \
			  default: __builtin_aarch64_ashrv4si),                \
		  simd_u32: _Generic(                                          \
			  _shiftby,                                            \
			  simd_i32: __builtin_aarch64_ushlv4si_uus,            \
			  simd_u32: __builtin_aarch64_ushlv4si_uus,            \
			  default: __builtin_aarch64_lshrv4si_uus))(           \
		 _simd,                                                        \
		 _Generic(                                                     \
			 _shiftby,                                             \
			 simd_i8: -_shiftby,                                   \
			 simd_u8: -_shiftby,                                   \
			 simd_i16: -_shiftby,                                  \
			 simd_u16: -_shiftby,                                  \
			 simd_i32: -_shiftby,                                  \
			 simd_u32: -_shiftby,                                  \
			 default: _shiftby)))
#endif
#define simd_shr_i8 simd_shr
#define simd_shr_i16 simd_shr
#define simd_shr_i32 simd_shr
#define simd_shr_u8 simd_shr
#define simd_shr_u16 simd_shr
#define simd_shr_u32 simd_shr
#define simd_shr_n_i8 simd_shr
#define simd_shr_n_i16 simd_shr
#define simd_shr_n_i32 simd_shr
#define simd_shr_n_u8 simd_shr
#define simd_shr_n_u16 simd_shr
#define simd_shr_n_u32 simd_shr

// Negate
#define simd_neg(_simd) (-(_simd))
#define simd_neg_i8 simd_neg
#define simd_neg_i16 simd_neg
#define simd_neg_i32 simd_neg
#define simd_neg_f32 simd_neg

// NOT
#define simd_not(_simd) (~(_simd))
#define simd_not_i8 simd_not
#define simd_not_u8 simd_not
#define simd_not_i16 simd_not
#define simd_not_u16 simd_not
#define simd_not_i32 simd_not
#define simd_not_u32 simd_not

// OR
#define simd_or(_lhs, _rhs) ((_lhs) | (_rhs))
#define simd_or_i8 simd_or
#define simd_or_u8 simd_or
#define simd_or_i16 simd_or
#define simd_or_u16 simd_or
#define simd_or_i32 simd_or
#define simd_or_u32 simd_or

// AND
#define simd_and(_lhs, _rhs) ((_lhs) & (_rhs))
#define simd_and_i8 simd_and
#define simd_and_u8 simd_and
#define simd_and_i16 simd_and
#define simd_and_u16 simd_and
#define simd_and_i32 simd_and
#define simd_and_u32 simd_and

// XOR
#define simd_xor(_lhs, _rhs) ((_lhs) ^ (_rhs))
#define simd_xor_i8 simd_xor
#define simd_xor_u8 simd_xor
#define simd_xor_i16 simd_xor
#define simd_xor_u16 simd_xor
#define simd_xor_i32 simd_xor
#define simd_xor_u32 simd_xor

// Compare Equal
#define simd_cmpeq(_lhs, _rhs) ((_lhs) == (_rhs))
#define simd_cmpeq_i8 simd_cmpeq
#define simd_cmpeq_u8 simd_cmpeq
#define simd_cmpeq_i16 simd_cmpeq
#define simd_cmpeq_u16 simd_cmpeq
#define simd_cmpeq_i32 simd_cmpeq
#define simd_cmpeq_u32 simd_cmpeq

// Compare Greater or equal to
#define simd_cmpge(_lhs, _rhs) ((_lhs) >= (_rhs))
#define simd_cmpge_i8 simd_cmpge
#define simd_cmpge_u8 simd_cmpge
#define simd_cmpge_i16 simd_cmpge
#define simd_cmpge_u16 simd_cmpge
#define simd_cmpge_i32 simd_cmpge
#define simd_cmpge_u32 simd_cmpge

// Compare Less or equal to
#define simd_cmple(_lhs, _rhs) ((_lhs) <= (_rhs))
#define simd_cmple_i8 simd_cmple
#define simd_cmple_u8 simd_cmple
#define simd_cmple_i16 simd_cmple
#define simd_cmple_u16 simd_cmple
#define simd_cmple_i32 simd_cmple
#define simd_cmple_u32 simd_cmple

// Compare Greater
#define simd_cmpgt(_lhs, _rhs) ((_lhs) > (_rhs))
#define simd_cmpgt_i8 simd_cmpgt
#define simd_cmpgt_u8 simd_cmpgt
#define simd_cmpgt_i16 simd_cmpgt
#define simd_cmpgt_u16 simd_cmpgt
#define simd_cmpgt_i32 simd_cmpgt
#define simd_cmpgt_u32 simd_cmpgt

// Compare Less
#define simd_cmplt(_lhs, _rhs) ((_lhs) < (_rhs))
#define simd_cmplt_i8 simd_cmplt
#define simd_cmplt_u8 simd_cmplt
#define simd_cmplt_i16 simd_cmplt
#define simd_cmplt_u16 simd_cmplt
#define simd_cmplt_i32 simd_cmplt
#define simd_cmplt_u32 simd_cmplt
