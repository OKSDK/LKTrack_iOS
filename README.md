# 统计SDK
----
### 一、统计SDK文件
>游戏或app接入统计SDK，需将压缩包中的文件libLKTrack.a和LKTrack.h添加到自己工程目录下，其中需注意配置文件lkstatis.cfg（如果不放配置文件默认用中国大陆的服务器），当中url字段为统计服务器地址,每个国家或地区url都不相同,请将对应地区的配置文件添加到工程中。
### 二、添加必要的库文件
>统计sdk依赖于OKSDK的KMToolBox.framework，如果工程中未添加此文件，则需要将下图文件添加到工程中，如果在接入OKSDK时已添加过，则只需替换即可。
![avatar](http://oscsfqu9d.bkt.clouddn.com/%E5%9B%BE%E7%89%87%202.png)
### 三、接口
>接口名以及参数都以宏定义，如果非OC原生工程调用接口过程中传递宏名不方便，也可直接传递宏定义的字符串，如：
```objective-c
	NSMutableDictionary *mutable_Dic = [NSMutableDictionary dictionary];
	[mutable_Dic setInstance:@"345" ForKey:LKEventParamChannelId];
	[mutable_Dic setInstance:@"12345345" ForKey:LKEventParamAdId];
	[mutable_Dic setInstance:@"180" ForKey:LKEventParamGameId];
	[[LKTrack shareInstance] eventTrackWithEventType:LK_TRACK_ACTIVE andEventValue:mutable_Dic];
```
>等价于
```objective-c
	NSMutableDictionary *mutable_Dic = [NSMutableDictionary dictionary];
	[mutable_Dic setInstance:@"345" ForKey:@”lk_track_channel_id”];
	[mutable_Dic setInstance:@"12345345" ForKey:@”lk_track_ad_id”];
	[mutable_Dic setInstance:@"180" ForKey:@”lk_track_game_id"];
	[[LKTrack shareInstance] eventTrackWithEventType:@”lk_sdk_active” andEventValue:mutable_Dic];
```
<font color=red>文档以下说明均以宏名表示字段名</font>

1. 激活（必接)  
eventType: LK\_TRACK\_ACTIVE  
eventValue:

 参数名 | 类型 | 描述
 ----|------|----
 LKEventParamChannelId | String  | 渠道id
 LKEventParamAdId | String  | 蓝港广告ID，可传空
 LKEventParamGameId | String  | 游戏ID
 LKEventParamAppId | String | 统计平台分配的appid
 
 示例：
 ```objective-c
    NSMutableDictionary *mutable_Dic = [NSMutableDictionary dictionary];
    [mutable_Dic setInstance:@"345" ForKey:LKEventParamChannelId];
    [mutable_Dic setInstance:@"12345345" ForKey:LKEventParamAdId];
    [mutable_Dic setInstance:@"180" ForKey:LKEventParamGameId];
    [mutable_Dic setInstance:@"ios_app_1" ForKey:LKEventParamAppId];
    [mutable_Dic setInstance:@"1080TI" ForKey:LKEventParamGPUModel];
    [mutable_Dic setInstance:@"8G" ForKey:LKEventParamGPUMemorySize];
    [mutable_Dic setInstance:@"1.3.5" ForKey:LKEventParamGPUVersion];
    [[LKTrack shareInstance] eventTrackWithEventType:LK_TRACK_ACTIVE andEventValue:mutable_Dic];
  ```
 
2. 登录（必接)【成功、失败、取消】  
eventType: LK\_TRACK\_LOGIN\_SUCCESS  、LK\_TRACK\_LOGIN\_FAILURE  、LK\_TRACK_LOGIN\_CANCEL  
eventValue:  

 参数名 | 类型 | 描述
 ----|------|----
 LKEventParamPassportId | String  | 游戏内的userid
 LKEventParamPassportName | String  | 游戏内的username
 LKEventParamPassportType | String  | 账号类型
 LKEventParamPassportBalance | String  | 账号余额
 
 示例：
