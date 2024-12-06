#pragma once

#define _simd_lanetype(_simd)                                                  \
	(typeof(_Generic(                                                      \
		_simd,                                                         \
			simd_i8: (int8_t)0,                                    \
			simd_u8: (uint8_t)0,                                   \
			simd_i16: (int16_t)0,                                  \
			simd_u16: (uint16_t)0,                                 \
			simd_i32: (int32_t)0,                                  \
			simd_u32: (uint32_t)0,                                 \
			simd_f32: (float)0)))

#ifdef __aarch64__
# include "simd_neon.h"
#endif
