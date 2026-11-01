/* ROM address: 0x000217cc; body bytes: 150; decompiled */

undefined4 * FUN_000217cc(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(uint)DAT_ffffb2f4;
  if (puVar1 == (undefined4 *)0x1) {
    DAT_ffffb2e4 = (float)FUN_00002068(DAT_ffffadc8,&DAT_00069ec0);
    DAT_ffffb2e8 = (float)FUN_00002068(DAT_ffffc12c,&DAT_00069ed4);
    DAT_ffffb2ec = (float)FUN_00002068(DAT_ffffb5b8,&DAT_00069ee8);
    DAT_ffffb2f0 = (float)FUN_00002068(DAT_ffffaa10,&DAT_00069efc);
    DAT_ffffb2dc = DAT_ffffb2e4 * 1.0 * DAT_ffffb2e8 * DAT_ffffb2ec * DAT_ffffb2f0;
    puVar1 = &DAT_000218a0;
    if (500.0 <= DAT_ffffb2dc) {
      DAT_ffffb2f5 = 1;
      puVar1 = (undefined4 *)FUN_00009630(0,1,&DAT_ffffb2dc);
      return puVar1;
    }
  }
  DAT_ffffb2f5 = 0;
  return puVar1;
}


