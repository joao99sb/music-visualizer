#include <math.h>
#include "../includes/fft.h"
// void fft(float *in, size_t stride, float complex *out, size_t n)
// {

//   assert(n > 0);
//   double pi = atan2f(1, 1) * 4;
//   if (n == 1)
//   {
//     out[0] = in[0];
//     return;
//   }

//   fft(in, stride * 2, out, n / 2);
//   fft(in + stride, stride * 2, out + n / 2, n / 2);

//   for (size_t k = 0; k < n / 2; ++k)
//   {
//     float t = (float)k / n;
//     float complex v = cexp(-2 * I * pi * t) * out[k + n / 2];
//     float complex e = out[k];
//     out[k] = e + v;
//     out[k + n / 2] = e - v;
//   }
// }

float amp(float complex z)
{
  float a = fabsf(crealf(z));
  float b = fabsf(cimagf(z));
  if (a < b)
    return b;
  return a;
}
