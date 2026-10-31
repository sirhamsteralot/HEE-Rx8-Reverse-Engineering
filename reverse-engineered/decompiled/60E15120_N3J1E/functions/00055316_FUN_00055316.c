/* ROM address: 0x00055316; body bytes: 72; decompiled */

/* Unique exact-byte match to related 60E0FC00 function at 0005346a (72 bytes). Names prefixed ref_
   are inherited hypotheses. */

int FUN_00055316(void)

{
  char cVar1;
  int iVar2;
  undefined1 auStack_38 [40];
  byte local_10;
  byte bStack_f;
  
  iVar2 = 0;
  cVar1 = FUN_00061af4(auStack_38);
  if (cVar1 == '\0') {
    cVar1 = FUN_00054994(auStack_38,2,&local_10);
    if (cVar1 == '\x02') {
      iVar2 = (uint)local_10 * 0x100 + (uint)bStack_f;
    }
  }
  return iVar2;
}


