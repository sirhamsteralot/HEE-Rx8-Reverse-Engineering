/* ROM address: 0x00067160; body bytes: 98; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00065a50 (98 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00067160(char param_1,char *param_2,short param_3)

{
  undefined4 uVar1;
  
  if (param_1 == '\0') {
    ref_setupForUdsResponse_(8,param_2,(int)param_3);
    DAT_ffffd948 = DAT_ffffd948 + param_3;
    uVar1 = FUN_00068d56();
  }
  else {
    if (param_1 == '\x02') {
      uVar1 = 2;
    }
    else {
      uVar1 = 1;
    }
    uVar1 = FUN_0006672a(8,(int)*param_2,uVar1);
  }
  return uVar1;
}


