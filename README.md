# StudentManageSystem
Student manage system based on C. Developed by PhonnixS. @Beijing University of Chemical Technoly
<form>
	<structure>
		<h3>代码结构</h3>
		<p>
			|--main.c 	//主函数<br>
			|<br>
			|--student.h 	//定义Student类的头文件，包含相关函数声明<br>
			|<br>
			|--student.c 	//定义Student类相关函数<br>
			|<br>
			|--view.h<br>
			|<br>
			|--view.c<br>
			|<br>
			|--.......<br>
			1.结构体定义在头文件中，并以对象名命名，一般为名词性名称。例如学生信息定义在student.h文件中；<br>
			2.对结构体对象的操作函数定义在与头文件命名相同的.c文件中；<br>
			3.输出函数定义在view.h头文件中；<br>
			4.main函数中只调用逻辑函数而不定义，以实现数据对象、控制函数及视图分层，降低代码耦合度，提高可读性。<br><br>
			<h4>注：</h4>main函数引用外部函数的方法：<br>
			1.在头文件开头添加如下代码：<br>
				#ifndef __NAME_H		//将NAME换为相应文件名<br>
				#define __NAME_H							<br>
			2.在头文件结尾添加 #endif<br>
			3.直接在name.c中编写函数；<br>
			4.同时编译name.c和main.c。
		</p>
	</structure>
	<name>
		<h3>命名</h3>
		<p>
			0.除用于循环体内计数变量外，名称必须具有实际意义；<br>
			1.结构体名采用驼峰命名；<br>
			2.变量名采用小驼峰命名，结构体类型数据的变量名前添加"m_&lt变量类型简写&gt"前缀，指针类型加p。例如学生中的姓名属性定义为"char m_cpName[10];"；<br>
			3.函数名采用小驼峰命名，建议命名为“动词+指向结构体名”以提高代码可读性；例如添加学生记录函数定义为"void addStudent"。
		</p>
	</name>
	<comment>
		<h3>注释</h3>
		<p>
			1.文件开头必须声明作者与改文件功能的注释，格式如下：
			<br>
			/****************************************<br>
			* Author:<br>
			* Description:<br>
			****************************************/
			<br>
			2.函数定义前添加声明作者、函数功能、相关描述的注释，格式如下：
			<br>
			/****************************************<br>
			* Author:<br>
			* Function:<br>				
			* Description:<br>
			****************************************/
			<br>
			3.其他情况酌情添加注释。
		</p>
	</comment>
</form>
