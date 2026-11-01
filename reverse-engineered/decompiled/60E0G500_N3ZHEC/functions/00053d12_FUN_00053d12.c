/* ROM address: 0x00053d12; body bytes: 134; decompiled */

undefined4 * FUN_00053d12(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = FUN_0003eb72(0,&DAT_ffff86a4);
  DAT_ffffd1c0 = (float)FUN_00002068(uVar2,&DAT_0006b948);
  DAT_ffffd1c4 = (float)FUN_00002068(uVar2,&DAT_0006b954);
  puVar1 = (undefined4 *)0x1;
  if ((DAT_ffffd201 == '\x01') ||
     (puVar1 = (undefined4 *)(uint)DAT_ffffcfb4, puVar1 == (undefined4 *)0x1)) {
    DAT_ffffd1be = 0;
  }
  else if ((DAT_ffffd1ac < DAT_ffffd1c0) &&
          (((puVar1 = &DAT_ffffd1b8, DAT_ffffd1b8 < DAT_ffffd1c4 &&
            (puVar1 = (undefined4 *)(uint)DAT_ffffd002, puVar1 == (undefined4 *)0x1)) &&
           (puVar1 = (undefined4 *)(uint)DAT_ffffd1bd, (undefined4 *)0x2 < puVar1)))) {
    DAT_ffffd1be = 1;
  }
  return puVar1;
}


