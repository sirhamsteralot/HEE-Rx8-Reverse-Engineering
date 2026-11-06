/* [ADDITIONAL SOURCE REVIEW]
 * idle_target_encode_u16 [high]: Encodes idle_target_rpm (fr4) to u16 with step 0.25 (f32 0x3e800000 at ROM 0x5cb64, loaded by mova at 0x5cb1a) through 0x2490 rx8_encode_u16_affine_saturate when diag override state 0xffffd319==0 and the active DID 0xffffd314==0x96e (word at pool 0x5cb42) passes mask 0xc0 (word at 0x5cb3e) on 0xffffd36c; result stored to 0xffffd34d (base 0xffffd335 + 0x18); otherwise decodes override cell 0xffffd34d via 0x24c0. Pool words of the function (classified mixed_pool starting 0x5cb3e): 0x5cb44=0xffffd319, 0x5cb4c=0xffffd335, 0x5cb50=0x5f728, 0x5cb54=0xffffd314, 0x5cb58=0xffffd318, 0x5cb5c=0xffffd316, 0x5cb60=0x5f734, 0x5cb68=0x2490. Sole caller 0x1506c stores the u16 to 0xffffa7ac, the Mode 22 PID 0x096e source (handler 0x56e22, encode *0.25). Not an actuator register.
 */
/* [MATH AND UNITS REVIEW]
 * Affine encoding (16-bit): param_1; decode = raw * 0.25 + (0) [unassigned units]. Encode applies trunc((signal-offset)/step + 0.5), then saturation; units follow prior signal interpretation.
 */
/* ROM address: 0x0005ca94; body bytes: 226; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint idle_target_encode_u16(undefined4 param_1)

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


