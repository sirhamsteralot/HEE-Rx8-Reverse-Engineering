/* ROM address: 0x00008ee6; body bytes: 68; decompiled */

undefined4 FUN_00008ee6(byte param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  uVar1 = FUN_00003920(0x10);
  if ((&DAT_ffffa0dc)[(uint)param_1 * 8] != '\0') {
    if ((&DAT_ffffa0dd)[(uint)param_1 * 8] == '\0') {
      uVar2 = 1;
    }
    else {
      uVar2 = 2;
    }
  }
  FUN_00003934(uVar1);
  return uVar2;
}


