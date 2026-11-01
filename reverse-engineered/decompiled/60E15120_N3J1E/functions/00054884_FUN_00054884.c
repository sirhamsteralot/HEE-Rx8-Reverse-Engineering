/* ROM address: 0x00054884; body bytes: 62; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00052970 (62 bytes). Names prefixed ref_
   are inherited hypotheses. */

int candidate_diag_encode_s16_div(float param_1,float param_2,float param_3)

{
  int iVar1;
  float fVar2;
  int iVar3;
  
  if (0.0 <= param_1 - param_3) {
    fVar2 = 0.5;
  }
  else {
    fVar2 = -0.5;
  }
  iVar1 = 0x7fff;
  iVar3 = (int)((param_1 - param_3) / param_2 + fVar2);
  if ((iVar3 < 0x8000) && (iVar1 = iVar3, iVar3 < -0x8000)) {
    iVar1 = -0x8000;
  }
  return iVar1;
}


