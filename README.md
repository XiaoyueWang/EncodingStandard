# EncodingStandard
#变量
1. 数据类型与变量名称之间留有一个空格
2. 变量名称使用驼峰命名法

	例子：
	
		NSString *URL;
		NSInteger flag;
		
3. 尽量使用属性代替全局变量，增强扩展性
	
#属性
1.  `@property`与`()`之间留有一个空格
2.  关键字之间用`, `分割，注意逗号后的空格
3.  `()`与数据类型之间留有一个空

	例子：

		@property (nonatomic, strong) UIButton *submitButton;

4.  关键字书写顺序，按照
	* 原子性（`atomic`--默认、`nonatomic`）
	* 存储器控制（`readwrite`--默认、`readonly`），若`readwrite`可以省略
	* 内存管理（`assign`--默认、`retian`、`strong`、`weak`、`copy`）

	例子：

		//没有省略
		@property (nonatomic, readwrite, strong) UIButton *submitButton;
		@property (nonatomic, readwrite, copy) NSString *URL;
		@property (nonatomic, readonly, assign) NSInteger flag;
	
		//省略readwrite
		@property (nonatomic, strong) UIButton *submitButton;
		@property (nonatomic, copy) NSString *URL;
		@property (nonatomic, readonly, assign) NSInteger flag;

5.  `NSString、NSArray、NSDictionary、NSMutableArray、NSMutableDictionary`使用`copy`关键字，防止对象引用后，修改属性值对对象原始值的影响

	例子：

		@property (nonatomic, copy) NSString *URL;
		@property (nonatomic, copy) NSArray *dataArray;
		@property (nonatomic, copy) NSDictionary *dataDic;
		@property (nonatomic, copy) NSMutableArray *dataMutArray;
		@property (nonatomic, copy) NSMutableDictionary *dataMutDic;

6. 变量：`/**< xxx */` 、 `///< xxx` 和 `/// xxx` 效果是一样的
	<p>一行代码不是很长，加注释也不需要换行，使用///< xxx 
	<p>一行代码比较长时，加注释会换行，使用/// xxx
	
	例子：
		
		@property (nonatomic, strong) NSArray *dataArray; /**< 数据 */
		@property (nonatomic, strong) NSArray *dataArray; ///< 数据
		///< 数据 
		@property (nonatomic, strong) NSArray *dataArray;
	![Alt text](/image/property_1.png)

7.  定义block属性，对象回调的时候使用
 
	例子：

		typedef void (^ResultDataBlock)(NSDictionary *resultDic);
		@property (nonatomic, copy) ResultDataBlock resultDataBlock;
		
8.  公共属性定义在.h文件中，私有属性定义在.m文件中，减少头文件属性过多导致调用者不能快速定位属性的情况
 
	例子：

		//  CBMIfSolveView.h
		
		@interface CBMIfSolveView : UIView

		@property (nonatomic, strong) DealParams *dealParams;
		@property (nonatomic, strong) CRadioButton *isNeedAssistButton;
		@property (nonatomic, copy) NSString *expectedCompletionTime;
		@property (nonatomic, copy) NSString *assistDep;
		@property (nonatomic, copy) NSString *assistCompletionTime;
		@property (nonatomic, copy) NSString *assistContent;
		@property (nonatomic) CGFloat height;

		@end
	---
		//  CBMIfSolveView.m
		
		@interface CBMIfSolveView () 

		@property (nonatomic, strong) UIButton *expectedCompletionTimeButton;/**< 预计完成时间按钮 */
		@property (nonatomic, strong) UIButton *assistCompletionTimeButton;/**< 协助完成时间按钮 */
		@property (nonatomic, strong) UIView *assistView;/**< 协助视图按钮 */
		@property (nonatomic, strong) PickerView *assistDepPickerView;/**< 协助部门按钮 */
		
		@end

#方法
1. ‘-’与返回类型之间留有一个空格
2. 参数与‘{’之间留有一个空格
3. 参数明确数据类型，尽量不要使用‘id’

	例子：

		- (instancetype)init {
    		// your code ...
		}
		
		- (instancetype)initWithFrame:(CGRect)frame {
    		// your code ...
		}
		
4. 名称和参数名称意思要明确

	例子：
	
		- (void)radioButton:(CRadioButton *)radioButton didSelectButtonAtParam:(NSString *)param {
			// your code ...
		}
		
5. 注释：/// xxx

	例子：
	
		/// 临时缓存目录，APP退出后，系统可能会删除这里的内容
		+ (NSString *)tmpPath;
	![Alt text](/image/function_1.png)
		
#注释
1. 变量：`/**< xxx */` 、 `///< xxx` 和 `/// xxx` 效果是一样的
	<p>一行代码不是很长，加注释也不需要换行，使用`///< xxx`
	<p>一行代码比较长时，加注释会换行，使用`/// xxx`
	
	例子：
		
		@property (nonatomic, strong) NSArray *dataArray; /**< 数据 */
		@property (nonatomic, strong) NSArray *dataArray; ///< 数据
		///< 数据 
		@property (nonatomic, strong) NSArray *dataArray;
	![Alt text](/image/property_1.png)
2. 方法：`/// xxx`

	例子：
	
		/// 临时缓存目录，APP退出后，系统可能会删除这里的内容
		+ (NSString *)tmpPath;
	![Alt text](/image/function_1.png)
3. 类名：`/// xxx`

	例子：
	
		/// sandbox 帮助类
		@interface UCSandboxHelper : NSObject
	![Alt text](/image/class_1.png)
	
#宏定义
宏定义详情[点这里](http://example.net/)

#目录结构
自定义的文件全部放到自定义的目录当中

1. 一级：公司的组织架构，`com.bonc`
2. 二级：按照模块划分
3. 三级：按照MVVM架构划分，`model/view/viewModel`

	例子：
		![Alt text](/image/directoryStructure_1.png)
		
4. 业务逻辑处理尽量放到viewModel中，给controller和view瘦身
		
#结构化
使用‘#pragma mark - XXX’对代码进行逻辑划分，使代码阅读起来更加结构化

	#pragma mark - life cycle 			//生命周期
	#pragma mark - setter/getter 		//存储器
	#pragma mark - UI 					//UI方法
	#pragma mark - datasource/delegate //代理方法
	#pragma mark - helper 				//请求数据、事件、业务逻辑等方法
	
#注意事项
###公共
1. 每行代码尽量控制在80个字符以内，可以在Xcode进行设置`Page guide`
	
		Xcode -> Preferences... -> Text Editing -> Page guide at column:

###日志
1. 功能完成时，开发过程中的日志尽量注释或者删除
