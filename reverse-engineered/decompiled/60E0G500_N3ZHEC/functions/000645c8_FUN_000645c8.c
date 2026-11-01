/* ROM address: 0x000645c8; body bytes: 84; decompiled */

void FUN_000645c8(void)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)&DAT_ffff8d7c;
  do {
    *(undefined1 *)puVar1 = 0;
    *(undefined1 *)((int)puVar1 + 1) = 0;
    puVar1 = puVar1 + 1;
  } while (puVar1 < &DAT_ffff8e94);
  DAT_ffff8e94 = FUN_00002420(0xa5);
  DAT_ffff8e96 = FUN_00002420(0xa5);
  DAT_ffff8e98 = FUN_00002420(0xa5);
  DAT_ffff8e9a = FUN_00002420(0);
  DAT_ffff8e9c = FUN_00002420(0);
  return;
}


