# specc

## Unit testing framework for C/C++

Example test suite using specc
```C
#include "../../src/main.h"

module(simple, {
  
  describe("simple test",{
    
    it("this is what a passing test looks like",
      should(1 == 1));

    it("failing boolean test",
      should(1 == 0););

    it("failing char test",
      should_eq('a','b',char););

    it("failing int test",
      should_eq(1,2,int););

    it("failing float test",
      should_eq(0.9f,2.4f,float););

    it("failing pointer test", {
      int a = 5;
      int b = 5;
      should_eq(&a,&b,int*);});

    it("failing string test",
      should_str_eq("hello","bye"););});});
```

Output:

![simple](https://raw.githubusercontent.com/g-jensen/specc/main/resources/simple.png)

## Current Comparison Support
* `should`
* `should_not`
* `should_eq` (for primitives)
* `should_not_eq` (for primitives)
* `should_str_eq`
* `should_str_not_eq`

# Buildling
## Custom
specc's entry point is in `src/main.c` so all you have to do is
```
gcc -c src/main.c
```
and then link all of your spec files.

## Pre-made runner
The runner in `runner/specc_runner.clj` requires Clojure to be installed.

Once Clojure is installed, configure `deps.edn` to make the runner look at the directories you want.

Then run:
```
clj -Mspecc-all
```
or
```
clj -Mspecc custom-path1 custom-path2
```
