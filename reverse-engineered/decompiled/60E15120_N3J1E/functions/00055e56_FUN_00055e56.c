/* ROM address: 0x00055e56; body bytes: 84; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00054172 (84 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_00055e56(char param_1)

{
  uint uVar1;
  
  for (uVar1 = 0; ((&DAT_0005f055)[(uVar1 & 0xff) * 6] != param_1 && ((uVar1 & 0xff) < 3));
      uVar1 = uVar1 + 1) {
  }
  if (((uVar1 & 0xff) < 3) && ((diag_permission_mask_ffffd3b4_ffffd3b4 & (&DAT_0005f058)[(uVar1 & 0xff) * 3]) == 0)) {
    uVar1 = 3;
  }
  return uVar1;
}


