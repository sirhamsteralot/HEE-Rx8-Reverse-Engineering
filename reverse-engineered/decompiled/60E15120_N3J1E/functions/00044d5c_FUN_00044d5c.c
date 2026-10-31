/* ROM address: 0x00044d5c; body bytes: 108; decompiled */

void FUN_00044d5c(void)

{
  ushort uVar1;
  
  FUN_00044dc8();
  DAT_ffffcbb5 = 10;
  uVar1 = ATUII_TSR3_W;
  if ((uVar1 & 0x20) != 0) {
    ATUII_TSR3_W = 0xffdf;
  }
  uVar1 = ATUII_TSR3_W;
  if ((uVar1 & 8) != 0) {
    ATUII_TSR3_W = 0xfff7;
  }
  DAT_ffffcbc3 = 0;
  DAT_ffffcbc4 = 0;
  uVar1 = ATUII_TSR3_W;
  if ((uVar1 & 4) != 0) {
    ATUII_TSR3_W = 0xfffb;
  }
  uVar1 = ATUII_TSR3_W;
  if ((uVar1 & 2) != 0) {
    ATUII_TSR3_W = 0xfffd;
  }
  DAT_ffffcbc5 = 0;
  DAT_ffffcbc6 = 0;
  DAT_ffffcbc8 = leading_ignition_timing_ffffa630;
  DAT_ffffcbcc = DAT_ffffa0d4;
  return;
}


