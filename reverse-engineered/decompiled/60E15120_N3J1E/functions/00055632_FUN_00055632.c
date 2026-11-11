/* [ADDITIONAL SOURCE REVIEW]
 * diag_read_gear_byte [high]: PID 0x30: 0x61d14 (ffff8788) clamp 0xff | promoted to high (data/labels/60E15120_N3J1E/uds_dispatch_labels.json/function_aliases)
 */
/* ROM address: 0x00055632; body bytes: 34; decompiled */

uint diag_read_gear_byte(void)

{
  uint uVar1;
  
  uVar1 = FUN_00061d14();
  if (0xff < (uVar1 & 0xffff)) {
    uVar1 = 0xff;
  }
  return uVar1;
}


