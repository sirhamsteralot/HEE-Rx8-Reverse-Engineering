/* ROM address: 0x00036dae; body bytes: 110; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000374ce (110 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_afterImmo_6(void)

{
  uint uVar1;
  int iVar2;
  undefined1 local_10;
  undefined1 uStack_f;
  undefined1 uStack_e;
  
  uVar1 = (uint)DAT_ffffc23d;
  iVar2 = 0;
  if ((uVar1 == 1) && (uVar1 = (uint)DAT_ffffc24c, uVar1 == 1)) {
    DAT_ffffc23d = 0;
    if (DAT_ffffc23b != '\0') {
      iVar2 = 0x22;
    }
    DAT_ffffc24c = 0;
    if (iVar2 == 0) {
      local_10 = 0xf1;
      uStack_f = 1;
      uStack_e = 0x9d;
      ref_setupForUdsResponse_(0xb1,&local_10,3);
    }
    else {
      ref_udsErrorResponse(0xb1);
    }
    uVar1 = ref_udsResponseRelated__(0xb1,3);
  }
  return uVar1;
}


