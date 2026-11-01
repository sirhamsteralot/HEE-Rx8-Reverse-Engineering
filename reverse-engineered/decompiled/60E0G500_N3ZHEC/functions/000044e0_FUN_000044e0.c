/* ROM address: 0x000044e0; body bytes: 148; decompiled */

uint FUN_000044e0(void)

{
  uint uVar1;
  uint in_r0;
  int in_r1;
  
  if (-1 < in_r1) {
    switch(in_r1) {
    case 0:
      break;
    case 7:
      in_r0 = in_r0 >> 1;
    case 6:
      in_r0 = in_r0 >> 1;
    case 5:
      in_r0 = in_r0 >> 1;
    case 4:
      in_r0 = in_r0 >> 1;
    case 3:
      in_r0 = in_r0 >> 1;
    case 2:
      in_r0 = in_r0 >> 1;
    case 1:
      in_r0 = in_r0 >> 1;
      break;
    case 0xf:
      in_r0 = in_r0 >> 1;
    case 0xe:
      in_r0 = in_r0 >> 1;
    case 0xd:
      in_r0 = in_r0 >> 1;
    case 0xc:
      in_r0 = in_r0 >> 1;
    case 0xb:
      in_r0 = in_r0 >> 1;
    case 10:
      in_r0 = in_r0 >> 1;
    case 9:
      in_r0 = in_r0 >> 1;
    case 8:
      return in_r0 >> 8;
    case 0x17:
      in_r0 = in_r0 >> 1;
    case 0x16:
      in_r0 = in_r0 >> 1;
    case 0x15:
      in_r0 = in_r0 >> 1;
    case 0x14:
      in_r0 = in_r0 >> 1;
    case 0x13:
      in_r0 = in_r0 >> 1;
    case 0x12:
      in_r0 = in_r0 >> 1;
    case 0x11:
      in_r0 = in_r0 >> 1;
    case 0x10:
      return in_r0 >> 0x10;
    case 0x1b:
      in_r0 = in_r0 >> 1;
    case 0x1a:
      in_r0 = in_r0 >> 1;
    case 0x19:
      in_r0 = in_r0 >> 1;
    case 0x18:
      return in_r0 >> 0x18;
    case 0x1c:
      uVar1 = in_r0 << 1;
      return (((uint)((in_r0 & 0x80000000) != 0) << 1 | (uint)((uVar1 & 0x80000000) != 0)) << 1 |
             (uint)((uVar1 & 0x40000000) != 0)) << 1 | (uint)((uVar1 & 0x20000000) != 0);
    case 0x1d:
      return ((uint)((in_r0 & 0x80000000) != 0) << 1 | (uint)((in_r0 << 1 & 0x80000000) != 0)) << 1
             | (uint)((in_r0 << 1 & 0x40000000) != 0);
    case 0x1e:
      return (uint)((in_r0 & 0x80000000) != 0) << 1 | (uint)((in_r0 & 0x40000000) != 0);
    case 0x1f:
      return (uint)((in_r0 & 0x80000000) != 0);
    default:
      return 0;
    }
  }
  return in_r0;
}


