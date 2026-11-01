/* ROM address: 0x00067c1a; body bytes: 126; decompiled_with_warnings */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00067c1a(void)

{
  undefined4 *puVar1;
  
  _DAT_ffff8fc0 = FUN_00002430(0);
  _DAT_ffff8fc4 = FUN_00002430(1);
  puVar1 = &DAT_ffff8ea8;
  do {
    *(undefined2 *)(puVar1 + 8) = 0xffff;
    *(undefined2 *)((int)puVar1 + 0x22) = 0;
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    *(undefined1 *)(puVar1 + 3) = 0;
    *(undefined1 *)((int)puVar1 + 0xd) = 0;
    *(undefined1 *)((int)puVar1 + 0xe) = 0;
    *(undefined1 *)((int)puVar1 + 0xf) = 0;
    *(undefined2 *)(puVar1 + 9) = 0;
    puVar1[4] = 0;
    puVar1[5] = 0;
    puVar1[6] = 0;
    *(undefined1 *)(puVar1 + 7) = 0;
    *(undefined1 *)((int)puVar1 + 0x1d) = 0;
    *(undefined1 *)((int)puVar1 + 0x1e) = 0;
    *(undefined1 *)((int)puVar1 + 0x1f) = 0;
    *(undefined1 *)((int)puVar1 + 0x26) = 0;
    *(undefined1 *)((int)puVar1 + 0x27) = 0xa7;
    puVar1 = puVar1 + 10;
  } while (puVar1 < &DAT_ffff8fc0);
  return 0x27;
}


