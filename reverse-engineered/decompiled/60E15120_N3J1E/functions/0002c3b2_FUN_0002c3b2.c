/* [ADDITIONAL SOURCE REVIEW]
 * gear_latch_confirm [high]: Latches current gear 0xffffbc3d: 0 when 0xffffb53a==1 (neutral), else candidate 0xffffbc3c once its per-gear counter (0xffffbc4a/4c/4e/50/52/54) exceeds 0xb; pool words 0x2c3d8 = 0xbc3c, 0x2c3da = 0xb534, 0x2c3dc = 0xb53a, 0x2c3de = 0xbc3d; jsr rx8_add_u16_saturate 0x2460 via pool 0x2c56c. Emulator: candidate 2 -> bc3d=2 after 20 runs; neutral -> 0. Called from 0x19aa0 (jsr 0x19adc, pool 0x19c88).
 */
/* ROM address: 0x0002c3b2; body bytes: 356; decompiled */

uint gear_latch_confirm(void)

{
  uint uVar1;
  
  if (DAT_ffffb53a == '\x01') {
    current_gear_ffffbc3d = 0;
  }
  else if ((candidate_gear_ffffbc3c == 1) && (0xb < DAT_ffffbc4a)) {
    current_gear_ffffbc3d = 1;
  }
  else if ((candidate_gear_ffffbc3c == 2) && (0xb < DAT_ffffbc4c)) {
    current_gear_ffffbc3d = 2;
  }
  else if ((candidate_gear_ffffbc3c == 3) && (0xb < DAT_ffffbc4e)) {
    current_gear_ffffbc3d = 3;
  }
  else if ((candidate_gear_ffffbc3c == 4) && (0xb < DAT_ffffbc50)) {
    current_gear_ffffbc3d = 4;
  }
  else if ((candidate_gear_ffffbc3c == 5) && (0xb < DAT_ffffbc52)) {
    current_gear_ffffbc3d = 5;
  }
  else if ((candidate_gear_ffffbc3c == 6) && (0xb < DAT_ffffbc54)) {
    current_gear_ffffbc3d = 6;
  }
  if (candidate_gear_ffffbc3c == 1) {
    DAT_ffffbc4a = rx8_add_u16_saturate((int)(short)DAT_ffffbc4a,1);
  }
  else {
    DAT_ffffbc4a = 0;
  }
  if (candidate_gear_ffffbc3c == 2) {
    DAT_ffffbc4c = rx8_add_u16_saturate((int)(short)DAT_ffffbc4c,1);
  }
  else {
    DAT_ffffbc4c = 0;
  }
  if (candidate_gear_ffffbc3c == 3) {
    DAT_ffffbc4e = rx8_add_u16_saturate((int)(short)DAT_ffffbc4e,1);
  }
  else {
    DAT_ffffbc4e = 0;
  }
  if (candidate_gear_ffffbc3c == 4) {
    DAT_ffffbc50 = rx8_add_u16_saturate((int)(short)DAT_ffffbc50,1);
  }
  else {
    DAT_ffffbc50 = 0;
  }
  if (candidate_gear_ffffbc3c == 5) {
    DAT_ffffbc52 = rx8_add_u16_saturate((int)(short)DAT_ffffbc52,1);
  }
  else {
    DAT_ffffbc52 = 0;
  }
  uVar1 = (uint)candidate_gear_ffffbc3c;
  if (uVar1 == 6) {
    uVar1 = rx8_add_u16_saturate((int)(short)DAT_ffffbc54,1);
    DAT_ffffbc54 = (ushort)uVar1;
  }
  else {
    DAT_ffffbc54 = 0;
  }
  return uVar1;
}


