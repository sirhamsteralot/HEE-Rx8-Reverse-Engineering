/* ROM address: 0x000329fc; body bytes: 156; decompiled */

undefined1 * FUN_000329fc(void)

{
  undefined1 *puVar1;
  float fVar2;
  
  fVar2 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(0,&DAT_ffff866c);
  puVar1 = &DAT_ffffbfd7;
  if ((((DAT_ffffbfd7 == '\0') &&
       (puVar1 = (undefined1 *)(uint)DAT_ffffbfba,
       puVar1 == (undefined1 *)((int)&vector_Poweron_Reset + 1))) ||
      ((DAT_ffffbfd8 == '\0' &&
       (puVar1 = (undefined1 *)(uint)DAT_ffffbfb9,
       puVar1 == (undefined1 *)((int)&vector_Poweron_Reset + 1))))) ||
     ((((DAT_ffffbfda == '\0' &&
        (puVar1 = (undefined1 *)(uint)DAT_ffffbfb8,
        puVar1 == (undefined1 *)((int)&vector_Poweron_Reset + 1))) || (DAT_ffffbced == '\0')) ||
      (DAT_ffffbfa0 - fVar2 <= 0.1)))) {
    DAT_ffffbfbc = 0;
  }
  else {
    puVar1 = (undefined1 *)(int)(char)DAT_ffffbfd9;
    if ((puVar1 == (undefined1 *)0x0) &&
       (puVar1 = (undefined1 *)(uint)DAT_ffffbfb6,
       puVar1 == (undefined1 *)((int)&vector_Poweron_Reset + 1))) {
      DAT_ffffbfbc = 1;
    }
  }
  DAT_ffffbfd7 = DAT_ffffbfba;
  DAT_ffffbfd8 = DAT_ffffbfb9;
  DAT_ffffbfd9 = DAT_ffffbfb6;
  DAT_ffffbfda = DAT_ffffbfb8;
  return puVar1;
}


