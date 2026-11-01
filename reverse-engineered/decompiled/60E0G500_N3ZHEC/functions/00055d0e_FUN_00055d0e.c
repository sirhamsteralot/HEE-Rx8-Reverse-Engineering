/* ROM address: 0x00055d0e; body bytes: 22; decompiled */

undefined4 diag_read_secondary_air_status(void)

{
  undefined4 uVar1;
  
  if (DAT_ffffa9e4 == '\x01') {
    uVar1 = 1;
  }
  else {
    uVar1 = 4;
  }
  return uVar1;
}


