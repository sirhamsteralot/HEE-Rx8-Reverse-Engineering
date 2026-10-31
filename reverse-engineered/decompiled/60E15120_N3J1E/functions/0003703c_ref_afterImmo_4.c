/* ROM address: 0x0003703c; body bytes: 162; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0003775c (162 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_afterImmo_4(void)

{
  uint uVar1;
  undefined1 local_14;
  undefined1 uStack_13;
  undefined1 uStack_12;
  
  if ((((DAT_ffffc253 == '\x01') && (DAT_ffffc254 == 0)) && (DAT_ffffc227 == '\0')) &&
     (DAT_ffffc261 == '\0')) {
    DAT_ffffc227 = '\x01';
    DAT_ffffc261 = '\x05';
    FUN_00035a8c(5);
    DAT_ffffc254 = 1;
    DAT_ffffc253 = '\0';
  }
  uVar1 = (uint)DAT_ffffc254;
  if (uVar1 == 1) {
    FUN_00035d80((int)DAT_ffffc261);
    uVar1 = (uint)DAT_ffffc288;
    if (uVar1 == 1) {
      DAT_ffffc262 = 0;
      DAT_ffffc227 = '\0';
      DAT_ffffc261 = '\0';
      DAT_ffffc254 = 0;
      local_14 = 0xf1;
      uStack_13 = 0xf0;
      uStack_12 = 4;
      ref_setupForUdsResponse_(0xb1,&local_14,3);
      uVar1 = ref_udsResponseRelated__(0xb1,3);
    }
  }
  return uVar1;
}


