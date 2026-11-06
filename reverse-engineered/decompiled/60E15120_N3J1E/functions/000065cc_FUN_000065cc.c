/* [ADDITIONAL SOURCE REVIEW]
 * task14_charging_control_entry [high]: ROADMAP C item 7. rec[14] @ROM 0x4a70 entry; pool 0x66dc = 0x11adc. Dynamic: harness call 0x65cc visits 0x11adc and ref_alternatorControlMain_00026868, reaches taskEnd -> idle 0x3dac.
 */
/* ROM address: 0x000065cc; body bytes: 14; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000065cc (14 bytes). Names prefixed ref_
   are inherited hypotheses. */

void task14_charging_control_entry(void)

{
  charging_control_batch();
  ref_taskEndRoutine_();
  return;
}


