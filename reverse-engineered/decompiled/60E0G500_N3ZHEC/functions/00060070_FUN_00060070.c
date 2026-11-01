/* ROM address: 0x00060070; body bytes: 46; decompiled */

uint FUN_00060070(uint param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  char cVar1;
  uint uVar2;
  
  cVar1 = '\0';
  uVar2 = 1;
  do {
    if ((param_1 & 1) != 0) {
      cVar1 = cVar1 + '\x01';
      param_4 = uVar2;
    }
    param_1 = (param_1 & 0xffff) >> 1;
    uVar2 = uVar2 + 1;
  } while ((uVar2 & 0xffff) < 3);
  if (cVar1 != '\x01') {
    param_4 = 0;
  }
  return param_4;
}


