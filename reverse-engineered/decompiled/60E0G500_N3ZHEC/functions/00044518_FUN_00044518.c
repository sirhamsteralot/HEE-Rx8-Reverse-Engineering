/* ROM address: 0x00044518; body bytes: 52; decompiled */

uint FUN_00044518(void)

{
  uint uVar1;
  undefined4 uVar2;
  float extraout_fr0;
  
  uVar1 = (uint)DAT_ffffcab4;
  if (uVar1 == 1) {
    uVar2 = FUN_00002500(0x3f800000,0,(int)DAT_ffffcaaf);
    uVar1 = FUN_00002068(uVar2,&DAT_0006bbc8);
    DAT_ffffca18 = DAT_ffffca1c * extraout_fr0;
  }
  return uVar1;
}


