/* [ADDITIONAL SOURCE REVIEW]
 * charging_dtc_raise_p2502 [medium]: FUN_0005fd38(0x7b, b5b1==0 ? 2 : 1): slot 0x7b -> code_id 0x71 (u16 at ROM 0x7df42+0xf6) -> raw 0x2502 at ROM 0x7e560+0xe2 = P2502 (charging system voltage problem). Called from 0x267c6 via pool 0x268ac.
 */
/* ROM address: 0x000545bc; body bytes: 22; decompiled */

void candidate_charging_dtc_raise_p2502(void)

{
  undefined4 uVar1;
  
  if (charging_ok_latch_ffffb5b1 == '\0') {
    uVar1 = 2;
  }
  else {
    uVar1 = 1;
  }
  dtc_set_fault_x0(0x7b,uVar1);
  return;
}


