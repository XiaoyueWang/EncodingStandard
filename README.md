# Welcome to the EncodingStandard wiki!
# EncodingStandard
#变量
1. 数据类型与变量名称之间留有一个空格
2. 变量名称使用驼峰命名法

	例子：
	
		NSString *URL;
		NSInteger flag;
		
3. 尽量使用属性代替全局变量，增强扩展性
4. CGFloat类型
	* 当小数点后数值为零时，可以省略，直接加单位`f`

		例子：
		
			button.layer.cornerRadius = 10.f;
	* 当小数点后数值不为零时，不要省略小数点后的数值以及单位`f`
	
		例子：
		
			self.backgroundColor = [UIColor colorWithWhite:0.5f alpha:0.4f];
5. NSArray

	例子：
		
		NSArray *array = @[@"协助部门", @"协助完成时间", @"协助内容"];

6. NSDictionary

	例子：
	
		NSDictionary *paramsDic = @{@"loginId":_loginId,
                            		@"serviceType":_servicetype,
                            		@"isYuejiFlag":_isYuejiFlag};


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
	![Alt text](https://github.com/XiaoyueWang/EncodingStandard/blob/master/image/property_1.png)

7.  定义block属性，对象回调的时候使用
 
	例子：

		typedef void (^ResultDataBlock)(NSDictionary *resultDic);
		@property (nonatomic, copy) ResultDataBlock resultDataBlock;
		
8.  公共属性定义在.h文件中，私有属性定义在.m文件中，减少头文件属性过多导致调用者不能快速定位属性的情况
 
	例子：

		//  CBMIfSolveView.h
		
		@interface CBMIfSolveView : UIView

		@property (nonatomic, strong) DealParams *dealParams;///< 参数model
		@property (nonatomic, strong) CRadioButton *isNeedAssistButton;///< 是否需要协助RadioButton
		@property (nonatomic, copy) NSString *expectedCompletionTime;///< 预计完成时间
		@property (nonatomic, copy) NSString *assistDep;///< 协助部门
		@property (nonatomic, copy) NSString *assistCompletionTime;///< 协助完成时间
		@property (nonatomic, copy) NSString *assistContent;///< 协助内容
		@property (nonatomic) CGFloat height;///< 高度

		@end
	---
		//  CBMIfSolveView.m
		
		@interface CBMIfSolveView () 

		@property (nonatomic, strong) UIButton *expectedCompletionTimeButton;///< 预计完成时间按钮
		@property (nonatomic, strong) UIButton *assistCompletionTimeButton;///< 协助完成时间按钮
		@property (nonatomic, strong) UIView *assistView;///< 协助视图按钮
		@property (nonatomic, strong) PickerView *assistDepPickerView;///< 协助部门按钮
		
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
		
5. 使用`({})`语法，对比下面两种写法，是不是第二种使用了`({})`语法代码更加模块化、更清晰？

	例子：
	
		// 是否转派
        UILabel *resendLabel = [[UILabel alloc] initWithFrame:CGRectMake(CHANGESIZE(30), CGRectGetMaxY(img.frame)+DEFSPACE, CHANGESIZE(140), CHANGESIZE(30))];
        resendLabel.font = FONT_MID;
        resendLabel.text = @"是否转派:";
    ---
	
		// 是否转派
        UILabel *resendLabel = ({
            UILabel *label = [[UILabel alloc] initWithFrame:({
                CGRectMake(CHANGESIZE(30), CGRectGetMaxY(img.frame)+DEFSPACE,
                           CHANGESIZE(140), CHANGESIZE(30));
            })];
            label.font = FONT_MID;
            label.text = @"是否转派:";
            label;
        });
        
	优势不明显？如果一段代码中有判断，使用`({})`语法的效果更加明显
	
	例子：
	
		// 是否解决视图
    	self.isSolveView.frame = ({
	        CGRect frame = CGRectZero;
	        if (_resendButton)
	            frame = CGRectMake(0, CGRectGetMaxY(_resendButton.frame)+DEFSPACE,
	                               CGRectGetWidth(self.frame), 0);
	        else
	            frame = CGRectMake(0, CGRectGetMaxY(img.frame)+DEFSPACE, CGRectGetWidth(self.frame), 0);
	        frame;
	    });
	
6. 方法参数过多时，要考虑代码的重构，实在避免不了的情况下，在调用的时候，要调整换行，保持参数对其

	例子：
	
		// 左侧取消按钮
        [self createDatePickerButtonWithFrame:CGRectMake(5.f, 5.f, 60.f, 20.f)
                                        Title:@"取消"
                              BackgroundColor:UIColorFromRGB(0xA4AAB0)
                                  NormalColor:[UIColor whiteColor]
                             HighlightedColor:[UIColor darkGrayColor]
                                       action:@selector(cancel) 
                                    SuperView:headView]; 

	
7. 注释：分为`无参数方法`和`有参数方法`

	无参数方法
	
	例子：
	
		/// 临时缓存目录，APP退出后，系统可能会删除这里的内容
		+ (NSString *)tmpPath;
	![Alt text](https://github.com/XiaoyueWang/EncodingStandard/blob/master/image/function_1.png)
	
	有参数方法
	
	例子：
	
		/**
		 *  责任部门数据处理
		 *
		 *  @param dic 服务端返回字典数据，key：branchCompanyDeptInfo、departmentInfo、comDeptPsnInfo
		 *
		 *  @return 数组，三个对象
		 */
		- (NSArray*)getResponsibilityDepDataWithDic:(NSDictionary*)dic;
			
#注释
> 良好的注释便于生成接口API文档

1. 变量：`/**< xxx */` 、 `///< xxx` 和 `/// xxx` 效果是一样的
	<p>一行代码不是很长，加注释也不需要换行，使用`///< xxx`
	<p>一行代码比较长时，加注释会换行，使用`/// xxx`
	
	例子：
		
		@property (nonatomic, strong) NSArray *dataArray; /**< 数据 */
		@property (nonatomic, strong) NSArray *dataArray; ///< 数据
		///< 数据 
		@property (nonatomic, strong) NSArray *dataArray;
	![Alt text](https://github.com/XiaoyueWang/EncodingStandard/blob/master/image/property_1.png)
2. 方法：分为`无参数方法`和`有参数方法`

	无参数方法
	
	例子：
	
		/// 临时缓存目录，APP退出后，系统可能会删除这里的内容
		+ (NSString *)tmpPath;
	![Alt text](https://github.com/XiaoyueWang/EncodingStandard/blob/master/image/function_1.png)
	
	有参数方法
	
	例子：
	
		/**
		 *  责任部门数据处理
		 *
		 *  @param dic 服务端返回字典数据，key：branchCompanyDeptInfo、departmentInfo、comDeptPsnInfo
		 *
		 *  @return 数组，三个对象
		 */
		- (NSArray*)getResponsibilityDepDataWithDic:(NSDictionary*)dic;
	
3. 类名：`/// xxx`

	例子：
	
		/// sandbox 帮助类
		@interface UCSandboxHelper : NSObject
	![Alt text](https://github.com/XiaoyueWang/EncodingStandard/blob/master/image/class_1.png)
	
#枚举
使用`typedef NS_ENUM(NSUInteger, name)`结构清晰

例子：

	typedef NS_ENUM(NSUInteger, CBCComponent) {
	    CBCComponentYear,
	    CBCComponentMonth,
	    CBCComponentDay
	};
		
	
#宏定义
格式：双下划线`__`+大写名称

例子：
	
	/// 获取屏幕宽度
	#define __SCREENWIDTH ([UIScreen mainScreen].bounds.size.width)
	
	/// 获取屏幕高度
	#define __SCREENHEIGHT ([UIScreen mainScreen].bounds.size.height)

详情[可以点这里](https://github.com/XiaoyueWang/EncodingStandard/blob/master/classes/CCommonMacroDefinition.h)

#杂项
1. 设置对象frame时，使用CG函数直接对frame进行取值

	例子：
	
		// 使用CG函数
		label.frame = ({
            CGRectMake(CGRectGetMinX(self.frame), CGRectGetMinY(self.frame),
                       CGRectGetWidth(self.frame), CGRectGetHeight(self.frame));
        });
        
        // 不要使用这种方法
		label.frame = ({
		    CGRectMake(self.frame.origin.x, self.frame.origin.y,
		               self.frame.size.width, self.frame.size.height);
		});

#目录结构
自定义的文件全部放到自定义的目录当中

1. 一级：类文件夹，`classes`
2. 二级：按照模块划分
3. 三级：按照MVVM架构划分，`model/view/viewModel`

	例子：
		![Alt text](https://github.com/XiaoyueWang/EncodingStandard/blob/master/image/directoryStructure_1.png)
		
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
