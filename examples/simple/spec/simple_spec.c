#include "../../../src/specc.h"
#include "../headers/simple.h"

module(simple, {
  
  describe("simple test",{
    
    it("this is what a passing test looks like",{
      should(1 == 1);
    });

    it("failing boolean test",{
      should(1 == 0);
    });

    it("failing char test", {
      should_eq('a','b',char);
    });

    it("failing int test", {
      should_eq(1,2,int);
    });

    it("failing float test", {
      should_eq(0.9f,2.4f,float);
    });

    it("failing pointer test", {
      int a = 5;
      int b = 5;
      should_eq(&a,&b,int*);
    });

    it("passing double equality", {
      should_double_eq(4.0,3.9,0.1);
    });

    it("passing using my_function()", {
      should_eq(5,my_function(),int);
    });

    context("context in middle", {
      it("failing pointer test", {
        int a = 5;
        int b = 5;
        should_eq(&a,&b,int*);
      });

      context("nested context", {
        it("failing pointer test", {
          int a = 5;
          int b = 5;
        should_eq(&a,&b,int*);
        });

        it("passing double equality", {
          should_double_eq(4.0,3.9,0.1);
        });
      });

      it("passing double equality", {
        should_double_eq(4.0,3.9,0.1);
      });
    });

    it("failing double equality", {
      should_double_eq(4.0,3.9,0.05);
    });

    it("passing double inequality", {
      should_double_not_eq(4.0,3.9,0.05);
    });

    it("failing string test", {
      should_str_eq("hello","bye");
    });

    context("new context", {
      it("passing double inequality", {
        should_double_not_eq(4.0,3.9,0.05);
      });

      it("failing string test", {
        should_str_eq("hello","bye");
      });
    });
  });
});