/* ROM address: 0x0001db18; body bytes: 712; decompiled */

undefined4 FUN_0001db18(void)

{
  char cVar1;
  short sVar2;
  ushort uVar3;
  undefined *puVar4;
  int iVar5;
  undefined4 uVar6;
  float extraout_fr0;
  float extraout_fr0_00;
  float fVar7;
  float fVar8;
  
  sVar2 = DAT_ffffae90;
  cVar1 = DAT_ffffa41c;
  iVar5 = (int)DAT_ffffb088;
  if (DAT_ffffaae8 < 1.25) {
    if (DAT_ffffaae8 < 1.33) {
      DAT_ffffb0d9 = '\0';
    }
  }
  else {
    DAT_ffffb0d9 = '\x01';
  }
  uVar6 = DAT_ffffaa88;
  fVar7 = DAT_ffffad98;
  fVar8 = DAT_ffffaa10;
  if (DAT_ffffaada == '\x01') {
    if (DAT_ffffb5aa == '\x01') {
      puVar4 = &DAT_0006a070;
    }
    else {
      puVar4 = &DAT_0006a08c;
    }
    DAT_ffffae78 = FUN_000020dc(DAT_ffffaa10,puVar4);
  }
  else {
    DAT_ffffae78 = FUN_000020dc(DAT_ffffaa10,DAT_ffffc12c,&DAT_0006a0a8);
  }
  if ((DAT_ffffaaf9 == '\0') || (cVar1 == '\x01')) {
    DAT_ffffb093 = '\0';
    iVar5 = 0;
  }
  else if (DAT_ffffb0d9 == '\x01') {
    DAT_ffffb093 = '\x01';
    iVar5 = FUN_00002460(iVar5,1);
    DAT_ffffb0dc = '\x01';
  }
  else {
    DAT_ffffb093 = '\0';
  }
  if ((((DAT_ffffb0dc == '\x01') && (DAT_ffffb093 == '\0')) && (DAT_ffffb0d0 < 3)) && (fVar7 < 0.5))
  {
    DAT_ffffb090 = 1;
  }
  uVar3 = FUN_000020c4(uVar6,&DAT_00069fb8);
  if (0.5 <= fVar7) {
    if (uVar3 < DAT_ffffb090) {
      DAT_ffffb090 = DAT_ffffb090 - uVar3;
    }
    else {
      DAT_ffffb090 = 0;
    }
  }
  fVar7 = 0.0;
  if (((fVar8 < 65.0) || (cVar1 == '\x01')) ||
     (((DAT_ffffb0dc == '\x01' && ((DAT_ffffb093 == '\0' && (2 < DAT_ffffb0d0)))) &&
      (DAT_ffffb090 == 0)))) {
    DAT_ffffb08a = 0;
  }
  else {
    if ((DAT_ffffb0db != '\x01') || (DAT_ffffb093 != '\0')) {
      if ((DAT_ffffb093 == '\0') && (sVar2 == 0)) {
        DAT_ffffb08c = FUN_000020c4(uVar6,&DAT_00069fc4);
        if (DAT_ffffb08c < DAT_ffffb08a) {
          DAT_ffffb08a = DAT_ffffb08a - DAT_ffffb08c;
        }
        else {
          DAT_ffffb08a = 0;
        }
      }
      goto LAB_0001ddba;
    }
    uVar6 = FUN_000024c0(0x42000000,0,iVar5);
    uVar6 = FUN_000020c4(uVar6,&PTR_PTR_00069fac);
    DAT_ffffb0cc = (undefined2)uVar6;
    DAT_ffffb08a = FUN_00002460((int)(short)DAT_ffffb08a,uVar6);
    if (0x124f < DAT_ffffb08a) {
      DAT_ffffb08a = 0x1250;
    }
  }
  iVar5 = 0;
LAB_0001ddba:
  if ((sVar2 == 0) && (DAT_ffffb08a != 0)) {
    DAT_ffffae98 = 1;
    DAT_ffffaf94 = -0.002;
  }
  else {
    DAT_ffffae98 = 0;
    DAT_ffffaf94 = fVar7;
  }
  if ((DAT_ffffb0dc == '\x01') && (DAT_ffffb093 == '\0')) {
    DAT_ffffb0d0 = FUN_00002460((int)(short)DAT_ffffb0d0,1);
  }
  else {
    DAT_ffffb0d0 = 0;
  }
  DAT_ffffb088 = (short)iVar5;
  DAT_ffffb0db = DAT_ffffb093;
  uVar6 = FUN_000024c0(0x41000000,fVar7,(int)DAT_ffffa424);
  uVar6 = FUN_000020dc(uVar6,fVar8,&DAT_0006a134);
  fVar8 = fVar7;
  if (extraout_fr0 <= DAT_ffffb078) {
    fVar8 = DAT_ffffb078 - extraout_fr0;
  }
  DAT_ffffb078 = fVar8;
  DAT_ffffb07c = extraout_fr0;
  if (DAT_ffffb198 != 0) {
    uVar6 = FUN_00002068(DAT_ffffb5b8,&PTR_DAT_00069f98);
    fVar7 = extraout_fr0_00;
  }
  DAT_ffffb084 = fVar7;
  return uVar6;
}


