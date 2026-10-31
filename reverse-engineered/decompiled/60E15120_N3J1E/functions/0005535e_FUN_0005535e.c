/* [ADDITIONAL SOURCE REVIEW]
 * diag_ol_status_byte [high]: OBD PID 0x0003 'OL Status' high byte: 2 (closed loop) or 0x10 when ae1f==1, 4 (OL-DTC) when ae1e==0, 8 when coolant >= 35 C, 1 when cold.
 * RAM 0xffffae1e closed_loop_allowed (uint8): CL allowed (0x1c13c): warm, warmup time met, not open loop, O2 healthy, no DTC-ish conditions.
 * RAM 0xffffae1f closed_loop_active (uint8): CL active = ae1e && cd5c==0 && lambda feedback (aa80/aa81); drives the OBD status byte 0x5535e.
 */
/* ROM address: 0x0005535e; body bytes: 80; decompiled */

undefined4 diag_ol_status_byte(void)

{
  undefined4 uVar1;
  
  if (closed_loop_active_ffffae1f == '\x01') {
    if (DAT_ffffad24 == '\0') {
      uVar1 = 0x10;
    }
    else {
      uVar1 = 2;
    }
  }
  else if (closed_loop_allowed_ffffae1e == '\0') {
    uVar1 = 4;
  }
  else if (35.0 <= inferred_coolant_temperature_ffffa98c) {
    uVar1 = 8;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


