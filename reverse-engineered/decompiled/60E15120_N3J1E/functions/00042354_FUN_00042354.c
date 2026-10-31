/* ROM address: 0x00042354; body bytes: 84; decompiled */

undefined1 * FUN_00042354(void)

{
  uint uVar1;
  undefined1 *puVar2;
  
  uVar1 = ref_getFaultStatus__(0x1b);
  puVar2 = (undefined1 *)(uVar1 & 0xff);
  if (puVar2 == (undefined1 *)0x0) {
    uVar1 = ref_getFaultStatus__(0x1a);
    puVar2 = (undefined1 *)(uVar1 & 0xff);
    if (puVar2 == (undefined1 *)0x0) {
      uVar1 = ref_getFaultStatus__(0x19);
      puVar2 = (undefined1 *)(uVar1 & 0xff);
      if (((puVar2 == (undefined1 *)0x0) &&
          (puVar2 = (undefined1 *)(uint)DAT_ffffb358,
          puVar2 == (undefined1 *)((int)&vector_Poweron_Reset + 1U))) && (DAT_ffffd1c5 == '\0')) {
        DAT_ffffc978 = 1;
        return &DAT_ffffc978;
      }
    }
  }
  DAT_ffffc978 = 0;
  return puVar2;
}


