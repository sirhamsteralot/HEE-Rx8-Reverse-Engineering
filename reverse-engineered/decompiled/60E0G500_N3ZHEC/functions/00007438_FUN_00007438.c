/* ROM address: 0x00007438; body bytes: 82; decompiled */

undefined2 * maf_sensor_scaling(void)

{
  ushort uVar1;
  undefined2 *puVar2;
  
  uVar1 = DAT_ffff9eea;
  DAT_ffff9f78 = FUN_00002068((float)DAT_ffff9eea * 7.6293945e-05,&DAT_00069e4c);
  if (uVar1 < 0xfae2) {
    puVar2 = &DAT_0006cf04;
    if (uVar1 < 0xac0) {
      DAT_ffff9f7c = 2;
    }
    else {
      DAT_ffff9f7c = 0;
    }
  }
  else {
    puVar2 = (undefined2 *)&UNK_00000001;
    DAT_ffff9f7c = 1;
  }
  return puVar2;
}


