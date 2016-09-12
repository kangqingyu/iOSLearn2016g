#2016.8.1
Rm –rf fileName  删除文件夹及其文件.
跳到对应的括号：%.

自定义tabbar命令：[self setValue:[[kqyTabBar alloc] init] forKey:@"kqyTabBar"];
这个key不可以随便设值。
重写tabbar,layoutSubViews来设置子控件。
initWithFrame设tabbar背景图

pch的路径：fileNameos1/classes/others/PrefixHeader.pch 不可以多写/，不可写成：/fileNameos1/classes/others/PrefixHeader.pch
#2016.8.2
重写tabBar的背景图，在tabBar的initWithFrame方法中定义。重写navvigation背景图在viewDidLoad中self.navigationBar setBackgroundImage:... forBarMetrics:UIBarMetricsDefault中定义。

设leftBarButtonItem的button时，要sizeToFit否则存在，但是看不到.也可以这样:itemBtn.kqy_size = [itemBtn imageForState:UIControlS**粗体文本**tateNormal].size; 获取uibutton的normal状态下的图的大小，让其大小与之相等。
autolayout:要设translatesAutoresizingMaskIntoConstraints = NO.否则无效。每一个子控件都要设置。

vim:
:％s/abc/def/g
来把所有的 abc 替换为 def。
：s/vivian/sky/ 替换当前行第一个 vivian 为 sky 
：s/vivian/sky/g 替换当前行所有 vivian 为 sky 
：n，$s/vivian/sky/ 替换第 n 行开始到最后一行中每一行的第一个 vivian 为 sky 
：n，$s/vivian/sky/g 替换第 n 行开始到最后一行中每一行所有 vivian 为 sky 
#2016.8.3
想改变button中图的位置：图在上，文字在下。如果用xib，只要重写layout方法，改变一下位置即可。如果用代码.- (CGRect)imageRectForContentRect:(CGRect)contentRect  。- (CGRect)titleRectForContentRect:(CGRect)contentRect    这两个方法可以用CGRectMake来改变图，文字的位置，但是要用自动布局，就不能这样做了。其实与xib相比，重写uibutton的代码是一样的。

autoLayout:
    NSLayoutAttributeLeft 和 NSLayoutAttributeRight ；NSLayoutAttributeLeading和 NSLayoutAttributeTrailing 。他们有什么不同？原来中国是从左到右的习惯。所以左边就是leading,右边就是trailing.而希伯来人,阿拉伯人却是相反的习惯。
  
#2016.8.4
  aspect ratio可设长和宽对应
  content priority ambiguity
  set horizontal hugging priority to 252.
  set horizontal compression resistance priority to 751.
  set horizontal hugging priority to 249.
  set horizontal hugging priority to 249.
  set horizontal compression resistance priority to 751.
  content priority ambiguity
  set veritical hugging priority to 249
  set vertical compression resistance priority to 751
  set vertical hugging priority to 249.
  set vertical compression resistance priority to 749.
  set vertical hugging priority to 252.
  做分享的3个图，间距相同。总是出现这些错。原来是中间的4个空格label的宽没有相等，虽然各自成比例，但是整体并没有关系，结果就会出错。
  
#2016.8.5
做了几个uitableView在一个大的scrollView中滑动的效果。在同在做几栏scrollView滑动时。在点击标题时没有设动画，则- (void)scrollViewDidEndScrollingAnimation:(UIScrollView *)scrollView {} 方法就不会调用。

拉新、召回、促销、刷口碑、打品牌。活动运营的五大属性。
何时可获得最大的关注、阅读量，，18时~23时之间是阅读高峰时段。因而，在此时间段开始的15分钟内发布文章，可以有效的提升阅读量。周四是一周中阅读量最大的一天，因为可以在这一天安排质量较高的文章，以期借势吸引更多目标读者的阅读。
http://www.niaogebiji.com/article-11538-1.html

