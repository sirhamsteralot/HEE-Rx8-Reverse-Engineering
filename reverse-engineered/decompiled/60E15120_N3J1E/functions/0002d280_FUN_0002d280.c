/* ROM address: 0x0002d280; body bytes: 86; decompiled */

undefined1 * FUN_0002d280(void)

{
  char cVar2;
  undefined1 *puVar1;
  
  cVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff8664,0);
  if ((((cVar2 == '\0') || (DAT_ffffaa68 == '\0')) || (DAT_ffffbd5c == '\x01')) ||
     ((puVar1 = (undefined1 *)(uint)DAT_ffffbd49, puVar1 == (undefined1 *)0x1 &&
      (DAT_ffffbfa0 < 22.5)))) {
    puVar1 = &DAT_ffffbce9;
    DAT_ffffbce9 = 1;
  }
  else {
    DAT_ffffbce9 = 0;
  }
  return puVar1;
}


