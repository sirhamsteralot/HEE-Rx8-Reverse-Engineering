/* ROM address: 0x00056db4; body bytes: 50; decompiled */

/* Handler candidate from 12-byte diagnostic dispatch record at 5f304. Table purpose inferred from
   neighboring code. */

void FUN_00056db4(char param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  uVar1 = rx8_decode_u16_affine(0x38a00000,0,(int)DAT_ffffad5e);
  uVar1 = FUN_00054884(uVar1,0x3a800000,uVar2);
  diag_append_u16_be((int)param_1,uVar1);
  return;
}


