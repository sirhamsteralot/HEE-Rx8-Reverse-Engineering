/* ROM address: 0x00044436; body bytes: 226; decompiled */

undefined4 * FUN_00044436(void)

{
  char cVar1;
  undefined4 *puVar2;
  
  cVar1 = DAT_ffffb694;
  puVar2 = (undefined4 *)(uint)DAT_ffffd1c5;
  if (puVar2 == (undefined4 *)((int)&vector_Poweron_Reset + 1)) {
    DAT_ffffcb60 = 0;
    DAT_ffffcb62 = 0;
    DAT_ffffcb68 = 0;
  }
  else {
    if ((((DAT_ffffcb64 <= DAT_ffffba50) && (DAT_ffffba50 <= DAT_ffffba80)) &&
        (puVar2 = (undefined4 *)(uint)DAT_ffffb69c,
        puVar2 == (undefined4 *)((int)&vector_Poweron_Reset + 1))) &&
       ((puVar2 = (undefined4 *)(int)DAT_ffffb53a, puVar2 == (undefined4 *)0x0 &&
        (((4000.0 <= engine_speed_rpm_ffffb548 || (puVar2 = &DAT_0007bf5c, vehicle_speed_ffffbbb4 < 0.0)) ||
         ((DAT_ffffb694 == '\0' && (DAT_ffffcb68 == 0)))))))) {
      if (DAT_ffffcb60 < 1000) {
        puVar2 = (undefined4 *)rx8_add_u16_saturate((int)(short)DAT_ffffcb60,1);
        DAT_ffffcb60 = (ushort)puVar2;
      }
      else {
        DAT_ffffcb60 = 1000;
      }
      if (DAT_ffffcb62 < 1000) {
        puVar2 = (undefined4 *)rx8_add_u16_saturate((int)(short)DAT_ffffcb62,1);
        DAT_ffffcb62 = (ushort)puVar2;
      }
      else {
        DAT_ffffcb62 = 1000;
      }
    }
    if (cVar1 == '\0') {
      if (DAT_ffffcb68 != 0) {
        DAT_ffffcb68 = DAT_ffffcb68 + -1;
      }
    }
    else {
      DAT_ffffcb68 = 0x28;
    }
  }
  return puVar2;
}


