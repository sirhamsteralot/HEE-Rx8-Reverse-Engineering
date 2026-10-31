/* ROM address: 0x0003290c; body bytes: 158; decompiled */

undefined1 * FUN_0003290c(void)

{
  undefined1 *puVar1;
  float fVar2;
  
  fVar2 = (float)ref_readValue_float_DEFAULTVAL_ADDRESS(0,&DAT_ffff866c);
  puVar1 = &DAT_ffffbfd3;
  if ((((DAT_ffffbfd3 == '\0') &&
       (puVar1 = (undefined1 *)(uint)DAT_ffffbfba,
       puVar1 == (undefined1 *)((int)&vector_Poweron_Reset + 1))) ||
      ((DAT_ffffbfd4 == '\0' &&
       (puVar1 = (undefined1 *)(uint)DAT_ffffbfb9,
       puVar1 == (undefined1 *)((int)&vector_Poweron_Reset + 1))))) ||
     ((((DAT_ffffbfd5 == '\0' &&
        (puVar1 = (undefined1 *)(uint)DAT_ffffbfb6,
        puVar1 == (undefined1 *)((int)&vector_Poweron_Reset + 1))) || (DAT_ffffbced == '\0')) ||
      (fVar2 - DAT_ffffbfa0 <= 0.1)))) {
    DAT_ffffbfbb = 0;
  }
  else {
    puVar1 = (undefined1 *)(int)(char)DAT_ffffbfd6;
    if ((puVar1 == (undefined1 *)0x0) &&
       (puVar1 = (undefined1 *)(uint)DAT_ffffbfb8,
       puVar1 == (undefined1 *)((int)&vector_Poweron_Reset + 1))) {
      DAT_ffffbfbb = 1;
    }
  }
  DAT_ffffbfd3 = DAT_ffffbfba;
  DAT_ffffbfd4 = DAT_ffffbfb9;
  DAT_ffffbfd5 = DAT_ffffbfb6;
  DAT_ffffbfd6 = DAT_ffffbfb8;
  return puVar1;
}


