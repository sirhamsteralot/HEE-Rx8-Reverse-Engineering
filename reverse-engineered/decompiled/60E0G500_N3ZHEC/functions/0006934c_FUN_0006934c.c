/* ROM address: 0x0006934c; body bytes: 30; decompiled */

void FUN_0006934c(void)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  
  puVar2 = &DAT_ffffde38;
  puVar1 = &DAT_ffffde40;
  do {
    *puVar1 = 0;
    *puVar2 = 0;
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
  } while (puVar1 < &DAT_ffffde5c);
  return;
}


