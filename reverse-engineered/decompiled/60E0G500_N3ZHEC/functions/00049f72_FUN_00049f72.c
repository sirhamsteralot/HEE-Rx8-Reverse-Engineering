/* ROM address: 0x00049f72; body bytes: 108; decompiled */

undefined2 * FUN_00049f72(void)

{
  undefined2 *puVar1;
  
  if (DAT_ffffcd7e == '\x01') {
    if ((DAT_ffffcd7f != '\0') || (puVar1 = &DAT_ffffcd5c, DAT_ffffcd5c == 0)) {
      puVar1 = (undefined2 *)FUN_00002460((int)(short)DAT_ffffcd5c,1);
      DAT_ffffcd5c = (short)puVar1;
      DAT_ffffcd7f = DAT_ffffcd7e;
      return puVar1;
    }
  }
  else if ((DAT_ffffcd7f != '\x01') || (puVar1 = (undefined2 *)0x20, 0x1f < DAT_ffffcd5c)) {
    if ((undefined2 *)(uint)DAT_ffffcd60 != (undefined2 *)0x1) {
      DAT_ffffcd7f = DAT_ffffcd7e;
      return (undefined2 *)(uint)DAT_ffffcd60;
    }
    DAT_ffffcd5c = 0;
    DAT_ffffcd7f = DAT_ffffcd7e;
    return (undefined2 *)&UNK_00000001;
  }
  DAT_ffffcd5c = 0;
  DAT_ffffcd7f = DAT_ffffcd7e;
  return puVar1;
}


