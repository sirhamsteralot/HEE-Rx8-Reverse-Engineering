/* ROM address: 0x000388c4; body bytes: 202; decompiled */

undefined4 FUN_000388c4(ushort param_1,byte param_2,char param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = FUN_00003920(0x10);
  if (DAT_ffffc511 == '\x01') {
    uVar3 = 1;
  }
  else {
    DAT_ffffc511 = '\x01';
    DAT_ffffc4fe = (undefined2)((int)(uint)param_1 >> 1);
    iVar2 = (uint)param_2 + (uint)param_1 + -1;
    DAT_ffffc500 = (undefined2)((int)(iVar2 + (uint)(iVar2 < 0)) >> 1);
    DAT_ffffc514 = 1;
    if (param_3 == '\x01') {
      DAT_ffffc2f8 = 0;
      DAT_ffffc2fb = 0;
      DAT_ffffc50c = 1;
    }
    else if (param_3 == '\x02') {
      DAT_ffffc2f9 = 0;
      DAT_ffffc2fc = 0;
      DAT_ffffc50c = 2;
    }
    else if (param_3 == '\x03') {
      DAT_ffffc50c = 3;
      DAT_ffffc2fa = 0;
      DAT_ffffc2fd = 0;
    }
    else if (param_3 == '\x04') {
      DAT_ffffc50c = 4;
    }
    else {
      DAT_ffffc50c = 0;
    }
    uVar3 = 0;
    DAT_ffffc50f = 0;
    DAT_ffffc516 = 0;
    DAT_ffffc515 = 0;
    DAT_ffffc510 = 0;
  }
  DAT_ffffc506 = param_1;
  FUN_00003934(uVar1);
  return uVar3;
}


