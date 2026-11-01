/* ROM address: 0x00063444; body bytes: 108; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00063444(void)

{
  undefined2 *puVar1;
  
  _DAT_ffff8928 = FUN_00002430(0);
  _DAT_ffff892c = FUN_00002430(1);
  puVar1 = &DAT_ffff87d8;
  do {
    *puVar1 = 0xffff;
    puVar1[1] = 0xffff;
    puVar1[2] = 0xffff;
    *(undefined1 *)(puVar1 + 3) = 0;
    *(undefined1 *)((int)puVar1 + 7) = 0;
    *(undefined1 *)(puVar1 + 4) = 3;
    *(undefined1 *)((int)puVar1 + 9) = 0x28;
    *(undefined1 *)(puVar1 + 5) = 0x50;
    *(undefined1 *)((int)puVar1 + 0xb) = 0;
    *(undefined1 *)(puVar1 + 6) = 0;
    *(undefined1 *)((int)puVar1 + 0xd) = 8;
    *(undefined1 *)(puVar1 + 7) = 0x28;
    puVar1 = puVar1 + 8;
  } while (puVar1 < &DAT_ffff8928);
  return 0x28;
}


