/* ROM address: 0x0002d870; body bytes: 108; decompiled */

undefined4 * FUN_0002d870(void)

{
  char cVar2;
  undefined4 *puVar1;
  
  cVar2 = FUN_00002440(DAT_ffffa790,0,0x3727c5ac);
  puVar1 = (undefined4 *)(uint)DAT_ffffaada;
  if ((((puVar1 != (undefined4 *)0x1) || (cVar2 != '\0')) ||
      (puVar1 = &DAT_0002d970, 2000.0 <= DAT_ffffb5b8)) ||
     (puVar1 = (undefined4 *)(uint)DAT_ffffce58, puVar1 != (undefined4 *)0x1)) {
    DAT_ffffbd0c = DAT_ffffbd04 -
                   (DAT_ffffbd00 - DAT_ffffa640) * (DAT_ffffbd00 - DAT_ffffa640) * DAT_ffffbcfc;
  }
  else {
    DAT_ffffbd0c = DAT_ffffbd08;
  }
  return puVar1;
}


