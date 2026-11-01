/* ROM address: 0x00006884; body bytes: 350; decompiled */

void adc_scan_sweep_all_channels(void)

{
  byte bVar1;
  
  bVar1 = DAT_fffff819;
  DAT_fffff819 = bVar1 & 0xdf;
  DAT_fffff818 = 0x33;
  bVar1 = DAT_fffff819;
  DAT_fffff819 = bVar1 & 0x2f | 0x20;
  bVar1 = DAT_fffff839;
  DAT_fffff839 = bVar1 & 0xdf;
  DAT_fffff838 = 0x33;
  bVar1 = DAT_fffff839;
  DAT_fffff839 = bVar1 & 0x2f | 0x20;
  bVar1 = DAT_fffff859;
  DAT_fffff859 = bVar1 & 0xdf;
  DAT_fffff858 = 0x2b;
  bVar1 = DAT_fffff859;
  DAT_fffff859 = bVar1 & 0x2f | 0x20;
  DAT_ffff9f27 = 0;
  DAT_ffff9f28 = 0xff;
  DAT_ffff9f2a = 0;
  DAT_ffff9f2d = 0;
  DAT_ffff9f30 = 0;
  do {
    bVar1 = DAT_fffff818;
  } while ((bVar1 & 0x80) == 0);
  do {
    bVar1 = DAT_fffff838;
  } while ((bVar1 & 0x80) == 0);
  do {
    bVar1 = DAT_fffff858;
  } while ((bVar1 & 0x80) == 0);
  DAT_ffff9ee4 = DAT_fffff800;
  DAT_ffff9ee6 = DAT_fffff802;
  DAT_ffff9ee8 = DAT_fffff804;
  DAT_ffff9eea = DAT_fffff806;
  DAT_ffff9eec = DAT_fffff808;
  DAT_ffff9eee = DAT_fffff80a;
  DAT_ffff9ef0 = DAT_fffff80c;
  DAT_ffff9ef2 = DAT_fffff80e;
  DAT_ffff9ef4 = DAT_fffff810;
  DAT_ffff9ef6 = DAT_fffff812;
  DAT_ffff9ef8 = DAT_fffff814;
  DAT_ffff9efa = DAT_fffff816;
  DAT_ffff9efc = DAT_fffff820;
  DAT_ffff9efe = DAT_fffff822;
  DAT_ffff9f00 = DAT_fffff824;
  DAT_ffff9f02 = DAT_fffff826;
  DAT_ffff9f04 = DAT_fffff828;
  DAT_ffff9f06 = DAT_fffff82a;
  DAT_ffff9f08 = DAT_fffff82c;
  DAT_ffff9f0a = DAT_fffff82e;
  DAT_ffff9f0c = DAT_fffff830;
  DAT_ffff9f0e = DAT_fffff832;
  DAT_ffff9f10 = DAT_fffff834;
  DAT_ffff9f12 = DAT_fffff836;
  DAT_ffff9f14 = DAT_fffff840;
  DAT_ffff9f16 = DAT_fffff842;
  DAT_ffff9f18 = DAT_fffff844;
  DAT_ffff9f1a = DAT_fffff846;
  DAT_ffff9f1c = DAT_fffff848;
  DAT_ffff9f1e = DAT_fffff84a;
  DAT_ffff9f20 = DAT_fffff84c;
  DAT_ffff9f22 = DAT_fffff84e;
  return;
}


