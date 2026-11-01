/* ROM address: 0x00068708; body bytes: 70; decompiled */

uint FUN_00068708(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffffde33;
  if ((uVar1 == 1) && (uVar1 = (uint)DAT_ffffde31, (DAT_ffffde31 & 0x10) == 0)) {
    DAT_ffffde33 = 0;
    DAT_ffffde16 = 0xff;
    uVar1 = FUN_0006874e();
  }
  return uVar1;
}


