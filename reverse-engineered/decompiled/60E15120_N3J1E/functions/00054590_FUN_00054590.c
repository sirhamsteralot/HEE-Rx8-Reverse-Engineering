/* [ADDITIONAL SOURCE REVIEW]
 * charging_dtc_raise_p2503 [medium]: FUN_0005fd38(0x7c, b5b2==0 ? 2 : 1): slot 0x7c -> code_id 0x72 -> raw 0x2503 = P2503 (charging system voltage low). Called from 0x2680e via pool 0x268cc.
 */
/* ROM address: 0x00054590; body bytes: 22; decompiled */

void candidate_charging_dtc_raise_p2503(void)

{
  undefined4 uVar1;
  
  if (low_voltage_latch_ffffb5b2 == '\0') {
    uVar1 = 2;
  }
  else {
    uVar1 = 1;
  }
  FUN_0005fd38(0x7c,uVar1);
  return;
}


