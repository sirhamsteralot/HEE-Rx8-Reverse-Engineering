/* ROM address: 0x00012dec; body bytes: 116; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x00012e42) */

undefined1 * FUN_00012dec(void)

{
  undefined1 *puVar1;
  
  if ((DAT_ffffa6a7 == '\x01') && (DAT_ffffb0cc == '\0')) {
    puVar1 = &DAT_00072307;
    DAT_ffffa688 = '\0';
  }
  else {
    puVar1 = (undefined1 *)(uint)DAT_ffffa6a8;
    if ((puVar1 == (undefined1 *)((int)&vector_Poweron_Reset + 1)) && (DAT_ffffb0cd == '\0')) {
      puVar1 = (undefined1 *)((int)&vector_Poweron_Reset + 1);
    }
    if (DAT_ffffa688 != '\0') {
      DAT_ffffa688 = DAT_ffffa688 + -1;
    }
  }
  DAT_ffffa6a7 = DAT_ffffb0cc;
  DAT_ffffa6a8 = DAT_ffffb0cd;
  return puVar1;
}


