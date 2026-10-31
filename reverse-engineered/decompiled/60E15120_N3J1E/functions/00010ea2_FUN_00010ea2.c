/* ROM address: 0x00010ea2; body bytes: 30; decompiled */

void FUN_00010ea2(void)

{
  undefined1 *puVar1;
  
  puVar1 = &DAT_ffffa578;
  do {
    puVar1[2] = 1;
    puVar1 = puVar1 + 0x2c;
  } while (puVar1 < &DAT_ffffa5d0);
  return;
}


