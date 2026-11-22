/* [ADDITIONAL SOURCE REVIEW]
 * immo_eeprom_write_step_1 [medium]: ref_afterImmo_1 (unique_exact_bytes to 60E0FC00 0x371ec). One step of the immo EEPROM-param write progress machine: on request flags (c24d/c24e/c227/c261) starts candidate_e2ram_param_write_dispatch(6), polls c288 via 0x35d80, and on completion answers UDS service 0xb1 with payload f1 01 01 (ref_setupForUdsResponse_(0xb1,...) + ref_udsResponseRelated__(0xb1,3)). afterImmo_2..8 are the same pattern with param ids 8/9/0xd/0xc/... — see e2ram_device_labels.json id map (id 2 -> (2, 0xffffc26c, 8) is the 8-byte immo key cell).
 */
/* ROM address: 0x00036acc; body bytes: 160; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000371ec (160 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_afterImmo_1(void)

{
  uint uVar1;
  undefined1 local_18;
  undefined1 uStack_17;
  undefined1 uStack_16;
  
  if ((((DAT_ffffc24d == '\x01') && (DAT_ffffc24e == 0)) && (DAT_ffffc227 == '\0')) &&
     (DAT_ffffc261 == '\0')) {
    DAT_ffffc227 = '\x01';
    DAT_ffffc261 = '\x06';
    candidate_e2ram_param_write_dispatch(6);
    DAT_ffffc24e = 1;
    DAT_ffffc24d = '\0';
  }
  uVar1 = (uint)DAT_ffffc24e;
  if (uVar1 == 1) {
    FUN_00035d80((int)DAT_ffffc261);
    uVar1 = (uint)DAT_ffffc288;
    if (uVar1 == 1) {
      DAT_ffffc262 = 0;
      DAT_ffffc227 = '\0';
      DAT_ffffc261 = '\0';
      DAT_ffffc24e = 0;
      local_18 = 0xf1;
      uStack_17 = 1;
      uStack_16 = 1;
      ref_setupForUdsResponse_(0xb1,&local_18,3);
      uVar1 = ref_udsResponseRelated__(0xb1,3);
    }
  }
  return uVar1;
}


