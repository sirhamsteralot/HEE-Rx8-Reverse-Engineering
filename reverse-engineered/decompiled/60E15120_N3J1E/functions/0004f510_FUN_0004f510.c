/* ROM address: 0x0004f510; body bytes: 80; decompiled */

uint FUN_0004f510(void)

{
  uint uVar1;
  uint extraout_r0;
  float fVar2;
  
  uVar1 = (uint)DAT_ffffcfbe;
  if ((uVar1 == 1) && (uVar1 = 10, DAT_ffffcff9 == '\n')) {
    if (DAT_ffffcff8 == '\0') {
      fVar2 = 0.96875;
    }
    else {
      fVar2 = 0.92578;
    }
    DAT_ffffcfe0 = rx8_first_order_filter(DAT_ffffcfdc,DAT_ffffcfe0,1.0 - fVar2,1e-05);
    uVar1 = extraout_r0;
  }
  return uVar1;
}


