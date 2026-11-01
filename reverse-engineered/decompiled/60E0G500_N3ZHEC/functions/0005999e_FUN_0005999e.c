/* ROM address: 0x0005999e; body bytes: 152; decompiled */

undefined4 FUN_0005999e(char param_1)

{
  char cVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((((((DAT_ffffd1e9 == '\x01') || (DAT_ffffd29d == '\x01')) || (DAT_ffffd2a2 == '\x01')) ||
       (DAT_ffffd2ab == '\x01')) ||
      (((cVar1 = FUN_000565e2(0), cVar1 == '\x01' && (cVar1 = FUN_000565e2(2), cVar1 == '\x01')) ||
       ((param_1 == '\x02' && (DAT_ffffd29a == '\0')))))) ||
     (((param_1 == -0x7e && (DAT_ffffd29b == '\0')) ||
      ((param_1 == '\x0f' && (DAT_ffffd29c == '\0')))))) {
    uVar2 = 1;
  }
  return uVar2;
}


