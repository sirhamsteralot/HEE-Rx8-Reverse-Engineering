/* ROM address: 0x000364c4; body bytes: 266; decompiled */

int FUN_000364c4(uint param_1,uint param_2,uint param_3)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  byte bVar6;
  uint uVar5;
  uint uVar7;
  
  uVar4 = (param_1 >> 0x10) + (param_3 >> 0x10);
  bVar6 = (char)uVar4 * '\r';
  bVar1 = (char)(param_1 + param_3) * '\r';
  uVar4 = ((uVar4 & 0xffff) >> 8) * 0xd & 0xff;
  uVar2 = ((param_1 + param_3 & 0xffff) >> 8) * 0xd & 0xff;
  uVar7 = param_2 >> 0x10 ^ (uint)(bVar6 >> 1) + (uint)bVar6 * 0x80;
  uVar5 = (uVar2 >> 1) + uVar2 * 0x80 ^ param_2 >> 8;
  uVar2 = param_2 ^ (uint)bVar1 * 0x80 + (uint)(bVar1 >> 1);
  uVar4 = (uVar4 >> 1) + uVar4 * 0x80 ^ param_2 >> 0x18;
  if ((uVar2 & 1) == 0) {
    uVar3 = uVar7 & 0xff;
    uVar7 = (uVar4 & 0xff) * 0x10 + ((int)(uVar4 & 0xff) >> 4);
    uVar4 = uVar3 * 0x10 + ((int)uVar3 >> 4);
    uVar3 = uVar5;
  }
  else {
    uVar3 = (uVar2 & 0xff) * 0x10 + ((int)(uVar2 & 0xff) >> 4);
    uVar5 = uVar5 & 0xff;
    uVar2 = uVar5 * 0x10 + ((int)uVar5 >> 4);
  }
  return uVar4 * 0x1000000 + (uVar7 & 0xff) * 0x10000 + (uVar3 & 0xff) * 0x100 + (uVar2 & 0xff);
}


