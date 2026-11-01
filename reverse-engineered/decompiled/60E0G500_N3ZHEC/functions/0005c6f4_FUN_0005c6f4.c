/* ROM address: 0x0005c6f4; body bytes: 26; decompiled */

void FUN_0005c6f4(void)

{
  undefined2 *puVar1;
  byte bVar2;
  
  puVar1 = &DAT_0005fecc;
  bVar2 = 0;
  do {
    bVar2 = bVar2 + 1;
    **(undefined1 **)(puVar1 + 6) = 0;
    puVar1 = puVar1 + 8;
  } while (bVar2 < 0x1a);
  return;
}


