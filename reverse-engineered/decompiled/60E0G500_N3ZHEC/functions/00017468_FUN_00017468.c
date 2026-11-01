/* ROM address: 0x00017468; body bytes: 98; decompiled */

uint FUN_00017468(void)

{
  uint uVar1;
  undefined4 uVar2;
  float extraout_fr0;
  
  DAT_ffffa93e = 4 < DAT_ffffc0c6;
  uVar1 = (uint)(byte)DAT_ffffa93e;
  if (uVar1 == 1) {
    uVar2 = FUN_00002500(0x3f800000,0);
    uVar1 = FUN_00002068(uVar2,&PTR_PTR_0006b24c);
    DAT_ffffa8fc = extraout_fr0;
  }
  else {
    DAT_ffffa8fc = DAT_ffffa8fc - 0.16;
    if (DAT_ffffa8fc < 0.0) {
      DAT_ffffa8fc = 0.0;
    }
  }
  return uVar1;
}


