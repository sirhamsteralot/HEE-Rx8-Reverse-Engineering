/* ROM address: 0x00060956; body bytes: 26; decompiled */

void FUN_00060956(void)

{
  undefined1 *puVar1;
  ushort uVar2;
  
  uVar2 = 0;
  puVar1 = &DAT_ffffd5ac;
  do {
    uVar2 = uVar2 + 1;
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  } while (uVar2 < 0x8c);
  DAT_ffffd3fc = 0;
  return;
}


