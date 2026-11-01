/* ROM address: 0x00023d40; body bytes: 78; decompiled */

undefined2 * FUN_00023d40(void)

{
  char cVar1;
  
  cVar1 = FUN_0003eaa4(&DAT_ffff80c6,0);
  if (((cVar1 == '\x01') && (DAT_ffffb55e == '\0')) &&
     (cVar1 = FUN_0003eaa4(&DAT_ffff8766,0), cVar1 == '\0')) {
    DAT_ffffb478 = 0;
    return (undefined2 *)0x0;
  }
  if (0x270 < DAT_ffffaa7e) {
    DAT_ffffb478 = 0;
    return &DAT_0007c2ba;
  }
  DAT_ffffb478 = 1;
  return (undefined2 *)&UNK_00000001;
}


