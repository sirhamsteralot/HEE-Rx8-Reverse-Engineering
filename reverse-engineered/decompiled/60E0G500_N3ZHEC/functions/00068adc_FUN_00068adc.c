/* ROM address: 0x00068adc; body bytes: 76; decompiled */

void FUN_00068adc(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00003920(0x90);
  if ((DAT_ffffde31 & 4) != 0) {
    DAT_ffffde34 = 0;
    (&DAT_ffffde30)[(uint)DAT_ffffde28 * 2] = 0;
    DAT_ffffde27 = 0;
    DAT_ffffde31 = DAT_ffffde31 & 0xfb;
    thunk_FUN_0005533c((int)DAT_ffffde26);
  }
  FUN_00003934(uVar1);
  return;
}


