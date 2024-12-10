# eksimd

> simple cross platform simd library to quickly get (aleast) 80% of the results

## Quick Refrence

#### Terminology Used

- `iscalar` integer scalar value (int8_t, int16_t, int32_t)
- `uscalar` unsigned integer scalar value (uint8_t, uint16_t, uint32_t)
- `fscalar` floating point scalar value (float)
- `scalar` any scalar value (int8_t, uint8_t, int16_t, uint16_t, int32_t, uint32_t, float)
- `isimd` integer simd value (simd_i8, simd_i16, simd_i32)
- `usimd` unsigned integer scalar value (simd_u8, simd_u16, simd_u32)
- `fsimd` floating point scalar value (simd_f32)
- `simd` any simd value (simd_i8, simd_u8, simd_i16, simd_u16, simd_i32, simd_u32, simd_f32)
- `iN` intN_t
- `uN` uintN_t
- `fN` float/double

### [Miscellaneous](#miscellaneous)

- [SIMD_SIZE](#simd_size)
- [simd_num_lanes](#simd_num_lanes)

### [Types](#types)

- [simd_i8](#simd_i8)
- [simd_i16](#simd_i16)
- [simd_i32](#simd_i32)
- [simd_u8](#simd_u8)
- [simd_u16](#simd_u16)
- [simd_u32](#simd_u32)
- [simd_f32](#simd_f32)

### [Vector Manipulation](#vector-manipulation)

- [simd_init](#simd_init)
- [simd_get_lane](#simd_get_lane)
- [simd_set_lane](#simd_set_lane)
- [simd_shuffle](#simd_shuffle)
- [simd_rev](#simd_rev)
- [simd_shl_lane](#simd_shl_lane)
- [simd_shr_lane](#simd_shr_lane)
- [simd_widen](#simd_widen)
- [simd_narrow](#simd_narrow)

### [Casting](#casting)

- [simd_cvt](#simd_cvt)
- [simd_reinterpret](#simd_reinterpret)

### [Load/Store](#load/store)

- [simd_ld](#simd_ld)
- [simd_st](#simd_st)

### [Arithmatic](#arithmatic)

- [simd_add](#simd_add)
- [simd_sub](#simd_sub)
- [simd_mul](#simd_mul)
- [simd_div](#simd_div)
- [simd_neg](#simd_neg)
- [simd_recp](#simd_recp)
- [simd_sqrt_recp](#simd_sqrt_recp)
- [simd_sqrt](#simd_sqrt)
- [simd_abs](#simd_abs)
- [simd_max](#simd_max)
- [simd_min](#simd_min)
- [simd_padd](#simd_padd)
- [simd_padd_widen](#simd_padd_widen)
- [simd_mla](#simd_mla)

### [Bitwise](#bitwise)

- [simd_shl](#simd_shl)
- [simd_shr](#simd_shr)
- [simd_not](#simd_not)
- [simd_and](#simd_and)
- [simd_or](#simd_or)
- [simd_xor](#simd_xor)

### [Comparisons](#comparisons)

- [simd_cmpeq](#simd_cmpeq)
- [simd_cmpge](#simd_cmpge)
- [simd_cmple](#simd_cmple)
- [simd_cmpgt](#simd_cmpgt)
- [simd_cmplt](#simd_cmplt)

# Miscellaneous

### SIMD_SIZE

`SIMD_SIZE uint`

> A macro defining how wide the SIMD registers you are using are in bits
> (usually 128 bits)

### simd_num_lanes

`simd_num_lanes(simd) -> int`

# Types

### simd_i8

> A N-bit vector of int8_t

### simd_u8

> A N-bit vector of uint8_t

### simd_i16

> A N-bit vector of int16_t

### simd_u16

> A N-bit vector of uint16_t

### simd_i32

> A N-bit vector of int32_t

### simd_u32

> A N-bit vector of uint32_t

### simd_f32

> A N-bit vector of float

# Vector Manipulation

### simd_init

`simd_N(splat: scalar) -> simd`

`simd_N(lane1: scalar, lane2: scalar, ...) -> simd`

`simd_init_N(lane1: scalar, lane2: scalar, ...) -> simd`

`simd_init_n_N(splat: scalar) -> simd`

### simd_get_lane

`simd_get_lane(simd, uscalar) -> scalar`

### simd_set_lane

`simd_set_lane(value, simd, lane: uscalar) -> simd`

### simd_shuffle

`simd_shuffle(simd, indexes: uscalar...) -> simd`

### simd_rev

`simd_rev(simd) -> simd`

### simd_shl_lane

`simd_shl_lane(simd, lanes: uscalar) -> simd`

### simd_shr_lane

`simd_shr_lane(simd, lanes: uscalar) -> simd`

### simd_widen

`simd_widen_lo(simd: simd_i8 | simd_u8 | simd_i16 | simd_u16) -> simd`

`simd_widen_hi(simd: simd_i8 | simd_u8 | simd_i16 | simd_u16) -> simd`

### simd_narrow

`simd_narrow(simd: simd_i16 | simd_u16 | simd_i32 | simd_u32) -> simd`

# [Casting](#casting)

### simd_cvt

`simd_TO_cvt_FROM(simd) -> simd`

### simd_reinterpret

`simd_reinterpret(TO_TYPE, simd) -> simd`

# [Load/Store](#load/store)

### simd_ld

`simd_ld_N(from: const void *) -> simd`

### simd_st

`simd_st(to: void *, simd)`

# [Arithmatic](#arithmatic)

### simd_add

`simd_add(lhs: simd, rhs: simd) -> simd`

### simd_sub

`simd_sub(lhs: simd, rhs: simd) -> simd`

### simd_mul

`simd_mul(lhs: simd, rhs: simd) -> simd`

### simd_div

`simd_div(lhs: simd, rhs: simd) -> simd`

### simd_neg

`simd_neg(simd) -> simd`

### simd_recp

`simd_recp(simd) -> simd`

### simd_sqrt_recp

`simd_sqrt_recp(simd) -> simd`

### simd_sqrt

`simd_sqrt(simd) -> simd`

### simd_abs

`simd_abs(isimd | fsimd) -> simd`

### simd_max

`simd_sqrt(simd) -> simd`

### simd_min

`simd_sqrt(simd) -> simd`

### simd_padd

`simd_padd(simd, simd) -> simd`

### simd_padd_widen

`simd_padd_widen(simd8 | simd16) -> simd`

### simd_mla

`simd_mla(accum: simd, lhs_factor: simd, rhs_factor: simd) -> simd`

# [Bitwise](#bitwise)

### simd_shl

`simd_shl(usimd | isimd, isimd) -> simd`

`simd_shl(usimd | isimd, iscalar) -> simd`

### simd_shr

`simd_shr(usimd | isimd, isimd) -> simd`

`simd_shr(usimd | isimd, iscalar) -> simd`

### simd_not

`simd_not(usimd | isimd) -> simd`

### simd_and

`simd_and(usimd | isimd, usimd | isimd) -> simd`

### simd_or

`simd_or(usimd | isimd, usimd | isimd) -> simd`

### simd_xor

`simd_xor(usimd | isimd, usimd | isimd) -> simd`

# [Comparisons](#comparisons)

### simd_cmpeq

`simd_cmpeq(simd, simd) -> simd`

### simd_cmpge

`simd_cmpge(simd, simd) -> simd`

### simd_cmple

`simd_cmple(simd, simd) -> simd`

### simd_cmpgt

`simd_cmpgt(simd, simd) -> simd`

### simd_cmplt

`simd_cmplt(simd, simd) -> simd`
