/* ROM address: 0x00002690; body bytes: 32; decompiled */

int FUN_00002690(void)

{
  short sVar1;
  int in_r0;
  int in_r1;
  short *psVar2;
  float in_fr0;
  
  psVar2 = (short *)(in_r1 + in_r0 * 2);
  sVar1 = *psVar2;
  if (in_fr0 != 0.0) {
    sVar1 = psVar2[1];
  }
  return (int)sVar1;
}


