/* ROM address: 0x000660da; body bytes: 74; decompiled */

undefined4 FUN_000660da(char param_1)

{
  undefined4 uVar1;
  char local_c;
  undefined1 uStack_b;
  undefined1 uStack_a;
  undefined1 uStack_9;
  undefined1 uStack_8;
  
  uVar1 = FUN_00066e4e(1,(int)param_1);
  uStack_b = (undefined1)((uint)uVar1 >> 0x18);
  uStack_a = (undefined1)((uint)uVar1 >> 0x10);
  uStack_9 = (undefined1)((uint)uVar1 >> 8);
  uStack_8 = (undefined1)uVar1;
  local_c = param_1;
  uVar1 = FUN_000688c8(1,&local_c,5);
  DAT_ffffd852 = DAT_ffffd852 + 5;
  return uVar1;
}


