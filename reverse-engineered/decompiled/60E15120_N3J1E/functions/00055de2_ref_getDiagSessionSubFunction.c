/* ROM address: 0x00055de2; body bytes: 72; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000540fe (72 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_getDiagSessionSubFunction(char param_1)

{
  uint uVar1;
  
  for (uVar1 = 0; ((&DAT_0005f040)[(uVar1 & 0xff) * 4] != param_1 && ((uVar1 & 0xff) < 5));
      uVar1 = uVar1 + 1) {
  }
  if (((uVar1 & 0xff) < 5) && ((diag_permission_mask_ffffd3b4_ffffd3b4 & (&DAT_0005f042)[(uVar1 & 0xff) * 2]) == 0)) {
    uVar1 = 5;
  }
  return uVar1;
}


