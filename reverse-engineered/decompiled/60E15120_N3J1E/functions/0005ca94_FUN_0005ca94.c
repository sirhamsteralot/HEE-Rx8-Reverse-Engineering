/* [MATH AND UNITS REVIEW]
 * Affine encoding (16-bit): param_1; decode = raw * 0.25 + (0) [unassigned units]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 */
/* ROM address: 0x0005ca94; body bytes: 226; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0005ca94(undefined4 param_1)

{
  uint uVar1;
  
  if (DAT_ffffd319 == '\0') {
    if (DAT_ffffd314 == 0x96e) {
      if ((DAT_ffffd36c & 0xc0) == 0) {
        DAT_ffffd319 = '\x02';
        DAT_ffffd327 = 0;
      }
      else {
        DAT_ffffd327 = DAT_ffffd318;
        DAT_ffffd319 = '\x01';
        if (DAT_ffffd318 == 7) {
          _DAT_ffffd34d = DAT_ffffd316;
        }
      }
    }
    else {
      DAT_ffffd319 = '\0';
      if ((DAT_ffffd36c & 0xc0) == 0) {
        DAT_ffffd327 = 0;
      }
    }
  }
  uVar1 = (uint)DAT_ffffd327;
  if (uVar1 == 0) {
    uVar1 = rx8_encode_u16_affine_saturate(param_1,0x3e800000,0);
    _DAT_ffffd34d = (undefined2)uVar1;
  }
  else if ((uVar1 == 5) || (uVar1 == 7)) {
    uVar1 = rx8_decode_u16_affine(0x3e800000,0,_DAT_ffffd34d);
  }
  return uVar1;
}


