/* [ADDITIONAL SOURCE REVIEW]
 * candidate_cranking_status_selector [high]: Returns 1 when byte 0xffffa79c (pool 0x10f7c) is 0 and 2 when it is set; the value is consumed by the CAN status builder 0x10390.
 */
/* ROM address: 0x00010e8e; body bytes: 20; decompiled */

undefined4 candidate_cranking_status_selector(void)

{
  undefined4 uVar1;
  
  if (candidate_engine_running_stable_ffffa79c == '\0') {
    uVar1 = 1;
  }
  else {
    uVar1 = 2;
  }
  return uVar1;
}


