/* [ADDITIONAL SOURCE REVIEW]
 * immo_state0_idle [high]: Main state 0 handler. c21e==3 -> c21d=1 and run state1 (0x34d12); c21e==1 -> run 0x34e68; c21f>1 -> FUN_00035738(0xc6); c20c timeout -> ImmoBadStateSet + c224=0 + TX cmd 1 + c22a=1.
 * RAM 0xffffc20c immo_timer_a (u16): set 500 on entry to challenge states; expiry -> bad state
 */
/* ROM address: 0x00034c5c; body bytes: 114; decompiled */

uint FUN_00034c5c(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_ffffc21e;
  if (uVar1 == 3) {
    DAT_ffffc21d = 1;
    uVar1 = FUN_00034d12();
    return uVar1;
  }
  if (uVar1 == 1) {
    uVar1 = FUN_00034e68();
    return uVar1;
  }
  if (1 < DAT_ffffc21f) {
    DAT_ffffc21f = 0;
    uVar1 = FUN_00035738(0xc6);
  }
  if (DAT_ffffc20c != 0) {
    DAT_ffffc20c = DAT_ffffc20c + -1;
  }
  if (DAT_ffffc20c == 0) {
    ref_ImmoBadStateSet_();
    DAT_ffffc224 = 0;
    uVar1 = FUN_00035738(1);
    DAT_ffffc22a = 1;
  }
  return uVar1;
}


