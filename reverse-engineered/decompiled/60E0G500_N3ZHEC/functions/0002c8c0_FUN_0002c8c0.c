/* ROM address: 0x0002c8c0; body bytes: 98; decompiled */

int FUN_0002c8c0(void)

{
  int iVar1;
  byte *pbVar2;
  
  pbVar2 = (byte *)&DAT_ffffbc97;
  if ((DAT_ffffbc97 != '\0') &&
     (iVar1 = FUN_00004144(&DAT_ffffbc97,DAT_ffffa415,(int)DAT_ffffa415,6), iVar1 == 0)) {
    *pbVar2 = *pbVar2 - 1;
  }
  iVar1 = FUN_00004144();
  if (iVar1 == 0) {
    if (*pbVar2 == 0) {
      DAT_ffffbc8c = 0;
      DAT_ffffbc96 = 0;
    }
    if (*pbVar2 < 0x65) {
      DAT_ffffbc90 = 0;
    }
  }
  return iVar1;
}


