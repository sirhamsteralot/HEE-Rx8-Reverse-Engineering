/* ROM address: 0x00065936; body bytes: 74; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 00064226 (74 bytes). Names prefixed ref_
   are inherited hypotheses. */

undefined4 FUN_00065936(char param_1)

{
  undefined4 uVar1;
  char local_c;
  undefined1 uStack_b;
  undefined1 uStack_a;
  undefined1 uStack_9;
  undefined1 uStack_8;
  
  uVar1 = FUN_000666aa(1,(int)param_1);
  uStack_b = (undefined1)((uint)uVar1 >> 0x18);
  uStack_a = (undefined1)((uint)uVar1 >> 0x10);
  uStack_9 = (undefined1)((uint)uVar1 >> 8);
  uStack_8 = (undefined1)uVar1;
  local_c = param_1;
  uVar1 = ref_setupForUdsResponse_(1,&local_c,5);
  DAT_ffffd816 = DAT_ffffd816 + 5;
  return uVar1;
}


