/* ROM address: 0x00028dc0; body bytes: 42; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00029768 (42 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_CAN216RX_Main(void)

{
  uint uVar1;
  
  uVar1 = ref_placeCANRX(&DAT_0004e22c);
  if ((uVar1 & 0xff) == 0) {
    FUN_0000e040();
    can216_unpack_mixed_width_fields();
    FUN_00028efc();
    uVar1 = FUN_00029028();
    return uVar1;
  }
  return uVar1 & 0xff;
}


