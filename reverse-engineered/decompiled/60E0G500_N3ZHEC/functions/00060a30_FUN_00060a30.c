/* ROM address: 0x00060a30; body bytes: 24; decompiled */

void FUN_00060a30(void)

{
  undefined1 *puVar1;
  ushort uVar2;
  
  puVar1 = &DAT_ffffd638;
  uVar2 = 0;
  do {
    *puVar1 = 0;
    uVar2 = uVar2 + 1;
    puVar1 = puVar1 + 1;
  } while (uVar2 < 0x8c);
  return;
}


