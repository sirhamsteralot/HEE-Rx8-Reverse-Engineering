/* ROM address: 0x000566f0; body bytes: 90; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00054a0c (90 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_000566f0(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  DAT_ffffd1e0 = 1;
  if (param_1 == '\0') {
    DAT_ffffd1e2 = 0xffff;
    DAT_ffffd1e4 = 0;
    goto LAB_0005673c;
  }
  if (param_1 != '\x01') {
    if (param_1 == '\x02') {
      DAT_ffffd1e4 = 2;
      goto LAB_0005673c;
    }
    if (param_1 != '\x03') goto LAB_0005673c;
    DAT_ffffd1e2 = 0;
  }
  DAT_ffffd1e4 = 1;
LAB_0005673c:
  uVar1 = ref_setSR(uVar1);
  return uVar1;
}


