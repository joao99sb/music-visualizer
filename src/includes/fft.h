#pragma once
#include <complex.h>
#include <assert.h>
#include <stdio.h>

void fft(float in[], size_t stride, float complex out[], size_t n);
float amp(float complex z);