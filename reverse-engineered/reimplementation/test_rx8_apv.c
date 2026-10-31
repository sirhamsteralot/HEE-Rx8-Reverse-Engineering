#include "rx8_apv.h"
#include <assert.h>
#include <math.h>
int main(void)
{
    assert(rx8_apv_scaled_sample(0) == 0.0f);
    assert(rx8_apv_scaled_sample(32768) == 2.5f);
    assert(rx8_apv_scaled_sample(65472) == 4.9951171875f);
    assert(rx8_apv_signed_fraction(50.0f,0) == 0.5f);
    assert(rx8_apv_signed_fraction(50.0f,1) == -0.5f);
    assert(rx8_apv_signed_fraction(50.0f,2) == 0.5f);
    for(int i=-100;i<=100;i++) {
        float f=(float)i / 100.0f;
        rx8_apv_ticks t=rx8_apv_split_ticks(f,96);
        assert(t.channel_a_ticks==0 || t.channel_b_ticks==0);
        assert(t.channel_a_ticks<=96 && t.channel_b_ticks<=96);
        assert((float)(t.channel_a_ticks+t.channel_b_ticks)<=fabsf(f*96.0f));
        assert(fabsf(f*96.0f)-(float)(t.channel_a_ticks+t.channel_b_ticks)<1.0f);
        rx8_apv_ticks mirror=rx8_apv_split_ticks(-f,96);
        assert(t.channel_a_ticks==mirror.channel_b_ticks);
        assert(t.channel_b_ticks==mirror.channel_a_ticks);
    }
    rx8_apv_ticks full=rx8_apv_split_ticks(1,96);
    assert(full.channel_a_ticks==96 && full.channel_b_ticks==0);
    rx8_apv_ticks quarter=rx8_apv_split_ticks(-0.25f,96);
    assert(quarter.channel_a_ticks==0 && quarter.channel_b_ticks==24);
    return 0;
}
