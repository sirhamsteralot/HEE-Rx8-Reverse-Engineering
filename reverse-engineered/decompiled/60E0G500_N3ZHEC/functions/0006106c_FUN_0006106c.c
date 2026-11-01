/* ROM address: 0x0006106c; body bytes: 176; decompiled */

void FUN_0006106c(undefined4 param_1,uint param_2,short param_3)

{
  undefined2 uVar1;
  char cVar2;
  uint uVar3;
  byte bVar4;
  
  uVar3 = 0;
  for (bVar4 = 0; ((&DAT_0005f560)[(uVar3 & 0xff) * 2] != -1 && (bVar4 < 0x28));
      bVar4 = bVar4 + cVar2) {
    if ((&DAT_0005f560)[(uVar3 & 0xff) * 2] == '\x02') {
      if (((param_2 & 0xffff) == 0) || ((param_2 & 0xffff) == 1)) {
        uVar1 = FUN_00061152((int)param_3);
      }
      else {
        uVar1 = (&DAT_0007e108)[param_2 & 0xffff];
      }
      (&DAT_ffffd6d0)[bVar4] = (char)((ushort)uVar1 >> 8);
      (&DAT_ffffd6d1)[bVar4] = (char)uVar1;
      cVar2 = '\x02';
    }
    else {
      cVar2 = FUN_000554cc(param_2,(int)(char)(&DAT_0005f560)[(uVar3 & 0xff) * 2],
                           &DAT_ffffd6d0 + bVar4);
    }
    uVar3 = uVar3 + 1;
  }
  FUN_00064378(&DAT_ffffd6d0);
  return;
}


