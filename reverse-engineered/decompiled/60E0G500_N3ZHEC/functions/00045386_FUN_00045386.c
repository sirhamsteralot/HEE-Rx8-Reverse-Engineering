/* ROM address: 0x00045386; body bytes: 226; decompiled */

undefined4 * FUN_00045386(void)

{
  char cVar1;
  undefined4 *puVar2;
  
  cVar1 = DAT_ffffb704;
  puVar2 = (undefined4 *)(uint)DAT_ffffd201;
  if (puVar2 == (undefined4 *)&UNK_00000001) {
    DAT_ffffcbd0 = 0;
    DAT_ffffcbd2 = 0;
    DAT_ffffcbd8 = 0;
  }
  else {
    if ((((DAT_ffffcbd4 <= DAT_ffffbab8) && (DAT_ffffbab8 <= DAT_ffffbae8)) &&
        (puVar2 = (undefined4 *)(uint)DAT_ffffb70c, puVar2 == (undefined4 *)&UNK_00000001)) &&
       ((puVar2 = (undefined4 *)(int)DAT_ffffb5aa, puVar2 == (undefined4 *)0x0 &&
        (((4000.0 <= DAT_ffffb5b8 || (puVar2 = &DAT_0007bd24, DAT_ffffbc1c < 0.0)) ||
         ((DAT_ffffb704 == '\0' && (DAT_ffffcbd8 == 0)))))))) {
      if (DAT_ffffcbd0 < 1000) {
        puVar2 = (undefined4 *)FUN_00002460((int)(short)DAT_ffffcbd0,1);
        DAT_ffffcbd0 = (ushort)puVar2;
      }
      else {
        DAT_ffffcbd0 = 1000;
      }
      if (DAT_ffffcbd2 < 1000) {
        puVar2 = (undefined4 *)FUN_00002460((int)(short)DAT_ffffcbd2,1);
        DAT_ffffcbd2 = (ushort)puVar2;
      }
      else {
        DAT_ffffcbd2 = 1000;
      }
    }
    if (cVar1 == '\0') {
      if (DAT_ffffcbd8 != 0) {
        DAT_ffffcbd8 = DAT_ffffcbd8 + -1;
      }
    }
    else {
      DAT_ffffcbd8 = 0x28;
    }
  }
  return puVar2;
}


