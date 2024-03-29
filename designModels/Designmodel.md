面向对象最本质的就是在变化和不变化之间寻找平衡点
### 设计原则
#### 依赖倒置原则


高层模块不能依赖底层模块，二者都应依赖于抽象；抽象不能依赖实现细节，实现细节应该依赖于抽象
核心思想： 面向接口编程
问题由来： 类A直接依赖类B，假如要将类A改为依赖类C，则必须通过修改类A的代码来达成。这种场景下，类A一般是高层模块，负责复杂的业务逻辑；类B和类C是低层模块，负责基本的原子操作；假如修改类A，会给程序带来不必要的风险。
解决方案： 将类A修改为依赖接口I，类B和类C各自实现接口I，类A通过接口I间接与类B或者类C发生联系，则会大大降低修改类A的几率

#### 开放封闭原则
对扩展开放，对修改封闭
类模块应该是可扩展的但是不可修改
它强调的是你设计的模块应该从不改变。当需求变化时，你可以通过添加新的代码来扩展这个模块的行为，而不去更改那些已经存在的可以工作的代码。
思考策略模式

#### 单一职责原则
**定义**：不要存在多于一个导致类变更的原因。通俗的说，即一个类只负责一项职责。
**问题由来**：类T负责两个不同的职责：职责P1，职责P2。当由于职责P1需求发生改变而需要修改类T时，有可能会导致原本运行正常的职责P2功能发生故障。

**解决方案**:遵循单一职责原则。分别建立两个类T1、T2，使T1完成职责P1功能，T2完成职责P2功能。这样，当修改类T1时，不会使职责P2发生故障风险；同理，当修改T2时，也不会使职责P1发生故障风险。

**遵循单一职责原的优点有**:
* 可以降低类的复杂度，一个类只负责一项职责，其逻辑肯定要比负责多项职责简单的多；
* 提高类的可读性，提高系统的可维护性；
* 变更引起的风险降低，变更是必然的，如果单一职责原则遵守的好，当修改一个功能时，可以显著降低对其他功能的影响。

#### 里氏替换原则
任何需要父类的地方，子类传过去都能使用

#### 接口隔离原则
不应该强迫客户程序依赖它们不用的方法
接口应该小而完备

#### 优先使用对象组合，而不是类继承
因为在继承关系中子类父类的耦合度过高

#### 封装变化点


#### 针对接口编程，而不是针对实现编程


### 抽象工厂模式
#### 定义
提供一个创建一系列相关或相互依赖对象的接口，而无须指定它们具体的类。（ 在抽象工厂模式中，每一个具体工厂都提供了多个工厂方法用于产生多种不同类型的对象）

抽象工厂和工厂方法一样可以划分为4大部分：
* AbstractFactory（抽象工厂）声明了一组用于创建对象的方法，注意是一组。
* ConcreteFactory（具体工厂）：它实现了在抽象工厂中声明的创建对象的方法，生成一组具体对象。
* AbstractProduct（抽象产品）：它为每种对象声明接口，在其中声明了对象所具有的业务方法。
* ConcreteProduct（具体产品）：它定义具体工厂生产的具体对象。

#### 适用场景
* 客户端不需要知道他所创建对象的类，仅需要知道平台以及相关的接口即可
* 需要一组接口共同完成某种功能的时候,客户端每次使用的是一组对象
* 接口稳定，不会频繁地增加产品，或更改接口
比如：不同操作系统下程序；QQ换皮肤，一整套一起换

#### 注意问题
* 优点：当一个产品族中的多个对象被设计成一起工作时，能保证客户端始终只使用同一产品族中的对象
* 缺点：产品族拓展困难，不满足开闭原则

#### 实例






### 策略模式
包含四部分：
抽象策略
具体策略
抽象应用上下文
具体应用上下文

当代码中出现 if else时，而且未来随着时间增加，if的情况需要增加，这个时候需要改为策略模式
随着时间变化，情况可能会扩增
优点：符合扩展封闭原则，代码执行效率更高

### 观察者模式

又称为订阅者发布者模式
抽象观察者
具体观察者
抽象被观察者
具体被观察者
被观察者内部存在一个观察者基类的集合，如果有观察者

https://blog.csdn.net/itachi85/article/details/50773358



### 模板模式
写好框架，然后开发人员光提供具体子步骤的使用
不要调用库函数，而是让库调用我们的函数
可以用函数指针替代，muduo就是用的函数指针