```objective-c
     NSMutableDictionary *mutable_Dic = [NSMutableDictionary dictionary];
    [mutable_Dic setInstance:self.lkAdId ForKey:LKEventParamAdId];
    [mutable_Dic setInstance:[resultDic objectForKey:@"userId"] ForKey:LKEventParamPassportName];
    [mutable_Dic setInstance:nil ForKey:LKEventParamPassportId];
    [mutable_Dic setInstance:nil ForKey:LKEventParamPassportType];
    [mutable_Dic setInstance:nil ForKey:LKEventParamPassportBalance];
    [[LKTrack shareInstance] eventTrackWithEventType:LK_TRACK_LOGIN_SUCCESS andEventValue:@""];
```

3. 创建角色（必接）  
eventType: LK\_TRACK\_CREATE\_ROLE  
eventValue:

 参数名 | 类型 | 描述
 ----|------|----
 LKEventParamServerId | String  | 区服id
 LKEventParamServerName | String  | 区服名称
 LKEventParamRoleId | String  | 角色id
 LKEventParamRoleName | String  | 角色名称
 LKEventParamCreateRoleTime | String  | 创建角色时间
 LKEventParamRoleCareer | String  | 角色职业
 LKEventParamRoleGender | String  | 角色性别
 
 示例：
  ```objective-c
     NSMutableDictionary *m_Dictionary = [NSMutableDictionary dictionary];
    [m_Dictionary setInstance:[paramDic objectForKey:@"roleId"] ForKey:LKEventParamRoleId];
    [m_Dictionary setInstance:[paramDic objectForKey:@"roleName"] ForKey:LKEventParamRoleName];
    [m_Dictionary setInstance:[paramDic objectForKey:@"serverId"] ForKey:LKEventParamServerId];
    [m_Dictionary setInstance:[paramDic objectForKey:@"serverName"] ForKey:LKEventParamServerName];
    [m_Dictionary setInstance:[paramDic objectForKey:@"createRoleTime"] ForKey:LKEventParamCreateRoleTime];
    [m_Dictionary setInstance:[paramDic objectForKey:@"roleCareer"] ForKey:LKEventParamRoleCareer];  
    [m_Dictionary setInstance:[paramDic objectForKey:@"roleGender"] ForKey:LKEventParamRoleGender];  
    [[LKTrack shareInstance] eventTrackWithEventType:LK_TRACK_CREATE_ROLE andEventValue:m_Dictionary];
 ```
 
4. 进入游戏（必接）  
eventType: LK\_TRACK\_ENTER\_GAME  
eventValue:

 参数名 | 类型 | 描述
 ----|------|----
 LKEventParamServerId | String  | 区服id
 LKEventParamServerName | String  | 区服名称
 LKEventParamRoleId | String  | 角色id
 LKEventParamRoleName | String  | 角色名称
 LKEvetnParamRoleLevel | String  | 角色等级
 LKEventParamCreateRoleTime | String  | 创建角色时间
 LKEventParamRoleBalance | String  | 角色余额
 LKEventParamRoleCareer | String  | 角色职业
 LKEventParamRoleGender | String  | 角色性别
 LKEventParamRoleFaction | String  | 角色阵营
 LKEventParamRoleUnion | String  | 角色帮会
 
 示例：
 ```objective-c
      NSMutableDictionary *mutable_Dic = [NSMutableDictionary dictionary];
    [mutable_Dic setInstance:@"98777" ForKey:LKEventParamServerId];
    [mutable_Dic setInstance:@"永恒一服" ForKey:LKEventParamServerName];
    [mutable_Dic setInstance:@"1234" ForKey:LKEventParamRoleId];
    [mutable_Dic setInstance:@"狂拽酷炫" ForKey:LKEventParamRoleName];
    [mutable_Dic setInstance:@"99" ForKey:LKEvetnParamRoleLevel];
    [mutable_Dic setInstance:@"2017-05-15" ForKey:LKEventParamCreateRoleTime];
    [mutable_Dic setInstance:@"99" ForKey:LKEventParamRoleBalance];
    [mutable_Dic setInstance:@"剑魂" ForKey:LKEventParamRoleCareer];
    [mutable_Dic setInstance:@"男" ForKey:LKEventParamRoleGender];
    [mutable_Dic setInstance:@"冒险家" ForKey:LKEventParamRoleFaction];
    [mutable_Dic setInstance:@"第一帮会" ForKey:LKEventParamRoleUnion];
    NSString *str = [self dataTojsonString:mutable_Dic];
    [[LKTrack shareInstance] eventTrackWithEventType:LK_TRACK_ENTER_GAME andEventValue:str];
```

