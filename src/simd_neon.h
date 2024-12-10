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
#else
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
# define simd_i16_set_lane(_val, _simd, _lane)                                 \
	 __simd_set_lane_any(_val, _simd, _lane)
# define simd_u16_set_lane(_val, _simd, _lane)                                 \
	 __simd_set_lane_any(_val, _simd, _lane)
# define simd_i32_set_lane(_val, _simd, _lane)                                 \
	 __simd_set_lane_any(_val, _simd, _lane)
# define simd_u32_set_lane(_val, _simd, _lane)                                 \
	 __simd_set_lane_any(_val, _simd, _lane)
# define simd_f32_set_lane(_val, _simd, _lane)                                 \
	 __simd_set_lane_any(_val, _simd, _lane)
# define simd_set_lane(_val, _simd, _lane)                                     \
	 __simd_set_lane_any(_val, _simd, _lane)
#endif

// Casts
_simdapi simd_i8  simd_i8_cvt_i8(simd_i8 val) { return val; }
_simdapi simd_u8  simd_i8_cvt_u8(simd_i8 val) { return (simd_u8)val; }
_simdapi simd_i16 simd_i16_cvt_i16(simd_i16 val) { return val; }
_simdapi simd_u16 simd_i16_cvt_u16(simd_i16 val) { return (simd_u16)val; }
_simdapi simd_i32 simd_i32_cvt_i32(simd_i32 val) { return val; }
_simdapi simd_u32 simd_i32_cvt_u32(simd_i32 val) { return (simd_u32)val; }
_simdapi simd_i8  simd_u8_cvt_i8(simd_u8 val) { return (simd_i8)val; }
_simdapi simd_u8  simd_u8_cvt_u8(simd_u8 val) { return val; }
_simdapi simd_i16 simd_u16_cvt_i16(simd_u16 val) { return (simd_i16)val; }
_simdapi simd_u16 simd_u16_cvt_u16(simd_u16 val) { return val; }
_simdapi simd_i32 simd_u32_cvt_i32(simd_u32 val) { return (simd_i32)val; }
_simdapi simd_u32 simd_u32_cvt_u32(simd_u32 val) { return val; }
_simdapi simd_f32 simd_f32_cvt_f32(simd_f32 val) { return val; }

#if __clang__
_simdapi simd_i32 simd_f32_cvt_i32(simd_f32 val) {
	return __builtin_neon_vcvtq_s32_v((simd_i8)val, 34);
}
_simdapi simd_u32 simd_f32_cvt_u32(simd_f32 val) {
	return __builtin_neon_vcvtq_u32_v((simd_i8)val, 50);
}
_simdapi simd_f32 simd_i32_cvt_f32(simd_i32 val) {
	return __builtin_neon_vcvtq_f32_v((simd_i8)val, 34);
}
_simdapi simd_f32 simd_u32_cvt_f32(simd_u32 val) {
	return __builtin_neon_vcvtq_f32_v((simd_i8)val, 50);
}
#else
_simdapi simd_i32 simd_f32_cvt_i32(simd_f32 val) {
	return __builtin_aarch64_lbtruncv4sfv4si(val);
}
_simdapi simd_u32 simd_f32_cvt_u32(simd_f32 val) {
	return __builtin_aarch64_lbtruncuv4sfv4si_us(val);
}
_simdapi simd_f32 simd_i32_cvt_f32(simd_i32 val) {
	return __builtin_aarch64_floatv4siv4sf(val);
}
_simdapi simd_f32 simd_u32_cvt_f32(simd_u32 val) {
	return __builtin_aarch64_floatunsv4siv4sf((simd_i32)val);
}
#endif // __clang__ else __GNUC__
#define simd_cvt(_simd, _toty)                                                 \
	(_Generic(                                                             \
		_simd,                                                         \
		 simd_i8: _Generic(                                            \
			 (_toty){},                                            \
			 simd_i8: simd_i8_cvt_i8,                              \
			 simd_u8: simd_i8_cvt_u8,                              \
			 simd_i16: NULL,                                       \
			 simd_u16: NULL,                                       \
			 simd_i32: NULL,                                       \
			 simd_u32: NULL,                                       \
			 simd_f32: NULL),                                      \
		 simd_u8: _Generic(                                            \
			 (_toty){},                                            \
			 simd_i8: simd_u8_cvt_i8,                              \
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
			 simd_u16: simd_i16_cvt_u16,                           \
			 simd_i32: NULL,                                       \
			 simd_u32: NULL,                                       \
			 simd_f32: NULL),                                      \
		 simd_u16: _Generic(                                           \
			 (_toty){},                                            \
			 simd_i8: NULL,                                        \
			 simd_u8: NULL,                                        \
			 simd_i16: simd_u16_cvt_i16,                           \
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
			 simd_u32: simd_i32_cvt_u32,                           \
			 simd_f32: simd_i32_cvt_f32),                          \
		 simd_u32: _Generic(                                           \
			 (_toty){},                                            \
			 simd_i8: NULL,                                        \
			 simd_u8: NULL,                                        \
			 simd_i16: NULL,                                       \
			 simd_u16: NULL,                                       \
			 simd_i32: simd_u32_cvt_i32,                           \
			 simd_u32: simd_u32_cvt_u32,                           \
			 simd_f32: simd_u32_cvt_f32),                          \
		 simd_f32: _Generic(                                           \
			 (_toty){},                                            \
			 simd_i8: NULL,                                        \
			 simd_u8: NULL,                                        \
			 simd_i16: NULL,                                       \
			 simd_u16: NULL,                                       \
			 simd_i32: simd_f32_cvt_i32,                           \
			 simd_u32: simd_f32_cvt_u32,                           \
			 simd_f32: simd_f32_cvt_f32))(_simd))

