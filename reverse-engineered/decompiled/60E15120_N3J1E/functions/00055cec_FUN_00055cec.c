/* ROM address: 0x00055cec; body bytes: 86; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00054008 (86 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00055cec(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  if (param_1 == '\0') {
    DAT_ffffd1d2 = 0x271;
    DAT_ffffd1d4 = 0;
    goto LAB_00055d34;
  }
  if (param_1 != '\x01') {
    if (param_1 == '\x02') {
      DAT_ffffd1d4 = 2;
      goto LAB_00055d34;
    }
    if (param_1 != '\x03') goto LAB_00055d34;
    DAT_ffffd1d2 = 0;
  }
  DAT_ffffd1d4 = 1;
LAB_00055d34:
  uVar1 = ref_setSR(uVar1);
  return uVar1;
}


