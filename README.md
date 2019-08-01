# DefineDemo
### `FOUNDATION_EXPORT`, `UIKIT_EXTERN`
该宏的作用类似于`extern`，使用方法也与`extern`类似，在`.m`文件中，定义如下

```
NSString *const kFoundationExportString = @"kFoundationExportString";

NSString *const kExternString = @"kExternString";
```

然后在`.h`文件中加上以下声明， 就可以在导入该`.h`文件的类中访问该常量。
```
FOUNDATION_EXPORT NSString *const kFoundationExportString;

extern NSString *const kExternString;  
```
如果要在未导入该`.h`文件的类中访问这两个常量， 则应该将上面的代码放入该类的`.m`文件中。
`UIKIT_EXTERN`相比`extern`只是增加了兼容性，使用方法一样。


使用如下：
```
NSString *str = @"Hello World";
if (str == kConstantString) {
NSLog(@"equal");
}
```
使用`FOUNDATION_EXPORT`声明的字符串常量比较的是指针的地址， 而`#define`宏定义的常量字符串只能使用`isEqualToString`来比较， 前者更加高效。


![define与FOUNDATION_EXPORT比较](https://user-gold-cdn.xitu.io/2019/8/1/16c4abcd0d10575a?w=1600&h=336&f=png&s=75564 "define与FOUNDATION_EXPORT比较")


### `NS_STRING_ENUM` 和 `NS_EXTENSIBLE_STRING_ENUM`
这两个个宏定义是用于为`Objective-C`桥接`Swift`所使用的，它的作用是在桥接到 Swift 中时可进行枚举扩展，使用如下：
在`.h`文件中声明
```
typedef NSString *ViewControllerKey NS_STRING_ENUM;
FOUNDATION_EXPORT ViewControllerKey const ViewControllerKeyTitle;
FOUNDATION_EXPORT ViewControllerKey const ViewControllerKeySubtitle;
FOUNDATION_EXPORT ViewControllerKey const ViewControllerKeySummary;
```
`.m`文件中定义：
```
ViewControllerKey const ViewControllerKeyTitle = @"title";
ViewControllerKey const ViewControllerKeySubtitle = @"subtitle";
ViewControllerKey const ViewControllerKeySummary = @"summary"; 
```
在swift文件中使用如下：
```
print("\(ViewControllerKey.title) \(ViewControllerKey.subtitle) \(ViewControllerKey.summary)")
```

这两个宏定义的区别在于，`NS_STRING_ENUM`是确定的， `NS_EXTENSIBLE_STRING_ENUM`则是可扩展的，还可以在在`swift`中进行扩展。


###  `__VA_ARGS__`
`##`就是个粘合剂，将前后两部分粘合起来，也就是有“字符化”的意思。

而__VA_ARGS__在预编译中会被实参列表取代， `...`表示可变参列表。

`##__VA_ARGS__` 宏前面加上`##`的作用在于，当可变参数的个数为0时，这里的`##`起到把前面多余的`,`去掉的作用,否则会编译出错

```
#define BLOCK_EXEC(block, ...) if (block) { block(__VA_ARGS__); };

#ifdef DEBUG
#define LogInfo( s, ... ) NSLog( @"[LogInfo]<%@:(%d)> %@", [[NSString stringWithUTF8String:__FILE__] lastPathComponent], __LINE__, [NSString stringWithFormat:(s), ##__VA_ARGS__] )
#else
#define LogInfo( s, ... )
#endif
```

