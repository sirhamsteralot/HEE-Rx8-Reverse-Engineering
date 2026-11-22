/* [ADDITIONAL SOURCE REVIEW]
 * dbw_task9_batch [high]: Task-table rec[9] @ROM 0x4a20 entry 0x64ba tail-calls 0x1150e (pool 0x656c=0x0001150e at 0x64d4); batch pool 0x116b8=0x000199d4 (pedal/TP sensor batch), 0x116c8=0x00022f86 (DBW control batch), 0x116e4=0x00021b4c (throttle torque batch) — words read from ROM, jsr sites in disasm.
 */
/* ROM address: 0x0001150e; body bytes: 38; decompiled */

void dbw_task9_batch(void)

{
  pedal_tp_sensor_batch();
  FUN_00038ee4();
  FUN_0002114a();
  FUN_0002e5a8();
  dbw_control_batch();
  jump_to_FUN_000236cc();
  return;
}


