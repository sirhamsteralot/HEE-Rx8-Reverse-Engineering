/* [ADDITIONAL SOURCE REVIEW]
 * RAM 0xffffd286 mil_lamp_flag (uint8): MIL flag: set by 0x5a130 when stored+enabled DTC exists (disasm 0x5a130 verified; emulator MIL=1 case in reviews/dtc_control/dynamic_validation_log.txt); gates 0x5a188 distance-MIL and 0x55278 CAN status.
 */
/* ROM address: 0x0005a130; body bytes: 50; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 000588e8 (50 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint ref_faultSomething0x1(void)

{
  uint uVar1;
  
  uVar1 = FUN_00061450(0x80);
  if (((uVar1 & 0xffff) == 0) || (uVar1 = (uint)DAT_ffffd1c5, uVar1 == 1)) {
    mil_lamp_flag_ffffd286 = 0;
  }
  else {
    mil_lamp_flag_ffffd286 = 1;
  }
  return uVar1;
}


