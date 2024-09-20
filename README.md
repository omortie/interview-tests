Solved C++/Qt interview tests

## Build
You have to install [Conan](https://conan.io/downloads) 2.x and then run this command in root of the project:
```c
conan profile detect
conan install . --build=missing -of=build
```
Then you can open any IDE with the ```CMakePresets.json``` generated by Conan  and try to run ```All CTest```