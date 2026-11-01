/* ROM address: 0x0005c7a2; body bytes: 38; decompiled */

undefined4 FUN_0005c7a2(byte param_1)

{
  undefined4 uVar1;
  
  if ((param_1 < 0x1a) && (*(&PTR_DAT_0005fed8)[(uint)param_1 * 4] == '\0')) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


