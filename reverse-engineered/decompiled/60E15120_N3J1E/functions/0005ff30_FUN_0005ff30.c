/* ROM address: 0x0005ff30; body bytes: 42; decompiled */

void FUN_0005ff30(void)

{
  undefined1 *puVar1;
  ushort uVar2;
  
  puVar1 = &DAT_ffffd3c2;
  uVar2 = 0;
  do {
    *puVar1 = 0;
    uVar2 = uVar2 + 1;
    puVar1 = puVar1 + 1;
  } while (uVar2 < 0x96);
  uVar2 = 0;
  puVar1 = &DAT_ffffd458;
  do {
    uVar2 = uVar2 + 1;
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  } while (uVar2 < 0x8c);
  return;
}


