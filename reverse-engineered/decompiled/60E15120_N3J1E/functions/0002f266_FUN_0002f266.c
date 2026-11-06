/* [ADDITIONAL SOURCE REVIEW]
 * fan_control_task [high]: Mask-0x10 fan task: pool 0x2f29c=0x2f51a, 0x2f2a0=0x2f65c, 0x2f2a4=0x2f1dc (words read from ROM; jsr at 0x2f276/0x2f27c/0x2f282); called from 0x117ac via pool 0x11a04 (load at 0x11826). Runs low-speed decision, high-speed decision, then the GPIO output.
 */
/* ROM address: 0x0002f266; body bytes: 42; decompiled */

void fan_control_task(void)

{
  undefined4 uVar1;
  
  uVar1 = sh_raise_interrupt_mask_return_previous(0x10);
  FUN_0002f2ac();
  fan_low_speed_decision();
  fan_high_speed_decision();
  fan_output_gpio();
  ref_setSR(uVar1);
  return;
}


