/* ROM address: 0x0004fcb4; body bytes: 80; decompiled */

uint FUN_0004fcb4(void)

{
  uint uVar1;
  uint extraout_r0;
  float fVar2;
  
  uVar1 = (uint)DAT_ffffcffa;
  if ((uVar1 == 1) && (uVar1 = 10, DAT_ffffd035 == '\n')) {
    if (DAT_ffffd034 == '\0') {
      fVar2 = 0.96875;
    }
    else {
      fVar2 = 0.92578;
    }
    DAT_ffffd01c = rx8_first_order_filter(DAT_ffffd018,DAT_ffffd01c,1.0 - fVar2,1e-05);
    uVar1 = extraout_r0;
  }
  return uVar1;
}


