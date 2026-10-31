/* ROM address: 0x00035438; body bytes: 164; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00035b58 (164 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00035438(uint param_1,byte param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = (param_1 >> 8 & 0xff) << 0x10 | (uint)param_2 << 8;
  uVar2 = uVar1 | param_1 & 0xff;
  uVar1 = (uVar1 & 0x1fc000) >> 9 | (uVar2 & 0xfe0) << 9 | uVar2 & 0xffe0301f;
  uVar2 = (~(uVar1 >> 0x10) + 1 & 0xff) << 0x10 | (~(uVar1 >> 8) + 1 & 0xff) << 8;
  uVar3 = uVar2 | ~uVar1 + 1 & 0xff;
  uVar1 = uVar3 >> 3;
  return (uVar1 & 0xff) << 0x10 | ((uVar2 & 0x7f800) >> 0xb) << 8 |
         (uint)(byte)((byte)((uVar3 << 0x15) >> 0x10) | (byte)(uVar1 >> 0x10));
}


