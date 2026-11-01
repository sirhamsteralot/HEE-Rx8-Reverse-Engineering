/* ROM address: 0x00004bbc; body bytes: 24; decompiled */

void FUN_00004bbc(ushort *param_1,ushort param_2,short param_3)

{
  if (param_3 == 0) {
    *param_1 = *param_1 & ~param_2;
    return;
  }
  *param_1 = *param_1 | param_2;
  return;
}


