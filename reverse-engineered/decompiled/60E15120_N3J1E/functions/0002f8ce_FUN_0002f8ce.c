/* [ADDITIONAL SOURCE REVIEW]
 * fuel_pump_outputs_pe2_pe1 [medium]: Writes PEDR_W bit 0x4 (PE2, pkg pin 9) = (FUN_0005c204(DAT_ffffbdd8) == 1) [diag actuator-override gate] and bit 0x2 (PE1, pkg pin 8) = (DAT_ffffbdbc == 1). Raw-bin verified: jsr 0x5c204 (pool 0x2f944) with r4=pool 0x2f930=0xbdd8; mask mov #0x4 at 0x2f8ea; r13=pool 0x2f932=0xf754 (PEDR); then cell pool 0x2f934=0xbdbc, mask mov #0x2 at 0x2f912, helper pool 0x2f93e=0x4bbc. Caller 0x2f95c ref_getOBDFuelModificationRequest (fueling task 0x117ac). PE1 harness candidate: fuel pump speed control 4M.
 * RAM 0xffffbdbc fuel_pump_speed_request (uint8): Written by 0x2fb20 ref_fuelingAddOBDControlMode_ = diag-wrapped ((bdd5 && engine_stopped_latch 0xffffa41c==0) || (injectors_off 0xffffa42c==1 && key_on 0xffffaa68==1) || (ROM[0x775bd]==0 && 0xffffbdd4>0)); the gate 0x5c2e4 forces the request on diagnostic modes 5/7. bdd5 = 1 when bdc0 >= bdc4, 0 when bdc0 < bdc4-3.5, else latched. Read by 0x2f8ce (PE1, pkg pin 8; harness candidate fuel pump speed control 4M), 0x2aa46 and 0x49308. Pool-anchored: 0x2fbca=0xbdbc, 0x2f934=0xbdbc.
 */
/* ROM address: 0x0002f8ce; body bytes: 96; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0002fd86 (96 bytes). Names prefixed ref_
   are inherited hypotheses. */

void candidate_fuel_pump_outputs_pe2_pe1(void)

{
  undefined4 local_18;
  undefined4 uStack_14;
  char cStack_10;
  
  cStack_10 = FUN_0005c204((int)fuel_pump_relay_request_ffffbdd8);
  ref_setSR_PARAM(&uStack_14,0xe0);
  ref_setRegister_REG_BIT_VAL(0xfffff754,4,cStack_10 == '\x01');
  FUN_00002064(uStack_14);
  cStack_10 = fuel_pump_speed_request_ffffbdbc;
  ref_setSR_PARAM(&local_18,0xe0);
  ref_setRegister_REG_BIT_VAL(0xfffff754,2,cStack_10 == '\x01');
  FUN_00002064(local_18);
  return;
}


