/* [ADDITIONAL SOURCE REVIEW]
 * can4b0_wheelspeed_extract [medium]: 0xffffbbac = bba4*0x100 + bba5; 0xffffbbae = bba6*0x100 + bba7 (two u16 wheelspeed signals from a CAN payload buffer at 0xffffbba4).
 */
/* ROM address: 0x0002b1d6; body bytes: 74; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002b92a (74 bytes). Names prefixed ref_
   are inherited hypotheses. */

void candidate_can4b0_wheelspeed_extract(void)

{
  DAT_ffffbba8 = (ushort)DAT_ffffbba0 * 0x100 + (ushort)DAT_ffffbba1;
  DAT_ffffbbaa = (ushort)DAT_ffffbba2 * 0x100 + (ushort)DAT_ffffbba3;
  wheelspeed_lr_raw_ffffbbac = (ushort)DAT_ffffbba4 * 0x100 + (ushort)DAT_ffffbba5;
  wheelspeed_rr_raw_ffffbbae = (ushort)DAT_ffffbba6 * 0x100 + (ushort)DAT_ffffbba7;
  return;
}