#2016.8.8 Monday
编码规范
http://ios.jobbole.com/81932/
最大行长为80，过长的一行代码将会导致可读性问题。
在-和(void)之间应该有一个空格，第一个大括号{的位置在函数所在行的末尾，同样应该有一个空格。 
如果一个函数有特别多的参数或者名称很长，应该将其按照:来对齐分行显示。
在分行时，如果第一段名称过短，后续名称可以以Tab的长度（4个空格）为单位进行缩进：
- (void)short:(GTMFoo *)theFoo    
&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&emsp;&emsp;&ensp;longKeyword:(NSRect)theRect  &ensp;  &#8194;  &emsp;  &#8195;
       evenLongerKeyword:(float)theInterval  
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&ensp;&ensp;error:(NSError **)theError {
    ...
}

函数调用的格式和书写差不多，可以按照函数的长短来选择写在一行或者分成多行：
@public和@private标记符应该以一个空格来进行缩进：
@interface MyClass : NSObject {   
&ensp; @public
  ...
&ensp; @private
  ...
}
@end   
&emsp;&emsp;在书写协议的时候注意用<>括起来的协议和类型名之间是没有空格的，比如IPCConnectHandler()<IPCPreconnectorDelegate>,这个规则适用所有书写协议的地方，包括函数声明、类声明、实例变量等等：
@interface MyProtocoledClass : NSObject&lt;NSWindowDelegate&gt; {
&ensp;@private
&emsp;&emsp;&ensp; id&lt;MyFancyDelegate&gt; _delegate;
}   
- (void)setDelegate:(id&lt;MyFancyDelegate&gt;)aDelegate;
@end
block暂时没用，不总结。
数据结构的语法糖：
&emsp;&emsp;应该使用可读性更好的语法糖来构造NSArray，NSDictionary等数据结构，避免使用冗长的alloc,init方法。
NSArray *array = @[&emsp; [foo description], @&quot;Another String&quot;, [bar description]&emsp; ];
NSDictionary *dict = @{&emsp; NSForegroundColorAttributeName : [NSColor redColor]&emsp; };   
&emsp;如果构造代码不写在一行内，构造元素需要使用两个空格来进行缩进，右括号]或者}写在新的一行，并且与调用语法糖那行代码的第一个非空字符对齐：
NSArray *array = @[
&emsp;&emsp;@&quot;This&quot;,
&emsp;&emsp;@&quot;is&quot;,
&emsp;&emsp;@&quot;an&quot;,
&emsp;&emsp;@&quot;array&quot;
];
NSDictionary *dictionary = @{
&emsp;&emsp;  NSFontAttributeName : [NSFont fontWithName:@&quot;Helvetica-Bold&quot; size:12],
  &emsp;&emsp; NSForegroundColorAttributeName : fontColor
};
构造字典时，字典的Key和Value与中间的冒号:都要留有一个空格，多行书写时，也可以将Value对齐：   
//正确，冒号&#039;:&#039;前后留有一个空格
NSDictionary *option1 = @{
&emsp;NSFontAttributeName &emsp;:&emsp; [NSFont fontWithName:@&quot;Helvetica-Bold&quot; size:12],
&emsp;NSForegroundColorAttributeName&emsp; : &emsp; fontColor
};
 
