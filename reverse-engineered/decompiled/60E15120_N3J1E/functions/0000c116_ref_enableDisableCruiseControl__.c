/* [ADDITIONAL SOURCE REVIEW]
 * reset_knock_state_on_mode_change [high]: Inherited name ref_enableDisableCruiseControl__ is a misnomer: on mode change (a38c != param) only resets a384=0xff, a385=0, a324=0. Callers: 0x335e4 (init, param 0) and 0x339ea (RPM window).
 * RAM 0xffffa38c knock_state_mode (uint8): Mode value passed to 0xc116; a change resets rotor index and knock state.
 */
/* ROM address: 0x0000c116; body bytes: 54; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000c116 (54 bytes). Names prefixed ref_
   are inherited hypotheses. */

void reset_knock_state_on_mode_change(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  if (knock_state_mode_ffffa38c != param_1) {
    knock_rotor_index_ffffa384 = 0xff;
    DAT_ffffa385 = 0;
    knock_detected_ffffa324 = 0;
    knock_state_mode_ffffa38c = param_1;
  }
  ref_setSR(uVar1);
  return;
}


