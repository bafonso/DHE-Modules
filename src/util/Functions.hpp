#pragma once

#include <cmath>
#include <functional>

namespace DHE {
inline float clamp(float in, float low, float high) {
  if (in < low)
    return low;
  if (in > high)
    return high;
  return in;
}


inline float normalizeFromRange(float scaled, float min, float max) {
  return min + scaled / (max - min);
}

inline float scaleToRange(float normalized, float min, float max) {
  return normalized * (max - min) + min;
}

inline float sigmoid(float x, float curvature) {
  static constexpr float precision = 1e-4f;
  static constexpr float maxCurvature = 1.0f - precision;
  float k = clamp(curvature, -maxCurvature, maxCurvature);
  x = clamp(x, -1.0f, 1.0f);
  return (x - x * k) / (k - abs(x) * 2.0f * k + 1.0f);
}

inline float toUnipolarVoltage(float normalized) {
  return scaleToRange(normalized, 0.0f, 10.0f);
}

inline float toUnipolarVoltage(bool state) {
  return state ? 10.0f : 0.0f;
}
}