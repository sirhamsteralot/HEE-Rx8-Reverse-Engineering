/* ROM address: 0x00068844; body bytes: 62; decompiled */

void FUN_00068844(int param_1)

{
  char cVar1;
  
  if ((((param_1 == 0x7e0) || (param_1 == 0x7df)) && (cVar1 = FUN_00068b78(), cVar1 != '@')) &&
     (cVar1 = FUN_00068bd0(), cVar1 == '\0')) {
    FUN_00068c58(param_1);
    return;
  }
  return;
}


