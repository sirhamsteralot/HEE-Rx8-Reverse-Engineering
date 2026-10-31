/* ROM address: 0x0005b33a; body bytes: 170; decompiled */

int FUN_0005b33a(char *param_1)

{
  char cVar1;
  uint uVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  char local_2c [8];
  char local_24;
  byte bStack_23;
  
  sh_copy_bytes_forward_r0_r1_r2(&DAT_0005edbc);
  iVar4 = 0;
  while (local_24 != -1) {
    uVar5 = 2;
    local_2c[0] = '\0';
    local_2c[1] = local_24;
    for (bVar3 = 0; bVar3 < bStack_23; bVar3 = bVar3 + 1) {
      cVar1 = *param_1;
      param_1 = param_1 + 1;
      uVar2 = uVar5 & 0xff;
      uVar5 = uVar5 + 1;
      local_2c[uVar2] = cVar1;
    }
    if (local_24 != '\x02') {
      ref_setupForUdsResponse_(0x12,local_2c,uVar5 & 0xff);
      iVar4 = iVar4 + (short)(uVar5 & 0xff);
    }
    sh_copy_bytes_forward_r0_r1_r2();
  }
  return iVar4;
}