5. 角色升级（必接）  
eventType: LK\_TRACK\_ROLE\_UPGRADE  
eventValue:

 参数名 | 类型 | 描述
 ----|------|----
 LKEvetnParamRoleLevel | String  | 角色等级
 LKEventParamRoleBalance | String  | 角色余额
 LKEventParamRoleFaction | String  | 角色阵营
 LKEventParamRoleUnion | String  | 角色帮会
 
 示例：
```objective-c
    NSMutableDictionary *mutable_Dic = [NSMutableDictionary dictionary];
    [mutable_Dic setInstance:@"35" ForKey:LKEvetnParamRoleLevel];
    [mutable_Dic setInstance:@"部落" ForKey:LKEventParamRoleFaction];
    [mutable_Dic setInstance:@"魔法少女协会" ForKey:LKEventParamRoleUnion];
    [mutable_Dic setInstance:@"9999999" ForKey:LKEventParamRoleBalance];
    [[LKTrack shareInstance] eventTrackWithEventType:LK_TRACK_ROLE_UPGRADE andEventValue:mutable_Dic];

```

6. 支付【成功、失败、取消】  
eventType: LK\_TRACK\_PURCHASE\_SUCCESS、LK\_TRACK\_PURCHASE\_FAILURE、LK\_TRACK\_PURCHASE\_CANCEL  
eventValue:

 参数名 | 类型 | 描述
 ----|------|----
 LKEventParamMoneyAmount | String  | 付费金额
 LKEventParamProductName | String  | 商品名称
 LKEventParamProductId | String  | 商品id
 
 示例：
```objective-c
	NSMutableDictionary *mutable_Dic = [NSMutableDictionary dictionary];
	[mutable_Dic setInstance:_amount ForKey:LKEventParamMoneyAmount];
	[mutable_Dic setInstance:_productName ForKey:LKEventParamProductName];
	[mutable_Dic setInstance:_productId ForKey:LKEventParamProductId];
	[[LKTrack shareInstance] eventTrackWithEventType:LK_TRACK_PURCHASE_SUCCESS andEventValue:mutable_Dic];
```

7. 登出（必接）  
eventType: LK\_TRACK\_LOGOUT  
eventValue:

 参数名 | 类型 | 描述
 ----|------|----
 LKEventParamMoney1 | String  | 当前下线时的金钱数1
 LKEventParamMoney2 | String  | 当前下线时的金钱数2
 LKEventParamExperience | String  | 当前经验值
 
 示例：
 
```objective-c
    NSMutableDictionary *mutable_Dic = [NSMutableDictionary dictionary];
    [mutable_Dic setInstance:@"325" ForKey:LKEventParamMoney1];
    [mutable_Dic setInstance:@"310" ForKey:LKEventParamMoney2];
    [mutable_Dic setInstance:@"988000 " ForKey:LKEventParamExperience];
    [[LKTrack shareInstance] eventTrackWithEventType:LK_TRACK_LOGOUT andEventValue:nil];
```

