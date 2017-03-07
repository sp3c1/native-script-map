# native-script-map
Low level plugin for NodeJS that implements a hash string map that is sitting in C++, allows for regex and chunking, and whats more important direct memory menagement.

# TODO
Support for 4.x and 6.x on all platforms.


# Test
```
mocha test\index.js
```

# Benchmark
Most of the test, allocate large string or append an entry it multiple times. You can find them in `test` folder to see for yourself.
```
cd test
sh oneCheck.sh
```

# Pros And Cons
So you are getting the c++ level of mem management. But it comms in execution time cost when you copy string overs. Now I have tried to bypass it using `Nan::Persistent` and use the `v8:String` but there still to be time cost and memmory management goes to shit. Feel free to look at it at https://github.com/sp3c1/native-string-map/tree/feature/map_stdstring_v8value and if you got any idea how you can utalise the v8, with persistent to not copy and manager properly the memory give me a shout or make a PR. I have started a question on SO so feel free to suggest stuff there (http://stackoverflow.com/questions/42539401/v8-concatenation-of-persistent-string).

# Build
```
node-gyp configure
node-gyp build
```

