/* ROM address: 0x0003d512; body bytes: 238; decompiled */

undefined1 * FUN_0003d512(void)

{
  char cVar1;
  undefined1 *puVar2;
  uint uVar3;
  
  cVar1 = DAT_ffffb53b;
  DAT_ffffc624 = 30.08 < vehicle_speed_ffffbbb4;
  if (DAT_ffffd1c5 == '\x01') {
    DAT_ffffc622 = '\0';
    DAT_ffffc620 = '\b';
    DAT_ffffc62a = 0;
    DAT_ffffc62b = 0;
    puVar2 = (undefined1 *)0x1;
  }
  else {
    if (DAT_ffffc623 != DAT_ffffb53b) {
      DAT_ffffc622 = '\x01';
    }
    if (DAT_ffffc622 == '\x01') {
      DAT_ffffc620 = '\b';
      puVar2 = (undefined1 *)(uint)DAT_ffffb534;
      if (puVar2 == (undefined1 *)0x1) {
        uVar3 = ref_getFaultStatus__(0x4c);
        puVar2 = (undefined1 *)(uVar3 & 0xff);
        if (puVar2 == (undefined1 *)0x0) {
          DAT_ffffc62b = 1;
          DAT_ffffc62a = 0;
        }
      }
    }
    else {
      puVar2 = (undefined1 *)(uint)(byte)DAT_ffffc624;
      if ((puVar2 == (undefined1 *)0x1) && (puVar2 = &DAT_ffffc627, DAT_ffffbf9c != DAT_ffffc627)) {
        if (DAT_ffffc620 != '\0') {
          DAT_ffffc620 = DAT_ffffc620 + -1;
        }
        if (DAT_ffffc620 == '\0') {
          uVar3 = ref_getFaultStatus__(0x4c);
          puVar2 = (undefined1 *)(uVar3 & 0xff);
          if ((puVar2 == (undefined1 *)0x0) &&
             (puVar2 = (undefined1 *)(uint)DAT_ffffb534, puVar2 == (undefined1 *)0x1)) {
            DAT_ffffc62a = 1;
            DAT_ffffc62b = 0;
          }
        }
      }
    }
  }
  DAT_ffffc623 = cVar1;
  return puVar2;
}


