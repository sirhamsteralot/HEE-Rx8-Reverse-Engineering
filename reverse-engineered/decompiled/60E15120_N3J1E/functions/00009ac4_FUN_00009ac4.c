/* ROM address: 0x00009ac4; body bytes: 32; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00009ac4 (32 bytes). Names prefixed ref_
   are inherited hypotheses. */

bool FUN_00009ac4(undefined4 param_1)

{
  byte *pbVar1;
  
  pbVar1 = (byte *)ref_getHCANRegisterAddress(param_1,&HCAN0_GSR_B);
  return (*pbVar1 & 1) != 0;
}


