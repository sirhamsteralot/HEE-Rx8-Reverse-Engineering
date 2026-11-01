/* ROM address: 0x000391f6; body bytes: 76; decompiled */

uint FUN_000391f6(void)

{
  uint uVar1;
  float fVar2;
  float fVar3;
  
  fVar3 = 0.0;
  fVar2 = DAT_ffffc548 - DAT_ffffc54c;
  uVar1 = FUN_00002440(0x47aba980,0,0x3727c5ac);
  DAT_ffffc544 = fVar3;
  if ((uVar1 & 0xff) != 0) {
    DAT_ffffc544 = fVar2 / 87891.0;
  }
  DAT_ffffc540 = DAT_ffffc540 + DAT_ffffc544;
  return uVar1;
}


