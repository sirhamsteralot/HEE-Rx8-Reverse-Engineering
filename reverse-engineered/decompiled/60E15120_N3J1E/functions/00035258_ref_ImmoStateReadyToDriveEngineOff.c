/* [ADDITIONAL SOURCE REVIEW]
 * immo_state5_ready_engine_off [medium]: ref_ImmoStateReadyToDriveEngineOff (inherited name, unique_exact_bytes match to 60E0FC00 0x35978). c21e!=1 -> c21e=5, c212 countdown, on 0 -> ImmoBadStateSet, c21d=5, TX 200, c212=500; c21e==1 -> spin on 0x3587c until c208 changes, then c20c=500, 0x34e68.
 */
/* [READABILITY RECONSTRUCTION]
 * Signatures, local names, observed fields and scoped constants refined.
 * See readability/changes.json for evidence and remaining ABI limitations.
 */
/* ROM address: 0x00035258; body bytes: 108; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00035978 (108 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint candidate_immo_state5_ready_engine_off(void)

{
  int snapshot_DAT_ffffc208;
  uint uVar2;
  
  snapshot_DAT_ffffc208 = immo_random_seed_ffffc208;
  uVar2 = (uint)immo_command_substate_ffffc21e;
  if (uVar2 != 1) {
    immo_command_substate_ffffc21e = 5;
    if (immo_timer_engine_off_ffffc212 != 0) {
      immo_timer_engine_off_ffffc212 = immo_timer_engine_off_ffffc212 + -1;
    }
    if (immo_timer_engine_off_ffffc212 == 0) {
      immo_set_rejected();
      immo_main_state_ffffc21d = 5;
      uVar2 = immo_tx_frame_build(200);
      immo_timer_engine_off_ffffc212 = 500;
    }
    return uVar2;
  }
  while (immo_random_seed_ffffc208 == snapshot_DAT_ffffc208) {
    immo_random_seed_gen();
  }
  immo_timer_a_ffffc20c = 500;
  uVar2 = immo_wait_for_key_step();
  return uVar2;
}


