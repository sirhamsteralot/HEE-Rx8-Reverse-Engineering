/* ROM address: 0x0004f22e; body bytes: 58; decompiled */

uint FUN_0004f22e(void)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  uVar2 = ref_readValue_float_DEFAULTVAL_ADDRESS(0,&DAT_ffff86a8);
  uVar1 = rx8_is_outside_tolerance_band(uVar2,uVar3,0x36b33333);
  if (((uVar1 & 0xff) != 0) && (uVar1 = (uint)DAT_ffffd0a8, uVar1 == 1)) {
    DAT_ffffcfca = 1;
  }
  return uVar1;
}


