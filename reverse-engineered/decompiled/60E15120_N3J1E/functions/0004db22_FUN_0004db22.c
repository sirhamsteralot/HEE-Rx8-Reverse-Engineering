/* [ADDITIONAL SOURCE REVIEW]
 * cruise_plausibility_stage [high]: Stages plausibility cascade 0xffffcf35-38 from latches 0xffffcf39/3a, 3b/3c, 3d/3e, 3f/40 gated on 0xffffbfa0 < 300.0; cf35-38 have no readers outside 0x4db22 (pool scan). Called from batch 0x2e692 (jsr 0x2e6da, pool 0x2e7e8).
 */
/* ROM address: 0x0004db22; body bytes: 324; decompiled */

undefined4 * cruise_plausibility_stage(void)

{
  undefined4 *puVar1;
  
  puVar1 = &DAT_0007d0ac;
  if (((DAT_ffffcf39 == '\0') && (puVar1 = (undefined4 *)&DAT_ffffcf3a, DAT_ffffcf3a == '\0')) ||
     (300.0 <= DAT_ffffbfa0)) {
    DAT_ffffcf35 = '\0';
  }
  else if (DAT_ffffbfa0 < 300.0) {
    DAT_ffffcf35 = '\x01';
  }
  if ((((DAT_ffffcf3b == '\0') &&
       (puVar1 = (undefined4 *)(int)DAT_ffffcf3c, puVar1 == (undefined4 *)0x0)) &&
      (puVar1 = (undefined4 *)&DAT_ffffcf35, DAT_ffffcf35 == '\0')) || (300.0 <= DAT_ffffbfa0)) {
    DAT_ffffcf36 = '\0';
  }
  else if (DAT_ffffbfa0 < 300.0) {
    DAT_ffffcf36 = '\x01';
  }
  if ((((DAT_ffffcf3d == '\0') &&
       (puVar1 = (undefined4 *)(int)DAT_ffffcf3e, puVar1 == (undefined4 *)0x0)) &&
      ((puVar1 = (undefined4 *)&DAT_ffffcf36, DAT_ffffcf36 == '\0' && (DAT_ffffcf35 == '\0')))) ||
     (300.0 <= DAT_ffffbfa0)) {
    DAT_ffffcf37 = '\0';
  }
  else if (DAT_ffffbfa0 < 300.0) {
    DAT_ffffcf37 = '\x01';
  }
  if (((((DAT_ffffcf3f == '\0') &&
        (puVar1 = (undefined4 *)(int)DAT_ffffcf40, puVar1 == (undefined4 *)0x0)) &&
       (puVar1 = (undefined4 *)&DAT_ffffcf37, DAT_ffffcf37 == '\0')) &&
      ((DAT_ffffcf36 == '\0' && (DAT_ffffcf35 == '\0')))) || (300.0 <= DAT_ffffbfa0)) {
    DAT_ffffcf38 = 0;
  }
  else if (DAT_ffffbfa0 < 300.0) {
    DAT_ffffcf38 = 1;
  }
  return puVar1;
}


