/* ROM address: 0x00009dfc; body bytes: 42; decompiled */

void FUN_00009dfc(char param_1,byte param_2,undefined1 *param_3,int param_4)

{
  undefined1 uVar1;
  byte bVar2;
  undefined1 *puVar3;
  
  bVar2 = param_1 + param_2;
  puVar3 = (undefined1 *)(param_4 + (uint)param_2);
  for (; param_2 < bVar2; param_2 = param_2 + 1) {
    uVar1 = *puVar3;
    puVar3 = puVar3 + 1;
    *param_3 = uVar1;
    param_3 = param_3 + 1;
  }
  return;
}


