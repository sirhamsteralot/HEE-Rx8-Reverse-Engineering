/* ROM address: 0x0000ce76; body bytes: 50; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000ce76 (50 bytes). Names prefixed ref_
   are inherited hypotheses. */

ushort FUN_0000ce76(char param_1)

{
  short sVar1;
  ushort uVar2;
  
  if (param_1 == '\0') {
    uVar2 = HCAN0_MBIMR_W;
    sVar1 = -0x1bf6;
  }
  else {
    uVar2 = HCAN1_MBIMR_W;
    sVar1 = -0x19f6;
  }
  return (~uVar2 & *(ushort *)(int)sVar1) << 8 | (~uVar2 & *(ushort *)(int)sVar1) >> 8;
}


