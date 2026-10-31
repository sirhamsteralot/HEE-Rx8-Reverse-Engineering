/* ROM address: 0x00044ee8; body bytes: 122; decompiled */

bool FUN_00044ee8(void)

{
  ushort uVar1;
  
  uVar1 = ATUII_TSR3_W;
  DAT_ffffcbc3 = (uVar1 & 0x20) != 0;
  if (DAT_ffffcbc3) {
    ATUII_TSR3_W = 0xffdf;
  }
  uVar1 = ATUII_TSR3_W;
  DAT_ffffcbc4 = (uVar1 & 8) != 0;
  if (DAT_ffffcbc4) {
    ATUII_TSR3_W = 0xfff7;
  }
  DAT_ffffcbaa = !DAT_ffffcbc3;
  DAT_ffffcbab = DAT_ffffcbc4;
  if ((!DAT_ffffcbc3) || (DAT_ffffcbc4)) {
    DAT_ffffcbac = 0;
  }
  else {
    DAT_ffffcbac = 1;
  }
  return DAT_ffffcbc3;
}


