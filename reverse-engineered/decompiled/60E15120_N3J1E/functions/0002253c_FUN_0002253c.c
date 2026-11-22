/* [ADDITIONAL SOURCE REVIEW]
 * ch7d_pwm_duty_batch [high]: Batch called from 0x118d0 (task[13] 0x65b2 -> pool 0x66d8=0x000118d0 -> pool 0x11a88=0x0002253c): mask 0x10, calls 0x22574, 0x22630, 0x25198 (pools 0x22560=0x3920, 0x22564=0x22574, 0x22568=0x22630, 0x2256c=0x25198).
 */
/* ROM address: 0x0002253c; body bytes: 36; decompiled */

void ch7d_pwm_duty_batch(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  ch7d_pwm_enable_condition();
  ch7d_pwm_duty_control_loop();
  ch7d_pwm_duty_ratio();
  ref_setSR(uVar1);
  return;
}