//正确，按照Value来对齐
NSDictionary *option2 = @{
 &emsp;NSFontAttributeName &emsp;:&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;[NSFont fontWithName:@&quot;Arial&quot; size:12],
  &emsp;NSForegroundColorAttributeName &emsp; :&emsp;fontColor
};
//错误，在冒号前只能有一个空格，冒号后才可以考虑按照Value对齐
NSDictionary *stillWrong = @{
  AKey  &ensp;&ensp;&emsp;&emsp;&emsp;  : @&quot;b&quot;,
  BLongerKey   : @&quot;c&quot;,
};
命名规范
基本原则
清晰
&emsp; 命名应该尽可能的清晰和简洁，但在Objective-C中，清晰比简洁更重要。由于Xcode强大的自动补全功能，我们不必担心名称过长的问题。
不要使用单词的简写，拼写出完整的单词.
然而，有部分单词简写在Objective-C编码过程中是非常常用的，以至于成为了一种规范，这些简写可以在代码中直接使用，下面列举了部分：
alloc   == Allocate             
max    == Maximum
alt     == Alternate                  
min    == Minimum
app     == Application                
msg    == Message
calc    == Calculate          
nib    == Interface Builder archive
dealloc == Deallocate  
pboard == Pasteboard
func    == Function                   
rect   == Rectangle
horiz   == Horizontal  
Rep    == Representation (used in class name such as NSBitmapImageRep).
info    == Information  
temp   == Temporary
init    == Initialize   
vert   == Vertical
int     == Integer
一致性
&emsp;整个工程的命名风格要保持一致性，最好和苹果SDK的代码保持统一。不同类中完成相似功能的方法应该叫一样的名字，比如我们总是用count来返回集合的个数，不能在A类中使用count而在B类中使用getNumber。
Objective-C的方法名通常都比较长，这是为了让程序有更好地可读性，按苹果的说法“好的方法名应当可以以一个句子的形式朗读出来”。
方法一般以小写字母打头，每一个后续的单词首字母大写，方法名中不应该有标点符号（包括下划线），有两个例外：
可以用一些通用的大写字母缩写打头方法，比如PDF,TIFF等。
可以用带下划线的前缀来命名私有方法或者类别中的方法。
如果方法表示让对象执行一个动作，使用动词打头来命名，注意不要使用do，does这种多余的关键字，动词本身的暗示就足够了：
每一个返回值和类型之前没空格。后边的多个参数之间要有空格。
   不要用and来连接两个参数，通常and用来表示方法执行了两个相对独立的操作（从设计上来说，这时候应该拆分成两个独立的方法）：
不要使用new方法
尽管很多时候能用new代替alloc init方法，但这可能会导致调试内存时出现不可预料的问题。Cocoa的规范就是使用alloc init方法，使用new会让一些读者困惑。
&emsp;共有接口要设计的简洁，满足核心的功能需求就可以了。不要设计很少会被用到，但是参数极其复杂的API。如果要定义复杂的方法，使用类别或者类扩展。
&emsp;  BOOL在Objective-C中被定义为signed  char类型，这意味着一个  BOOL类型的变量不仅仅可以表示YES(1)和NO(0)两个值，所以永远不要将BOOL类型变量直接和YES比较：
//错误，无法确定|great|的值是否是YES(1)，不要将BOOL值直接与YES比较
BOOL great = [foo isGreat];
if (great == YES)
  // ...be great!
//正确
BOOL great = [foo isGreat];
if (great)
  // ...be great!
同样的，也不要将其它类型的值作为BOOL来返回，这种情况下，BOOL变量只会取值的最后一个字节来赋值，这样很可能会取到0（NO）。但是，一些逻辑操作符比如&&,||,!的返回是可以直接赋给BOOL的：
NSString非常常用，在它被传递或者赋值时应当保证是以复制（copy）的方式进行的，这样可以防止在不知情的情况下String的值被其它对象修改。
- (void)setFoo:(NSString *)aFoo {
  _foo = [aFoo copy];
}

使用带有@符号的语法糖来生成NSNumber对象能使代码更简洁：
NSNumber *fortyTwo = @42;
NSNumber *piOverTwo = @(M_PI / 2);
enum {
  kMyEnum = 2;
};
NSNumber *myEnum = @(kMyEnum);

#2016.8.9
大多笔记在myproject中记录
自动布局的刷新，默认要等RunLoop.用layoutIfNeeded可以强制刷新。
分组，在
- (instancetype)init {
    return [self initWithStyle:UITableViewStyleGrouped];
}
可以更安全。

self.tableView.sectionFooterHeight = 0;
self.tableView.sectionHeaderHeight = 0;
每一组的头尾的高度。用section的方法可以设不同组为不同高。
图的缩放，可以用contetMode来选择。
#2016.8.10  
做个人设置界面时要调后台数据用AFN，开始写错：PodFile与类文件在同一级文件夹下。
提示：
Updating local specs repositories

