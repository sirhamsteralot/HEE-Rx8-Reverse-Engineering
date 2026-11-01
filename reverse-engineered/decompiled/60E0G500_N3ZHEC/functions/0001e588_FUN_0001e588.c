/* ROM address: 0x0001e588; body bytes: 760; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x0001e8b4) */
/* WARNING: Removing unreachable block (ram,0x0001e8ce) */

undefined4 * FUN_0001e588(void)

{
  char cVar1;
  undefined4 *puVar2;
  float *pfVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float arg3;
  float fVar8;
  
  fVar8 = 0.0;
  fVar4 = (float)FUN_0003eb72(0,&DAT_ffff8114);
  cVar1 = DAT_ffffcb38;
  arg3 = 1e-05;
  if (DAT_ffffb0ed == '\x01') {
    fVar4 = (float)DAT_ffffa424 * 8.0;
    if (DAT_ffffcb38 == DAT_ffffb133) {
      if (DAT_ffffcb38 == '\0') {
        fVar8 = DAT_ffffb110;
        fVar5 = (float)FUN_00002068(&DAT_0006a208);
        fVar6 = (float)FUN_00002068(fVar4,&DAT_0006a148);
        fVar7 = (float)FUN_00002068(fVar4,&DAT_0006a258);
        fVar4 = (float)FUN_00002068(fVar4,&DAT_0006a264);
        DAT_ffffb0f4 = fVar6 * -0.8 * fVar5;
        if (DAT_ffffb0ec == '\x01') {
          fVar5 = (DAT_ffffb12c - DAT_ffffb0e8) * 0.993;
          DAT_ffffb118 = 0.003;
        }
        else {
          fVar5 = (DAT_ffffb12c - DAT_ffffb0e8) * 0.9899999;
          DAT_ffffb118 = -0.003;
        }
        DAT_ffffb104 = (DAT_ffffb0e8 + fVar5) - DAT_ffffb0f0;
        DAT_ffffb108 = rx8_first_order_filter(DAT_ffffb104,DAT_ffffb108,0.75,arg3);
        DAT_ffffb10c = rx8_clamp_float(DAT_ffffb0f4 * DAT_ffffb108,fVar7,fVar4);
        DAT_ffffb0f8 = -0.008;
        fVar8 = DAT_ffffb108 + fVar8;
      }
      else {
        fVar8 = DAT_ffffb110;
        fVar5 = (float)FUN_00002068(DAT_ffffaa88,&DAT_0006a21c);
        fVar6 = (float)FUN_00002068(fVar4,&DAT_0006a15c);
        fVar7 = (float)FUN_00002068(fVar4,&DAT_0006a270);
        fVar4 = (float)FUN_00002068(fVar4,&DAT_0006a170);
        DAT_ffffb0f4 = fVar6 * -1.5 * fVar5;
        if (DAT_ffffb0ec == '\x01') {
          fVar5 = (DAT_ffffb12c - DAT_ffffb0e8) * 0.993;
          DAT_ffffb118 = 0.001;
        }
        else {
          fVar5 = (DAT_ffffb12c - DAT_ffffb0e8) * 0.9899999;
          DAT_ffffb118 = -0.001;
        }
        DAT_ffffb104 = (DAT_ffffb0e8 + fVar5) - DAT_ffffb0f0;
        DAT_ffffb108 = rx8_first_order_filter(DAT_ffffb104,DAT_ffffb108,0.75,arg3);
        DAT_ffffb10c = rx8_clamp_float(DAT_ffffb0f4 * DAT_ffffb108,fVar7,fVar4);
        DAT_ffffb0f8 = -0.005;
        fVar8 = DAT_ffffb108 + fVar8;
      }
      DAT_ffffb11c = DAT_ffffb10c + DAT_ffffb118 + DAT_ffffb0f8 * fVar8;
      puVar2 = (undefined4 *)FUN_0001e978(DAT_ffffb0f8 * fVar8,fVar8);
    }
    else {
      if (DAT_ffffb0ec == '\x01') {
        pfVar3 = (float *)&DAT_0007153c;
      }
      else {
        pfVar3 = (float *)&DAT_00071540;
      }
      DAT_ffffb104 = (DAT_ffffb0e8 + (DAT_ffffb12c - DAT_ffffb0e8) * *pfVar3) - DAT_ffffb0f0;
      DAT_ffffb108 = DAT_ffffb104;
      if (DAT_ffffcb38 == '\x01') {
        puVar2 = (undefined4 *)0x1;
        DAT_ffffb0e4 = fVar8;
        DAT_ffffb110 = fVar8;
        DAT_ffffb114 = fVar8;
      }
      else {
        fVar4 = (float)FUN_0003eb72(fVar8,&DAT_ffff811c);
        puVar2 = (undefined4 *)FUN_00002440(0xbc03126f,fVar8,arg3);
        DAT_ffffb0e4 = fVar4;
        DAT_ffffb110 = fVar8;
        DAT_ffffb114 = fVar4;
        if (((uint)puVar2 & 0xff) != 0) {
          DAT_ffffb110 = fVar4 / -0.008;
        }
      }
    }
  }
  else {
    if (DAT_ffffb0ec == '\x01') {
      pfVar3 = (float *)&DAT_0007153c;
    }
    else {
      pfVar3 = (float *)&DAT_00071540;
    }
    DAT_ffffb104 = (DAT_ffffb0e8 + (DAT_ffffb12c - DAT_ffffb0e8) * *pfVar3) - DAT_ffffb0f0;
    if (DAT_ffffb132 == '\0') {
      DAT_ffffb132 = '\x01';
      DAT_ffffb110 = fVar8;
      DAT_ffffb114 = fVar8;
    }
    puVar2 = &DAT_ffffaa10;
    if (80.0 <= DAT_ffffaa10) {
      pfVar3 = (float *)&DAT_00071558;
    }
    else {
      pfVar3 = (float *)&DAT_00071554;
    }
    DAT_ffffb0e4 = *pfVar3 * fVar4;
    DAT_ffffb108 = DAT_ffffb104;
  }
  DAT_ffffb12c = DAT_ffffb0f0;
  DAT_ffffb133 = cVar1;
  return puVar2;
}


