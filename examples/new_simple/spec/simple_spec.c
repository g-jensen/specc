#include "../../../src/specc.h"
#include "../headers/simple.h"

spec(passing_spec)(spec_t *s) {
  should(s, 1 == 1);
}

spec(failing_bool_spec)(spec_t *s) {
  should(s, 1 == 0);
}

spec(failing_char_spec)(spec_t *s) {
  should_eq(s, 'a', 'b', char);
}

spec(passing_char_spec)(spec_t *s) {
  should_eq(s, 'a', 'a', char);
}

spec(failing_int_spec)(spec_t *s) {
  should_eq(s, 1, 2, int);
}

spec(failing_float_spec)(spec_t *s) {
  should_eq(s, 0.9f, 2.4f, float);
}

spec(failing_pointer_test)(spec_t *s) {
  int a = 5;
  int b = 5;
  should_eq(s, &a, &b, int*);
}

spec(passing_double_equality)(spec_t *s) {
  should_double_eq(s, 4.0, 3.9, 0.1);
}

spec(passing_using_myfunction)(spec_t *s) {
  should_eq(s, 5, my_function(), int);
}

spec(pass_followed_by_fail)(spec_t *s) {
  should_eq(s, 2, 2, int);
  should_eq(s, 5, 2, int);
}

spec(fail_followed_by_pass)(spec_t *s) {
  should_eq(s, 5, 2, int);
  should_eq(s, 2, 2, int);
}

spec(multiple_failures)(spec_t *s) {
  should_eq(s, 1, 2, int);
  should_eq(s, 3, 4, int);
}

spec(passing_str_equal)(spec_t *s) {
  should_str_eq(s, "hi", "hi");
}

spec(failing_str_equal)(spec_t *s) {
  should_str_eq(s, "hi", "bye");
}

spec(passing_double_equal)(spec_t *s) {
  should_double_eq(s, 0.0, 0.5, 1.0);
}

spec(failing_double_equal)(spec_t *s) {
  should_double_eq(s, 0.0, 10.0, 1.0);
}