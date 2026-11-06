/* [ADDITIONAL SOURCE REVIEW]
 * charging_dtc_raise_p2504 [medium]: FUN_0005fd38(0x7d, b5b0==0 ? 2 : 1): slot 0x7d -> code_id 0x73 -> raw 0x2504 = P2504 (charging system voltage high). Called from 0x2680e via pool 0x268d0.
 */
/* ROM address: 0x000545a6; body bytes: 22; decompiled */

void candidate_charging_dtc_raise_p2504(void)

{
  undefined4 uVar1;
  
  if (DAT_ffffb5b0 == '\0') {
    uVar1 = 2;
  }
  else {
    uVar1 = 1;
  }
  FUN_0005fd38(0x7d,uVar1);
  return;
}


