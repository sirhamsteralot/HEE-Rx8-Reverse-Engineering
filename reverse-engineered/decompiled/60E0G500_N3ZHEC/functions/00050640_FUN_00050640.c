/* ROM address: 0x00050640; body bytes: 274; decompiled */

char FUN_00050640(void)

{
  char cVar1;
  undefined4 uVar2;
  float fVar3;
  
  fVar3 = 0.0;
  uVar2 = FUN_0003eb72(0,&DAT_ffff86a4);
  DAT_ffffd088 = (float)FUN_00002068(uVar2,&DAT_0006b7a4);
  DAT_ffffd08c = (float)FUN_00002068(uVar2,&DAT_0006b7b8);
  DAT_ffffd090 = (float)FUN_00002068(uVar2,&DAT_0006b7cc);
  DAT_ffffd094 = (float)FUN_00002068(uVar2,&DAT_0006b7e0);
  DAT_ffffd098 = (float)FUN_00002068(uVar2,&DAT_0006b7f4);
  DAT_ffffd09c = (float)FUN_00002068(uVar2,&DAT_0006b808);
  DAT_ffffd0a0 = (float)FUN_00002068(uVar2,&DAT_0006b81c);
  DAT_ffffd0a4 = (float)FUN_00002068(uVar2,&DAT_0006b830);
  DAT_ffffd0a8 = (float)FUN_00002068(DAT_ffffd050,&DAT_0006b85c);
  if (DAT_ffffd201 == '\x01') {
    cVar1 = '\x01';
    DAT_ffffd054 = fVar3;
    DAT_ffffd058 = fVar3;
    DAT_ffffd05c = fVar3;
    DAT_ffffd060 = fVar3;
    DAT_ffffd064 = fVar3;
    DAT_ffffd068 = fVar3;
    DAT_ffffd06c = fVar3;
    DAT_ffffd070 = fVar3;
  }
  else {
    cVar1 = DAT_ffffd083;
    if (DAT_ffffd083 == '\x01') {
      DAT_ffffd054 = DAT_ffffd088 * DAT_ffffd0a8;
      DAT_ffffd058 = DAT_ffffd08c * DAT_ffffd0a8;
      DAT_ffffd05c = DAT_ffffd090 * DAT_ffffd0a8;
      DAT_ffffd060 = DAT_ffffd094 * DAT_ffffd0a8;
      DAT_ffffd064 = DAT_ffffd098 * DAT_ffffd0a8;
      DAT_ffffd068 = DAT_ffffd09c * DAT_ffffd0a8;
      DAT_ffffd06c = DAT_ffffd0a0 * DAT_ffffd0a8;
      DAT_ffffd070 = DAT_ffffd0a4 * DAT_ffffd0a8;
    }
  }
  return cVar1;
}


