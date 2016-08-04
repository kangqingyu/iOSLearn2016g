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
  