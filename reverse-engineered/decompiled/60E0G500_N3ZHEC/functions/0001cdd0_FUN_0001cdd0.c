/* ROM address: 0x0001cdd0; body bytes: 24; decompiled */

void FUN_0001cdd0(void)

{
  undefined4 *puVar1;
  byte bVar2;
  
  puVar1 = &DAT_ffffaee4;
  bVar2 = 1;
  do {
    *puVar1 = 0;
    bVar2 = bVar2 + 1;
    puVar1 = puVar1 + 1;
  } while (bVar2 < 0x16);
  return;
}


