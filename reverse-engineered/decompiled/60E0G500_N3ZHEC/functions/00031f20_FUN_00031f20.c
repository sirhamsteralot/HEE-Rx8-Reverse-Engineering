/* ROM address: 0x00031f20; body bytes: 310; decompiled */

char FUN_00031f20(void)

{
  undefined *puVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  undefined4 uVar5;
  float arg1;
  undefined4 uVar6;
  
  puVar1 = (undefined *)((uint)DAT_ffffa6b4 << 3);
  arg1 = 0.0;
  uVar5 = DAT_ffffaa10;
  uVar6 = DAT_ffffad8c;
  if (puVar1 < (undefined *)0x233) {
    fVar2 = (float)FUN_00002068(DAT_ffffaa10,&DAT_0006b0cc);
    fVar3 = (float)FUN_00002068(uVar6,&DAT_0006b0e0);
    DAT_ffffbfc0 = fVar2 * fVar3;
  }
  else if (puVar1 < (undefined *)0x3a9) {
    DAT_ffffbfc0 = rx8_max_float(DAT_ffffbfc0 - 0.0008,0.0);
  }
  if (&DAT_00001405 < puVar1) {
    DAT_ffffbfc4 = rx8_max_float(DAT_ffffbfc4 - 50.0,arg1);
  }
  else if ((undefined *)0x3a8 < puVar1) {
    fVar2 = (float)FUN_00002068(uVar5,&DAT_0006b0f4);
    fVar3 = (float)FUN_00002068(uVar6,&DAT_0006b108);
    DAT_ffffbfc4 = fVar2 * fVar3;
  }
  if (&DAT_00001405 < puVar1) {
    DAT_ffffbfc8 = rx8_max_float(DAT_ffffbfc8 - 50.0,arg1);
  }
  else {
    fVar2 = (float)FUN_00002068(uVar5,&DAT_0006b11c);
    fVar3 = (float)FUN_00002068(uVar6,&DAT_0006b130);
    fVar4 = (float)FUN_00002068(DAT_ffffc12c,&DAT_0006b144);
    DAT_ffffbfc8 = fVar2 * fVar3 * fVar4;
  }
  DAT_ffffbfb0 = DAT_ffffbfc8;
  if (((DAT_ffffa6b9 != '\x01') && (DAT_ffffbfb0 = DAT_ffffbfc0, DAT_ffffa6b7 != '\x01')) &&
     (DAT_ffffbfb0 = DAT_ffffbfc4, DAT_ffffa6b8 != '\x01')) {
    DAT_ffffbfb0 = arg1;
    return DAT_ffffa6b8;
  }
  return '\x01';
}


