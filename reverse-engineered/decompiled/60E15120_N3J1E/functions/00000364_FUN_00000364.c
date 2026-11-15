/* [ADDITIONAL SOURCE REVIEW]
 * RAM 0xffffdfa8 reset_cause (uint8): Reset-cause selector: written by the param!=0 branch of 0x4e0 (pool 0x590=0xdfa8) and by 0x5b0; selects the 0x210 vs 0x450 dispatch in 0x364/0x338.
 */
/* ROM address: 0x00000364; body bytes: 76; decompiled */

void FUN_00000364(void)

{
  int iVar1;
  
  if (reset_cause_ffffdfa8 == '\0') {
    iVar1 = FUN_00000210();
  }
  else {
    iVar1 = FUN_00000450(&DAT_ffffd4e0 + (uint)DAT_ffffdfb4 * 8);
  }
  if ((iVar1 == 1) && (DAT_ffffdfb4 = DAT_ffffdfb4 + 1, 99 < DAT_ffffdfb4)) {
    DAT_ffffdfb4 = 0;
  }
  return;
}


