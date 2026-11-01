/* ROM address: 0x00068fca; body bytes: 66; decompiled */

void FUN_00068fca(void)

{
  DAT_ffffde0c = DAT_ffffde0c | DAT_ffffde1f;
  FUN_0006861c((int)DAT_ffffde1e,&DAT_ffffde0d,7);
  if (DAT_ffffde1f < 0xf) {
    DAT_ffffde1f = DAT_ffffde1f + 1;
  }
  else {
    DAT_ffffde1f = '\0';
  }
  DAT_ffffde1d = 10;
  FUN_0006936a(4,0x30);
  return;
}


