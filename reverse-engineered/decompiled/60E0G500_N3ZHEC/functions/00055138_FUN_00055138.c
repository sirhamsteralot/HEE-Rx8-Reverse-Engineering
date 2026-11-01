/* ROM address: 0x00055138; body bytes: 80; decompiled */

uint FUN_00055138(undefined1 *param_1,char param_2,undefined1 *param_3)

{
  undefined1 uVar1;
  uint uVar2;
  char *pcVar3;
  
  for (pcVar3 = &DAT_0005f560; (*pcVar3 != param_2 && (*pcVar3 != -1)); pcVar3 = pcVar3 + 2) {
    param_1 = param_1 + (byte)pcVar3[1];
  }
  if (*pcVar3 == -1) {
    uVar2 = 0;
  }
  else {
    for (uVar2 = 0; (uVar2 & 0xff) < (uint)(byte)pcVar3[1]; uVar2 = uVar2 + 1) {
      uVar1 = *param_1;
      param_1 = param_1 + 1;
      *param_3 = uVar1;
      param_3 = param_3 + 1;
    }
  }
  return uVar2;
}


