/* ROM address: 0x00036c3c; body bytes: 162; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0003735c (162 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_afterImmo_2(void)

{
  uint uVar1;
  undefined1 local_18;
  undefined1 uStack_17;
  undefined1 uStack_16;
  
  if ((((DAT_ffffc24f == '\x01') && (DAT_ffffc250 == 0)) && (DAT_ffffc227 == '\0')) &&
     (DAT_ffffc261 == '\0')) {
    DAT_ffffc227 = '\x01';
    DAT_ffffc261 = '\x04';
    candidate_e2ram_param_write_dispatch(4);
    DAT_ffffc250 = 1;
    DAT_ffffc24f = '\0';
  }
  uVar1 = (uint)DAT_ffffc250;
  if (uVar1 == 1) {
    FUN_00035d80((int)DAT_ffffc261);
    uVar1 = (uint)DAT_ffffc288;
    if (uVar1 == 1) {
      DAT_ffffc262 = 0;
      DAT_ffffc227 = '\0';
      DAT_ffffc261 = '\0';
      DAT_ffffc250 = 0;
      local_18 = 0xf1;
      uStack_17 = 1;
      uStack_16 = 0x9c;
      ref_setupForUdsResponse_(0xb1,&local_18,3);
      uVar1 = ref_udsResponseRelated__(0xb1,3);
    }
  }
  return uVar1;
}


