/* ROM address: 0x000606d4; body bytes: 42; decompiled */

void FUN_000606d4(void)

{
  undefined1 *puVar1;
  ushort uVar2;
  
  puVar1 = &DAT_ffffd3fe;
  uVar2 = 0;
  do {
    *puVar1 = 0;
    uVar2 = uVar2 + 1;
    puVar1 = puVar1 + 1;
  } while (uVar2 < 0x96);
  uVar2 = 0;
  puVar1 = &DAT_ffffd494;
  do {
    uVar2 = uVar2 + 1;
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  } while (uVar2 < 0x8c);
  return;
}


