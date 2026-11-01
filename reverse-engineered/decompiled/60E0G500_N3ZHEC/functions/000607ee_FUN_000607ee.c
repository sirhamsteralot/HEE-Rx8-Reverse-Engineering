/* ROM address: 0x000607ee; body bytes: 24; decompiled */

void FUN_000607ee(void)

{
  undefined1 *puVar1;
  ushort uVar2;
  
  uVar2 = 0;
  puVar1 = &DAT_ffffd520;
  do {
    uVar2 = uVar2 + 1;
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  } while (uVar2 < 0x8c);
  return;
}


