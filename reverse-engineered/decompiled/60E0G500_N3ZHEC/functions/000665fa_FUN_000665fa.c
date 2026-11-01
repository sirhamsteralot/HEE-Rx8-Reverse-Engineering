/* ROM address: 0x000665fa; body bytes: 82; decompiled */

undefined4 FUN_000665fa(char param_1,undefined1 param_2)

{
  undefined4 uVar1;
  char local_c;
  undefined1 uStack_b;
  undefined1 uStack_a;
  undefined1 uStack_9;
  undefined1 uStack_8;
  undefined1 uStack_7;
  
  uVar1 = FUN_00066e4e(2,(int)param_1);
  uStack_a = (undefined1)((uint)uVar1 >> 0x18);
  uStack_9 = (undefined1)((uint)uVar1 >> 0x10);
  uStack_8 = (undefined1)((uint)uVar1 >> 8);
  uStack_7 = (undefined1)uVar1;
  local_c = param_1;
  uStack_b = param_2;
  uVar1 = FUN_000688c8(2,&local_c,6);
  DAT_ffffd854 = DAT_ffffd854 + 6;
  return uVar1;
}


