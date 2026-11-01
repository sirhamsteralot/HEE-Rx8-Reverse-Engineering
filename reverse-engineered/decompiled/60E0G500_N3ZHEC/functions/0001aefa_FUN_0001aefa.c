/* ROM address: 0x0001aefa; body bytes: 164; decompiled */

undefined4 * FUN_0001aefa(void)

{
  ushort uVar1;
  undefined4 *puVar2;
  undefined4 extraout_fr0;
  
  uVar1 = DAT_ffff9eea;
  puVar2 = (undefined4 *)FUN_000024c0(0x38a00000,0,(int)(short)DAT_ffff9eea);
  DAT_ffffaac8 = extraout_fr0;
  if (uVar1 < 0xf852) {
    DAT_ffffaacd = 0;
  }
  else {
    puVar2 = (undefined4 *)FUN_00002478((int)(char)DAT_ffffaacd,1);
    DAT_ffffaacd = (byte)puVar2;
  }
  if (uVar1 < 0x7ae) {
    puVar2 = (undefined4 *)FUN_00002478((int)(char)DAT_ffffaace,1);
    DAT_ffffaace = (byte)puVar2;
  }
  else {
    DAT_ffffaace = 0;
  }
  if (((2 < DAT_ffffaacd) || (2 < DAT_ffffaace)) ||
     ((uVar1 < 0xf852 && (puVar2 = (undefined4 *)0x7ae, 0x7ad < uVar1)))) {
    DAT_ffffaa80 = DAT_ffffaac8;
    puVar2 = &DAT_ffffaa84;
    DAT_ffffaa84 = DAT_ffff9f78;
  }
  return puVar2;
}


