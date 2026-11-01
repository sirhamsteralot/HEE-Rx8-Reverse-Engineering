/* ROM address: 0x000507bc; body bytes: 152; decompiled */

undefined1 * FUN_000507bc(void)

{
  ushort uVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar1 = DAT_ffffcfe6;
  uVar4 = 0;
  uVar3 = FUN_0003eb72(0,&DAT_ffff86a4);
  DAT_ffffd0b4 = FUN_000020c4(uVar3,&DAT_0006b850);
  if (DAT_ffffd201 == '\x01') {
    puVar2 = (undefined1 *)FUN_0003ec20(uVar4,&DAT_ffff86ac);
    return puVar2;
  }
  if (((DAT_ffffd07c != '\x01') || (DAT_ffffd0b4 < uVar1)) &&
     ((DAT_ffffcfc1 < 0x28 || ((uVar1 <= DAT_ffffcfe4 || (DAT_ffffd034 != '\0')))))) {
    return &DAT_0007d959;
  }
  puVar2 = (undefined1 *)FUN_0003ec20(DAT_ffffd01c - DAT_ffffd024,&DAT_ffff86ac);
  return puVar2;
}


