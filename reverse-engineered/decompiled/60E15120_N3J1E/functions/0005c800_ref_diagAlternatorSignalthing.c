/* [MATH AND UNITS REVIEW]
 * Affine encoding (16-bit): param_1; decode = raw * 0.003051757812 + (0) [unassigned units]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 */
/* ROM address: 0x0005c800; body bytes: 226; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Unique exact-byte match to related 60E0FC00 function at 0005aff0 (226 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_diagAlternatorSignalthing(undefined4 param_1)

{
  uint uVar1;
  
  if (DAT_ffffd319 == '\0') {
    if (DAT_ffffd314 == 0x16e8) {
      if ((DAT_ffffd36c & 0x40) == 0) {
        DAT_ffffd319 = '\x02';
        DAT_ffffd324 = 0;
      }
      else {
        DAT_ffffd324 = DAT_ffffd318;
        DAT_ffffd319 = '\x01';
        if (DAT_ffffd318 == 7) {
          _DAT_ffffd347 = DAT_ffffd316;
        }
      }
    }
    else {
      DAT_ffffd319 = '\0';
      if ((DAT_ffffd36c & 0x40) == 0) {
        DAT_ffffd324 = 0;
      }
    }
  }
  uVar1 = (uint)DAT_ffffd324;
  if (uVar1 == 0) {
    uVar1 = rx8_encode_u16_affine_saturate(param_1,0x3b480000,0);
    _DAT_ffffd347 = (undefined2)uVar1;
  }
  else if ((uVar1 == 5) || (uVar1 == 7)) {
    uVar1 = rx8_decode_u16_affine(0x3b480000,0,_DAT_ffffd347);
  }
  return uVar1;
}


