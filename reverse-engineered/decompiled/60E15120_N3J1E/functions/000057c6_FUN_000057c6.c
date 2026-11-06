/* [ADDITIONAL SOURCE REVIEW]
 * alternator_pwm_service [high]: ATU-II ch5B PWM service: splits duty 0xffff9f48 vs period 0xffff9f44 into compare windows (0x7e margin) into 0xffff9f46/0xffff9f4a, then GR5B_W = TCNT5_W + compare with TIOR5A_B output config toggled (0x10/0x20); clears TSR3_W 0x77ff; called via pool 0x2b88 (load at 0x2b82) from the ch5B compare interrupt path. Registers from symbols.tsv: ATUII_TCNT5_W 0xfffff4e0, ATUII_GR5B_W 0xfffff4e4, ATUII_TIOR5A_B 0xfffff4eb, ATUII_TSR3_W 0xfffff480.
 * RAM 0xffff9f44 alternator_pwm_period (uint16): ATU-II ch5B PWM period, init 1000 by 0x25674; duty fraction computed against it in 0x25710 (mov.w @r5 at 0x2573c) and split into compare windows in 0x57c6.
 * RAM 0xffff9f48 alternator_pwm_duty (uint16): ATU-II ch5B PWM duty counts, written by 0x25710 (mov.w r0,@(0x4,r2) at 0x2574a with base 0xffff9f44) from 0xffffb5ac percent; consumed by 0x57c6 into GR5B 0xfffff4e4.
 */
/* ROM address: 0x000057c6; body bytes: 242; decompiled */

void alternator_pwm_service(void)

{
  short sVar1;
  short sVar2;
  byte bVar3;
  ushort uVar4;
  ushort uVar5;
  undefined4 local_10 [2];
  
  ATUII_TSR3_W = 0x77ff;
  if (DAT_ffff9f4d == '\x01') {
    if (alternator_pwm_duty_ffff9f48 < 0x7e) {
      DAT_ffff9f46 = 0;
      DAT_ffff9f4a = alternator_pwm_period_ffff9f44;
    }
    else if ((ushort)(alternator_pwm_period_ffff9f44 - alternator_pwm_duty_ffff9f48) < 0x7e) {
      DAT_ffff9f46 = alternator_pwm_period_ffff9f44;
      DAT_ffff9f4a = 0;
    }
    else {
      DAT_ffff9f46 = alternator_pwm_duty_ffff9f48;
      DAT_ffff9f4a = alternator_pwm_period_ffff9f44 - alternator_pwm_duty_ffff9f48;
    }
  }
  sVar2 = ATUII_GR5B_W;
  if (DAT_ffff9f4c == '\x01') {
    DAT_ffff9f4e = 1;
    uVar5 = DAT_ffff9f46;
    if (DAT_ffff9f4a != 0) {
      bVar3 = ATUII_TIOR5A_B;
      ATUII_TIOR5A_B = bVar3 & 0x8f | 0x10;
      DAT_ffff9f4c = '\0';
      DAT_ffff9f4d = '\0';
    }
  }
  else {
    DAT_ffff9f4e = 0;
    uVar5 = DAT_ffff9f4a;
    if (DAT_ffff9f46 != 0) {
      bVar3 = ATUII_TIOR5A_B;
      ATUII_TIOR5A_B = bVar3 & 0x8f | 0x20;
      DAT_ffff9f4c = '\x01';
      if (DAT_ffff9f4d == '\x01') {
        uVar5 = 0;
      }
    }
    DAT_ffff9f4d = '\x01';
  }
  ref_setSR_PARAM(local_10,0xe0);
  sVar1 = ATUII_TCNT5_W;
  uVar4 = (sVar1 - sVar2) + 1;
  if (uVar5 < uVar4) {
    uVar5 = uVar4;
  }
  ATUII_GR5B_W = uVar5 + sVar2;
  FUN_00002064(local_10[0]);
  return;
}