CocoaPods 1.1.0.beta.1 is available.
To update use: `gem install cocoapods --pre`
[!] This is a test version we'd love you to try.

For more information see http://blog.cocoapods.org
and the CHANGELOG for this version http://git.io/BaH8pQ.

Analyzing dependencies
[!] Could not automatically select an Xcode project. Specify one in your Podfile like so:

    xcodeproj 'path/to/Project.xcodeproj'
    
搜索找不到项目，于是把这个删除了，重新在移到更上一级的文件夹下。

接下来OK，安好了，但是：
kangMac:百思不得姐g1 kqy$ pod install
Updating local specs repositories

CocoaPods 1.1.0.beta.1 is available.
To update use: `gem install cocoapods --pre`
[!] This is a test version we'd love you to try.

For more information see http://blog.cocoapods.org
and the CHANGELOG for this version http://git.io/BaH8pQ.

Analyzing dependencies
Downloading dependencies
Using AFNetworking (3.1.0)
Using SDWebImage (3.8.1)
Generating Pods project
Integrating client project
Sending stats
Pod installation complete! There are 2 dependencies from the Podfile and 2
total pods installed.

[!] CocoaPods did not set the base configuration of your project because your project already has a custom config set. In order for CocoaPods integration to work at all, please either set the base configurations of the target `百思不得姐g1` to `Pods/Target Support Files/Pods-百思不得姐g1/Pods-百思不得姐g1.debug.xcconfig` or include the `Pods/Target Support Files/Pods-百思不得姐g1/Pods-百思不得姐g1.debug.xcconfig` in your build configuration.

[!] CocoaPods did not set the base configuration of your project because your project already has a custom config set. In order for CocoaPods integration to work at all, please either set the base configurations of the target `百思不得姐g1` to `Pods/Target Support Files/Pods-百思不得姐g1/Pods-百思不得姐g1.release.xcconfig` or include the `Pods/Target Support Files/Pods-百思不得姐g1/Pods-百思不得姐g1.release.xcconfig` in your build configuration.
打开项目，编译出错：
提示：
ld: library not found for -lAFNetworking
clang: error: linker command failed with exit code 1 (use -v to see invocation)

把当前Pod的目录清理一下就行了。在终端执行以下命令：
pod repo remove master
pod setup
setup成功后执行install
cmd+shift+k清理了，再安，也不行。

pod全删再repo removemaster,  pod install.把afN注释了。还是这个错：
ld: library not found for -lPods
clang: error: linker command failed with exit code 1 (use -v to see invocation)
.
最后，决定把pod全删除了。
http://www.jianshu.com/p/552f21a989ba  这个写的很有效。如何删除已经配置的类库和移除CocoaPods

但是把framework这个文件夹也删除了。运行时出错：
/Users/kqy/Library/Developer/Xcode/DerivedData/百思不得姐g1-dbrrgjnpbhbvgsfjyfnukgqxwlek/Build/Intermediates/百思不得姐g1.build/Debug-iphonesimulator/百思不得姐g1.build/Script-8E0B573C1D1E1468E9D7A3A0.sh: line 2: /Users/kqy/Documents/gitKQY/iOSLearn2016g/百思不得姐g1/Pods/Target Support Files/Pods-百思不得姐g1/Pods-百思不得姐g1-frameworks.sh: No such file or directory
再pod install终于好了。
虽然安成功了，但是导入AFNetworking提示找不到，而且不可以自动补全。选择工程的 Target -> Build Settings 菜单->搜索header,找到"User Header Search Paths";新增一个值"$(PODS_ROOT)",并且选择”recursive”，这样Xcode就会在项目目录中递归搜索文件且会自动找到Pods文件,头文件自动补齐功能马上就好使了.而且AFN可以用了。

