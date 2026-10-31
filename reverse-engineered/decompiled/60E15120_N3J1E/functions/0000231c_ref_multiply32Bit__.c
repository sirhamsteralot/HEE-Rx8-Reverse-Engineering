/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* [MATH AND UNITS REVIEW]
 * rx8_mul_s32_shift16_saturate: DMULS.L forms signed 64-bit product; 16 SHAR/ROTCR pairs perform arithmetic >>16; range check clamps to INT32_MIN/MAX. Equivalent to saturate_s32(floor((int64)a*b/65536)). Compatible with Q16.16 multiplication if both inputs use that format; actual operand units depend on callers. Not GCC __mulsi3, which returns an ordinary integer product.
 */
/* ROM address: 0x0000231c; body bytes: 114; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000231c (114 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint rx8_mul_s32_shift16_saturate(int multiplicand,int multiplier)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = (uint)((ulonglong)((longlong)multiplier * (longlong)multiplicand) >> 0x20);
  iVar2 = (int)uVar3 >> 0x10;
  uVar1 = (uint)(((int)uVar3 >> 0xf & 1U) == 1);
  uVar3 = ((((((((((((((((uint)((longlong)multiplier * (longlong)multiplicand) >> 1 |
                        (uint)((uVar3 & 1) == 1) * -0x80000000) >> 1 |
                       (uint)(((int)uVar3 >> 1 & 1U) == 1) * -0x80000000) >> 1 |
                      (uint)(((int)uVar3 >> 2 & 1U) == 1) * -0x80000000) >> 1 |
                     (uint)(((int)uVar3 >> 3 & 1U) == 1) * -0x80000000) >> 1 |
                    (uint)(((int)uVar3 >> 4 & 1U) == 1) * -0x80000000) >> 1 |
                   (uint)(((int)uVar3 >> 5 & 1U) == 1) * -0x80000000) >> 1 |
                  (uint)(((int)uVar3 >> 6 & 1U) == 1) * -0x80000000) >> 1 |
                 (uint)(((int)uVar3 >> 7 & 1U) == 1) * -0x80000000) >> 1 |
                (uint)(((int)uVar3 >> 8 & 1U) == 1) * -0x80000000) >> 1 |
               (uint)(((int)uVar3 >> 9 & 1U) == 1) * -0x80000000) >> 1 |
              (uint)(((int)uVar3 >> 10 & 1U) == 1) * -0x80000000) >> 1 |
             (uint)(((int)uVar3 >> 0xb & 1U) == 1) * -0x80000000) >> 1 |
            (uint)(((int)uVar3 >> 0xc & 1U) == 1) * -0x80000000) >> 1 |
           (uint)(((int)uVar3 >> 0xd & 1U) == 1) * -0x80000000) >> 1 |
          (uint)(((int)uVar3 >> 0xe & 1U) == 1) * -0x80000000) >> 1 | uVar1 * -0x80000000;
  if (iVar2 < 0) {
    if ((iVar2 != -1) || (uVar1 == 0)) {
      uVar3 = 0x80000000;
    }
  }
  else if ((iVar2 != 0) || (uVar1 != 0)) {
    uVar3 = 0x7fffffff;
  }
  return uVar3;
}