// Reinterpret Cast
#define simd_reinterpret(_simd, _toty) ((_toty)(_simd))

// Reverse bits in each byte
#if __clang__
# define simd_rbit_i8(_simd)                                                   \
	 (simd_i8) __builtin_neon_vrbitq_v((simd_i8)_simd, 32)
# define simd_rbit_u8(_simd)                                                   \
	 (simd_u8) __builtin_neon_vrbitq_v((simd_i8)_simd, 48)
# define simd_rbit(_simd)                                                      \
	 ((typeof(_simd))_Generic(                                             \
		 _simd,                                                        \
		  simd_i8: __builtin_neon_vrbitq_v,                            \
		  simd_u8: __builtin_neon_vrbitq_v)(                           \
		 _simd_lane_cast_type(_simd) _simd,                            \
		 _Generic(_simd, simd_i8: 32, simd_u8: 48)))
#else
# define simd_rbit_i8(_simd)                                                   \
	 (simd_i8) __builtin_aarch64_rbitv16qi((simd_i8)_simd)
# define simd_rbit_u8(_simd)                                                   \
	 (simd_u8) __builtin_aarch64_rbitv16qi((simd_i8)_simd)
# define simd_rbit(_simd)                                                      \
	 ((typeof(_simd))_Generic(                                             \
		 _simd,                                                        \
		  simd_i8: __builtin_aarch64_rbitv16qi,                        \
		  simd_u8: __builtin_aarch64_rbitv16qi)(                       \
		 _simd_lane_cast_type(_simd) _simd))
#endif

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
_simdapi simd_i8 simd_i8_rev(simd_i8 val) {
	return _simd_shuffle(
		val, val, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0);
}
_simdapi simd_u8 simd_u8_rev(simd_u8 val) {
	return _simd_shuffle(
		val, val, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0);
}
_simdapi simd_i16 simd_i16_rev(simd_i16 val) {
	return _simd_shuffle(val, val, 7, 6, 5, 4, 3, 2, 1, 0);
}
_simdapi simd_u16 simd_u16_rev(simd_u16 val) {
	return _simd_shuffle(val, val, 7, 6, 5, 4, 3, 2, 1, 0);
}
_simdapi simd_i32 simd_i32_rev(simd_i32 val) {
	return _simd_shuffle(val, val, 3, 2, 1, 0);
}
_simdapi simd_u32 simd_u32_rev(simd_u32 val) {
	return _simd_shuffle(val, val, 3, 2, 1, 0);
}
_simdapi simd_f32 simd_f32_rev(simd_f32 val) {
	return _simd_shuffle(val, val, 3, 2, 1, 0);
}
#define simd_rev(_simd)                                                        \
	(_Generic(                                                             \
		_simd,                                                         \
		 simd_i8: simd_i8_rev,                                         \
		 simd_u8: simd_u8_rev,                                         \
		 simd_i16: simd_i16_rev,                                       \
		 simd_u16: simd_u16_rev,                                       \
		 simd_i32: simd_i32_rev,                                       \
		 simd_u32: simd_u32_rev,                                       \
		 simd_f32: simd_f32_rev)(_simd))

