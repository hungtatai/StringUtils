# StringUtils

This library implements many commonly used but not natively supported function in **std::string**, like `Split`, `Join`, `Trim`, `Compact`, `ReplaceAll`, `ToLower`, `ToUpper`, `Repeat`, `ReadFile`, `WriteFile`, etc.

# Test

`make test`

```
Passing: Split(s, delim, false)
Passing: Split(s, delim, true)
Passing: Join(res, delim, false)
Passing: Join(res, delim, true)
Passing: Compact(res)
Passing: Trim(" hi ")
Passing: Repeat("-", 5)
Passing: ReplaceAll("monday morning", "mo", "kk")
Passing: ToUpper("abcd")
Passing: ToLower("ABCD")
Passing: ReadFile("test_readfile.txt")
Passing: WriteFile("test_writefile.txt", "abcde")
Result: 12/12 Completed.
```

# Usage

see example: [test.cpp](https://github.com/HondaDai/StringUtils/blob/master/test/main.cpp)

see source code: [string-utils.h](https://github.com/HondaDai/StringUtils/blob/master/string-utils.h)

see demo: [demo](https://github.com/HondaDai/StringUtils/tree/master/demo/customize_configuration)


## Split

```c++
vector<string> v = Split("one,two,three", ","); // v: ["one", "two", "three"]
```
  
## Join

```c++
vector<string> v;
v.push_back("1");
v.push_back("2");
v.push_back("3");
string s = Join(v, ":"); // s: "1:2:3"
```

## Trim

```c++
string s = Trim(" hi "); // v: "hi"
```

## Repeat

```c++
string s = Repeat("#", 5); // v: "#####"
```

## ReplaceAll

```c++
vector<string> v = ReplaceAll("1-2-3-4", "-", "#"); // v: "1#2#3#4"
```

## Compact

remove empty string

```c++
vector<string> v;
v.push_back("1");
v.push_back("");
v.push_back("2");
v.push_back("3");
v.push_back("");
// v: ["1", "", "2", "3", ""]
v = Compact(v);
// v: ["1", "2", "3"]
```

## ToLower

```c++
string s = ToLower("ABCD"); // v: "abcd"
```

## ToUpper

```c++
string s = ToUpper("abcd"); // v: "ABCD"
```

## ReadFile

read file to string

```c++
string content = ReadFile(...file path...);
```

## WriteFile

write string to file

```c++
string content = "...";
WriteFile(...file path..., content);
```

# Demo

build and run: `make demo`

see demo: [demo](https://github.com/HondaDai/StringUtils/tree/master/demo/customize_configuration)

# Contributing

We love contributions! If you'd like to contribute please submit a pull request.

# License

[License.md](https://github.com/HondaDai/StringUtils/blob/master/LICENSE.md)