用AFN向后台发送请求，返回的responseObject 在AFN中是id.
[responseObject writeToFile:<#(nonnull NSString *)#> atomically:<#(BOOL)#>]
 [responseObject writeToFile:@"/Users/kqy/Desktop/baisi081001.plist" atomically:YES encoding:NSUTF8StringEncoding error:nil];
 这2个。如果是id,认为是字符串，没有第一个方法，自已改为NSDictionary就会有这个转NSDictionary到plist的方法。
 字典转模型，MJExtension.
#2016.8.11
 "UIImageView+WebCache.h"这是加载图片的库，但是button要分状态。
 "UIButton+WebCache.h" 是为button专用kewoi。 
 字典的key的遵守NSCopy协议。因此要用NSString。
 用字典来存储，泛型。用代码重写控件时调initWithFrame.用xib写时调用awakeFromNib.
#2016.8.12
apple不提供获取网页进度的API，safari是真的.调用了这个API的APP，不可以上架。
清空缓存：1.找到沙盒：NSHomeDirectory。2.tmp，下次打开软件就清空的目录3.Documents是永久的文件夹，全备份到iTunes.下载的东西也不可以放在这里。[SDImageCache sharedImageCache].getSize是3方直接算出大小。        
#2016.8.15
os1中重写了meVC中的界面，加入AFN等库，还是只有AFN出错：
ld: framework not found AFNetworking
clang: error: linker command failed with exit code 1 (use -v to see invocation)

改成3.0.4（默认是3.1）还是不可以。
删了所有的库：
PhaseScriptExecution Embed\ Pods\ Frameworks /Users/kqy/Library/Developer/Xcode/DerivedData/百思不得姐os1-heklaqhtvlmhufdabzoplbsdktum/Build/Intermediates/百思不得姐os1.build/Debug-iphonesimulator/百思不得姐os1.build/Script-E02704DE89C90A854F78A6D3.sh
    cd /Users/kqy/Documents/gitKQY/iOSLearn2016os/百思不得姐os1
    /bin/sh -c /Users/kqy/Library/Developer/Xcode/DerivedData/百思不得姐os1-heklaqhtvlmhufdabzoplbsdktum/Build/Intermediates/百思不得姐os1.build/Debug-iphonesimulator/百思不得姐os1.build/Script-E02704DE89C90A854F78A6D3.sh

/Users/kqy/Library/Developer/Xcode/DerivedData/百思不得姐os1-heklaqhtvlmhufdabzoplbsdktum/Build/Intermediates/百思不得姐os1.build/Debug-iphonesimulator/百思不得姐os1.build/Script-E02704DE89C90A854F78A6D3.sh: line 2: /Users/kqy/Documents/gitKQY/iOSLearn2016os/百思不得姐os1/Pods/Target Support Files/Pods-百思不得姐os1/Pods-百思不得姐os1-frameworks.sh: No such file or directory

再vim Podfile, pod install.
以回到了没AFN的提示：
ld: framework not found AFNetworking
clang: error: linker command failed with exit code 1 (use -v to see invocation)
估计是没有清理。所以：
把当前Pod的目录清理一下就行了。在终端执行以下命令： 
pod repo remove master 
pod setup 
setup成功后执行install 
cmd+shift+k清理了，删所有的库，再装，另外改了一下（不知是不是这个原因），就好了。设选入每一个具体的 pod。。然后设置 Build Active Architecture Only为NO`   https://github.com/QYL/v2ex/commit/ee53ed75c1f5c3e4f78e25432c73678fbf84a073
可以运行了，又加了一些代码，就出现了错。。。还是这个错。。。。
ld: framework not found MJRefresh
clang: error: linker command failed with exit code 1 (use -v to see invocation)  果然，改了build active architecture only  为no 就好了

#2016.8.16
清空缓存：
 NSString *cachesPath = NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES).lastObject;
    NSString *dirPath = [cachesPath stringByAppendingPathComponent:@"MP3"];
    NSLog(@"dirPath:%@",dirPath);
    //file manager
    NSFileManager *fileMng =  [NSFileManager defaultManager];
    // attribute属性
    NSDictionary *attrs = [fileMng attributesOfItemAtPath:dirPath error:nil];
    kqyLog(@"%@", attrs);
    //得到一层文件夹的大小，得到所有的
    kqyLog(@"content: %@", [fileMng contentsOfDirectoryAtPath:dirPath error:nil]);
    kqyLog(@"subpaths:%@", [fileMng subpathsAtPath:dirPath]);
    NSUInteger size = 0;
    NSArray *subpaths = [fileMng subpathsAtPath:dirPath];
    for (NSString *subpath in subpaths) {
        NSString *fullSubPath = [dirPath stringByAppendingPathComponent:subpath];
        //文件的FileSize属性
        NSDictionary *attrs = [fileMng attributesOfItemAtPath:fullSubPath error:nil];
        size += [attrs[NSFileSize] unsignedIntegerValue];
    }
    kqyLog(@"file size : %zd", size / 1000.0);
    
快速安pod.
pod install --no-repo-update 这样快多了。

#2016.8.17
先禁用cell，再设文字，这会让文字变灰。但是反之还是正常的黑色。
在计算缓存时，退出了这个控制器，虽然这个cell销毁了，但是代码还是会运行，因为强引用指向的block不会暂停。用__weak typeof(self) weakSelf = self;可以解决这个问题。
离开一个界面时，正在进行的动画会因为uiwindow的离开而取消，解决的方法就是在每一次调用cell的单元格时，重新加载这个动画。
注册单元格分为代码和xib。 [self.tableView registerNib:[UINib nibWithNibName:NSStringFromClass([meOtherCell class]) bundle:nil] forCellReuseIdentifier:meOtherCellIden];;   
[self.tableView registerClass:[meSettingOtherCell class] forCellReuseIdentifier:meSettingOtherCellId];
开会的内容，新建了一个公众号：蝌蚪聚力。如何在线上更好的推广产品，要有一种主题，硬粉丝。
二维码分享的按钮，加上 关注之后、可以获得什么，这样给用户一个加关注的理由。
#2016.8.18
我们可以简单的将code snippet包含的文本内容修改为“#pragma mark – “即可。不过，这里还有更好的一个办法——将文本块封装到“<#” 和 “#>”中间，这样code snippet将指出我们可以插入自定义文本的完整范围。

#2016.8.19
熟悉教练端发现界面的代码。下个月开始接管教练端代码的维护。
学了两场讲座。关于公司的产品以及发展。另外就是学习了技术部的一些常见问题，在android端就是权限的问题。还有一个问题就是何时开始计时，何时结束，这是一个很麻烦的问题，有关很多情况。
    8.15～8.19周总结。
    周总结。这周学习了计算并清空缓存的方法，以及对清缓存单元格的封装。
    解决了使用三方库时编译错误的问题。
    学习了3场部门的讲座。
   
#2016.8.22
 
 教练端的代码，看完第3部分发现。
 ddcoach:
 userSafeViewController这个是以后打算用的？
#2016.8.23
常用的json序列化工具JsonKit,SBJson,TouchJson,NSJSONSerialization.从服务器收到的 json数据转为模型常用的框架有Mantle,JSONM。
当有一个APP的ipa时，可以用iOS Image Extractor提取出其中的图。
当一个控制器没有设背景色，tabbar出现这个时会移动一点，给人以延时的感觉，原来这是原生的特性。
 
#2016.8.24
通过stringByAppendingPathComponent，stringByAppendingString这2个方法可以得到路径，但是如果不小心出错，并没有提醒，使用NSString *documentsPath = [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) lastObject];
大多数文件夹都有枚举定义，个别没有的就需要拼接了。
   当模型要存储时，但是无法调用writeToFile时，就要用归档，反归档了。
    一个tabBarVc中有A,B，C,3个控制器，调用的方法顺序，如果是A切换到B，刚是：B viewDidLoad.B viewWillAppear.A viewWillDisappear. A viewDidDisAppear. B viewDidAppear. 当来回切换，view DidLoad 则不再调用。




本周练习：通讯录的代码写法。其中用了3种存储方法。


#2016.8.25
bool 类改写getter方法。getter = isVip.
如果用了autolayout. 则不可以用frame了。如果想要改，.通过storyboard拖线可以得到对应的约束。

#2016.8.26
uicollectionViewLayout作为父类，uicollectionFlowLayout多了更多的功能。
开会讲了下次进行推广的细节，大家都要了解一下客服的流程。
本周：看教练端的代码，看完第3部分发现。对法律模块字体进行修改。
学习了常用的json序列化工具。通讯录中存联系人的3种方法，顺，逆传值。
学习了collectionView的使用。

#2016.8.29  
Masonry现在都加上了mas前缀。
装箱：make.top.mas_equalTo(42)，不加mas就会出错。
纯代码写自动布局，不等高算定义cell 的时候，在算定义cell的setBlogModel方法时，对时有时无的图（微博有些没图，有些有图）在这里判断并分两种情况写上布局的改变。

#2016.8.30 
uicollectionView sectionInset可以设四周的边距；
minimumInteritemSpacing 设item之间的距离；
uicollectionViewController的头尾要通过代理来设置.
查找某个类可以用command+shift+o.

400电话客服的问题：武汉信呼通讯有限责任公司。可以连20个人的手机。
1.按顺序依次震铃，间隔可自定义，第一个绑定的电话没人接听或占线时即呼叫第一个绑定的电话，依次呼叫； 
2.在绑定的电话中随机选择一个电话震铃，如其占线，则随机呼叫另外一个绑定的电话；
3.绑定的电话同时震铃，直到其中一个电话接起电话为止。    
企业为了达到为客户提供24小时全天候的服务，也可以将不同的来电时间转接到不同的号码接听，比如工作时间将来电转接至公司座机、非工作时间可以转接至客服人员手机。这样确保了在任何时间下不错失任何一个电话，也体现了企业用户至上的服务理念。
向外拨打问题：联通的是买3年的套餐才可以向外拨打


#2016.8.31
launch screen file 可以省去不同尺寸的麻烦。
用uicollectionView,uiTAbleView的时候，如果横屏，刚左右两侧会空出很多地方，这是因为旋转的时候屏宽并没变。在uicollectionView中就可以用uicollectionViewFlowLayout来解决这个问题。

#2016.9.1
tabbar Image的图过大无法显示,会变成一个方块
要自定义tabBar才可解决这个问题.
1.自定义tabBar.2自定义UIView代替tabBar
因为即使自定义了tabBar,依然是tabBar，所以用uiview可以有其他的优势。

在ARC中，没有被强引用的何时被销毁？
并不会马上被销毁，在下一次运行循环到来时，看哪些没有强引用，才会被销毁。


#2016.9.2
搜索到很多结果时，google选中一个只会转到另一个界面，并不会重新打开一个标签，command+k之后再按可以解决这个问题。
封装不同的类，用代理更方便进行相与之前的联系。uitableView,uiScrollView都用代理，统一性更好，扩展性更好。

本周的总结：
学习了uicollectionView;masonry框架，这在蝌蚪两款产品中应用广泛。
解决了400只有梦瑶一个客服的问题。

#2016.9.5
重写tabBar用uiView的话，要先把tabBar移除，才可以显示出来算定义的uiView;

400电话绑定，联系：QQ:130950400.TELL:18986228758；88863803。需要绑定的手机的发票，发给400服务商就可以把这个手机号绑定。

#2016.9.6
在uinavigationcontroller中得到其他的uinavigationBar.可以用[uinavigationBar appearance]，这个可以改变所有的uinavigationBar的颜色。但是实际只要改变一部分，就可以用uinavigationBar appearanceWehnContainedInInstancesOfClasses:self];
init方法在其和子类中都会调用。如果只想调用一次，刚要判断其是不是为父类。
蒙版中加入uiview,其透明度都是一样的，分开写可以让只有其中一个是透明的。
代理可以让类之前更加低耦合。

#2016.9.7
block在ARC中，要定义为strong，才不会被销毁。非arc中没有strong,weak，要用copy. 

为了方便等到uiview的width,height,x,y，可以写uiview的分类，上一个百思项目是都是一个个写的定义，其实可以写property，这样就自动生成了声名，只要自己实现一下方法就可以了。

#2016.9.8
uisegment.tintcolor是分割线有颜色。
discover界面用storyboard来写。
当定义一个button有imageView,title的时候，如果要多次发动这个文字内容，每次都要sizeToFit，可以重写setTitle方法，把sizeToFit写在这里边。  
#2016.9.9
QZ周一发布的APP已上架。
从git上pull的时候，提示：
kangMac:DDCoach kqy$ git pull origin master
remote: Counting objects: 18, done.
remote: Compressing objects: 100% (18/18), done.
remote: Total 18 (delta 14), reused 0 (delta 0)
Unpacking objects: 100% (18/18), done.
From git.oschina.net:A3dexam/DDCoach
 * branch            master     -> FETCH_HEAD
   c6551ba..9059e43  master     -> origin/master
Updating c6551ba..9059e43
error: Your local changes to the following files would be overwritten by merge:
	DDCoach/DDCoach.xcodeproj/project.pbxproj
	DDCoach/DDCoach/Classes/Me-我的/Info-个人信息/UserInfoCell.xib
Please, commit your changes or stash them before you can merge.
Aborting

当转到kqy 分支时。
error: you need to resolve your current index first
好像上一次因为和master不同步，一直没管他了，原来这里有错导致后边总是出错。
git：回退到上一个版本：
git reset --hard HEAD^^
然后在 kqy分支中pull master 就可以得到最新的同步，现在在kqy，在这里改，提交到kqy即可。


conflict:
order:writeorder viewcontroller
205行有错。
/Users/kqy/Desktop/A3dexam-qianzhen/A3dexam/A3dexam/A3dexam/Classes/Order-订单/View/WriteOrderTableViewCell.xib
Line 40:startTag: invalid element name
xib冲突：原来用textEdit打开可以改冲突。
<<<<<<< HEAD
                    <label opaque="NO" userInteractionEnabled="NO" contentMode="left" horizontalHuggingPriority="251" verticalHuggingPriority="251" misplaced="YES" text="" textAlignment="natural" lineBreakMode="tailTruncation" baselineAdjustment="alignBaselines" adjustsFontSizeToFit="NO" translatesAutoresizingMaskIntoConstraints="NO" id="hnm-ox-bpY">
                        <rect key="frame" x="110" y="10" width="459" height="39"/>
                        <fontDescription key="fontDescription" type="system" pointSize="17"/>
=======
                    <label opaque="NO" userInteractionEnabled="NO" contentMode="left" horizontalHuggingPriority="251" verticalHuggingPriority="251" text="" textAlignment="natural" lineBreakMode="tailTruncation" baselineAdjustment="alignBaselines" adjustsFontSizeToFit="NO" translatesAutoresizingMaskIntoConstraints="NO" id="hnm-ox-bpY">
                        <rect key="frame" x="110" y="10" width="459" height="43"/>
                        <fontDescription key="fontDescription" type="system" pointSize="14"/>
>>>>>>> a064d3730a6a017e0f8c5fbebf8fadc7f85b8d40


日志：冲突时可以回退：git reset --hard HEAD^^
Line 40:startTag: invalid element name
xib冲突：原来用textEdit打开可以改冲突。
周总结：修改关于我们界面箭头的颜色，全局统一；
版本介绍后没有界面，取消箭头；
引导页面第4页为空，删除这个空白页。
#2016.9.11
看完彩票第2天的隐藏tabbar。
data:
完成蝌蚪聚力公众号简单的自动回复。
选择以后为做公众号学习的内容：h4,css,js,h5,php等计划。
