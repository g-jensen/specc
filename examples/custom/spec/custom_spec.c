#include "../../../src/specc.h"
#include "../headers/custom.h"

#define should_vector_equal(spec_ptr, expected, actual)\
  if (!(expected.x == actual.x && expected.y == actual.y)) {\
    specc_fail_message(spec_ptr, "> Expected: {%f, %f} Actual: {%f, %f}",expected.x,expected.y,actual.x,actual.y)\
  }

spec(passing_custom_spec)(spec_t *s) {
  vector v1 = {1,5};
  vector v2 = {1,5};
  should_vector_equal(s, v1, v2);
}

spec(failing_custom_spec)(spec_t *s) {
  vector v1 = {1,5};
  vector v2 = {2,6};
  should_vector_equal(s, v1, v2);
}