/* ROM address: 0x00044424; body bytes: 100; decompiled */

undefined4 * FUN_00044424(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  float extraout_fr0;
  
  puVar1 = (undefined4 *)(uint)DAT_ffffcab4;
  if (puVar1 == (undefined4 *)&UNK_00000001) {
    puVar1 = &DAT_0007b410;
    if (DAT_ffffca40 < 20.0) {
      if (DAT_ffffca40 <= 0.0) {
        DAT_ffffca28 = 0.0;
      }
      else {
        uVar2 = FUN_00002500(0x3f800000,0,(int)DAT_ffffcaad);
        puVar1 = (undefined4 *)FUN_000020dc(DAT_ffffca90,uVar2,&PTR_DAT_0006bc9c);
        DAT_ffffca28 = (DAT_ffffca60 + DAT_ffffca44 * extraout_fr0) - DAT_ffffca84;
      }
    }
    else {
      DAT_ffffca28 = 20.0;
    }
  }
  return puVar1;
}


