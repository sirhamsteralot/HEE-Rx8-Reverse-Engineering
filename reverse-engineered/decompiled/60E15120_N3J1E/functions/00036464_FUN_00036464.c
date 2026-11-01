/* ROM address: 0x00036464; body bytes: 156; decompiled */

undefined1 * FUN_00036464(void)

{
  undefined1 *puVar1;
  uint uVar2;
  
  puVar1 = (undefined1 *)-((((int)inferred_ram_c1d3_ffffc1d3_ffffc1d3 & 0x80U) == 0) - 1);
  if (((puVar1 == (undefined1 *)((int)&vector_Poweron_Reset + 1U)) &&
      (puVar1 = (undefined1 *)(uint)inferred_ram_c1d2_ffffc1d2_ffffc1d2, puVar1 == (undefined1 *)0x55)) &&
     (puVar1 = (undefined1 *)(uint)DAT_ffffc247,
     puVar1 == (undefined1 *)((int)&vector_Poweron_Reset + 1U))) {
    uVar2 = (uint)inferred_ram_c1d4_ffffc1d4_ffffc1d4 * 600;
    if (0xffff < uVar2) {
      uVar2 = 0xffff;
    }
    if ((uVar2 & 0xffff) <= (uint)DAT_ffffc234) {
      inferred_ram_c1d2_ffffc1d2_ffffc1d2 = 0xaa;
      DAT_ffffc247 = 0;
      DAT_ffffc23e = 1;
      DAT_ffffc236 = 0;
      return &DAT_ffffc23e;
    }
    if (DAT_ffffc236 != 0xff) {
      DAT_ffffc236 = DAT_ffffc236 + 1;
    }
    if (0x18 < DAT_ffffc236) {
      if (DAT_ffffc234 != 0xffff) {
        DAT_ffffc234 = DAT_ffffc234 + 1;
      }
      DAT_ffffc236 = 0;
    }
  }
  return puVar1;
}


