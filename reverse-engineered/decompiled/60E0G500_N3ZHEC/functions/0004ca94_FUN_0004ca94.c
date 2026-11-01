/* ROM address: 0x0004ca94; body bytes: 136; decompiled */

undefined * FUN_0004ca94(void)

{
  ushort uVar1;
  undefined *puVar2;
  undefined *puVar3;
  
  uVar1 = DAT_fffff72c;
  DAT_ffffceda = (uVar1 & 0x1000) == 0;
  uVar1 = DAT_fffff72c;
  DAT_ffffcedb = (uVar1 & 0x2000) == 0;
  puVar3 = (undefined *)(uint)DAT_ffffa1bc;
  puVar2 = &DAT_ffffcee8;
  if (puVar3 == (undefined *)(uint)DAT_ffffcee8) {
    if (puVar3 == (undefined *)0x0) {
      DAT_ffffced3 = 1;
      DAT_ffffced0 = 0;
      DAT_ffffced1 = 0;
    }
    else {
      puVar2 = puVar3;
      if (puVar3 == &UNK_00000002) {
        DAT_ffffced1 = 1;
        DAT_ffffced3 = 0;
        DAT_ffffced0 = 0;
      }
      else {
        if (puVar3 != &UNK_00000001) {
          if (puVar3 != &UNK_00000003) {
            DAT_ffffcee8 = DAT_ffffa1bc;
            return puVar3;
          }
          DAT_ffffced0 = 0;
          DAT_ffffced1 = 0;
          DAT_ffffced2 = 1;
          DAT_ffffced3 = 0;
          DAT_ffffcee8 = DAT_ffffa1bc;
          return puVar3;
        }
        DAT_ffffced0 = 1;
        DAT_ffffced3 = 0;
        DAT_ffffced1 = 0;
      }
    }
    DAT_ffffced2 = 0;
  }
  DAT_ffffcee8 = DAT_ffffa1bc;
  return puVar2;
}


