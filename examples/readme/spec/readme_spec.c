#include "../../../src/specc.h"

spec(passing_spec)(spec_t *s) {
  should(s, 1 == 1);
}

spec(failing_boolean_spec)(spec_t *s) {
  should(s, 1 == 0);
}

spec(failing_integer_spec)(spec_t *s) {
  should_eq(s, 1, 2, int);
}

spec(failing_float_spec)(spec_t *s) {
  should_eq(s, 0.9f, 2.4f, float);
}

spec(failing_pointer_spec)(spec_t *s) {
  int a, b;
  should_eq(s, &a, &b, int*);
}

spec(failing_string_spec)(spec_t *s) {
  should_str_eq(s, "hello", "goodbye");
}