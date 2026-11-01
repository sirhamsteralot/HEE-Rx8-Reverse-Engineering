/* ROM address: 0x00030cda; body bytes: 206; decompiled */

undefined4 * FUN_00030cda(void)

{
  byte bVar1;
  undefined4 *puVar2;
  float fVar3;
  
  bVar1 = DAT_ffffa42c;
  puVar2 = (undefined4 *)&DAT_ffffbed0;
  if (DAT_ffffbed0 == '\0') {
    fVar3 = DAT_ffffaa10;
    if (DAT_ffffbf14 == '\0') {
      if ((DAT_ffffbf13 == '\0') &&
         (puVar2 = (undefined4 *)(uint)DAT_ffffa42c, puVar2 == (undefined4 *)&UNK_00000001)) {
        DAT_ffffbf10 = 0;
        DAT_ffffbf14 = '\x01';
      }
    }
    else {
      puVar2 = (undefined4 *)FUN_00002478((int)(char)DAT_ffffbf10,1);
      DAT_ffffbf10 = (byte)puVar2;
    }
    if ((((0xb < DAT_ffffbf10) && (-5.0 <= fVar3)) &&
        (puVar2 = (undefined4 *)(int)DAT_ffffa428, puVar2 == (undefined4 *)0x0)) &&
       (((DAT_ffffadbc < 20.0 && (puVar2 = &DAT_00078280, DAT_ffffaa40 < 80.0)) &&
        (DAT_ffffce6f == '\0')))) {
      DAT_ffffbed0 = '\x01';
      DAT_ffffbf10 = 0;
      DAT_ffffbf14 = '\0';
      DAT_ffffbecc = FUN_00002068(fVar3,&DAT_0006afcc);
      puVar2 = (undefined4 *)FUN_00009630(0,1,&DAT_ffffbecc);
    }
  }
  DAT_ffffbf13 = bVar1;
  return puVar2;
}


