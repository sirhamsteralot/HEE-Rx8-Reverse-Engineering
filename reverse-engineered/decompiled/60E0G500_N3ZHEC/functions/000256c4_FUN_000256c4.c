/* ROM address: 0x000256c4; body bytes: 20; decompiled */

void FUN_000256c4(byte param_1,byte *param_2,byte *param_3)

{
  *param_3 = ~(*param_2 ^ param_1) & param_1 | *param_3 & (*param_2 ^ param_1);
  *param_2 = param_1;
  return;
}


