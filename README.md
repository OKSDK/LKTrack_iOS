# 统计SDK
----
### 一、统计SDK文件

### 二、添加必要的库文件
>统计sdk依赖于OKSDK的KMToolBox.framework，如果工程中未添加此文件，则需要将下图文件添加到工程中，如果在接入OKSDK时已添加过，则只需替换即可。


### 三、info.plist配置

### 四、接口
>接口名以及参数都以宏定义，如果非OC原生工程调用接口过程中传递宏名不方便，也可直接传递宏定义的字符串，如：
```objective-c
	NSMutableDictionary *mutable_Dic = [NSMutableDictionary dictionary];
	[mutable_Dic setInstance:@"123" ForKey:LKEventParamCompanyId];
	[mutable_Dic setInstance:@"345" ForKey:LKEventParamChannelId];
	[mutable_Dic setInstance:@"12345345" ForKey:LKEventParamAdId];
	[mutable_Dic setInstance:@"180" ForKey:LKEventParamGameId];
	[[LKTrack shareInstance] eventTrackWithEventType:LK_TRACK_ACTIVE andEventValue:mutable_Dic];
```
>等价于
```objective-c
	NSMutableDictionary *mutable_Dic = [NSMutableDictionary dictionary];
	[mutable_Dic setInstance:@"123" ForKey:@“lk_track_company_id”];
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
 LKEventParamCompanyId | String  | 公司id
 LKEventParamChannelId | String  | 渠道id
 LKEventParamAdId | String  | 蓝港广告ID
 LKEventParamGameId | String  | 游戏ID
 
2. 登录（必接)【成功、失败、取消】  
eventType: LK\_TRACK\_LOGIN\_SUCCESS  、LK\_TRACK\_LOGIN\_FAILURE  、LK\_TRACK_LOGIN\_CANCEL  
eventValue:  

 参数名 | 类型 | 描述
 ----|------|----
 LKEventParamPassportId | String  | 游戏内的userid
 LKEventParamPassportName | String  | 游戏内的username
 LKEventParamPassportType | String  | 账号类型
 LKEventParamPassportBalance | String  | 账号余额

3. 创建角色（必接）  
eventType: LK\_TRACK\_CREATE\_ROLE  
eventValue:

 参数名 | 类型 | 描述
 ----|------|----
 LKEventParamPassportId | String  | 游戏内的userid
 LKEventParamPassportName | String  | 游戏内的username
 LKEventParamPassportType | String  | 账号类型
 LKEventParamPassportBalance | String  | 账号余额
 LKEventParamServerId | String  | 区服id
 LKEventParamServerName | String  | 区服名称
 LKEventParamRoleId | String  | 角色id
 LKEventParamRoleName | String  | 角色名称
 LKEvetnParamRoleLevel | String  | 角色等级
 LKEventParamCreateRoleTime | String  | 创建角色时间
 LKEventParamDelRoleTime | String  | 删除角色时间
 LKEventParamRoleBalance | String  | 角色余额
 LKEventParamRoleCareer | String  | 角色职业
 LKEventParamRoleGender | String  | 角色性别
 LKEventParamRoleFaction | String  | 角色阵营
 LKEventParamRoleUnion | String  | 角色帮会
 
4. 进入游戏（必接）  
eventType: LK\_TRACK\_ENTER\_GAME  
eventValue:

 参数名 | 类型 | 描述
 ----|------|----
 LKEventParamPassportId | String  | 游戏内的userid
 LKEventParamPassportName | String  | 游戏内的username
 LKEventParamPassportType | String  | 账号类型
 LKEventParamPassportBalance | String  | 账号余额
 LKEventParamServerId | String  | 区服id
 LKEventParamServerName | String  | 区服名称
 LKEventParamRoleId | String  | 角色id
 LKEventParamRoleName | String  | 角色名称
 LKEvetnParamRoleLevel | String  | 角色等级
 LKEventParamCreateRoleTime | String  | 创建角色时间
 LKEventParamDelRoleTime | String  | 删除角色时间
 LKEventParamRoleBalance | String  | 角色余额
 LKEventParamRoleCareer | String  | 角色职业
 LKEventParamRoleGender | String  | 角色性别
 LKEventParamRoleFaction | String  | 角色阵营
 LKEventParamRoleUnion | String  | 角色帮会
  
5. 角色升级（必接）  
eventType: LK\_TRACK\_ROLE\_UPGRADE  
eventValue:

 参数名 | 类型 | 描述
 ----|------|----
 LKEvetnParamRoleLevel | String  | 角色等级
 
6. 支付【成功、失败、取消】  
eventType: LK\_TRACK\_PURCHASE\_SUCCESS、LK\_TRACK\_PURCHASE\_FAILURE、LK\_TRACK\_PURCHASE\_CANCEL  
eventValue:

 参数名 | 类型 | 描述
 ----|------|----
 LKEventParamMoneyAmount | String  | 付费金额
 LKEventParamProductName | String  | 商品名称
 LKEventParamProductId | String  | 商品id
 
7. 登出（必接）  
eventType: LK\_TRACK\_LOGOUT  
eventValue:

 参数名 | 类型 | 描述
 ----|------|----
 LKEventParamMoney1 | String  | 当前下线时的金钱数1
 LKEventParamMoney2 | String  | 当前下线时的金钱数2
 LKEventParamExperience | String  | 当前经验值
  
8. 自定义事件  
eventType: LK\_TRACK\_CUSTOM  
eventValue:

 参数名 | 类型 | 描述
 ----|------|----
 LKEventParamCustomInfo | String  | 自定义参数（json字符串）
 
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
 
9. 完成关卡（必接）  
eventType: LK\_TRACK\_PASS\_RESULT  
eventValue:

 参数名 | 类型 | 描述
 ----|------|----
 LKEventParamResultTime | String  | 完成关卡时间
 LKEventParamPassId | String  | 关卡ID（如：坐骑副本，装备副本）
 LKEventParamKey1 | String  | 预留字段1
 LKEventParamKey2 | String  | 预留字段2
 LKEventParamKey3 | String  | 预留字段3
 LKEventParamResultId | String  | 结果，如：1 - 成功；2 - 失败
  
10. 固定事件（必接）  
eventType: LK\_TRACK\_FIXED\_EVENT  
eventValue:

 参数名 | 类型 | 描述
 ----|------|----
 LKEventParamEventGid | String  | 事件ID
 LKEventParamEventPid | String  | 事件父ID
 LKEventParamEventDesc | String  | 事件描述
示例：（图中为BIController传的参数，因为捉妖已经接过BIController，可以不用修改直接传，其他游戏只用传上表中三个字段即可）
 
11. 日常运营活动  
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

