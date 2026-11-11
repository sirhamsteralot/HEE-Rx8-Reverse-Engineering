/* [ADDITIONAL SOURCE REVIEW]
 * can_error_full_reset [high]: bsr ref_canSetup 0xd9f4 at 0xdae0, then ref_resetCANTimers 0xda94; called only from ref_checkCANsomethingKeyOnBased 0xdcc0 via bsr at 0xdda8 when error counter 0xffffa40c >= 1000 (cmp/ge 0x3e8, pool 0xddc6) - full CAN reset after a persistent bus-off/error condition.
 */
/* ROM address: 0x0000dade; body bytes: 10; decompiled */

void can_error_full_reset(void)

{
  ref_canSetup();
  ref_resetCANTimers();
  return;
}


