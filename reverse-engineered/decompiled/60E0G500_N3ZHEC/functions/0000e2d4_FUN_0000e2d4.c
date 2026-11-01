/* ROM address: 0x0000e2d4; body bytes: 324; decompiled */

int FUN_0000e2d4(void)

{
  int iVar1;
  
  DAT_ffffa430 = 0;
  if ((((DAT_ffffa444 == '\x01') || (DAT_ffffa4a4 == '\x01')) || (DAT_ffffa9e8 == '\x01')) ||
     ((((DAT_ffffca0c == '\x01' || (DAT_ffffccb1 == '\x01')) ||
       ((DAT_ffffbcf2 == '\x01' || ((DAT_ffffccb2 == '\x01' || (DAT_ffffcab5 == '\x01')))))) ||
      ((DAT_ffffcdfe == '\x01' ||
       ((((DAT_ffffcdff == '\x01' || (DAT_ffffce00 == '\x01')) || (DAT_ffffce01 == '\x01')) ||
        (DAT_ffffc240 == '\0')))))))) {
    DAT_ffffa430 = 1;
  }
  iVar1 = 1;
  if (((DAT_ffffa445 == '\x01') || (iVar1 = 1, DAT_ffffa4a5 == '\x01')) ||
     ((((iVar1 = 1, DAT_ffffa9e8 == '\x01' ||
        ((iVar1 = 1, DAT_ffffca0c == '\x01' || (iVar1 = 1, DAT_ffffccb1 == '\x01')))) ||
       (iVar1 = 1, DAT_ffffbcf3 == '\x01')) ||
      ((((iVar1 = 1, DAT_ffffccb3 == '\x01' || (iVar1 = 1, DAT_ffffcab5 == '\x01')) ||
        (iVar1 = 1, DAT_ffffcdfe == '\x01')) ||
       (((iVar1 = 1, DAT_ffffcdff == '\x01' || (iVar1 = 1, DAT_ffffce00 == '\x01')) ||
        ((iVar1 = 1, DAT_ffffce01 == '\x01' || (iVar1 = (int)DAT_ffffc240, iVar1 == 0)))))))))) {
    DAT_ffffa430 = DAT_ffffa430 | 2;
  }
  return iVar1;
}


