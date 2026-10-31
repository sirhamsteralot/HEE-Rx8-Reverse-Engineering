/* [ADDITIONAL SOURCE REVIEW]
 * knock_filter_constants_init [high]: Sets c060=0.0625, c064=0.1253, c068=0.03125, c05d=0 (calm-state filter constants; 0x336c4 switches c060 to 0.1875 and c068 to ROM 0x7a23c=0.09375 on transient c05d==1; c064 stays 0.1253).
 */
/* ROM address: 0x00033632; body bytes: 32; decompiled */

void knock_filter_constants_init(void)

{
  knock_filter_coeff_a_ffffc060 = 0x3d800000;
  knock_filter_coeff_b_ffffc064 = 0x3e004ea5;
  knock_filter_coeff_c_ffffc068 = 0x3d000000;
  knock_transient_flag_ffffc05d = 0;
  return;
}


