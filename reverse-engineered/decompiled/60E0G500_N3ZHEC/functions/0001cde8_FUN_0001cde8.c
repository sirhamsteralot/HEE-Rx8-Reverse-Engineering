/* ROM address: 0x0001cde8; body bytes: 38; decompiled */

void FUN_0001cde8(void)

{
  undefined4 *puVar1;
  byte bVar2;
  
  bVar2 = 1;
  puVar1 = &DAT_ffffaf44;
  DAT_ffffae64 = 0x3f800000;
  DAT_ffffae68 = 0x3f800000;
  DAT_ffffae6c = 0x3f800000;
  do {
    bVar2 = bVar2 + 1;
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  } while (bVar2 < 0x15);
  return;
}


