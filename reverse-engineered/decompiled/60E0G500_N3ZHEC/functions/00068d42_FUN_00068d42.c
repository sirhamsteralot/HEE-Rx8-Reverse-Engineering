/* ROM address: 0x00068d42; body bytes: 130; decompiled */

uint isotp_first_frame_accept(void)

{
  uint uVar1;
  
  uVar1 = (DAT_ffffde04 & 0xf) * 0x100 + (uint)DAT_ffffde05;
  if ((uVar1 < 0x1000) && (7 < uVar1)) {
    DAT_ffffde31 = DAT_ffffde31 | 4;
    FUN_00068b58();
    DAT_ffffde28 = uds_rx_channel_alloc((int)DAT_ffffde06);
    DAT_ffffde27 = 2;
    DAT_ffffde22 = (undefined2)uVar1;
    DAT_ffffde26 = DAT_ffffde06;
    DAT_ffffde24 = 6;
    DAT_ffffde29 = 1;
    FUN_000685c0((int)DAT_ffffde28,&DAT_ffffde06,6);
    FUN_0006936a(6,5);
    uVar1 = thunk_FUN_00055306((int)DAT_ffffde26);
    return uVar1;
  }
  return (uint)DAT_ffffde05;
}


