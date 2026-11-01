/* ROM address: 0x0001d080; body bytes: 940; decompiled */

uint FUN_0001d080(void)

{
  char cVar1;
  uint uVar2;
  byte bVar3;
  byte bVar4;
  undefined4 *puVar5;
  uint uVar6;
  float arg0;
  float fVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  float arg1;
  
  cVar1 = DAT_ffffae97;
  if (DAT_ffffb5b8 < 5500.0) {
    if (DAT_ffffb5b8 < 5400.0) {
      DAT_ffffb0d8 = '\0';
    }
  }
  else {
    DAT_ffffb0d8 = '\x01';
  }
  arg1 = 1.0;
  uVar9 = DAT_ffffaa88;
  fVar7 = DAT_ffffb5b8;
  if ((DAT_ffffae97 == '\x01') || (DAT_ffffb0d8 == '\0')) {
    arg0 = (float)FUN_0003ea74(0x41f00000,DAT_ffffb5b8);
    DAT_ffffae9c = rx8_min_float(arg0,arg1);
    DAT_ffffaea4 = (float)FUN_000020dc(uVar9,fVar7,&DAT_0006a038);
    DAT_ffffb098 = (float)FUN_00002068(uVar9,&DAT_00069f10);
    DAT_ffffaea8 = DAT_ffffb098 * 1.0;
  }
  if (cVar1 == '\0') {
    DAT_ffffb068 = 0.09999999;
  }
  else {
    DAT_ffffb068 = rx8_min_float(DAT_ffffb068 + 0.05,arg1);
  }
  DAT_ffffb080 = 1.0;
  if ((cVar1 == '\x01') || (uVar2 = (uint)DAT_ffffb0d8, uVar2 == 0)) {
    DAT_ffffb09c = (float)FUN_000020dc(uVar9,fVar7,&DAT_0006a054);
    DAT_ffffaeac = DAT_ffffb068 * 1.0 * DAT_ffffb080 * DAT_ffffb09c;
    DAT_ffffaeb0 = DAT_ffffae9c * DAT_ffffaeac;
    DAT_ffffaeb4 = FUN_0003ea74(DAT_ffffae9c,DAT_ffffaea8);
    DAT_ffffaeb8 = (float)FUN_00002068(DAT_ffffaeb4,&DAT_00069fd0);
    fVar7 = (float)FUN_0003ea74(DAT_ffffaea4,DAT_ffffae9c);
    DAT_ffffaea0 = rx8_min_float(fVar7,20.0);
    uVar9 = 0;
    DAT_ffffb092 = FUN_000024d0(DAT_ffffaea0 + -0.5,arg1,0);
    if (DAT_ffffb092 == 0) {
      DAT_ffffb092 = 1;
    }
    else if (0x13 < DAT_ffffb092) {
      DAT_ffffb092 = 0x13;
    }
    fVar7 = (float)FUN_00002500(arg1,uVar9,(int)(char)DAT_ffffb092);
    DAT_ffffaebc = DAT_ffffaea4 - DAT_ffffae9c * fVar7;
    DAT_ffffaec0 = FUN_0003ea74(DAT_ffffae9c - DAT_ffffaebc,DAT_ffffaea8);
    DAT_ffffb0a0 = (float)FUN_00002068(DAT_ffffaec0,&DAT_00069fdc);
    DAT_ffffaec4 = arg1 - DAT_ffffb0a0;
    DAT_ffffaec8 = (arg1 - DAT_ffffaeb8) - DAT_ffffaec4;
    DAT_ffffaecc = DAT_ffffaeb0 * 0.9;
    fVar7 = 2.0;
    DAT_ffffaed0 = DAT_ffffaecc * 2.0;
    DAT_ffffb0a4 = (float)FUN_00002068(DAT_ffffaecc,&DAT_00069fe8);
    DAT_ffffaed4 = -((arg1 - (arg1 - 0.80999994) * DAT_ffffaeb0 * DAT_ffffaeb0 * 0.5) * DAT_ffffb0a4
                    * fVar7);
    DAT_ffffaed8 = (float)FUN_00002068(DAT_ffffaed0,&DAT_00069ff4);
    DAT_ffffaedc = (float)FUN_0003ea74(DAT_ffffaed4 + DAT_ffffaed8 + arg1,
                                       DAT_ffffaec4 + DAT_ffffaec8);
    DAT_ffffaee4 = (-1.0 - DAT_ffffaeb8) - DAT_ffffaed4;
    if (DAT_ffffb092 == 1) {
      fVar7 = (float)FUN_0003ea74(DAT_ffffaeb8,DAT_ffffaec8 + DAT_ffffaeb8 * DAT_ffffaec4);
      DAT_ffffaf3c = fVar7 * (DAT_ffffaee4 * DAT_ffffaeb8 - DAT_ffffaec8 * DAT_ffffaedc);
      DAT_ffffaee8 = (float)FUN_0003ea74(DAT_ffffaec8 * DAT_ffffaf3c,DAT_ffffaeb8);
      bVar3 = 3;
      puVar5 = &DAT_ffffaeec;
      do {
        *puVar5 = uVar9;
        bVar3 = bVar3 + 1;
        puVar5 = puVar5 + 1;
      } while (bVar3 < 0x16);
      uVar2 = 8;
    }
    else if (DAT_ffffb092 == 2) {
      DAT_ffffaee8 = (DAT_ffffaeb8 + DAT_ffffaee4 * (DAT_ffffaeb8 + arg1)) - DAT_ffffaed8;
      fVar7 = (float)FUN_0003ea74(DAT_ffffaeb8);
      DAT_ffffaf3c = fVar7 * (DAT_ffffaee8 * DAT_ffffaeb8 - DAT_ffffaec8 * DAT_ffffaedc);
      DAT_ffffaeec = FUN_0003ea74(DAT_ffffaec8 * DAT_ffffaf3c,DAT_ffffaeb8);
      bVar3 = 4;
      puVar5 = &DAT_ffffaef0;
      do {
        *puVar5 = uVar9;
        bVar3 = bVar3 + 1;
        puVar5 = puVar5 + 1;
      } while (bVar3 < 0x16);
      uVar2 = 0xc;
    }
    else {
      DAT_ffffaee8 = (DAT_ffffaeb8 + DAT_ffffaee4 * (DAT_ffffaeb8 + arg1)) - DAT_ffffaed8;
      for (bVar3 = 3; bVar3 <= DAT_ffffb092; bVar3 = bVar3 + 1) {
        *(float *)(&DAT_ffffaee0 + (uint)bVar3 * 4) =
             *(float *)(&DAT_ffffaee0 + (bVar3 - 1) * 4) * (DAT_ffffaeb8 + arg1) -
             *(float *)(&DAT_ffffaee0 + (bVar3 - 2) * 4) * DAT_ffffaeb8;
      }
      bVar4 = DAT_ffffb092 + 1;
      bVar3 = DAT_ffffb092 + 2;
      DAT_ffffaf38 = *(float *)(&DAT_ffffaee0 + (uint)DAT_ffffb092 * 4);
      fVar7 = (float)FUN_0003ea74(DAT_ffffaeb8);
      DAT_ffffaf3c = fVar7 * (DAT_ffffaeb8 * DAT_ffffaf38 - DAT_ffffaec8 * DAT_ffffaedc);
      uVar8 = FUN_0003ea74(DAT_ffffaec8 * DAT_ffffaf3c,DAT_ffffaeb8);
      *(undefined4 *)(&DAT_ffffaee0 + (uint)bVar4 * 4) = uVar8;
      uVar2 = (uint)(char)bVar3;
      puVar5 = (undefined4 *)(&DAT_ffffaee0 + (uint)bVar3 * 4);
      uVar6 = uVar2;
      if (bVar3 < 0x16) {
        do {
          uVar6 = uVar6 + 1;
          *puVar5 = uVar9;
          puVar5 = puVar5 + 1;
        } while ((uVar6 & 0xff) < 0x16);
      }
    }
  }
  return uVar2;
}


