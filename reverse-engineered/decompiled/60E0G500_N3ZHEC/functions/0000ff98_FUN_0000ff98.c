/* ROM address: 0x0000ff98; body bytes: 62; decompiled */

void FUN_0000ff98(void)

{
  undefined2 *puVar1;
  
  if ((DAT_ffffa428 == '\0') || (DAT_ffffbea8 != '\0')) {
    DAT_ffffa574 = 0;
  }
  else {
    DAT_ffffa574 = 2;
  }
  puVar1 = (undefined2 *)&DAT_ffffa4b4;
  do {
    *(undefined1 *)(puVar1 + 3) = 1;
    puVar1 = puVar1 + 0x2c;
  } while (puVar1 < &DAT_ffffa564);
  return;
}


