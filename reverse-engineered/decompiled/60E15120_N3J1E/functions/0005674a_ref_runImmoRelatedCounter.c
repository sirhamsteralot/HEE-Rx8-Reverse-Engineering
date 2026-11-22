/* [ADDITIONAL SOURCE REVIEW]
 * immo_counter_increment [high]: ref_runImmoRelatedCounter (unique_exact_bytes to 60E0FC00 0x54a66), called from slow_background_task 0x11534. Mask-0x10: if 0xffffd1e4==1 && 0xffffd1e2!=-1 -> d1e2++ (the immo-related counter exposed in the diag RAM area; PID 0xc116 thunk 0x576c2 reads the c239-c281 state block).
 * RAM 0xffffd1e2 immo_counter (u16): Word accesses with extu.w and a 0xffff ceiling (0x56766-0x56776): u16, saturating; incremented when 0xffffd1e4 == 1 from the slow task 0x11534.
 * RAM 0xffffd1e4 immo_counter_enable (u8): diag RAM area cell
 */
/* ROM address: 0x0005674a; body bytes: 60; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00054a66 (60 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 ref_runImmoRelatedCounter(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  if ((DAT_ffffd1e4 == '\x01') && (DAT_ffffd1e2 != -1)) {
    DAT_ffffd1e2 = DAT_ffffd1e2 + 1;
  }
  uVar1 = ref_setSR(uVar1);
  return uVar1;
}


