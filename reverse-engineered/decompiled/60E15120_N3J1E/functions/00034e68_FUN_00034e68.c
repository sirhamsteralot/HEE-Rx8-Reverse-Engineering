/* [ADDITIONAL SOURCE REVIEW]
 * immo_wait_for_key_step [high]: c21e==1 dispatch on c221: 1 -> bad state (c224=0, TX 1, c22a=1); 3 -> c21d=0; 2 (seed request) -> key-count check (c282: 0 or >2 -> lamp off, c1d0=0; else c282-=1, c22f=1, lamp on, c1d0=1, c228=0), c216=0x2ee, immo_compute_seed 0x353ce, TX cmd 7 with raw seed c208, c21d=2. Dynamically verified.
 */
/* ROM address: 0x00034e68; body bytes: 178; decompiled */

uint FUN_00034e68(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffffc21e;
  if (uVar1 == 1) {
    uVar1 = (uint)DAT_ffffc221;
    if (uVar1 == 1) {
      ref_ImmoBadStateSet_();
      DAT_ffffc224 = 0;
      uVar1 = FUN_00035738(1);
      DAT_ffffc22a = 1;
    }
    else if (uVar1 == 3) {
      DAT_ffffc21d = 0;
    }
    else if (uVar1 == 2) {
      if ((DAT_ffffc282 == 0) || (2 < DAT_ffffc282)) {
        ref_setImmoLight__(0);
        inferred_ram_c1d0_ffffc1d0_ffffc1d0 = 0;
      }
      else {
        DAT_ffffc282 = DAT_ffffc282 - 1;
        DAT_ffffc22f = 1;
        ref_setImmoLight__(1);
        inferred_ram_c1d0_ffffc1d0_ffffc1d0 = 1;
        DAT_ffffc228 = 0;
      }
      DAT_ffffc216 = 0x2ee;
      ref_ImmoGetSeed();
      uVar1 = FUN_00035738(7);
      DAT_ffffc21d = 2;
    }
  }
  else {
    if (uVar1 == 3) {
      uVar1 = FUN_00034d12();
      return uVar1;
    }
    DAT_ffffc21e = 5;
  }
  return uVar1;
}


