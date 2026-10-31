/* ROM address: 0x00050950; body bytes: 58; decompiled */

uint FUN_00050950(void)

{
  uint uVar1;
  float extraout_fr0;
  
  uVar1 = (uint)DAT_ffffcf86;
  if ((uVar1 == 1) &&
     (uVar1 = ref_readValue_float_DEFAULTVAL_ADDRESS(0,&DAT_ffff8684), extraout_fr0 < 0.0004)) {
    uVar1 = ref_getFaultStatus__(0x2e);
    uVar1 = uVar1 & 0xff;
    if (uVar1 == 0) {
      DAT_ffffd045 = 1;
    }
  }
  return uVar1;
}


