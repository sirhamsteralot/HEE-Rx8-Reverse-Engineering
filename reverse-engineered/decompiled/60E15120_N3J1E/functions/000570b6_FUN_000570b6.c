/* ROM address: 0x000570b6; body bytes: 56; decompiled */

/* Handler candidate from 12-byte diagnostic dispatch record at 5f400. Table purpose inferred from
   neighboring code. */

void FUN_000570b6(char param_1)

{
  float fVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  fVar1 = (float)rx8_decode_u8_affine(0x43000000,0,(int)DAT_ffffd1ac);
  uVar2 = rx8_encode_u8_affine_saturate(fVar1 / 1000.0,0x3dcccccc,uVar2);
  diag_append_u8((int)param_1,uVar2);
  return;
}


