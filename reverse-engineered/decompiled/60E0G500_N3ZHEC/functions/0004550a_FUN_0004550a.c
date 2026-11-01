/* ROM address: 0x0004550a; body bytes: 280; decompiled */

undefined4 FUN_0004550a(void)

{
  undefined4 uVar1;
  ushort uVar2;
  ushort uVar3;
  float fVar4;
  float fVar5;
  undefined4 uVar6;
  
  uVar3 = DAT_ffffb702;
  if (DAT_ffffd201 == '\x01') {
    DAT_ffffcbdd = 0;
    DAT_ffffcbde = 0;
    DAT_ffffcbdc = 0;
    DAT_ffffcbdf = 0;
    DAT_ffffcbe0 = '\0';
    uVar1 = 1;
  }
  else {
    uVar1 = 2000;
    if (DAT_ffffbb06 == 2000) {
      uVar1 = 0x3f800000;
      uVar6 = 0;
      fVar4 = (float)FUN_000024c0(0x3f800000,0,(int)(short)DAT_ffffb702);
      fVar5 = (float)FUN_000024c0(0x3e800000,uVar6,4);
      uVar2 = FUN_00002490(fVar4 * fVar5,uVar1,uVar6);
      if ((uVar3 < DAT_ffffcbe2) || (uVar2 < DAT_ffffcbd2)) {
        DAT_ffffcbdd = 1;
        DAT_ffffcbde = 0;
      }
      else {
        DAT_ffffcbdd = 0;
        DAT_ffffcbde = 1;
        uVar3 = FUN_00002490(fVar4 * 0.9,uVar1,uVar6);
        if (uVar3 < DAT_ffffb6fc) {
          DAT_ffffcbdf = 1;
        }
        if (uVar3 < DAT_ffffb6fe) {
          DAT_ffffcbe0 = '\x01';
        }
        DAT_ffffcbdc = DAT_ffffcbe0 << 1 | DAT_ffffcbdf;
      }
      uVar1 = FUN_0004565c();
      DAT_ffffcbdc = 0;
      DAT_ffffb6fc = 0;
      DAT_ffffb6fe = 0;
      DAT_ffffcbe6 = 0;
      DAT_ffffcbea = 0;
      DAT_ffffcbd2 = 0;
      DAT_ffffbb08 = 0;
      DAT_ffffcbdf = 0;
      DAT_ffffcbe0 = '\0';
    }
  }
  return uVar1;
}


