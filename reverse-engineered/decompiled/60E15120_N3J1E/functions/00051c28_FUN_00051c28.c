/* ROM address: 0x00051c28; body bytes: 86; decompiled */

undefined1 * FUN_00051c28(void)

{
  char cVar2;
  undefined1 *puVar1;
  
  cVar2 = ref_readValue_8bit_ADDRESS_VAL(&DAT_ffff86c4,0x17);
  puVar1 = (undefined1 *)0x0;
  if ((cVar2 == '\0') ||
     ((((DAT_ffffd0f2 == '\x01' && (DAT_ffffcfaa == 0x88)) && (DAT_ffffd0f4 == '\0')) &&
      (puVar1 = &DAT_ffffd0f5, DAT_ffffd0f5 == '\0')))) {
    DAT_ffffd0f3 = 1;
  }
  else {
    puVar1 = (undefined1 *)0x0;
    DAT_ffffd0f3 = 0;
  }
  return puVar1;
}


