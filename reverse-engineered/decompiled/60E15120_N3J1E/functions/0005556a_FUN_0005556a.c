/* ROM address: 0x0005556a; body bytes: 22; decompiled */

undefined4 diag_read_secondary_air_status(void)

{
  undefined4 uVar1;
  
  if (secondary_air_request_final_ffffa960 == '\x01') {
    uVar1 = 1;
  }
  else {
    uVar1 = 4;
  }
  return uVar1;
}


