/* [ADDITIONAL SOURCE REVIEW]
 * diag_read_runtime_s [high]: PID 0x1f: ffffd284 via 0x409c clamp 0xffff
 * RAM 0xffffd284 engine_runtime_counter_ffffd284 (uint32): PID 0x1f via 0x409c, clamp 0xffff (OBD PID 1F s)
 */
/* ROM address: 0x000555d0; body bytes: 40; decompiled */

uint diag_read_runtime_s(void)

{
  uint uVar1;
  
  uVar1 = FUN_0000409c((int)engine_runtime_counter_ffffd284_ffffd284);
  if (0xffff < uVar1) {
    uVar1 = 0xffff;
  }
  return uVar1;
}


