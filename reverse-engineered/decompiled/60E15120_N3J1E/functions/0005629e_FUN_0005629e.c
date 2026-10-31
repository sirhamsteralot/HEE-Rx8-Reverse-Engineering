/* ROM address: 0x0005629e; body bytes: 110; decompiled */

undefined4 FUN_0005629e(void)

{
  char cVar1;
  
  if (((0.64 <= maf_voltage_latched_ffffa9e4) || (DAT_ffffa984 <= 4.8)) || ((DAT_ffff9ec8 & 0x20) == 0)) {
    DAT_ffffd1cd = 0;
  }
  else {
    DAT_ffffd1cd = 1;
  }
  cVar1 = FUN_00055e3e(4);
  if ((cVar1 == '\0') && (cVar1 = ref_securityNotUnlocked(1), cVar1 == '\0')) {
    DAT_ffffd1ce = 1;
  }
  else {
    DAT_ffffd1ce = 0;
  }
  return 0;
}


