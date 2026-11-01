/* ROM address: 0x000681c8; body bytes: 68; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_000681c8(void)

{
  undefined2 *puVar1;
  
  _DAT_ffff8fdc = FUN_00002430(0);
  _DAT_ffff8fe0 = FUN_00002430(1);
  puVar1 = &DAT_ffff8fc8;
  do {
    *puVar1 = 0xffff;
    puVar1[2] = 0;
    puVar1[1] = 0;
    puVar1[3] = 0;
    *(undefined1 *)(puVar1 + 4) = 0xa7;
    puVar1 = puVar1 + 5;
  } while (puVar1 < &DAT_ffff8fdc);
  return 0xa7;
}


