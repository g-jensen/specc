#include "../../../src/specc.h"
#include "../headers/custom.h"

#define should_vector_equal(expected, actual)\
  if (!(expected.x == actual.x && expected.y == actual.y)) {\
    specc_fail_message(" | Expected: {%f, %f} Actual: {%f, %f}",expected.x,expected.y,actual.x,actual.y)\
  }

module(custom, {
  
  describe("custom test",{
    
    it("passing custom test",{
      vector v1 = {1,5};
      should_vector_equal(v1,v1);
    });

    it("failing custom test",{
      vector v1 = {1,5};
      vector v2 = {2,6};
      should_vector_equal(v1,v2);
    });
  });
});