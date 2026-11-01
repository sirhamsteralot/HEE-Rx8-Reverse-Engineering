/* ROM address: 0x00023480; body bytes: 236; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x000234f4) */
/* WARNING: Removing unreachable block (ram,0x00023514) */
/* WARNING: Removing unreachable block (ram,0x00023516) */
/* WARNING: Removing unreachable block (ram,0x00023526) */
/* WARNING: Removing unreachable block (ram,0x00023528) */
/* WARNING: Heritage AFTER dead removal. Example location: r0xffffb408 : 0x00023540 */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void FUN_00023480(void)

{
  undefined *puVar1;
  uint uVar2;
  char cVar3;
  float *pfVar4;
  float fVar5;
  
  if (DAT_ffffb33c == '\x01') {
    puVar1 = &DAT_0006a9c8;
  }
  else {
    if (DAT_ffffb33d != '\x01') {
      if (DAT_ffffb33e == '\x01') {
        puVar1 = &DAT_0006aa00;
      }
      else {
        puVar1 = &DAT_0006aa1c;
      }
      fVar5 = (float)FUN_000020dc(DAT_ffffb5b8,DAT_ffffaa40,puVar1);
      goto LAB_000234d6;
    }
    puVar1 = &DAT_0006a9e4;
  }
  fVar5 = (float)FUN_000020dc(DAT_ffffb5b8,DAT_ffffaa40,puVar1);
LAB_000234d6:
  fVar5 = rx8_clamp_float(fVar5,0.0,84.0);
  DAT_ffffb45c = 0;
  cVar3 = '\f';
  uVar2 = 0xb;
  DAT_ffffb43c = DAT_ffffb408;
  pfVar4 = &DAT_ffffb43c;
  DAT_ffffb408 = fVar5;
  do {
    cVar3 = cVar3 + -1;
    pfVar4 = pfVar4 + -1;
    *pfVar4 = (&DAT_ffffb408)[uVar2 & 0xff];
    uVar2 = uVar2 + 0xff;
  } while (cVar3 != '\0');
  return;
}


