/* ROM address: 0x0000c116; body bytes: 54; decompiled */

void reset_knock_state_on_mode_change(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00003920(0x10);
  if (DAT_ffffa38c != param_1) {
    DAT_ffffa384 = 0xff;
    DAT_ffffa385 = 0;
    DAT_ffffa324 = 0;
    DAT_ffffa38c = param_1;
  }
  FUN_00003934(uVar1);
  return;
}


