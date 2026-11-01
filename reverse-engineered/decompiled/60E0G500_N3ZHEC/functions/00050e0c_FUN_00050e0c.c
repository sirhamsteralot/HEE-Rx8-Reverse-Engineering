/* ROM address: 0x00050e0c; body bytes: 168; decompiled */

undefined * FUN_00050e0c(void)

{
  byte bVar2;
  byte bVar3;
  undefined *puVar1;
  undefined4 uVar4;
  undefined4 uVar5;
  
  bVar2 = FUN_0003eaa4(&DAT_ffff86c8,0);
  bVar3 = FUN_0003eaa4(&DAT_ffff86ca,0);
  uVar5 = 0;
  uVar4 = FUN_0003eb72(0,&DAT_ffff86a4);
  DAT_ffffd0b2 = FUN_000020c4(uVar4,&DAT_0006b844);
  if (DAT_ffffd201 == '\x01') {
    puVar1 = (undefined *)FUN_0003ec20(uVar5,&DAT_ffff86bc);
  }
  else {
    puVar1 = &DAT_ffffd0c0;
    if ((DAT_ffffd0c0 == '\0') && (puVar1 = (undefined *)(uint)bVar3, puVar1 == &UNK_00000001)) {
      uVar4 = DAT_ffffd060;
      if (DAT_ffffcfe6 <= DAT_ffffd0b2) {
        uVar4 = DAT_ffffd05c;
      }
      puVar1 = (undefined *)FUN_0003ec20(uVar4,&DAT_ffff86bc);
    }
    else if ((DAT_ffffd0bf == '\0') && (puVar1 = (undefined *)(uint)bVar2, puVar1 == &UNK_00000001))
    {
      puVar1 = (undefined *)FUN_0003ec20(DAT_ffffd060,&DAT_ffff86bc);
    }
  }
  DAT_ffffd0c0 = bVar3;
  DAT_ffffd0bf = bVar2;
  return puVar1;
}


