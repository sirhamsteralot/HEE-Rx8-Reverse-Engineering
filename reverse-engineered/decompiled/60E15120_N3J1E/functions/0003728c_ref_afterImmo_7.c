/* ROM address: 0x0003728c; body bytes: 162; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000379ac (162 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_afterImmo_7(void)

{
  uint uVar1;
  undefined1 local_14;
  undefined1 uStack_13;
  undefined1 uStack_12;
  
  if ((((DAT_ffffc259 == '\x01') && (DAT_ffffc25a == 0)) && (DAT_ffffc227 == '\0')) &&
     (DAT_ffffc261 == '\0')) {
    DAT_ffffc227 = '\x01';
    DAT_ffffc261 = '\v';
    FUN_00035a8c(0xb);
    DAT_ffffc25a = 1;
    DAT_ffffc259 = '\0';
  }
  uVar1 = (uint)DAT_ffffc25a;
  if (uVar1 == 1) {
    FUN_00035d80((int)DAT_ffffc261);
    uVar1 = (uint)DAT_ffffc288;
    if (uVar1 == 1) {
      DAT_ffffc262 = 0;
      DAT_ffffc227 = '\0';
      DAT_ffffc261 = '\0';
      DAT_ffffc25a = 0;
      local_14 = 0xf1;
      uStack_13 = 0;
      uStack_12 = 0xb;
      ref_setupForUdsResponse_(0xb1,&local_14,3);
      uVar1 = ref_udsResponseRelated__(0xb1,3);
    }
  }
  return uVar1;
}


