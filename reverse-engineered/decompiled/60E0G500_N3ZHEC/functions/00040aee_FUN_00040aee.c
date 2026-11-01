/* ROM address: 0x00040aee; body bytes: 4884; decompiled */

void FUN_00040aee(void)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  char cVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  short sVar11;
  ushort uVar12;
  ushort uVar13;
  ushort uVar14;
  ushort uVar15;
  ushort uVar16;
  ushort uVar17;
  ushort uVar18;
  ushort uVar19;
  ushort uVar20;
  ushort uVar21;
  ushort uVar22;
  ushort uVar23;
  ushort uVar24;
  ushort uVar25;
  ushort uVar26;
  ushort uVar27;
  char cVar28;
  char cVar29;
  char cVar30;
  char cVar31;
  char cVar32;
  char cVar33;
  char cVar34;
  char cVar35;
  char cVar36;
  float fVar37;
  char cStack_59;
  char cStack_58;
  char cStack_53;
  char cStack_52;
  char cStack_51;
  char cStack_50;
  ushort uStack_40;
  
  cVar34 = DAT_ffffd201;
  sVar11 = DAT_ffffc820;
  fVar10 = DAT_ffffc784;
  fVar9 = DAT_ffffc780;
  fVar8 = DAT_ffffc77c;
  fVar7 = DAT_ffffc778;
  cVar6 = DAT_ffffc770;
  cVar33 = DAT_ffffae99;
  cStack_50 = DAT_ffffc852;
  cStack_51 = DAT_ffffc853;
  cStack_52 = DAT_ffffc854;
  cStack_53 = DAT_ffffc855;
  bVar5 = false;
  DAT_ffffc96c = FUN_00002460((int)(short)DAT_ffffc96c,1);
  if (DAT_ffffc96c < 2) {
    DAT_ffffc978 = '\0';
  }
  else {
    DAT_ffffc96c = 0;
    DAT_ffffc978 = '\x01';
    DAT_ffffc822 = FUN_0000213c(DAT_ffffc12c,DAT_ffffb5b8,&DAT_0006ba0c);
  }
  if (cVar34 == '\x01') {
    DAT_ffffc826 = 0;
    DAT_ffffc824 = 0xffff;
    DAT_ffffc828 = 0;
    DAT_ffffc794 = 0.0;
    DAT_ffffc798 = 0.0;
    DAT_ffffc7a0 = 0.0;
    DAT_ffffc7a4 = 0.0;
    DAT_ffffc7ac = 0.0;
    DAT_ffffc7b0 = 0.0;
    DAT_ffffc7b8 = 0.0;
    DAT_ffffc7bc = 0.0;
    DAT_ffffc7c4 = 0.0;
    DAT_ffffc7c8 = 0.0;
    DAT_ffffc7d0 = 0.0;
    DAT_ffffc7d4 = 0.0;
    DAT_ffffc7dc = 0.0;
    DAT_ffffc7e0 = 0.0;
    DAT_ffffc7e8 = 0.0;
    DAT_ffffc7ec = 0.0;
    DAT_ffffc84d = '\0';
    DAT_ffffc774 = '\0';
    DAT_ffffc771 = 0;
    DAT_ffffc760 = 0.0;
    DAT_ffffc764 = 0.0;
    DAT_ffffc7f0 = 0.0;
    DAT_ffffc7f4 = 0.0;
    DAT_ffffc85e = '\0';
    DAT_ffffc85f = '\0';
    DAT_ffffc860 = '\0';
    DAT_ffffc861 = '\0';
    DAT_ffffc974 = 0;
    DAT_ffffc97a = '\0';
    DAT_ffffc977 = '\0';
    DAT_ffffc976 = '\0';
  }
  else {
    cStack_58 = DAT_ffffc774;
    if (DAT_ffffc978 == '\x01') {
      if (((cVar6 == '\x01') && (sVar11 == 0)) && (DAT_ffffc828 != 0x32)) {
        DAT_ffffc774 = '\x01';
        DAT_ffffc771 = 0;
      }
      else {
        DAT_ffffc774 = '\0';
      }
      if ((((DAT_ffffc774 == '\x01') && (cVar33 == '\x01')) &&
          ((DAT_ffffc976 == '\x01' || (DAT_ffffc977 == '\x01')))) && (DAT_ffffc828 < 0x32)) {
        DAT_ffffc828 = FUN_00002460((int)(short)DAT_ffffc828,1);
      }
      DAT_ffffc977 = '\0';
      DAT_ffffc976 = '\0';
    }
    if (((DAT_ffffc979 == '\x01') && (cVar6 == '\0')) && (DAT_ffffc824 != 0xffff)) {
      DAT_ffffc826 = DAT_ffffc822;
    }
    else if (DAT_ffffc826 != 0) {
      DAT_ffffc826 = DAT_ffffc826 - 1;
    }
    if (((cVar6 == '\x01') && (sVar11 == 0)) && (DAT_ffffc828 != 0x32)) {
      if (DAT_ffffc96e == 1) {
        DAT_ffffc824 = DAT_ffffc822;
      }
      else if (DAT_ffffc824 != 0) {
        DAT_ffffc824 = DAT_ffffc824 - 1;
      }
    }
    else if ((DAT_ffffc824 == 0xffff) || (DAT_ffffc824 == 0)) {
      DAT_ffffc824 = 0xffff;
    }
    else {
      DAT_ffffc824 = DAT_ffffc824 - 1;
    }
    cStack_59 = DAT_ffffc84d;
    if ((DAT_ffffc824 == 0) || (DAT_ffffc826 != 0)) {
      DAT_ffffc84d = '\x01';
    }
    else {
      DAT_ffffc84d = '\0';
    }
  }
  if (DAT_ffffc978 == '\x01') {
    for (uStack_40 = 10; uStack_40 != 0; uStack_40 = uStack_40 - 1) {
      (&DAT_ffffc864)[uStack_40] = (&DAT_ffffc864)[(ushort)(uStack_40 - 1)];
    }
    DAT_ffffc864 = fVar9;
    for (uStack_40 = 10; cVar32 = DAT_ffffc855, cVar31 = DAT_ffffc854, cVar30 = DAT_ffffc853,
        cVar29 = DAT_ffffc852, cVar28 = DAT_ffffc851, cVar36 = DAT_ffffc850, cVar35 = DAT_ffffc84f,
        cVar33 = DAT_ffffc84e, uVar27 = DAT_ffffc848, uVar26 = DAT_ffffc846, uVar25 = DAT_ffffc844,
        uVar24 = DAT_ffffc842, uVar23 = DAT_ffffc840, uVar22 = DAT_ffffc83e, uVar21 = DAT_ffffc83c,
        uVar20 = DAT_ffffc83a, uVar19 = DAT_ffffc838, uVar18 = DAT_ffffc836, uVar17 = DAT_ffffc834,
        uVar16 = DAT_ffffc832, uVar15 = DAT_ffffc830, uVar14 = DAT_ffffc82e, uVar13 = DAT_ffffc82c,
        uVar12 = DAT_ffffc82a, uStack_40 != 0; uStack_40 = uStack_40 - 1) {
      (&DAT_ffffc8e0)[uStack_40] = (&DAT_ffffc8e0)[(ushort)(uStack_40 - 1)];
    }
    DAT_ffffc8e0 = fVar10;
    DAT_ffffc788 = fVar9 - DAT_ffffc88c;
    DAT_ffffc78c = fVar10 - DAT_ffffc908;
    if (DAT_ffffc788 < 0.0) {
      if (0.0 <= DAT_ffffc788) {
        DAT_ffffc84e = '\0';
        DAT_ffffc84f = '\0';
      }
      else {
        DAT_ffffc84f = '\x01';
        DAT_ffffc84e = '\0';
      }
    }
    else {
      DAT_ffffc84e = '\x01';
      DAT_ffffc84f = '\0';
    }
    if (DAT_ffffc78c < 0.0) {
      if (0.0 <= DAT_ffffc78c) {
        DAT_ffffc850 = '\0';
        DAT_ffffc851 = '\0';
      }
      else {
        DAT_ffffc851 = '\x01';
        DAT_ffffc850 = '\0';
      }
    }
    else {
      DAT_ffffc850 = '\x01';
      DAT_ffffc851 = '\0';
    }
    if ((cVar33 == '\x01') && (DAT_ffffc84e == '\0')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if ((cVar35 == '\x01') && (DAT_ffffc84f == '\0')) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    if ((cVar36 == '\x01') && (DAT_ffffc850 == '\0')) {
      bVar3 = true;
    }
    else {
      bVar3 = false;
    }
    if ((cVar28 == '\x01') && (DAT_ffffc851 == '\0')) {
      bVar4 = true;
    }
    else {
      bVar4 = false;
    }
    if (DAT_ffffc82a < 2) {
      DAT_ffffc82a = 0;
    }
    else {
      DAT_ffffc82a = DAT_ffffc82a - 2;
    }
    if (DAT_ffffc82c < 2) {
      DAT_ffffc82c = 0;
    }
    else {
      DAT_ffffc82c = DAT_ffffc82c - 2;
    }
    if (DAT_ffffc82e < 2) {
      DAT_ffffc82e = 0;
    }
    else {
      DAT_ffffc82e = DAT_ffffc82e - 2;
    }
    if (DAT_ffffc830 < 2) {
      DAT_ffffc830 = 0;
    }
    else {
      DAT_ffffc830 = DAT_ffffc830 - 2;
    }
    if ((uVar12 != 0) && (DAT_ffffc82a == 0)) {
      cStack_50 = '\x01';
    }
    if ((uVar13 != 0) && (DAT_ffffc82c == 0)) {
      cStack_50 = '\x01';
    }
    if ((uVar14 != 0) && (DAT_ffffc82e == 0)) {
      cStack_50 = '\0';
      if (DAT_ffffc82a != 0) {
        DAT_ffffc84e = '\0';
        DAT_ffffc82a = 0;
        DAT_ffffc85e = '\x01';
      }
      if ((uVar13 != 0) && (DAT_ffffc82c == 0)) {
        cStack_50 = DAT_ffffc84e;
      }
    }
    if ((uVar15 != 0) && (DAT_ffffc830 == 0)) {
      cStack_50 = '\0';
      if (DAT_ffffc82c != 0) {
        DAT_ffffc84e = '\0';
        DAT_ffffc82c = 0;
        DAT_ffffc85e = '\x01';
      }
      if ((uVar12 != 0) && (DAT_ffffc82a == 0)) {
        cStack_50 = DAT_ffffc84e;
      }
    }
    DAT_ffffc852 = cStack_50;
    if ((cVar33 == '\0') && (DAT_ffffc84e == '\x01')) {
      if (DAT_ffffc97b == '\0') {
        if ((DAT_ffffc82e == 0) && (DAT_ffffc82a == 0)) {
          DAT_ffffc82a = DAT_ffffc822;
          DAT_ffffc97b = '\x01';
        }
      }
      else if ((DAT_ffffc830 == 0) && (DAT_ffffc82c == 0)) {
        DAT_ffffc82c = DAT_ffffc822;
        DAT_ffffc97b = '\0';
      }
    }
    if (bVar1) {
      if (DAT_ffffc97b == '\x01') {
        if (DAT_ffffc82e == 0) {
          DAT_ffffc82e = DAT_ffffc822;
        }
      }
      else if (DAT_ffffc830 == 0) {
        DAT_ffffc830 = DAT_ffffc822;
      }
    }
    if (DAT_ffffc832 < 2) {
      DAT_ffffc832 = 0;
    }
    else {
      DAT_ffffc832 = DAT_ffffc832 - 2;
    }
    if (DAT_ffffc834 < 2) {
      DAT_ffffc834 = 0;
    }
    else {
      DAT_ffffc834 = DAT_ffffc834 - 2;
    }
    if (DAT_ffffc836 < 2) {
      DAT_ffffc836 = 0;
    }
    else {
      DAT_ffffc836 = DAT_ffffc836 - 2;
    }
    if (DAT_ffffc838 < 2) {
      DAT_ffffc838 = 0;
    }
    else {
      DAT_ffffc838 = DAT_ffffc838 - 2;
    }
    if ((uVar16 != 0) && (DAT_ffffc832 == 0)) {
      cStack_51 = '\x01';
    }
    if ((uVar17 != 0) && (DAT_ffffc834 == 0)) {
      cStack_51 = '\x01';
    }
    if ((uVar18 != 0) && (DAT_ffffc836 == 0)) {
      cStack_51 = '\0';
      if (DAT_ffffc832 != 0) {
        DAT_ffffc84f = '\0';
        DAT_ffffc832 = 0;
        DAT_ffffc85f = '\x01';
      }
      if ((uVar17 != 0) && (DAT_ffffc834 == 0)) {
        cStack_51 = DAT_ffffc84f;
      }
    }
    if ((uVar19 != 0) && (DAT_ffffc838 == 0)) {
      cStack_51 = '\0';
      if (DAT_ffffc834 != 0) {
        DAT_ffffc84f = '\0';
        DAT_ffffc834 = 0;
        DAT_ffffc85f = '\x01';
      }
      if ((uVar16 != 0) && (DAT_ffffc832 == 0)) {
        cStack_51 = DAT_ffffc84f;
      }
    }
    DAT_ffffc853 = cStack_51;
    if ((cVar35 == '\0') && (DAT_ffffc84f == '\x01')) {
      if (DAT_ffffc97c == '\0') {
        if ((DAT_ffffc836 == 0) && (DAT_ffffc832 == 0)) {
          DAT_ffffc832 = DAT_ffffc822;
          DAT_ffffc97c = '\x01';
        }
      }
      else if ((DAT_ffffc838 == 0) && (DAT_ffffc834 == 0)) {
        DAT_ffffc834 = DAT_ffffc822;
        DAT_ffffc97c = '\0';
      }
    }
    if (bVar2) {
      if (DAT_ffffc97c == '\x01') {
        if (DAT_ffffc836 == 0) {
          DAT_ffffc836 = DAT_ffffc822;
        }
      }
      else if (DAT_ffffc838 == 0) {
        DAT_ffffc838 = DAT_ffffc822;
      }
    }
    if (DAT_ffffc83a < 2) {
      DAT_ffffc83a = 0;
    }
    else {
      DAT_ffffc83a = DAT_ffffc83a - 2;
    }
    if (DAT_ffffc83c < 2) {
      DAT_ffffc83c = 0;
    }
    else {
      DAT_ffffc83c = DAT_ffffc83c - 2;
    }
    if (DAT_ffffc83e < 2) {
      DAT_ffffc83e = 0;
    }
    else {
      DAT_ffffc83e = DAT_ffffc83e - 2;
    }
    if (DAT_ffffc840 < 2) {
      DAT_ffffc840 = 0;
    }
    else {
      DAT_ffffc840 = DAT_ffffc840 - 2;
    }
    if ((uVar20 != 0) && (DAT_ffffc83a == 0)) {
      cStack_52 = '\x01';
    }
    if ((uVar21 != 0) && (DAT_ffffc83c == 0)) {
      cStack_52 = '\x01';
    }
    if ((uVar22 != 0) && (DAT_ffffc83e == 0)) {
      cStack_52 = '\0';
      if (DAT_ffffc83a != 0) {
        DAT_ffffc850 = '\0';
        DAT_ffffc83a = 0;
        DAT_ffffc860 = '\x01';
      }
      if ((uVar21 != 0) && (DAT_ffffc83c == 0)) {
        cStack_52 = DAT_ffffc850;
      }
    }
    if ((uVar23 != 0) && (DAT_ffffc840 == 0)) {
      cStack_52 = '\0';
      if (DAT_ffffc83c != 0) {
        DAT_ffffc850 = '\0';
        DAT_ffffc83c = 0;
        DAT_ffffc860 = '\x01';
      }
      if ((uVar20 != 0) && (DAT_ffffc83a == 0)) {
        cStack_52 = DAT_ffffc850;
      }
    }
    DAT_ffffc854 = cStack_52;
    if ((cVar36 == '\0') && (DAT_ffffc850 == '\x01')) {
      if (DAT_ffffc97d == '\0') {
        if ((DAT_ffffc83e == 0) && (DAT_ffffc83a == 0)) {
          DAT_ffffc83a = DAT_ffffc822;
          DAT_ffffc97d = '\x01';
        }
      }
      else if ((DAT_ffffc840 == 0) && (DAT_ffffc83c == 0)) {
        DAT_ffffc83c = DAT_ffffc822;
        DAT_ffffc97d = '\0';
      }
    }
    if (bVar3) {
      if (DAT_ffffc97d == '\x01') {
        if (DAT_ffffc83e == 0) {
          DAT_ffffc83e = DAT_ffffc822;
        }
      }
      else if (DAT_ffffc840 == 0) {
        DAT_ffffc840 = DAT_ffffc822;
      }
    }
    if (DAT_ffffc842 < 2) {
      DAT_ffffc842 = 0;
    }
    else {
      DAT_ffffc842 = DAT_ffffc842 - 2;
    }
    if (DAT_ffffc844 < 2) {
      DAT_ffffc844 = 0;
    }
    else {
      DAT_ffffc844 = DAT_ffffc844 - 2;
    }
    if (DAT_ffffc846 < 2) {
      DAT_ffffc846 = 0;
    }
    else {
      DAT_ffffc846 = DAT_ffffc846 - 2;
    }
    if (DAT_ffffc848 < 2) {
      DAT_ffffc848 = 0;
    }
    else {
      DAT_ffffc848 = DAT_ffffc848 - 2;
    }
    if ((uVar24 != 0) && (DAT_ffffc842 == 0)) {
      cStack_53 = '\x01';
    }
    if ((uVar25 != 0) && (DAT_ffffc844 == 0)) {
      cStack_53 = '\x01';
    }
    if ((uVar26 != 0) && (DAT_ffffc846 == 0)) {
      cStack_53 = '\0';
      if (DAT_ffffc842 != 0) {
        DAT_ffffc851 = '\0';
        DAT_ffffc842 = 0;
        DAT_ffffc861 = '\x01';
      }
      if ((uVar25 != 0) && (DAT_ffffc844 == 0)) {
        cStack_53 = DAT_ffffc851;
      }
    }
    if ((uVar27 != 0) && (DAT_ffffc848 == 0)) {
      cStack_53 = '\0';
      if (DAT_ffffc844 != 0) {
        DAT_ffffc851 = '\0';
        DAT_ffffc844 = 0;
        DAT_ffffc861 = '\x01';
      }
      if ((uVar24 != 0) && (DAT_ffffc842 == 0)) {
        cStack_53 = DAT_ffffc851;
      }
    }
    DAT_ffffc855 = cStack_53;
    if ((cVar28 == '\0') && (DAT_ffffc851 == '\x01')) {
      if (DAT_ffffc97e == '\0') {
        if ((DAT_ffffc846 == 0) && (DAT_ffffc842 == 0)) {
          DAT_ffffc842 = DAT_ffffc822;
          DAT_ffffc97e = '\x01';
        }
      }
      else if ((DAT_ffffc848 == 0) && (DAT_ffffc844 == 0)) {
        DAT_ffffc844 = DAT_ffffc822;
        DAT_ffffc97e = '\0';
      }
    }
    if (bVar4) {
      if (DAT_ffffc97e == '\x01') {
        if (DAT_ffffc846 == 0) {
          DAT_ffffc846 = DAT_ffffc822;
        }
      }
      else if (DAT_ffffc848 == 0) {
        DAT_ffffc848 = DAT_ffffc822;
      }
    }
    if (cVar34 == '\0') {
      if (DAT_ffffc85e == '\x01') {
        DAT_ffffc794 = 0.0;
        DAT_ffffc7c4 = 0.0;
        DAT_ffffc85e = '\0';
      }
      else {
        if ((DAT_ffffc774 == '\x01') && (DAT_ffffc84e == '\x01')) {
          DAT_ffffc790 = fVar9 - DAT_ffffc964;
          fVar37 = rx8_max_float(0.0,DAT_ffffc790);
          DAT_ffffc794 = DAT_ffffc794 + fVar37;
        }
        else if (((cVar33 == '\x01') && (DAT_ffffc84e == '\0')) ||
                ((cStack_58 == '\x01' && (DAT_ffffc774 == '\0')))) {
          DAT_ffffc798 = DAT_ffffc794 + DAT_ffffc798;
          DAT_ffffc794 = 0.0;
        }
        if ((DAT_ffffc84d == '\x01') && (DAT_ffffc852 == '\x01')) {
          DAT_ffffc7c0 = fVar7 - DAT_ffffc95c;
          fVar37 = rx8_min_float(0.0,DAT_ffffc7c0);
          DAT_ffffc7c4 = DAT_ffffc7c4 - fVar37;
        }
        else if (((cStack_59 == '\x01') && (DAT_ffffc84d == '\0')) ||
                ((cVar29 == '\x01' && (DAT_ffffc852 == '\0')))) {
          DAT_ffffc7c8 = DAT_ffffc7c4 + DAT_ffffc7c8;
          DAT_ffffc7c4 = 0.0;
        }
      }
      if (DAT_ffffc85f == '\x01') {
        DAT_ffffc7a0 = 0.0;
        DAT_ffffc7d0 = 0.0;
        DAT_ffffc85f = '\0';
      }
      else {
        if ((DAT_ffffc774 == '\x01') && (DAT_ffffc84f == '\x01')) {
          DAT_ffffc79c = fVar9 - DAT_ffffc964;
          fVar37 = rx8_min_float(0.0,DAT_ffffc79c);
          DAT_ffffc7a0 = DAT_ffffc7a0 - fVar37;
        }
        else if (((cVar35 == '\x01') && (DAT_ffffc84f == '\0')) ||
                ((cStack_58 == '\x01' && (DAT_ffffc774 == '\0')))) {
          DAT_ffffc7a4 = DAT_ffffc7a0 + DAT_ffffc7a4;
          DAT_ffffc7a0 = 0.0;
        }
        if ((DAT_ffffc84d == '\x01') && (DAT_ffffc853 == '\x01')) {
          DAT_ffffc7cc = fVar7 - DAT_ffffc95c;
          fVar37 = rx8_max_float(0.0,DAT_ffffc7cc);
          DAT_ffffc7d0 = DAT_ffffc7d0 + fVar37;
        }
        else if (((cStack_59 == '\x01') && (DAT_ffffc84d == '\0')) ||
                ((cVar30 == '\x01' && (DAT_ffffc853 == '\0')))) {
          DAT_ffffc7d4 = DAT_ffffc7d0 + DAT_ffffc7d4;
          DAT_ffffc7d0 = 0.0;
        }
      }
      if (DAT_ffffc860 == '\x01') {
        DAT_ffffc7ac = 0.0;
        DAT_ffffc7dc = 0.0;
        DAT_ffffc860 = '\0';
      }
      else {
        if ((DAT_ffffc774 == '\x01') && (DAT_ffffc850 == '\x01')) {
          DAT_ffffc7a8 = fVar10 - DAT_ffffc968;
          fVar37 = rx8_max_float(0.0,DAT_ffffc7a8);
          DAT_ffffc7ac = DAT_ffffc7ac + fVar37;
        }
        else if (((cVar36 == '\x01') && (DAT_ffffc850 == '\0')) ||
                ((cStack_58 == '\x01' && (DAT_ffffc774 == '\0')))) {
          DAT_ffffc7b0 = DAT_ffffc7ac + DAT_ffffc7b0;
          DAT_ffffc7ac = 0.0;
        }
        if ((DAT_ffffc84d == '\x01') && (DAT_ffffc854 == '\x01')) {
          DAT_ffffc7d8 = fVar8 - DAT_ffffc960;
          fVar37 = rx8_min_float(0.0,DAT_ffffc7d8);
          DAT_ffffc7dc = DAT_ffffc7dc - fVar37;
        }
        else if (((cStack_59 == '\x01') && (DAT_ffffc84d == '\0')) ||
                ((cVar31 == '\x01' && (DAT_ffffc854 == '\0')))) {
          DAT_ffffc7e0 = DAT_ffffc7dc + DAT_ffffc7e0;
          DAT_ffffc7dc = 0.0;
        }
      }
      if (DAT_ffffc861 == '\x01') {
        DAT_ffffc7b8 = 0.0;
        DAT_ffffc7e8 = 0.0;
        DAT_ffffc861 = '\0';
      }
      else {
        if ((DAT_ffffc774 == '\x01') && (DAT_ffffc851 == '\x01')) {
          DAT_ffffc7b4 = fVar10 - DAT_ffffc968;
          fVar37 = rx8_min_float(0.0,DAT_ffffc7b4);
          DAT_ffffc7b8 = DAT_ffffc7b8 - fVar37;
        }
        else if (((cVar28 == '\x01') && (DAT_ffffc851 == '\0')) ||
                ((cStack_58 == '\x01' && (DAT_ffffc774 == '\0')))) {
          DAT_ffffc7bc = DAT_ffffc7b8 + DAT_ffffc7bc;
          DAT_ffffc7b8 = 0.0;
        }
        if ((DAT_ffffc84d == '\x01') && (DAT_ffffc855 == '\x01')) {
          DAT_ffffc7e4 = fVar8 - DAT_ffffc960;
          fVar37 = rx8_max_float(0.0,DAT_ffffc7e4);
          DAT_ffffc7e8 = DAT_ffffc7e8 + fVar37;
        }
        else if (((cStack_59 == '\x01') && (DAT_ffffc84d == '\0')) ||
                ((cVar32 == '\x01' && (DAT_ffffc855 == '\0')))) {
          DAT_ffffc7ec = DAT_ffffc7e8 + DAT_ffffc7ec;
          DAT_ffffc7e8 = 0.0;
        }
      }
      cVar33 = DAT_ffffc97a;
      uVar12 = DAT_ffffc974;
      if (((cVar6 == '\x01') && (sVar11 == 0)) && (DAT_ffffc828 == 0x32)) {
        DAT_ffffc97a = '\x01';
        if (cVar33 == '\0') {
          bVar5 = true;
        }
      }
      else {
        DAT_ffffc97a = '\0';
      }
      if ((bVar5) && (DAT_ffffc974 == 0)) {
        DAT_ffffc974 = DAT_ffffc822;
      }
      else if (DAT_ffffc974 < 2) {
        DAT_ffffc974 = 0;
      }
      else {
        DAT_ffffc974 = DAT_ffffc974 - 2;
      }
      if ((uVar12 == 0) || (DAT_ffffc974 != 0)) {
        DAT_ffffc771 = 0;
      }
      else {
        DAT_ffffc771 = 1;
        cVar33 = FUN_00002440(DAT_ffffc798,0,0x3727c5ac);
        cVar34 = FUN_00002440(DAT_ffffc7a4,0,0x3727c5ac);
        cVar35 = FUN_00002440(DAT_ffffc7b0,0,0x3727c5ac);
        cVar36 = FUN_00002440(DAT_ffffc7bc,0,0x3727c5ac);
        if (cVar33 == '\0') {
          DAT_ffffc760 = 0.0;
        }
        else {
          DAT_ffffc760 = DAT_ffffc7c8 / DAT_ffffc798;
        }
        if (cVar34 == '\0') {
          DAT_ffffc764 = 0.0;
        }
        else {
          DAT_ffffc764 = DAT_ffffc7d4 / DAT_ffffc7a4;
        }
        if (cVar35 == '\0') {
          DAT_ffffc7f0 = 0.0;
        }
        else {
          DAT_ffffc7f0 = DAT_ffffc7e0 / DAT_ffffc7b0;
        }
        if (cVar36 == '\0') {
          DAT_ffffc7f4 = 0.0;
        }
        else {
          DAT_ffffc7f4 = DAT_ffffc7ec / DAT_ffffc7bc;
        }
      }
    }
    DAT_ffffc964 = fVar9;
    DAT_ffffc968 = fVar10;
    DAT_ffffc95c = fVar7;
    DAT_ffffc960 = fVar8;
  }
  DAT_ffffc96e = sVar11;
  DAT_ffffc979 = cVar6;
  return;
}


