/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x0002c9ca; body bytes: 70; decompiled */

void FUN_0002c9ca(void)

{
  float fVar1;
  float arg1;
  float fVar2;
  float snapshot_DAT_ffffbca8;
  
  arg1 = 0.0;
  fVar2 = 4.0;
  snapshot_DAT_ffffbca8 = DAT_ffffbca8;
  fVar1 = (float)rx8_decode_u8_affine(0x3f800000,0,(int)DAT_ffffbc83);
  DAT_ffffbc7c = snapshot_DAT_ffffbca8 * ((-fVar1 + fVar2) / fVar2);
  DAT_ffffbc78 = rx8_max_float(snapshot_DAT_ffffbca8 - DAT_ffffbc7c,arg1);
  return;
}


