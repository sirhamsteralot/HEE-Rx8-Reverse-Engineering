/* ROM address: 0x00003bf4; body bytes: 54; decompiled */

void FUN_00003bf4(int param_1,undefined4 param_2,char *param_3)

{
  undefined1 *puVar1;
  undefined1 local_44 [16];
  undefined1 local_34 [4];
  
  puVar1 = local_34;
  if (*param_3 == '\x04') {
    puVar1 = local_44;
  }
  **(undefined1 **)(param_3 + 4) = 4;
  *(undefined1 **)(param_1 + 0xc) = puVar1;
  FUN_00003c68();
  return;
}


