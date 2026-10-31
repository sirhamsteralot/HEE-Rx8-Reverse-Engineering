/* ROM address: 0x0000e0f4; body bytes: 122; decompiled */

uint FUN_0000e0f4(void)

{
  uint uVar1;
  undefined4 uVar2;
  
  if ((-10.0 <= inferred_coolant_temperature_ffffa98c) || (engine_injectors_off_ffffa42c != '\x01')) {
    if ((DAT_ffffa416 < 0xfa) && (uVar1 = (uint)engine_stopped_latch_ffffa41c, uVar1 != 1)) {
      DAT_ffffa418 = 0;
      goto LAB_0000e180;
    }
    DAT_ffffa418 = 1;
    uVar2 = 0;
  }
  else {
    DAT_ffffa418 = 2;
    uVar2 = 1;
  }
  uVar1 = FUN_000074da(uVar2);
LAB_0000e180:
  if (engine_speed_rpm_ffffb548 <= 1000.0) {
    DAT_ffffa416 = 0;
  }
  else {
    uVar1 = rx8_add_u16_saturate((int)(short)DAT_ffffa416,1);
    DAT_ffffa416 = (ushort)uVar1;
  }
  return uVar1;
}


