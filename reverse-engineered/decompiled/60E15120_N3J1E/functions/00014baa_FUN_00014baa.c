/* ROM address: 0x00014baa; body bytes: 250; decompiled */

undefined2 * FUN_00014baa(void)

{
  undefined2 *puVar1;
  
  if (DAT_ffffa823 == DAT_ffffbd69) {
    if (DAT_ffffa80c != 0) {
      DAT_ffffa80c = DAT_ffffa80c + -1;
    }
  }
  else {
    DAT_ffffa80c = 0x1f;
  }
  if (DAT_ffffa824 == DAT_ffffb53c) {
    if (DAT_ffffa80e != 0) {
      DAT_ffffa80e = DAT_ffffa80e + -1;
    }
  }
  else {
    DAT_ffffa80e = 0x1f;
  }
  if ((DAT_ffffad18 == '\x01') && (DAT_ffffa825 == '\0')) {
    DAT_ffffa810 = 0xc;
  }
  else if (DAT_ffffa810 != 0) {
    DAT_ffffa810 = DAT_ffffa810 + -1;
  }
  if ((DAT_ffffad18 == '\0') && (DAT_ffffa825 == '\x01')) {
    DAT_ffffa812 = 0x5c;
    puVar1 = (undefined2 *)((int)&vector_Poweron_Reset + 1);
  }
  else {
    puVar1 = (undefined2 *)(int)DAT_ffffa812;
    if (puVar1 != (undefined2 *)0x0) {
      DAT_ffffa812 = DAT_ffffa812 + -1;
    }
  }
  if ((((DAT_ffffa80c == 0) && (DAT_ffffa80e == 0)) &&
      (puVar1 = (undefined2 *)(int)DAT_ffffa810, puVar1 == (undefined2 *)0x0)) &&
     (puVar1 = &DAT_ffffa812, DAT_ffffa812 == 0)) {
    DAT_ffffa7b5 = 0;
  }
  else {
    DAT_ffffa7b5 = 1;
  }
  DAT_ffffa823 = DAT_ffffbd69;
  DAT_ffffa824 = DAT_ffffb53c;
  DAT_ffffa825 = DAT_ffffad18;
  return puVar1;
}


