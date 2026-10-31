/* ROM address: 0x0000cd10; body bytes: 48; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000cd10 (48 bytes). Names prefixed ref_
   are inherited hypotheses. */

byte FUN_0000cd10(byte param_1,byte param_2)

{
  int iVar1;
  
  iVar1 = FUN_0000cee8((int)(char)param_1,&HCAN0_MC0_1__B);
  *(byte *)(iVar1 + (param_1 & 0xf) * 8) = param_2 & 0xf;
  return param_2 & 0xf;
}


