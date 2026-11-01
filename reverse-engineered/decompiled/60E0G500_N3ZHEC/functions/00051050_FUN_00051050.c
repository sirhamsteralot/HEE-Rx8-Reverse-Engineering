/* ROM address: 0x00051050; body bytes: 116; decompiled */

undefined2 * FUN_00051050(void)

{
  uint uVar1;
  uint uVar2;
  undefined2 *puVar3;
  int iVar4;
  
  uVar1 = FUN_0003eaa4(&DAT_ffff86c4,0);
  uVar2 = FUN_0003eaa4(&DAT_ffff8fe4,0);
  puVar3 = (undefined2 *)(uVar2 & 0xff);
  if (((puVar3 == (undefined2 *)&UNK_00000001) && (puVar3 = &DAT_0007d2b6, DAT_ffffa426 == 0x249))
     && (puVar3 = (undefined2 *)-(((DAT_ffffcff1 & 0x20) == 0) - 1),
        puVar3 == (undefined2 *)&UNK_00000001)) {
    if ((uVar1 & 0xff) == 3) {
      puVar3 = (undefined2 *)FUN_0003ebc0(&DAT_ffff86c4,0);
    }
    else {
      if ((uVar1 & 0xff) < 3) {
        iVar4 = uVar1 + 1;
      }
      else {
        iVar4 = 3;
      }
      puVar3 = (undefined2 *)FUN_0003ebc0(&DAT_ffff86c4,iVar4);
    }
  }
  return puVar3;
}


