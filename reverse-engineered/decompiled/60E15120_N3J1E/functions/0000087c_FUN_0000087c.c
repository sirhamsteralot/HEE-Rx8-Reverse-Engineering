/* ROM address: 0x0000087c; body bytes: 48; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0000087c (48 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_0000087c(undefined1 *param_1,int param_2,undefined4 *param_3)

{
  undefined1 uVar1;
  undefined4 uVar2;
  
  if ((param_3 < &DAT_ffff6000) || ((int)&DAT_ffffdffc + 3U < (uint)((int)param_3 + param_2 + -1)))
  {
    uVar2 = 0xffffffff;
  }
  else {
    for (; param_2 != 0; param_2 = param_2 + -1) {
      uVar1 = *param_1;
      param_1 = param_1 + 1;
      *(undefined1 *)param_3 = uVar1;
      param_3 = (undefined4 *)((int)param_3 + 1);
    }
    uVar2 = 0;
  }
  return uVar2;
}


