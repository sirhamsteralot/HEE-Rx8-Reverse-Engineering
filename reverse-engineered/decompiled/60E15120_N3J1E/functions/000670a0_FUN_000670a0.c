/* ROM address: 0x000670a0; body bytes: 156; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00065990 (156 bytes). Names prefixed ref_
   are inherited hypotheses. */

uint FUN_000670a0(undefined4 param_1,char param_2)

{
  uint uVar1;
  undefined4 unaff_r11;
  int iVar2;
  undefined1 local_1c [4];
  char cStack_18;
  
  iVar2 = 0;
  local_1c[0] = 0x48;
  cStack_18 = param_2;
  uVar1 = FUN_000671c2(param_1);
  if ((uVar1 & 0xff) == 0) {
    ref_udsServiceResponse(8,&DAT_ffffd94a,param_1);
    unaff_r11 = FUN_00066718((int)DAT_ffffd94a);
    uVar1 = FUN_000671d8(unaff_r11,&DAT_ffffd94a,param_1);
    if ((uVar1 & 0xff) != 0) {
      iVar2 = 1;
    }
  }
  else {
    iVar2 = 1;
  }
  if (iVar2 == 0) {
    ref_setupForUdsResponse_(8,local_1c,1);
    DAT_ffffd948 = 1;
    uVar1 = FUN_00066c4c(unaff_r11,&DAT_ffffd94a,param_1,(int)cStack_18);
    if ((uVar1 & 0xff) != 0) {
      iVar2 = 2;
    }
  }
  if (iVar2 != 0) {
    uVar1 = FUN_000671f0(iVar2,(int)cStack_18);
  }
  return uVar1;
}