8. 自定义事件  
eventType: LK\_TRACK\_CUSTOM  
eventValue:

 参数名 | 类型 | 描述
 ----|------|----
 LKEventParamCustomInfo | String  | 自定义参数（json字符串）
 
 示例：
 ```objective-c
     NSMutableDictionary *mutable_Dic = [NSMutableDictionary dictionary];
     [mutable_Dic setInstance:@"{\"eventName\":\"这是一个自定义事件\"}" ForKey:LKEventParamCustomInfo];
     [[LKTrack shareInstance] eventTrackWithEventType:LK_TRACK_CUSTOM andEventValue:mutable_Dic];
```

9. 进入关卡（必接）  
eventType: LK\_TRACK\_PASS\_ENTER  
eventValue:

 参数名 | 类型 | 描述
 ----|------|----
 LKEventParamEnterTime | String  | 进入关卡时间
 LKEventParamPassId | String  | 关卡ID（如：坐骑副本，装备副本）
 LKEventParamKey1 | String  | 预留字段1
 LKEventParamKey2 | String  | 预留字段2
 LKEventParamKey3 | String  | 预留字段3
 
 示例：
```objective-c
     NSMutableDictionary *mutable_Dic = [NSMutableDictionary dictionary];
    [mutable_Dic setInstance:@"2017-06-26" ForKey:LKEventParamEnterTime];
    [mutable_Dic setInstance:@"123" ForKey:LKEventParamPassId];
    [mutable_Dic setInstance:@"99" ForKey:LKEventParamKey1];
    [mutable_Dic setInstance:@"98" ForKey:LKEventParamKey2];
    [mutable_Dic setInstance:@"97" ForKey:LKEventParamKey3];
    NSString *str = [self dataTojsonString:mutable_Dic];
    [[LKTrack shareInstance] eventTrackWithEventType:LK_TRACK_PASS_ENTER andEventValue:str];
  ```
10. 完成关卡（必接）  
eventType: LK\_TRACK\_PASS\_RESULT  
eventValue:

 参数名 | 类型 | 描述
 ----|------|----
 LKEventParamEnterTime | String  | 进入关卡时间
 LKEventParamResultTime | String  | 完成关卡时间
 LKEventParamPassId | String  | 关卡ID（如：坐骑副本，装备副本）
 LKEventParamKey1 | String  | 预留字段1
 LKEventParamKey2 | String  | 预留字段2
 LKEventParamKey3 | String  | 预留字段3
 LKEventParamResultId | String  | 结果，如：1 - 成功；2 - 失败
 
 示例：
```objective-c
    NSMutableDictionary *mutable_Dic = [NSMutableDictionary dictionary];
    [mutable_Dic setInstance:@"2017-06-26" ForKey:LKEventParamEnterTime];
    [mutable_Dic setInstance:@"2017-06-26" ForKey:LKEventParamResultTime];
    [mutable_Dic setInstance:@"123" ForKey:LKEventParamPassId];
    [mutable_Dic setInstance:@"1" ForKey:LKEventParamResultId];
    [mutable_Dic setInstance:@"99" ForKey:LKEventParamKey1];
    [mutable_Dic setInstance:@"98" ForKey:LKEventParamKey2];
    [mutable_Dic setInstance:@"97" ForKey:LKEventParamKey3];
    NSString *str = [self dataTojsonString:mutable_Dic];
    [[LKTrack shareInstance] eventTrackWithEventType:LK_TRACK_PASS_RESULT andEventValue:str];
```
    
11. 固定事件（必接）  
eventType: LK\_TRACK\_FIXED\_EVENT  
eventValue:

 参数名 | 类型 | 描述
 ----|------|----
 LKEventParamEventGid | String  | 事件ID
 LKEventParamEventPid | String  | 事件父ID
 LKEventParamEventDesc | String  | 事件描述
 
