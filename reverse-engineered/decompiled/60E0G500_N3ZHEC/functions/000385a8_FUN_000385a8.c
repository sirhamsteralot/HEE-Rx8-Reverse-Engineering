/* ROM address: 0x000385a8; body bytes: 684; decompiled */

undefined * FUN_000385a8(void)

{
  char extraout_var;
  char cVar4;
  undefined4 uVar1;
  ushort uVar3;
  undefined *puVar2;
  undefined1 *unaff_r14;
  undefined2 *puStack_44;
  undefined2 local_34;
  undefined2 local_32;
  undefined2 local_30;
  undefined2 local_2e;
  undefined1 uStack_2c;
  char cStack_2b;
  char cStack_2a;
  char cStack_29;
  char cStack_28;
  char cStack_27;
  char cStack_26;
  char cStack_25;
  char cStack_24;
  
  if ((DAT_ffffd20a == '\x01') && (cVar4 = FUN_00056678(1), cVar4 == '\0')) {
    if (DAT_ffffc2f3 == '\0') {
      DAT_ffffc2f4 = '\0';
      DAT_ffffc245 = 0;
      DAT_ffffc2f5 = '\0';
      DAT_ffffc246 = 0;
      DAT_ffffc247 = 0;
      DAT_ffffc248 = 0;
      DAT_ffffc2f6 = '\0';
    }
    else {
      if (DAT_ffffc2f4 == '\0') {
        uVar1 = FUN_00003920(0x10);
        unaff_r14 = &uStack_2c;
        cVar4 = FUN_0000bed8();
        if (cVar4 == '\0') {
          puStack_44 = &local_34;
          local_34 = FUN_0000bdfa(0x6010000);
          local_32 = FUN_0000bdfa(0x6020000);
          local_30 = FUN_0000bdfa(0x6030000);
          local_2e = FUN_0000bdfa(0x6040000);
          cStack_2b = (char)((ushort)local_34 >> 8);
          cStack_2a = (char)local_34;
          cStack_29 = (char)((ushort)local_32 >> 8);
          cStack_28 = (char)local_32;
          cStack_27 = (char)((ushort)local_30 >> 8);
          cStack_26 = (char)local_30;
          cStack_25 = (char)((ushort)local_2e >> 8);
          cStack_24 = (char)local_2e;
          DAT_ffffc2f4 = '\x01';
        }
        FUN_00003934(uVar1);
        if (DAT_ffffc2f4 == '\x01') {
          if ((((((cStack_2b == '\0') && (cStack_2a == '\0')) && (cStack_29 == '\0')) &&
               ((cStack_28 == '\0' && (cStack_27 == '\0')))) &&
              ((cStack_26 == '\0' && ((cStack_25 == '\0' && (cStack_24 == '\0')))))) ||
             ((cStack_2b == -1 &&
              ((((cStack_2a == -1 && (cStack_29 == -1)) && (cStack_28 == -1)) &&
               (((cStack_27 == -1 && (cStack_26 == -1)) && ((cStack_25 == -1 && (cStack_24 == -1))))
               )))))) {
            DAT_ffffc245 = 0;
          }
          else {
            DAT_ffffc245 = 1;
          }
        }
      }
      if (DAT_ffffc2f5 == '\0') {
        uVar1 = FUN_00003920(0x10);
        cVar4 = FUN_0000bed8();
        if (cVar4 == '\0') {
          unaff_r14 = (undefined1 *)FUN_0000bdfa(0x60b0000);
          uVar3 = FUN_0000bdfa(0x60c0000);
          puStack_44 = (undefined2 *)((uint)uVar3 << 0x10);
          DAT_ffffc2f5 = '\x01';
        }
        FUN_00003934(uVar1);
        if (DAT_ffffc2f5 == '\x01') {
          if (((puStack_44._0_2_ == -1) &&
              ((undefined *)((uint)unaff_r14 & 0xffff) == (undefined *)0xffff)) ||
             (((uint)unaff_r14 & 0xffff) == 0)) {
            DAT_ffffc246 = 0;
          }
          else {
            DAT_ffffc246 = 1;
          }
        }
      }
      if (DAT_ffffc2f6 == '\0') {
        uVar1 = FUN_00003920(0x10);
        cVar4 = FUN_0000bed8();
        if (cVar4 == '\0') {
          FUN_0000bdfa(0x6050000);
          DAT_ffffc2f6 = '\x01';
          puStack_44._0_1_ = extraout_var;
        }
        FUN_00003934(uVar1);
        if (DAT_ffffc2f6 == '\x01') {
          if (puStack_44._0_1_ == '\0') {
            DAT_ffffc247 = 0;
            DAT_ffffc248 = 0;
          }
          else if (puStack_44._0_1_ == '\x01') {
            DAT_ffffc247 = 1;
            DAT_ffffc248 = 0;
          }
          else {
            DAT_ffffc247 = 1;
            DAT_ffffc248 = 1;
          }
        }
      }
    }
  }
  if (DAT_ffffd20a != '\x01') {
    puVar2 = &DAT_ffffc2f3;
  }
  else {
    puVar2 = &UNK_00000001;
  }
  DAT_ffffc2f3 = DAT_ffffd20a == '\x01';
  return puVar2;
}


