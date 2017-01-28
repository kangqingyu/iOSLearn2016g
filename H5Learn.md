H5 learn    

111
h5;html;


#2016.9.12
http://html5test.com/ 学习H5的网站。
http://w3school.com.cn/
网页的组成：HTML,CSS,JS.
meta charset="UTF-8"<h1>,<h5 > 五层标题
<input>也有placeholder,value两种属性。
type = color;type = date; type = file 
有调色板；日期选择；文件上传。
绝对路径：http://,ftp://,file://
相对路径:../../
<p>
<img src=可选相对，绝对路径。
超链接标签<a>,href=#为自己，用于回到顶部。
href="",加上target= _black可以重新打开一个网页。
列表：<ul>,<li>
<hr>换行分割线。
<div> 
h5新加的属性：
1.article可以作为新闻的框架。
2.progress 进度条。
css:
1.行内样式可以设字体颜色，大小。
2.页内样式：可以在head中统一设body,div等的颜色、字体。
3.外部样式：单独的CSS文件中书写，然后在网页中用link标签引用。

#2016.9.13
一、css标签选择器
1.标签选择器；
2.类选择器；   "."加上类名
3.id选择器;     “#”加上类名。
4.复合选择器
5.后代选择器： 只要是后代就可以。
6.直接后代选择器：必须是直接后代，孙子不可以。 div > p {}   就是改div中的直接p。
7.想邻兄弟选择器：div+p {color:red} ;与div相邻的p.
8.属性选择器： 
<div name = "jog">111</div>
9.伪类
10.伪元素。
在style中*{ color: red; }  *作为统配符。可以设body中所有颜色为红。性能低，一般不用。
二、css选择器的优先级：
1.相同级别的选择器，就近原则；2.叠加原则。
3.优先级：import > 行内 > id选择器 > 类选择器 〉 标签选择器。
类选择器，一个div可以有2个不同的类名，但是一个div不可以有2个不同的id。
HTML标签类型：
1.块级标签：独占一行的标签。
2.行内标签
3.行内-块级标签
