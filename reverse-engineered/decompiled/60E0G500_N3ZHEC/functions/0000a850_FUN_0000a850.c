/* ROM address: 0x0000a850; body bytes: 58; decompiled */

void FUN_0000a850(void)

{
  ushort uVar1;
  undefined4 local_c [2];
  
  FUN_00002054(local_c,0xe0);
  uVar1 = DAT_fffff738;
  DAT_fffff738 = uVar1 | 0x8000;
  FUN_0000239c(0x96);
  uVar1 = DAT_fffff738;
  DAT_fffff738 = uVar1 & 0x7fff;
  FUN_0000239c(0x96);
  FUN_00002064(local_c[0]);
  return;
}


