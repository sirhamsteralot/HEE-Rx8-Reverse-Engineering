/* ROM address: 0x00060cc0; body bytes: 24; decompiled */

void FUN_00060cc0(void)

{
  undefined2 *puVar1;
  
  puVar1 = &DAT_ffffd6c8;
  do {
    *puVar1 = 0xffff;
    puVar1 = puVar1 + 2;
  } while (puVar1 < &DAT_ffffd6d0);
  return;
}


