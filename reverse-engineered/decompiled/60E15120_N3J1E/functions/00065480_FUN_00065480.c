/* ROM address: 0x00065480; body bytes: 224; decompiled */

void FUN_00065480(short *param_1)

{
  char cVar1;
  char cVar2;
  
  FUN_000626d4(0);
  if ((*(char *)(param_1 + 3) == '\0') || (*(char *)(param_1 + 3) == 'P')) {
    FUN_0006763c(0);
    FUN_000676c8(0);
  }
  else if (*(char *)(param_1 + 6) == '\0') {
    FUN_000676c8(0);
  }
  if (*param_1 == 1) {
    cVar1 = FUN_00061800(0);
    cVar2 = FUN_00061d1a(0);
  }
  else {
    cVar1 = FUN_00061800(1);
    cVar2 = FUN_00061d1a(1);
  }
  if (((*(char *)(param_1 + 3) == '\0') || (*(char *)(param_1 + 3) == 'P')) &&
     ((cVar1 == '\0' || (cVar1 == 'P')))) {
    FUN_00067b88(0);
  }
  if ((*(char *)(param_1 + 6) == '\0') && (cVar2 == '\0')) {
    FUN_00067c06(0);
  }
  if (((*(char *)(param_1 + 3) == '\0') || (*(char *)(param_1 + 3) == 'P')) &&
     ((cVar1 == '\0' || (cVar1 == 'P')))) {
    FUN_00067c64(0);
  }
  FUN_00062918(0);
  return;
}


