/* ROM address: 0x0004ede2; body bytes: 104; decompiled */

undefined1 * FUN_0004ede2(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)(uint)DAT_ffffcfbd;
  if (puVar2 == (undefined1 *)((int)&vector_Poweron_Reset + 1)) {
    if (DAT_ffffcfd2 == '\0') {
      DAT_ffffcfba = 1;
      puVar1 = (undefined1 *)((int)&vector_Poweron_Reset + 1);
    }
    else {
      puVar1 = (undefined1 *)0x0;
      if (DAT_ffffcfac == '\0') {
        DAT_ffffcfba = 0;
      }
    }
  }
  else {
    DAT_ffffcfba = 0;
    puVar1 = puVar2;
  }
  if (puVar2 == (undefined1 *)0x0) {
    if (DAT_ffffcfd2 == '\x01') {
      DAT_ffffcfbb = 1;
      puVar1 = (undefined1 *)((int)&vector_Poweron_Reset + 1);
    }
    else {
      puVar1 = &DAT_0007d4fc;
      if (DAT_ffffcfae == '\0') {
        DAT_ffffcfbb = 0;
      }
    }
  }
  else {
    DAT_ffffcfbb = 0;
  }
  DAT_ffffcfd2 = DAT_ffffcfbd;
  return puVar1;
}


