/* [ADDITIONAL SOURCE REVIEW]
 * hcan_bus_off_flag [high]: returns (HCANx_GSR_B & 1) != 0 for channel param_1 (HCAN0_GSR_B 0xffffe401 / HCAN1_GSR_B 0xffffe601; GSR bit0 = bus-off flag, REC >= 256, Sh7055h.pdf 16.2.2); called from 0xdcc0 via pool 0xddd4 = 0x9ac4 (jsr at 0xdd4e/0xdd5c).
 */
/* ROM address: 0x00009ac4; body bytes: 32; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00009ac4 (32 bytes). Names prefixed ref_
   are inherited hypotheses. */

bool hcan_bus_off_flag(undefined4 param_1)

{
  byte *pbVar1;
  
  pbVar1 = (byte *)ref_getHCANRegisterAddress(param_1,&HCAN0_GSR_B);
  return (*pbVar1 & 1) != 0;
}


