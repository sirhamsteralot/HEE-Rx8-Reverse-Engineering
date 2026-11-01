/* ROM address: 0x00050d64; body bytes: 168; decompiled */

undefined * FUN_00050d64(void)

{
  byte bVar2;
  byte bVar3;
  undefined *puVar1;
  undefined4 uVar4;
  undefined4 uVar5;
  
  bVar2 = FUN_0003eaa4(&DAT_ffff86cc,0);
  bVar3 = FUN_0003eaa4(&DAT_ffff86ce,0);
  uVar5 = 0;
  uVar4 = FUN_0003eb72(0,&DAT_ffff86a4);
  DAT_ffffd0b0 = FUN_000020c4(uVar4,&DAT_0006b844);
  if (DAT_ffffd201 == '\x01') {
    puVar1 = (undefined *)FUN_0003ec20(uVar5,&DAT_ffff86b4);
  }
  else {
    puVar1 = &DAT_ffffd0be;
    if ((DAT_ffffd0be == '\0') && (puVar1 = (undefined *)(uint)bVar3, puVar1 == &UNK_00000001)) {
      uVar4 = DAT_ffffd058;
      if (DAT_ffffcfe6 <= DAT_ffffd0b0) {
        uVar4 = DAT_ffffd054;
      }
      puVar1 = (undefined *)FUN_0003ec20(uVar4,&DAT_ffff86b4);
    }
    else if ((DAT_ffffd0bd == '\0') && (puVar1 = (undefined *)(uint)bVar2, puVar1 == &UNK_00000001))
    {
      puVar1 = (undefined *)FUN_0003ec20(DAT_ffffd058,&DAT_ffff86b4);
    }
  }
  DAT_ffffd0be = bVar3;
  DAT_ffffd0bd = bVar2;
  return puVar1;
}


