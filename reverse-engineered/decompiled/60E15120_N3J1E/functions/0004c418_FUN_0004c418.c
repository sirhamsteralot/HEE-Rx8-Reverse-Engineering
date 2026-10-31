/* ROM address: 0x0004c418; body bytes: 288; decompiled */

uint FUN_0004c418(void)

{
  uint uVar1;
  char cVar2;
  
  DAT_ffffcea4 = apv_position_voltage_ffffcab0 < -1.0;
  DAT_ffffcea5 = 6.0 < apv_position_voltage_ffffcab0;
  if (DAT_ffffd1c5 == '\x01') {
    DAT_ffffcea0 = -0x60;
    uVar1 = 0xffffffa0;
    DAT_ffffcea1 = -0x60;
    DAT_ffffcea9 = 0;
    DAT_ffffcea6 = '\0';
    DAT_ffffcea7 = 0;
    DAT_ffffcea8 = 0;
  }
  else if (((apv_position_voltage_ffffcab0 < -1.0) || (6.0 < apv_position_voltage_ffffcab0)) ||
          (cVar2 = ref_getFaultStatus__(0x57), cVar2 != '\0')) {
    if (DAT_ffffcea4 == '\x01') {
      if (DAT_ffffcea0 == '\0') {
        DAT_ffffcea6 = '\x01';
      }
      else {
        DAT_ffffcea0 = DAT_ffffcea0 + -1;
      }
    }
    if (DAT_ffffcea5 == '\x01') {
      if (DAT_ffffcea1 == '\0') {
        DAT_ffffcea7 = 1;
      }
      else {
        DAT_ffffcea1 = DAT_ffffcea1 + -1;
      }
    }
    if ((DAT_ffffcea6 == '\x01') || (uVar1 = (uint)DAT_ffffcea7, uVar1 == 1)) {
      uVar1 = ref_getFaultStatus__(0x57);
      uVar1 = uVar1 & 0xff;
      if (uVar1 == 0) {
        DAT_ffffcea9 = 1;
        DAT_ffffcea8 = 0;
      }
    }
  }
  else {
    DAT_ffffcea8 = 1;
    DAT_ffffcea0 = -0x60;
    DAT_ffffcea1 = -0x60;
    DAT_ffffcea9 = 0;
    DAT_ffffcea6 = '\0';
    DAT_ffffcea7 = 0;
    uVar1 = 0;
  }
  return uVar1;
}


