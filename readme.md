# StringUtils

This library implements many commonly used but not natively supported function in **std::string**, like `Split`, `Join`, `Trim`, `Compact`, `ReplaceAll`, `Repeat`, `ReadFile`, `WriteFile`, etc.

# Test

`make test`

# Usage

see example: [test.cpp](https://github.com/HondaDai/StringUtils/blob/master/test/main.cpp#L45)

see source: [string-utils.h](https://github.com/HondaDai/StringUtils/blob/master/string-utils.h)

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

## ReadFile

read file to string

```c++
string content = ReadFile(...file path...);
```

## WriteFile

write string to file

```c++
string content = "...";
ReadFile(...file path..., content);
```