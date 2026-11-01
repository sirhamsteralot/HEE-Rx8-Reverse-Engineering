/* ROM address: 0x00065c24; body bytes: 224; decompiled */

void FUN_00065c24(short *param_1)

{
  char cVar1;
  char cVar2;
  
  FUN_00062e78(0);
  if ((*(char *)(param_1 + 3) == '\0') || (*(char *)(param_1 + 3) == 'P')) {
    FUN_00067de0(0);
    FUN_00067e6c(0);
  }
  else if (*(char *)(param_1 + 6) == '\0') {
    FUN_00067e6c(0);
  }
  if (*param_1 == 1) {
    cVar1 = FUN_00061fa4(0);
    cVar2 = FUN_000624be(0);
  }
  else {
    cVar1 = FUN_00061fa4(1);
    cVar2 = FUN_000624be(1);
  }
  if (((*(char *)(param_1 + 3) == '\0') || (*(char *)(param_1 + 3) == 'P')) &&
     ((cVar1 == '\0' || (cVar1 == 'P')))) {
    FUN_0006832c(0);
  }
  if ((*(char *)(param_1 + 6) == '\0') && (cVar2 == '\0')) {
    FUN_000683aa(0);
  }
  if (((*(char *)(param_1 + 3) == '\0') || (*(char *)(param_1 + 3) == 'P')) &&
     ((cVar1 == '\0' || (cVar1 == 'P')))) {
    FUN_00068408(0);
  }
  FUN_000630bc(0);
  return;
}


