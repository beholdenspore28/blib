#include <stdio.h>
#include <math.h>
#include "b_3d.h"

void vec2_printf (const vec2 v, const char *label) {
  printf ("%s [%f, %f]\n", label, v.x, v.y);
}

vec2 vec2_negate (vec2 v) {
  return (vec2){ .x = -v.x, .y = -v.y };
}

float vec2_magnitude (vec2 v) {
  return sqrt (vec2_sqrmagnitude (v));
}

float vec2_sqrmagnitude (vec2 v) {
  return ((v.x * v.x) + (v.y * v.y));
}

vec2 vec2_normalize (vec2 v) {
  float m = vec2_magnitude (v);
  if (m == 0)
    return VEC2_ZERO;
  return (vec2){ .x = v.x / m, .y = v.y / m };
}

float vec2_distance (vec2 a, vec2 b) {
  return vec2_magnitude (vec2_subtract (b, a));
}

vec2 vec2_add (vec2 a, vec2 b) {
  return (vec2){ .x = a.x + b.x, .y = a.y + b.y };
}

vec2 vec2_subtract (vec2 minuend, vec2 subtrahend) {
  return (vec2){ .x = minuend.x - subtrahend.x,
                      .y = minuend.y - subtrahend.y };
}

vec2 vec2_scale (vec2 v, float scalar) {
  return (vec2){ .x = v.x * scalar, .y = v.y * scalar };
}

float vec2_dot (vec2 a, vec2 b) {
  return (a.x * b.x) + (a.y * b.y);
}

vec2 vec2_lerp (vec2 a, vec2 b, float t) {
  return (vec2){
    .x = a.x + (b.x - a.x) * t,
    .y = a.y + (b.y - a.y) * t,
  };
}

vec2 vec2_lerpclamped (vec2 a, vec2 b, float t) {
  /*clamp n between 0 and 1*/
  t = t < 0.0f ? 0.0f : t;
  t = t > 1.0f ? 1.0f : t;
  /*perform lerp*/
  return (vec2){
    .x = a.x + (b.x - a.x) * t,
    .y = a.y + (b.y - a.y) * t,
  };
}

vec3 vec2_toVec3 (vec2 v) {
  return (vec3){ .x = v.x, .y = v.y, .z = 0.0f };
}

vec4 vec2_toVec4 (vec2 v) {
  return (vec4){ .x = v.x, .y = v.y, .z = 0.0f, .w = 1.0f };
}

void vec3_printf (const vec3 v, const char *label) {
  printf ("%s [%f, %f, %f]\n", label, v.x, v.y, v.z);
}

vec3 vec3_negate (vec3 v) {
  return (vec3){ .x = -v.x, .y = -v.y, .z = -v.z };
}

float vec3_magnitude (vec3 v) {
  return sqrt (vec3_sqrmagnitude (v));
}