示例：（图中为BIController传的参数，因为捉妖已经接过BIController，可以不用修改直接传，其他游戏只用传上表中三个字段即可）
```objective-c
    NSMutableDictionary *mutable_Dic = [NSMutableDictionary dictionary];
    [mutable_Dic setInstance:@"123" ForKey:LKEventParamGameId];
    [mutable_Dic setInstance:@"246" ForKey:LKEventParamServerId];
    [mutable_Dic setInstance:@"123141243" ForKey:LKEventParamPassportId];
    [mutable_Dic setInstance:@"1241234" ForKey:LKEventParamRoleId];
    [mutable_Dic setInstance:@"234" ForKey:LKEventParamEventGid];
    [mutable_Dic setInstance:@"234" ForKey:LKEventParamEventPid];
    [mutable_Dic setInstance:@"这是一个事件" ForKey:LKEventParamEventDesc];
    NSString *str = [self dataTojsonString:mutable_Dic];
    [[LKTrack shareInstance] eventTrackWithEventType:LK_TRACK_FIXED_EVENT andEventValue:str];
```
 
12. 日常运营活动  
eventType: LK\_TRACK\_SDK\_ACTIVITY  
eventValue:

 参数名 | 类型 | 描述
 ----|------|----
 LKEventParamActivityTime | String  | 参与活动时间，每变动一次记录一次
 LKEventParamActivityId | String  | 活动ID
 LKEventParamActivityType1 | String  | 活动子类型1（如：日常、运营、商业化）
 LKEventParamActivityType2 | String  | 活动子类型2（如：日常充值活动中A活动）
 LKEventParamActivityType3 | String  | 活动子类型3（如：日常充值活动中A活动下的A1项目）
 LKEventParamOperationType | String  | 操作类型（1 - 查看；2 - 参加；3 - 完成）
 LKEventParamKey1 | String  | 预留字段1
 LKEventParamKey2 | String  | 预留字段2
 LKEventParamKey3 | String  | 预留字段3
 
   示例：
```objective-c
    NSMutableDictionary *mutable_Dic = [NSMutableDictionary dictionary];
    [mutable_Dic setInstance:@"2017-06-26" ForKey:LKEventParamActivityTime];
    [mutable_Dic setInstance:@"125" ForKey:LKEventParamActivityId];
    [mutable_Dic setInstance:@"129" ForKey:LKEventParamActivityType1];
    [mutable_Dic setInstance:@"128" ForKey:LKEventParamActivityType2];
    [mutable_Dic setInstance:@"127" ForKey:LKEventParamActivityType3];
    [mutable_Dic setInstance:@"1" ForKey:LKEventParamOperationType];
    [mutable_Dic setInstance:@"99" ForKey:LKEventParamKey1];
    [mutable_Dic setInstance:@"98" ForKey:LKEventParamKey2];
    [mutable_Dic setInstance:@"97" ForKey:LKEventParamKey3];
    NSString *str = [self dataTojsonString:mutable_Dic];
    [[LKTrack shareInstance] eventTrackWithEventType:LK_TRACK_SDK_ACTIVITY andEventValue:str];
```
    
