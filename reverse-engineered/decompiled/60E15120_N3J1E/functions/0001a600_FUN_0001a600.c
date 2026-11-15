/* [ADDITIONAL SOURCE REVIEW]
 * key_on_flag_update [high]: Copies 0xffffaa69 (pool 0x1a60c) to engine_running_flag 0xffffaa68 (pool 0x1a60a=0xaa68); called from 0x19640/0x19950. 0xffffaa68 gates the CAN RX/TX mains (0xdbf6/0xdb58), CAN error recovery 0xdcc0, the fan after-run clause in 0x2f51a and the key-off state machine 0x252c2.
 */
/* ROM address: 0x0001a600; body bytes: 10; decompiled */

void key_on_flag_update(void)

{
  engine_running_flag_ffffaa68 = key_on_latch_aa69_ffffaa69;
  return;
}


