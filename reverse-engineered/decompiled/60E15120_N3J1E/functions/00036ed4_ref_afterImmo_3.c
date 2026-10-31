/* ROM address: 0x00036ed4; body bytes: 164; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000375f4 (164 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_afterImmo_3(void)

{
  uint uVar1;
  undefined1 local_18;
  undefined1 uStack_17;
  undefined1 uStack_16;
  
  if ((((DAT_ffffc251 == '\x01') && (DAT_ffffc252 == 0)) && (DAT_ffffc227 == '\0')) &&
     (DAT_ffffc261 == '\0')) {
    DAT_ffffc227 = '\x01';
    DAT_ffffc261 = '\a';
    FUN_00035a8c(7);
    DAT_ffffc252 = 1;
    DAT_ffffc251 = '\0';
  }
  uVar1 = (uint)DAT_ffffc252;
  if (uVar1 == 1) {
    FUN_00035d80((int)DAT_ffffc261);
    uVar1 = (uint)DAT_ffffc288;
    if (uVar1 == 1) {
      DAT_ffffc262 = 0;
      DAT_ffffc227 = '\0';
      DAT_ffffc261 = '\0';
      DAT_ffffc252 = 0;
      local_18 = 0xf1;
      uStack_17 = 0xf0;
      uStack_16 = 1;
      ref_setupForUdsResponse_(0xb1,&local_18,3);
      uVar1 = ref_udsResponseRelated__(0xb1,3);
    }
  }
  return uVar1;
}


