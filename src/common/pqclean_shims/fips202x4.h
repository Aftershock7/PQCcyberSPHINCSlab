// SPDX-License-Identifier: MIT

#ifndef FIPS202X4_H
#define FIPS202X4_H

#include <oqs/sha3x4.h>

/* Additions "just" for SPHINCS: */
#include <immintrin.h>
/* Provide a reference to the common AVX2 KeccakP1600times4_PermuteAll_24rounds */
#define KECCAKTIMES4_IMPL_NAMESPACE(x) x##_avx2
#define KeccakP1600times4_PermuteAll_24rounds KECCAKTIMES4_IMPL_NAMESPACE(KeccakP1600times4_PermuteAll_24rounds)

#define shake256x4 OQS_SHA3_shake256_x4
#define shake128x4incctx OQS_SHA3_shake128_x4_inc_ctx
#define shake128x4_inc_init OQS_SHA3_shake128_x4_inc_init
#define shake128x4_inc_absorb OQS_SHA3_shake128_x4_inc_absorb
#define shake128x4_inc_finalize OQS_SHA3_shake128_x4_inc_finalize
#define shake128x4_inc_squeeze OQS_SHA3_shake128_x4_inc_squeeze
#define shake128x4_inc_ctx_release OQS_SHA3_shake128_x4_inc_ctx_release
#define shake128x4_inc_ctx_clone OQS_SHA3_shake128_x4_inc_ctx_clone
#define shake128x4_inc_ctx_reset OQS_SHA3_shake128_x4_inc_ctx_reset

#define shake256x4incctx OQS_SHA3_shake256_x4_inc_ctx
#define shake256x4_inc_init OQS_SHA3_shake256_x4_inc_init
#define shake256x4_inc_absorb OQS_SHA3_shake256_x4_inc_absorb
#define shake256x4_inc_finalize OQS_SHA3_shake256_x4_inc_finalize
#define shake256x4_inc_squeeze OQS_SHA3_shake256_x4_inc_squeeze
#define shake256x4_inc_ctx_release OQS_SHA3_shake256_x4_inc_ctx_release
#define shake256x4_inc_ctx_clone OQS_SHA3_shake256_x4_inc_ctx_clone
#define shake256x4_inc_ctx_reset OQS_SHA3_shake256_x4_inc_ctx_reset

#define shake128x4_absorb_once OQS_SHA3_shake128_x4_absorb_once
void OQS_SHA3_shake128_x4_absorb_once(shake128x4incctx *state, const uint8_t *in0, const uint8_t *in1, const uint8_t *in2, const uint8_t *in3, size_t inlen);

#define shake256x4_absorb_once OQS_SHA3_shake256_x4_absorb_once
void OQS_SHA3_shake256_x4_absorb_once(shake256x4incctx *state, const uint8_t *in0, const uint8_t *in1, const uint8_t *in2, const uint8_t *in3, size_t inlen);

#define shake128x4_squeezeblocks(OUT0, OUT1, OUT2, OUT3, NBLOCKS, STATE) \
        OQS_SHA3_shake128_x4_inc_squeeze(OUT0, OUT1, OUT2, OUT3, (NBLOCKS)*OQS_SHA3_SHAKE128_RATE, STATE)

#define shake256x4_squeezeblocks(OUT0, OUT1, OUT2, OUT3, NBLOCKS, STATE) \
        OQS_SHA3_shake256_x4_inc_squeeze(OUT0, OUT1, OUT2, OUT3, (NBLOCKS)*OQS_SHA3_SHAKE256_RATE, STATE)

#endif
