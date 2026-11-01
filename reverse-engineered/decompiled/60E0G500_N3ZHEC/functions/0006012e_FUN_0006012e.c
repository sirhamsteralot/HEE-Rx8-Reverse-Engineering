/* ROM address: 0x0006012e; body bytes: 38; decompiled */

uint FUN_0006012e(short param_1)

{
  uint uVar1;
  
  for (uVar1 = 0; ((&DAT_0007e102)[uVar1 & 0xffff] != param_1 && ((uVar1 & 0xffff) < 3));
      uVar1 = uVar1 + 1) {
  }
  return uVar1;
}


