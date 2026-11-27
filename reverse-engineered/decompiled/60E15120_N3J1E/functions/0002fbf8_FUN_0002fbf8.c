/* [ADDITIONAL SOURCE REVIEW]
 * fuel_pump_run_on_disable [high]: 8-byte body: DAT_ffffbddc = 0xffff (mov.w r1,@r0 at 0x2fbfe), which puts the run-on grace counter past its 0x3e keep-alive window. Pools 0x2fcd4=0x0000ffff, 0x2fcd8=0xffffbddc. Called from 0x2f948.
 */
/* ROM address: 0x0002fbf8; body bytes: 8; decompiled */

void fuel_pump_run_on_disable(void)

{
  fuel_pump_run_on_grace_counter_ffffbddc = 0xffff;
  return;
}


