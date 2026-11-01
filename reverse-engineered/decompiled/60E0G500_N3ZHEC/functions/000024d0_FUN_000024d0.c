/* ROM address: 0x000024d0; body bytes: 40; decompiled */

int FUN_000024d0(float param_1,float param_2,float param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0xff;
  iVar2 = (int)((param_1 - param_3) / param_2 + 0.5);
  if ((iVar2 < 0x100) && (iVar1 = iVar2, iVar2 < 0)) {
    iVar1 = 0;
  }
  return iVar1;
}


