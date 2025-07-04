# specc

## Unit testing framework for C/C++

Example test suite using specc
```C
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
```

Output:

![readme example](https://raw.githubusercontent.com/g-jensen/specc/main/resources/readme.png)

## Current Comparison Support
* `should`
* `should_not`
* `should_eq` (for primitives)
* `should_not_eq` (for primitives)
* `should_str_eq`
* `should_str_not_eq`
* `should_double_eq` (with given err)
* `should_double_not_eq` (with given err)

You can also implement your own custom comparisons. An example of this can be found in examples/custom


## Stubbing
The only support specc has for any kind of 'stubbing' is a `#define SPECC` to allow different behavior when tests are being run.

# Building
## Custom
specc's entry point is in `src/specc.c` so all you have to do is
```
gcc -c src/specc.c
```
and then link all of your spec files.

## Makefile
```
# alternatively, `make spec-auto`
make spec
```

Right now, the Makefile is configured to run the simple example, but it isn't too hard to change it for your needs.