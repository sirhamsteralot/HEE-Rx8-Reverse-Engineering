/* [ADDITIONAL SOURCE REVIEW]
 * alternator_target_encode_u16 [medium]: Diag-override-aware u16 encoder for the voltage target, DID 0x97c (mask 0x60 on 0xffffd36c, state 0xffffd319/0xffffd328, cell 0xffffd34f): step f32 0x3a000000 via 0x2490 rx8_encode_u16_affine_saturate; decode via 0x24c0. Same pattern as 0x5ca94 (PID 0x096e). Sole caller 0x25c6c stores result into 0xffffb59c.
 */
/* [MATH AND UNITS REVIEW]
 * Affine encoding (16-bit): param_1; decode = raw * 0.00048828125 + (0) [unassigned units]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 */
/* ROM address: 0x0005cba4; body bytes: 226; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Unique exact-byte match to related 60E0FC00 function at 0005b394 (226 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint candidate_alternator_target_encode_u16(undefined4 param_1)

{
  uint uVar1;
  
  if (DAT_ffffd319 == '\0') {
    if (DAT_ffffd314 == 0x97c) {
      if ((DAT_ffffd36c & 0x60) == 0) {
        DAT_ffffd319 = '\x02';
        DAT_ffffd328 = 0;
      }
      else {
        DAT_ffffd328 = DAT_ffffd318;
        DAT_ffffd319 = '\x01';
        if (DAT_ffffd318 == 7) {
          _DAT_ffffd34f = DAT_ffffd316;
        }
      }
    }
    else {
      DAT_ffffd319 = '\0';
      if ((DAT_ffffd36c & 0x60) == 0) {
        DAT_ffffd328 = 0;
      }
    }
  }
  uVar1 = (uint)DAT_ffffd328;
  if (uVar1 == 0) {
    uVar1 = rx8_encode_u16_affine_saturate(param_1,0x3a000000,0);
    _DAT_ffffd34f = (undefined2)uVar1;
  }
  else if ((uVar1 == 5) || (uVar1 == 7)) {
    uVar1 = rx8_decode_u16_affine(0x3a000000,0,_DAT_ffffd34f);
  }
  return uVar1;
}


