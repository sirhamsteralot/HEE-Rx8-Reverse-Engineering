/* ROM address: 0x0004a2cc; body bytes: 144; decompiled */

undefined2 * FUN_0004a2cc(void)

{
  short sVar1;
  undefined2 *puVar2;
  float extraout_fr0;
  
  sVar1 = DAT_ffffcd5e;
  puVar2 = (undefined2 *)(uint)DAT_ffffd201;
  if (puVar2 == (undefined2 *)&UNK_00000001) {
    DAT_ffffcd58 = 0.0;
    puVar2 = (undefined2 *)&DAT_ffffcd62;
    DAT_ffffcd61 = 0;
    DAT_ffffcd62 = 0;
  }
  else {
    if (DAT_ffffcd5e != 0) {
      puVar2 = (undefined2 *)FUN_000024c0(0x3f800000,0);
      DAT_ffffcd58 = DAT_ffffcd68 / extraout_fr0;
    }
    if (sVar1 == -1) {
      if (1e+23 <= DAT_ffffcd58) {
        DAT_ffffcd62 = 1;
      }
      else {
        DAT_ffffcd61 = 1;
      }
    }
    else {
      puVar2 = &DAT_0007c5ca;
      if (DAT_ffffcd58 < 1e+23) {
        DAT_ffffcd61 = 1;
      }
    }
  }
  return puVar2;
}


