/* ROM address: 0x000536e8; body bytes: 174; decompiled */

void FUN_000536e8(void)

{
  char cVar1;
  float fVar2;
  float fVar3;
  
  fVar3 = DAT_ffffcfcc;
  fVar2 = (float)FUN_0003eb72(0,&DAT_ffff86a4);
  fVar3 = fVar3 - fVar2;
  cVar1 = FUN_00011f34();
  if (DAT_ffffd201 == '\x01') {
    DAT_ffffd182 = 0;
  }
  else if ((((float)0x41366666 < fVar3) && (DAT_ffffd194 == '\0')) && (cVar1 == '\x01')) {
    DAT_ffffd182 = 1;
  }
  if (((DAT_ffffd0e8 == '\x01') || (DAT_ffffd0e9 == '\x01')) || (DAT_ffffd201 == '\x01')) {
    FUN_0003ebc0(&DAT_ffff870c,0);
  }
  else if ((((float)0x41366666 < fVar3) && (DAT_ffffd194 == '\0')) && (cVar1 == '\x01')) {
    FUN_0003ebc0(&DAT_ffff870c,1);
  }
  DAT_ffffd194 = cVar1;
  FUN_000504c4();
  return;
}


