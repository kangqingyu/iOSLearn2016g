#2016.8.1
Rm –rf fileName  删除文件夹及其文件.
跳到对应的括号：%.

自定义tabbar命令：[self setValue:[[kqyTabBar alloc] init] forKey:@"kqyTabBar"];
这个key不可以随便设值。
重写tabbar,layoutSubViews来设置子控件。
initWithFrame设tabbar背景图

pch的路径：fileNameos1/classes/others/PrefixHeader.pch 不可以多写/，不可写成：/fileNameos1/classes/others/PrefixHeader.pch