// Shuffle
#define simd_i8_shuffle(_simd, ...) _simd_shuffle(_simd, _simd, __VA_ARGS__)
#define simd_u8_shuffle(_simd, ...) _simd_shuffle(_simd, _simd, __VA_ARGS__)
#define simd_i16_shuffle(_simd, ...) _simd_shuffle(_simd, _simd, __VA_ARGS__)
#define simd_u16_shuffle(_simd, ...) _simd_shuffle(_simd, _simd, __VA_ARGS__)
#define simd_i32_shuffle(_simd, ...) _simd_shuffle(_simd, _simd, __VA_ARGS__)
#define simd_u32_shuffle(_simd, ...) _simd_shuffle(_simd, _simd, __VA_ARGS__)
#define simd_f32_shuffle(_simd, ...) _simd_shuffle(_simd, _simd, __VA_ARGS__)
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
# define simd_i8_shl_lane simd_shl_lane
# define simd_u8_shl_lane simd_shl_lane
# define simd_i16_shl_lane simd_shl_lane
# define simd_u16_shl_lane simd_shl_lane
# define simd_i32_shl_lane simd_shl_lane
# define simd_u32_shl_lane simd_shl_lane
# define simd_f32_shl_lane simd_shl_lane
#else
_simdapi simd_i8 simd_i8_shl_lane(simd_i8 val, const int lanes) {
	const int bias = 4 - lanes;
	return _simd_shuffle(
		simd_i8(0), val, bias, bias + 1, bias + 2, bias + 3, bias + 4,
		bias + 5, bias + 6, bias + 7, bias + 8, bias + 9, bias + 10,
		bias + 11, bias + 12, bias + 13, bias + 14, bias + 15);
}
_simdapi simd_u8 simd_u8_shl_lane(simd_u8 val, const int lanes) {
	const int bias = 4 - lanes;
	return _simd_shuffle(
		simd_u8(0), val, bias, bias + 1, bias + 2, bias + 3, bias + 4,
		bias + 5, bias + 6, bias + 7, bias + 8, bias + 9, bias + 10,
		bias + 11, bias + 12, bias + 13, bias + 14, bias + 15);
}
_simdapi simd_i16 simd_i16_shl_lane(simd_i16 val, const int lanes) {
	const int bias = 4 - lanes;
	return _simd_shuffle(
		simd_i16(0), val, bias, bias + 1, bias + 2, bias + 3, bias + 4,
		bias + 5, bias + 6, bias + 7);
}
_simdapi simd_u16 simd_u16_shl_lane(simd_u16 val, const int lanes) {
	const int bias = 4 - lanes;
	return _simd_shuffle(
		simd_u16(0), val, bias, bias + 1, bias + 2, bias + 3, bias + 4,
		bias + 5, bias + 6, bias + 7);
}
_simdapi simd_i32 simd_i32_shl_lane(simd_i32 val, const int lanes) {
	const int bias = 4 - lanes;
	return _simd_shuffle(
		simd_i32(0), val, bias, bias + 1, bias + 2, bias + 3);
}
_simdapi simd_u32 simd_u32_shl_lane(simd_u32 val, const int lanes) {
	const int bias = 4 - lanes;
	return _simd_shuffle(
		simd_u32(0), val, bias, bias + 1, bias + 2, bias + 3);
}
_simdapi simd_f32 simd_f32_shl_lane(simd_f32 val, const int lanes) {
	const int bias = 4 - lanes;
	return _simd_shuffle(
		simd_f32(0), val, bias, bias + 1, bias + 2, bias + 3);
}
# define simd_shl_lane(_simd, _lanes)                                          \
	 (_Generic(                                                            \
		 _simd,                                                        \
		  simd_i8: simd_i8_shl_lane,                                   \
		  simd_u8: simd_u8_shl_lane,                                   \
		  simd_i16: simd_i16_shl_lane,                                 \
		  simd_u16: simd_u16_shl_lane,                                 \
		  simd_i32: simd_i32_shl_lane,                                 \
		  simd_u32: simd_u32_shl_lane,                                 \
		  simd_f32: simd_f32_shl_lane)(_simd, _lanes))
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
# define simd_i8_shr_lane simd_shr_lane
# define simd_u8_shr_lane simd_shr_lane
# define simd_i16_shr_lane simd_shr_lane
# define simd_u16_shr_lane simd_shr_lane
# define simd_i32_shr_lane simd_shr_lane
# define simd_u32_shr_lane simd_shr_lane
# define simd_f32_shr_lane simd_shr_lane
#else
_simdapi simd_i8 simd_i8_shr_lane(simd_i8 val, const int lanes) {
	return _simd_shuffle(
		val, simd_i8(0), lanes, lanes + 1, lanes + 2, lanes + 3,
		lanes + 4, lanes + 5, lanes + 6, lanes + 7, lanes + 8,
		lanes + 9, lanes + 10, lanes + 11, lanes + 12, lanes + 13,
		lanes + 14, lanes + 15);
}
_simdapi simd_u8 simd_u8_shr_lane(simd_u8 val, const int lanes) {
	return _simd_shuffle(
		val, simd_u8(0), lanes, lanes + 1, lanes + 2, lanes + 3,
		lanes + 4, lanes + 5, lanes + 6, lanes + 7, lanes + 8,
		lanes + 9, lanes + 10, lanes + 11, lanes + 12, lanes + 13,
		lanes + 14, lanes + 15);
}
_simdapi simd_i16 simd_i16_shr_lane(simd_i16 val, const int lanes) {
	return _simd_shuffle(
		val, simd_i16(0), lanes, lanes + 1, lanes + 2, lanes + 3,
		lanes + 4, lanes + 5, lanes + 6, lanes + 7);
}
_simdapi simd_u16 simd_u16_shr_lane(simd_u16 val, const int lanes) {
	return _simd_shuffle(
		val, simd_u16(0), lanes, lanes + 1, lanes + 2, lanes + 3,
		lanes + 4, lanes + 5, lanes + 6, lanes + 7);
}
_simdapi simd_i32 simd_i32_shr_lane(simd_i32 val, const int lanes) {
	return _simd_shuffle(
		val, simd_i32(0), lanes, lanes + 1, lanes + 2, lanes + 3);
}
_simdapi simd_u32 simd_u32_shr_lane(simd_u32 val, const int lanes) {
	return _simd_shuffle(
		val, simd_u32(0), lanes, lanes + 1, lanes + 2, lanes + 3);
}
_simdapi simd_f32 simd_f32_shr_lane(simd_f32 val, const int lanes) {
	return _simd_shuffle(
		val, simd_f32(0), lanes, lanes + 1, lanes + 2, lanes + 3);
}
# define simd_shr_lane(_simd, _lanes)                                          \
	 (_Generic(                                                            \
		 _simd,                                                        \
		  simd_i8: simd_i8_shr_lane,                                   \
		  simd_u8: simd_u8_shr_lane,                                   \
		  simd_i16: simd_i16_shr_lane,                                 \
		  simd_u16: simd_u16_shr_lane,                                 \
		  simd_i32: simd_i32_shr_lane,                                 \
		  simd_u32: simd_u32_shr_lane,                                 \
		  simd_f32: simd_f32_shr_lane)(_simd, _lanes))
#endif

// Load
// Store
// Widen
// Narrow

// Addition
// Subtract
// Multiply
// Multiply by scalar
// Division
// Reciprocal
// Absolute
// Maximum
// Minimum
// Round
// Square Root
// Pairwise Addition
// Pairwise Addition with Narrow
// Addition Across
// Maxmumum Across
// Minumum Across

// Shift left
// Shift right
// Shift left insert
// Shift right insert

// Negate
// NOT
// OR
// AND
// XOR

// Compare Equal
// Compare Not Equal
// Compare Greater or equal to
// Compare Less or equal to
// Compare Greater
// Compare Less

// Bitwise select
// Population count
// Count leading zeros
