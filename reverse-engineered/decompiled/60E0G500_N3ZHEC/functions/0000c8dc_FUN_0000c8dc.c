/* ROM address: 0x0000c8dc; body bytes: 352; decompiled_with_warnings */

/* WARNING: Removing unreachable block (ram,0x0000ca3a) */

void FUN_0000c8dc(void)

{
  ushort uVar1;
  undefined4 uVar2;
  byte bVar3;
  byte bVar4;
  float fVar5;
  
  uVar2 = FUN_00003920(0x90);
  uVar1 = DAT_fffff666;
  if ((uVar1 & 0x1000) != 0) {
    FUN_0000a8a4(0xfffff658,0);
    knock_reference_adc_read();
  }
  FUN_00003934(uVar2);
  if (DAT_ffffa385 == '\x01') {
    DAT_ffffa384 = DAT_ffffa383;
  }
  bVar4 = DAT_ffffa383 + 1;
  if (1 < (byte)(DAT_ffffa383 + 1U)) {
    bVar4 = 0;
  }
  DAT_ffff9f34 = DAT_ffff9f34 & 0xbc | (&DAT_0000d90c)[bVar4];
  if (DAT_ffffa386 == '\0') {
    (&DAT_ffffa387)[bVar4] = (&DAT_0007a164)[bVar4];
  }
  else {
    (&DAT_ffffa387)[bVar4] = (&DAT_0007a16a)[bVar4];
  }
  if (((&DAT_ffffa387)[bVar4] == '\x01') || ((&DAT_ffffa387)[bVar4] != '\x02')) {
    bVar3 = 0;
  }
  else {
    bVar3 = 4;
  }
  DAT_ffff9f34 = DAT_ffff9f34 & 0xfb | bVar3;
  fVar5 = (float)(&DAT_ffffa368)[bVar4];
  if (fVar5 < 192.0) {
    if (fVar5 < 128.0) {
      if (fVar5 < 96.0) {
        if (fVar5 < 64.0) {
          DAT_ffffa380 = '\x06';
        }
        else {
          DAT_ffffa380 = '\x05';
        }
      }
      else {
        DAT_ffffa380 = '\x04';
      }
    }
    else {
      DAT_ffffa380 = '\x02';
    }
  }
  else {
    DAT_ffffa380 = '\0';
  }
  (&DAT_ffffa381)[bVar4] = DAT_ffffa380;
  if (DAT_ffffa380 != '\0') {
    if (DAT_ffffa380 == '\x02') {
      bVar4 = 8;
      goto LAB_0000ca7e;
    }
    if (DAT_ffffa380 == '\x04') {
      bVar4 = 0x10;
      goto LAB_0000ca7e;
    }
    if (DAT_ffffa380 == '\x05') {
      bVar4 = 0x18;
      goto LAB_0000ca7e;
    }
    if (DAT_ffffa380 == '\x06') {
      bVar4 = 0x20;
      goto LAB_0000ca7e;
    }
  }
  bVar4 = 0;
LAB_0000ca7e:
  DAT_ffff9f34 = DAT_ffff9f34 & 199 | bVar4;
  FUN_00007188();
  return;
}


