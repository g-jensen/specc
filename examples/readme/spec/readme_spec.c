#include "../../../src/specc.h"

module(readme_example, {
  
  describe("README Example",{
    
    it("passes a test",{
      should(1 == 1);
    })

    context("some context", {

      it("doesn't need curlies",
        should(1 == 1);
      )

      it("fails a boolean test", {
        should(1 == 0);
      })
    })

    it("fails a char test", {
      should_eq('a','b',char);
    })

    it("fails an int test", {
      should_eq(1,2,int);
    })

    it("fails a float test", {
      should_eq(0.9f,2.4f,float);
    })

    it("fails a pointer test", {
      int a = 5;
      int b = 5;
      should_eq(&a,&b,int*);
    })

    it("fails a string test", {
      should_str_eq("hello","bye");
    })
  })
})