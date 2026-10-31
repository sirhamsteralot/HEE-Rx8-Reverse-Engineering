/* ROM address: 0x000608c8; body bytes: 176; decompiled */

void FUN_000608c8(undefined4 param_1,uint param_2,short param_3)

{
  undefined2 uVar1;
  char cVar2;
  uint uVar3;
  byte bVar4;
  
  uVar3 = 0;
  for (bVar4 = 0; ((&DAT_0005edbc)[(uVar3 & 0xff) * 2] != -1 && (bVar4 < 0x28));
      bVar4 = bVar4 + cVar2) {
    if ((&DAT_0005edbc)[(uVar3 & 0xff) * 2] == '\x02') {
      if (((param_2 & 0xffff) == 0) || ((param_2 & 0xffff) == 1)) {
        uVar1 = FUN_000609ae((int)param_3);
      }
      else {
        uVar1 = (&DAT_0007e560)[param_2 & 0xffff];
      }
      (&DAT_ffffd694)[bVar4] = (char)((ushort)uVar1 >> 8);
      (&DAT_ffffd695)[bVar4] = (char)uVar1;
      cVar2 = '\x02';
    }
    else {
      cVar2 = FUN_00054d28(param_2,(int)(char)(&DAT_0005edbc)[(uVar3 & 0xff) * 2],
                           &DAT_ffffd694 + bVar4);
    }
    uVar3 = uVar3 + 1;
  }
  FUN_00063bd4(&DAT_ffffd694);
  return;
}


