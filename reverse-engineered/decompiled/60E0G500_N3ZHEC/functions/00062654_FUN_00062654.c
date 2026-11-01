/* ROM address: 0x00062654; body bytes: 258; decompiled */

void FUN_00062654(uint param_1,char param_2,undefined2 param_3)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  
  bVar2 = FUN_0006359c(param_1);
  bVar1 = DAT_ffffd6ff;
  cVar3 = FUN_000637ea(param_1);
  if ((bVar2 == 0) || (bVar2 == 0x50)) {
    if ((bVar1 == 0) || (0x3f < bVar1)) {
      if ((bVar1 & 0x80) == 0x80) {
        DAT_ffffd6fa = param_3;
        DAT_ffffd6fe = 2;
        return;
      }
      if (param_2 == '\x01') goto LAB_0006271e;
      if (param_2 != '\x02') {
        if (((param_1 & 0xffff) != 0) && ((param_1 & 0xffff) != 1)) {
          DAT_ffffd6fa = param_3;
          DAT_ffffd6fe = 8;
          return;
        }
        DAT_ffffd6fa = param_3;
        DAT_ffffd6fe = 9;
        return;
      }
      if (cVar3 != '\0') {
        DAT_ffffd6fa = param_3;
        DAT_ffffd6fe = 4;
        return;
      }
    }
    DAT_ffffd6fe = 1;
  }
  else {
    if ((bVar2 == 0) || (0x3f < bVar2)) {
      if ((bVar2 & 0x80) != 0x80) {
        DAT_ffffd6fa = param_3;
        DAT_ffffd6fe = 8;
        return;
      }
      DAT_ffffd6fa = param_3;
      DAT_ffffd6fe = 5;
      return;
    }
    if ((bVar1 & 0x80) == 0x80) {
      DAT_ffffd6fa = param_3;
      DAT_ffffd6fe = 3;
      return;
    }
    if ((bVar1 != 0) && (bVar1 != 0x50)) {
      if (bVar1 == 0) {
        DAT_ffffd6fa = param_3;
        DAT_ffffd6fe = 8;
        return;
      }
      if (0x3f < bVar1) {
        DAT_ffffd6fa = param_3;
        DAT_ffffd6fe = 8;
        return;
      }
      DAT_ffffd6fa = param_3;
      DAT_ffffd6fe = 4;
      return;
    }
LAB_0006271e:
    DAT_ffffd6fe = 7;
  }
  DAT_ffffd6fa = param_3;
  return;
}


