/* ROM address: 0x00065e56; body bytes: 82; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00064746 (82 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00065e56(char param_1,undefined1 param_2)

{
  undefined4 uVar1;
  char local_c;
  undefined1 uStack_b;
  undefined1 uStack_a;
  undefined1 uStack_9;
  undefined1 uStack_8;
  undefined1 uStack_7;
  
  uVar1 = FUN_000666aa(2,(int)param_1);
  uStack_a = (undefined1)((uint)uVar1 >> 0x18);
  uStack_9 = (undefined1)((uint)uVar1 >> 0x10);
  uStack_8 = (undefined1)((uint)uVar1 >> 8);
  uStack_7 = (undefined1)uVar1;
  local_c = param_1;
  uStack_b = param_2;
  uVar1 = ref_setupForUdsResponse_(2,&local_c,6);
  DAT_ffffd818 = DAT_ffffd818 + 6;
  return uVar1;
}