13. 系统生命周期方法
请务必在游戏Xcode工程同名系统方法中调用
```objective-c
/*!
 *  接口预留系统方法
 *  在程序的启动的Appdelegate相应的代理方法里面调用
 */
/**
 *  程序加载完成
 *
 *  @param application
 *  @param launchOptions
 *
 *  @return
 */
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;
/**
 *  程序获得焦点
 *
 *  @param application
 */
- (void)applicationDidBecomeActive:(UIApplication *)application;
/**
 *  程序进入后台
 *
 *  @param application
 */
- (void)applicationDidEnterBackground:(UIApplication *)application;
/**
 *  程序跳转
 *
 *  @param application
 *  @param url
 *  @param sourceApplication
 *  @param annotation
 *
 *  @return
 */
- (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation;
/**
 *  程序销毁
 *
 *  @param application
 */
- (void)applicationWillTerminate:(UIApplication *)application;
```
### 四、附录（接口头文件）
```objective-c
//
//  LKTrack.h
//  OKSDKLK
//
//  Created by Madoka on 17/3/10.
//  Copyright © 2017年 zxq. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

// In app event names constants
#define LK_TRACK_ACTIVE           @"lk_sdk_active"              // 激活
#define LK_TRACK_LOGIN_SUCCESS    @"lk_sdk_login_success"       // 登录成功
#define LK_TRACK_LOGIN_FAILURE    @"lk_sdk_login_failure"       // 登录失败
#define LK_TRACK_LOGIN_CANCEL     @"lk_sdk_login_cancel"        // 登录取消
#define LK_TRACK_LOGOUT           @"lk_sdk_logout"              // 登出
#define LK_TRACK_CREATE_ROLE      @"lk_sdk_create_role"         // 创建角色
#define LK_TRACK_ENTER_GAME       @"lk_sdk_enter_game"          // 进入游戏
#define LK_TRACK_ROLE_UPGRADE     @"lk_sdk_role_upgrade"        // 角色升级
#define LK_TRACK_PURCHASE_SUCCESS @"lk_sdk_purchase_success"    // 支付成功
#define LK_TRACK_PURCHASE_FAILURE @"lk_sdk_purchase_failure"    // 支付失败
#define LK_TRACK_PURCHASE_CANCEL  @"lk_sdk_puchase_cancel"      // 支付取消
#define LK_TRACK_USE_ITEM         @"lk_sdk_use_item"            // 使用道具
#define LK_TRACK_REWARD           @"lk_sdk_reward"              // 奖励
#define LK_TRACK_CUSTOM           @"lk_sdk_custom"              // 自定义事件
#define LK_TRACK_PASS_ENTER       @"lk_sdk_pass_enter"          // 关卡----进入
#define LK_TRACK_PASS_RESULT      @"lk_sdk_pass_result"         // 关卡----结果
#define LK_TRACK_FIXED_EVENT      @"lk_sdk_fixed_event"         // 固定事件
#define LK_TRACK_SDK_ACTIVITY     @"lk_sdk_activity"            // 日常运营活动

// In app event parameter names
#define LKEventParamGameId          @"lk_track_game_id"             // gameId
#define LKEventParamCompanyId       @"lk_track_company_id"          // 公司Id
#define LKEventParamChannelId       @"lk_track_channel_id"          // 渠道Id
#define LKEventParamPassportId      @"lk_track_passport_id"         // 账号Id
#define LKEventParamPassportName    @"lk_track_passport_name"       // 账号名
#define LKEventParamPassportType    @"lk_track_passport_type"       // 账号类型
#define LKEventParamPassportBalance @"lk_track_passport_balance"    // 账号余额
#define LKEventParamServerId        @"lk_track_server_id"           // 服务器Id
#define LKEventParamServerName      @"lk_track_server_name"         // 服务器名称
#define LKEventParamRoleName        @"lk_track_role_name"           // 角色名
#define LKEventParamRoleId          @"lk_track_role_id"             // 角色Id
#define LKEvetnParamRoleLevel       @"lk_track_role_level"          // 角色等级
#define LKEventParamCreateRoleTime  @"lk_track_role_create_time"  // 角色创建时间
#define LKEventParamRoleUnion       @"lk_track_role_union"          // 角色公会&帮派
#define LKEventParamRoleBalance     @"lk_track_role_balance"        // 角色余额
#define LKEventParamRoleCareer      @"lk_track_role_career"         // 角色职业
#define LKEventParamRoleGender      @"lk_track_role_gender"         // 角色性别
#define LKEventParamRoleFaction     @"lk_track_role_faction"        // 角色阵营
#define LKEventParamMoneyAmount     @"lk_track_money_amount"        // 付费金额
#define LKEventParamProductName     @"lk_track_product_name"        // 商品名称
#define LKEventParamProductId       @"lk_track_product_id"          // 商品Id
#define LKEventParamMoney1          @"lk_track_money1"              //
#define LKEventParamMoney2          @"lk_track_money2"
#define LKEventParamExperience      @"lk_track_exprience"           // 经验值
#define LKEventParamAdId            @"lk_track_ad_id"               // 广告Id
#define LKEventParamCustomInfo      @"lk_track_customInfo"          // 自定义事件json
/*                  关卡进入事件参数                  */
#define LKEventParamAppId           @"lk_track_app_id"              // 应用Id
#define LKEventParamEnterTime       @"lk_track_enter_time"          // 进入关卡时间
#define LKEventParamPassId          @"lk_track_pass_id"             // 关卡Id
#define LKEventParamKey1            @"lk_track_key1"                // 预留字段1
#define LKEventParamKey2            @"lk_track_key2"                // 预留字段2
#define LKEventParamKey3            @"lk_track_key3"                // 预留字段3
/*                  关卡结果事件参数                  */
#define LKEventParamResultTime      @"lk_track_result_time"         // 关卡完成时间
#define LKEventParamResultId        @"lk_track_result_id"           // 关卡结果Id
/*                  固定事件参数                  */
#define LKEventParamEventGid        @"lk_track_event_gid"           // 事件Id
#define LKEventParamEventPid        @"lk_track_event_pid"           // 事件父Id
#define LKEventParamEventDesc       @"lk_track_event_desc"          // 事件描述
/*                  日常运营活动事件参数                  */
#define LKEventParamActivityTime    @"lk_track_product_activity_time"       // 参与活动时间
#define LKEventParamActivityId      @"lk_track_product_activity_id"         // 活动Id
#define LKEventParamRoleOccupation  @"lk_track_product_role_occupation"     // 角色职业
#define LKEventParamActivityType1   @"lk_track_product_activity_type1"      // 活动子类型1
#define LKEventParamActivityType2   @"lk_track_product_activity_type2"      // 活动子类型2
#define LKEventParamActivityType3   @"lk_track_product_activity_type3"      // 活动子类型3
#define LKEventParamOperationType   @"lk_track_operation_type"              // 操作类型
/*                  激活新增参数                  */
#define LKEventParamAppId           @"lk_track_app_id"                      // 蓝港分配的appId
#define LKEventParamGPUModel        @"lk_track_gpu_model"                   // GPU型号
#define LKEventParamGPUMemorySize   @"lk_track_gpu_memory_size"             // 显存
#define LKEventParamGPUVersion      @"lk_track_gpu_version"                 // GPU版本


@interface LKTrack : NSObject
/**
 *  单例
 *
 */
+ (instancetype)shareInstance;
/**
 *  事件追踪
 *
 *  @param eventType  事件类型
 *  @param eventValue 事件JSON
 */
- (void)eventTrackWithEventType:(NSString *)eventType andEventValue:(NSString *)eventStr;

/*!
 *  接口预留系统方法
 *  在程序的启动的Appdelegate相应的代理方法里面调用
 */
/**
 *  程序加载完成
 *
 *  @param application
 *  @param launchOptions
 *
 *  @return
 */
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;
/**
 *  程序获得焦点
 *
 *  @param application
 */
- (void)applicationDidBecomeActive:(UIApplication *)application;
/**
 *  程序进入后台
 *
 *  @param application
 */
- (void)applicationDidEnterBackground:(UIApplication *)application;
/**
 *  程序跳转
 *
 *  @param application
 *  @param url
 *  @param sourceApplication
 *  @param annotation
 *
 *  @return
 */
- (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation;
/**
 *  程序销毁
 *
 *  @param application
 */
- (void)applicationWillTerminate:(UIApplication *)application;

@end
```
