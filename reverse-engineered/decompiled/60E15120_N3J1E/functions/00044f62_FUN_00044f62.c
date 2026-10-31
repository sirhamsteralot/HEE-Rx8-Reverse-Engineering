/* ROM address: 0x00044f62; body bytes: 122; decompiled */

bool FUN_00044f62(void)

{
  ushort uVar1;
  
  uVar1 = ATUII_TSR3_W;
  DAT_ffffcbc5 = (uVar1 & 4) != 0;
  if (DAT_ffffcbc5) {
    ATUII_TSR3_W = 0xfffb;
  }
  uVar1 = ATUII_TSR3_W;
  DAT_ffffcbc6 = (uVar1 & 2) != 0;
  if (DAT_ffffcbc6) {
    ATUII_TSR3_W = 0xfffd;
  }
  DAT_ffffcbad = !DAT_ffffcbc5;
  DAT_ffffcbae = DAT_ffffcbc6;
  if ((!DAT_ffffcbc5) || (DAT_ffffcbc6)) {
    DAT_ffffcbaf = 0;
  }
  else {
    DAT_ffffcbaf = 1;
  }
  return DAT_ffffcbc5;
}