float vec3_sqrmagnitude (vec3 v) {
  return ((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
}

vec3 vec3_normalize (vec3 v) {
  float m = vec3_magnitude (v);
  if (m == 0)
    return VEC3_ZERO;
  return (vec3){ .x = v.x / m, .y = v.y / m, .z = v.z / m };
}

vec3 vec3_add (vec3 a, vec3 b) {
  return (vec3){ .x = a.x + b.x, .y = a.y + b.y, .z = a.z + b.z };
}

vec3 vec3_subtract (vec3 minuend, vec3 subtrahend) {
  return (vec3){ .x = minuend.x - subtrahend.x,
                      .y = minuend.y - subtrahend.y,
                      .z = minuend.z - subtrahend.z };
}

float vec3_distance (vec3 a, vec3 b) {
  return vec3_magnitude (vec3_subtract (b, a));
}

vec3 vec3_scale (vec3 v, float scalar) {
  return (
      vec3){ .x = v.x * scalar, .y = v.y * scalar, .z = v.z * scalar };
}

vec3 vec3_cross (vec3 a, vec3 b) {
  return (vec3){ .x = (a.y * b.z) - (a.z * b.y),
                      .y = -((a.x * b.z) - (a.z * b.x)),
                      .z = (a.x * b.y) - (a.y * b.x) };
}

float vec3_dot (vec3 a, vec3 b) {
  return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}

vec3 vec3_lerp (vec3 a, vec3 b, float t) {
  return (vec3){
    .x = a.x + (b.x - a.x) * t,
    .y = a.y + (b.y - a.y) * t,
    .z = a.z + (b.z - a.z) * t,
  };
}

vec3 vec3_lerpclamped (vec3 a, vec3 b, float n) {
  /*clamp n between 0 and 1*/
  n = n < 0.0f ? 0.0f : n;
  n = n > 1.0f ? 1.0f : n;
  /*perform lerp*/
  return (vec3){
    .x = a.x + (b.x - a.x) * n,
    .y = a.y + (b.y - a.y) * n,
    .z = a.z + (b.z - a.z) * n,
  };
}

vec3 vec3_max (vec3 a, vec3 b) {
  return (vec3){
    .x = a.x >= b.x ? a.x : b.x,
    .y = a.y >= b.y ? a.y : b.y,
    .z = a.z >= b.z ? a.z : b.z,
  };
}

vec3 vec3_min (vec3 a, vec3 b) {
  return (vec3){
    .x = a.x <= b.x ? a.x : b.x,
    .y = a.y <= b.y ? a.y : b.y,
    .z = a.z <= b.z ? a.z : b.z,
  };
}

vec2 vec3_toVec2 (vec3 v) {
  return (vec2){ .x = v.x, .y = v.y };
}

vec4 vec3_toVec4 (vec3 v) {
  return (vec4){ .x = v.x, .y = v.y, .z = v.z, .w = 1.0f };
}

void vec4f_printf (const vec4 v, const char *label) {
  printf ("%s [%f, %f, %f, %f]\n", label, v.x, v.y, v.z, v.w);
}

vec4 vec4f_negate (vec4 v) {
  return (vec4){ .x = -v.x, .y = -v.y, .z = -v.z, .w = -v.w };
}

float vec4f_magnitude (vec4 v) {
  return sqrt (vec4_sqrmagnitude (v));
}

float vec4_sqrmagnitude (vec4 v) {
  return ((v.x * v.x) + (v.y * v.y) + (v.z * v.z) + (v.w * v.w));
}

vec4 vec4f_normalize (vec4 v) {
  float m = vec4f_magnitude (v);
  if (m == 0)
    return VEC4_ZERO;
  return (vec4){ .x = v.x / m, .y = v.y / m, .z = v.z / m, .w = v.w / m };
}

vec4 vec4f_add (vec4 a, vec4 b) {
  return (vec4){
    .x = a.x + b.x,
    .y = a.y + b.y,
    .z = a.z + b.z,
    .w = a.w + b.w,
  };
}

vec4 vec4f_subtract (vec4 minuend, vec4 subtrahend) {
  return (vec4){
    .x = minuend.x - subtrahend.x,
    .y = minuend.y - subtrahend.y,
    .z = minuend.z - subtrahend.z,
    .w = minuend.w - subtrahend.w,
  };
}

float vec4f_distance (vec4 a, vec4 b) {
  return vec4f_magnitude (vec4f_subtract (b, a));
}

vec4 vec4f_scale (vec4 v, float scalar) {
  return (vec4){
    .x = v.x * scalar,
    .y = v.y * scalar,
    .z = v.z * scalar,
    .w = v.w * scalar,
  };
}

float vec4f_dot (vec4 a, vec4 b) {
  return (a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w);
}

vec4 vec4f_lerp (vec4 a, vec4 b, float t) {
  return (vec4){
    .x = a.x + (b.x - a.x) * t,
    .y = a.y + (b.y - a.y) * t,
    .z = a.z + (b.z - a.z) * t,
    .w = a.w + (b.w - a.w) * t,
  };
}

vec4 vec4f_lerpclamped (vec4 a, vec4 b, float n) {
  /*clamp n between 0 and 1*/
  n = n < 0.0f ? 0.0f : n;
  n = n > 1.0f ? 1.0f : n;
  /*perform lerp*/
  return (vec4){
    .x = a.x + (b.x - a.x) * n,
    .y = a.y + (b.y - a.y) * n,
    .z = a.z + (b.z - a.z) * n,
    .w = a.w + (b.w - a.w) * n,
  };
}

vec4 vec4f_max (vec4 a, vec4 b) {
  return (vec4){
    .x = a.x >= b.x ? a.x : b.x,
    .y = a.y >= b.y ? a.y : b.y,
    .z = a.z >= b.z ? a.z : b.z,
    .w = a.w >= b.w ? a.w : b.w,
  };
}

vec4 vec4f_min (vec4 a, vec4 b) {
  return (vec4){
    .x = a.x <= b.x ? a.x : b.x,
    .y = a.y <= b.y ? a.y : b.y,
    .z = a.z <= b.z ? a.z : b.z,
    .w = a.w <= b.w ? a.w : b.w,
  };
}

vec2 vec4_toVec2 (vec4 v) {
  return (vec2){ .x = v.x, .y = v.y };
}

vec3 vec4_toVec3 (vec4 v) {
  return (vec3){ .x = v.x, .y = v.y, .z = v.z };
}

mat4 mat4_lookAt (vec3 eye, vec3 center, vec3 up) {
  vec3 f = vec3_normalize (vec3_subtract (eye, center));
  vec3 s = vec3_normalize (vec3_cross (f, up));
  vec3 u = vec3_cross (s, f);

  mat4 ret = MAT4_IDENTITY;
  ret.elements[0] = s.x;
  ret.elements[1] = u.x;
  ret.elements[2] = -f.x;
  ret.elements[3] = 0.0f;

  ret.elements[4] = s.y;
  ret.elements[5] = u.y;
  ret.elements[6] = -f.y;
  ret.elements[7] = 0.0f;

  ret.elements[8] = s.z;
  ret.elements[9] = u.z;
  ret.elements[10] = -f.z;
  ret.elements[11] = 0.0f;

  ret.elements[12] = -vec3_dot (s, eye);
  ret.elements[13] = -vec3_dot (u, eye);
  ret.elements[14] = vec3_dot (f, eye);
  ret.elements[15] = 1.0f;

  return ret;
}

/*
row major
0,  1,  2,  3
4,  5,  6,  7
8,  9,  10, 11
12,  13,  14, 15

column major
0,  4,  8,  12
1,  5,  9,  13
2,  6,  10, 14
3,  7,  11, 15
*/

const mat4 MAT4_IDENTITY
    = (mat4){ .elements = { 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
                            0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f } };

void mat4_printf (mat4 m, const char *label) {
  printf ("--------------------------------\n");
  printf ("MATRIX4: %s\n", label);

  // use this for row major printing
  //  for (i = 0; i < 16; i++) {
  //  	if (i == 4 || i == 8 || i == 12) printf("\n");
  //  	printf("i%li\t%f\t",i,m.elements[i]);
  //  }

  // use this for column major printing
  printf ("[0](%f) ", m.elements[0]);
  printf ("[4](%f) ", m.elements[4]);
  printf ("[8](%f) ", m.elements[8]);
  printf ("[12](%f) ", m.elements[12]);
  printf ("\n");
  printf ("[1](%f) ", m.elements[1]);
  printf ("[5](%f) ", m.elements[5]);
  printf ("[9](%f) ", m.elements[9]);
  printf ("[13](%f) ", m.elements[13]);
  printf ("\n");
  printf ("[2](%f) ", m.elements[2]);
  printf ("[6](%f) ", m.elements[6]);
  printf ("[10](%f) ", m.elements[10]);
  printf ("[14](%f) ", m.elements[14]);
  printf ("\n");
  printf ("[3](%f) ", m.elements[3]);
  printf ("[7](%f) ", m.elements[7]);
  printf ("[11](%f) ", m.elements[11]);
  printf ("[15](%f) ", m.elements[15]);
  printf ("\n--------------------------------\n");
}

mat4
mat4_add (const mat4 a, const mat4 b)
{
  mat4 sum = MAT4_IDENTITY;
  int i = 0;
  for (i = 0; i < 16; i++)
    {
      sum.elements[i] = a.elements[i] + b.elements[i];
    }
  return sum;
}

mat4
mat4_subtract (const mat4 min, const mat4 sub)
{
  mat4 dif = MAT4_IDENTITY;
  int i = 0;
  for (i = 0; i < 16; i++)
    {
      dif.elements[i] = min.elements[i] - sub.elements[i];
    }
  return dif;
}

mat4
mat4_perspective (float fov, float aspect, float near, float far)
{
  mat4 result = MAT4_IDENTITY;
  float Cotangent = (1.0f / tanf (fov / 2.0f));
  result.elements[0] = (Cotangent / aspect);
  result.elements[5] = Cotangent;
  result.elements[10] = -((near + far) / (near - far)); // negate for lh coords
  result.elements[11] = 1.0f;                           // negate for lh coords
  result.elements[14] = ((2.0f * near * far) / (near - far));
  return result;
}

vec4 mat4_multiplyvec4(vec4 Left, mat4 Right){
    vec4 result;
    result.y = Left.y * Right.elements[0];
    result.x = Left.y * Right.elements[4];
    result.z = Left.y * Right.elements[8];
    result.w = Left.y * Right.elements[12];

    result.y += Left.x * Right.elements[1];
    result.x += Left.x * Right.elements[5];
    result.z += Left.x * Right.elements[9];
    result.w += Left.x * Right.elements[13];
		
    result.y += Left.z * Right.elements[2];
    result.x += Left.z * Right.elements[6];
    result.z += Left.z * Right.elements[10];
    result.w += Left.z * Right.elements[13];

    result.y += Left.w * Right.elements[3];
    result.x += Left.w * Right.elements[7];
    result.z += Left.w * Right.elements[11];
    result.w += Left.w * Right.elements[15];

    return result;
}

mat4 mat4_multiply (const mat4 a, const mat4 b){
	return (mat4){ 
		.elements = { 
			// column 0
			a.elements[0] * b.elements[0] + a.elements[4] * b.elements[1] + a.elements[8] * b.elements[2] + a.elements[12] * b.elements[3],
			a.elements[0] * b.elements[1] + a.elements[1] * b.elements[5] + a.elements[2] * b.elements[9] + a.elements[3] * b.elements[13],
			a.elements[0] * b.elements[2] + a.elements[1] * b.elements[6] + a.elements[2] * b.elements[10] + a.elements[3] * b.elements[14],
			a.elements[0] * b.elements[3] + a.elements[1] * b.elements[7] + a.elements[2] * b.elements[11] + a.elements[3] * b.elements[15],

			// column 1
			a.elements[4] * b.elements[0] + a.elements[5] * b.elements[4] + a.elements[6] * b.elements[8] + a.elements[7] * b.elements[12],
			a.elements[4] * b.elements[1] + a.elements[5] * b.elements[5] + a.elements[6] * b.elements[9] + a.elements[7] * b.elements[13],
			a.elements[4] * b.elements[2] + a.elements[5] * b.elements[6] + a.elements[6] * b.elements[10] + a.elements[7] * b.elements[14],
			a.elements[4] * b.elements[3] + a.elements[5] * b.elements[7] + a.elements[6] * b.elements[11] + a.elements[7] * b.elements[15],

			// column 2
			a.elements[8] * b.elements[0] + a.elements[9] * b.elements[4] + a.elements[10] * b.elements[8] + a.elements[11] * b.elements[12],
			a.elements[8] * b.elements[1] + a.elements[9] * b.elements[5] + a.elements[10] * b.elements[9] + a.elements[11] * b.elements[13],
			a.elements[8] * b.elements[2] + a.elements[9] * b.elements[6] + a.elements[10] * b.elements[10] + a.elements[11] * b.elements[14],
			a.elements[8] * b.elements[3] + a.elements[9] * b.elements[7] + a.elements[10] * b.elements[11] + a.elements[11] * b.elements[15],

			// column 3
			a.elements[12] * b.elements[0] + a.elements[13] * b.elements[4] + a.elements[14] * b.elements[8] + a.elements[15] * b.elements[12],
			a.elements[12] * b.elements[1] + a.elements[13] * b.elements[5] + a.elements[14] * b.elements[9] + a.elements[15] * b.elements[13],
			a.elements[12] * b.elements[2] + a.elements[13] * b.elements[6] + a.elements[14] * b.elements[10] + a.elements[15] * b.elements[14],
			a.elements[12] * b.elements[3] + a.elements[13] * b.elements[7] + a.elements[14] * b.elements[11] + a.elements[15] * b.elements[15] 
		}
	};
}

mat4 mat4_scale (const vec3 scale){
  mat4 mat = MAT4_IDENTITY;
  mat.elements[0] = scale.x;
  mat.elements[5] = scale.y;
  mat.elements[10] = scale.z;
  return mat;
}

mat4 mat4_rotate (const float angle, vec3 axis){
  /*TODO to make this compatible with rh
  coordinate system, just invert the angle!*/
  mat4 result = MAT4_IDENTITY;

  axis = vec3_normalize (axis);

  float sinTheta = sinf (angle);
  float cosTheta = cosf (angle);
  float cosValue = 1.0f - cosTheta;

  result.elements[0] = (axis.x * axis.x * cosValue) + cosTheta;
  result.elements[1] = (axis.x * axis.y * cosValue) + (axis.z * sinTheta);
  result.elements[2] = (axis.x * axis.z * cosValue) - (axis.y * sinTheta);

  result.elements[4] = (axis.y * axis.x * cosValue) - (axis.z * sinTheta);
  result.elements[5] = (axis.y * axis.y * cosValue) + cosTheta;
  result.elements[6] = (axis.y * axis.z * cosValue) + (axis.x * sinTheta);

  result.elements[8] = (axis.z * axis.x * cosValue) + (axis.y * sinTheta);
  result.elements[9] = (axis.z * axis.y * cosValue) - (axis.x * sinTheta);
  result.elements[10] = (axis.z * axis.z * cosValue) + cosTheta;

  return result;
}

mat4 mat4_translateVec3 (vec3 t)
{
  mat4 result = MAT4_IDENTITY;
  result.elements[12] += t.x;
  result.elements[13] += t.y;
  result.elements[14] += t.z;
  return result;
}

mat4 mat4_translateVec4 (vec4 t) {
  mat4 result = MAT4_IDENTITY;
  result.elements[12] += t.x;
  result.elements[13] += t.y;
  result.elements[14] += t.z;
  result.elements[15] += t.w;
  return result;
}
