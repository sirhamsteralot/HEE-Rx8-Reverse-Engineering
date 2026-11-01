/* ROM address: 0x00016950; body bytes: 162; decompiled */

undefined4 * FUN_00016950(void)

{
  undefined4 *puVar1;
  undefined *puVar2;
  undefined4 extraout_fr0;
  undefined4 extraout_fr0_00;
  undefined4 extraout_fr0_01;
  
  if (DAT_ffffbdd5 == '\0') {
    puVar1 = &DAT_ffffa8dc;
    DAT_ffffa8dc = 0;
  }
  else {
    if ((DAT_ffffb5a4 == '\x01') || (DAT_ffffb5ac == '\0')) {
      if (DAT_ffffbe24 == '\0') {
        puVar2 = &DAT_00069928;
      }
      else {
        puVar2 = &DAT_0006993c;
      }
      puVar1 = (undefined4 *)FUN_00002068(puVar2);
      DAT_ffffa8e0 = extraout_fr0;
    }
    else if (DAT_ffffb5b0 == '\x01') {
      if (DAT_ffffbe24 == '\0') {
        puVar2 = &DAT_00069950;
      }
      else {
        puVar2 = &DAT_00069964;
      }
      puVar1 = (undefined4 *)FUN_00002068(puVar2);
      DAT_ffffa8e0 = extraout_fr0_00;
    }
    else {
      puVar1 = (undefined4 *)(uint)DAT_ffffb5ae;
      if (puVar1 == (undefined4 *)0x1) {
        if (DAT_ffffbe24 == '\0') {
          puVar2 = &DAT_00069978;
        }
        else {
          puVar2 = &DAT_0006998c;
        }
        puVar1 = (undefined4 *)FUN_00002068(DAT_ffffae54,puVar2);
        DAT_ffffa8e0 = extraout_fr0_01;
      }
    }
    DAT_ffffa8dc = DAT_ffffa8e0;
  }
  return puVar1;
}


