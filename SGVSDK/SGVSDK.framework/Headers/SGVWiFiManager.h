//
//  SGVWiFiConnectManager.h
//  Pods
//
//  Created by dengjian on 8/30/16.
//
//

#import <Foundation/Foundation.h>
#import "SGVResponse.h"


/**
 网络类型的枚举
 */
typedef NS_ENUM(NSInteger, SGVNetType){
    /// 未知网络类型
    SGVNetTypeUnknown                   = -1,
    /// 不可达类型
    SGVNetTypeUnReachable               = 0,
    /// SGV WiFi
    SGVNetTypeWiFiSGV                   = 1,
    /// SGV WiFi内网
    SGVNetTypeWiFiSGVInner              = 2,
    /// 普通 WiFi
    SGVNetTypeWiFiNormal                = 3,
    /// 2G/3G/4G
    SGVNetType2G3G4G                    = 4,
};


@interface SGVApPosInfo : NSObject

@property(nonatomic) NSInteger cityCode;    //城市编码
@property(nonatomic) NSInteger lineCode;    //线路编码
@property(nonatomic) NSInteger wType;       //AP位置类型
@property(nonatomic) NSInteger infoCode;    //站、车编号


@end

/**网速信息结构
 */
@interface SGVNetSpeedItem : NSObject

/// 网速，单位byte/s
@property(nonatomic) double speed;
@end

/**网速结果回调
 @param code 结果错误码
 @param speedItems 网速测试的结果集合。每个元素为SGVNetSpeedItem类型
 */
typedef void(^SGVSpeedResultBlock)(SGVRespCode code, NSArray * speedItems, double averageSpeed);

/**网速过程回调
 @param item 网速测试过程的回调信息
 */
typedef void(^SGVSpeedFeedbackBlock)(SGVNetSpeedItem * item);


/**网络可达检测
 @param canReach 可达结果
 */
typedef void(^SGVReachabilityResultBlock)(BOOL canReach);



typedef void(^SGVApPosInfoResultBlock)(SGVRespCode code, SGVApPosInfo * apInfo);


/**
 用户信息
 */
@interface SGVUser : NSObject
/// 用户手机号码
@property(nonatomic, copy) NSString * phoneNumber;
/// 用户tag。用于标示用户群组，比如等级。
@property(nonatomic, copy) NSString * tag;

/// 到站提醒站的站台 SGVSettedStation 结构。目前只支持1个提醒站
@property(nonatomic, strong) NSArray * tipStations;

@end


/**
 网络状态的枚举
 */
typedef NS_ENUM(NSInteger, SGVNetStatus){
    /// 未知网络状态
    SGVNetStatusUnknown                   = -1,
    /// 附着SGV WiFi 可以正常上网
    SGVNetStatusWiFiSGVReachable          = 0,
    
    /// 附着SGV WiFi 但是无法访问外网
    SGVNetStatusWiFiSGVUnReachable        = 1,
    
    /// 附着普通 WiFi 可以正常上网
    SGVNetStatusWiFiNormalReachable       = 2,
    
    /// 附着普通 WiFi 但是无法访问外网
    SGVNetStatusWiFiNormalUnReachable     = 3,
    
    /// 手机自带网络 2G/3G/4G
    SGVNetStatusVia2G3G4G                 = 4,

    /// WiFi开关关闭
    SGVNetStatusWiFiSwitchOff             = 5,
    /// 无网络 无网络或者不让app访问网络
    SGVNetStatusUnReachable               = 6,
};

///网络状态变更通知
extern NSString * kSGVNetStatusChangedNotification;
/// 网络状态变更通知带回的userinfo信息中 当前网络状态的key
extern NSString * kSGVNetStatusChangedNotifycationCurrNetStatusKey;
/// 网络状态变更通知带回的userinfo信息中 上一个网络状态的key
extern NSString * kSGVNetStatusChangedNotifycationLastNetStatusKey;


///实时网速通知
extern NSString * kSGVRealtimeNetSpeedNotification;
///实时网速通知带回的userinfo信息中 网络类型的key
extern NSString * kSGVRealtimeNetSpeedNotificationNetTypeKey;
///实时网速通知带回的userinfo信息中 网速的key。单位 byte/s
extern NSString * kSGVRealtimeNetSpeedNotificationNetSpeedKey;


///网络状况差通知
extern NSString * kSGVBadNetworkNotification;
///网络差的原因
extern NSString * kSGVBadNetworkNotificationReasonKey;




/**
 网络状况差的原因
 */
typedef NS_ENUM(NSInteger, SGVBadNetworkReason){
    /// 丢包严重
    SGVBadNetworkReasonLostTooMuch          = 1,
    /// 延迟严重
    SGVBadNetworkReasonDelayTooMuch         = 2,
    /// 信号弱
    SGVBadNetworkReasonSignalWeak           = 3,
    /// 信号弱
    SGVBadNetworkReasonSignalUnStable       = 4,
    /// 流量低
    SGVBadNetworkReasonFlowTooLittle        = 5,
};

/** WiFi管理类
 */
@interface SGVWiFiManager : NSObject


/// 网络状态
+(SGVNetStatus) netStatus;

/// 当前连接ssid名称
+(NSString *)currentSsid;

/// 判断是否连接SGV WiFi
+(BOOL)isConnectedSGVSsid;


/** 是否外网可达
 @param complete 网络可达的结果
 */
+(void)reachabilityDeteckComplete:(SGVReachabilityResultBlock)complete;

/** 是否WiFi开关开了
 */
+(BOOL)isWiFiSwitchOn;

/** 是否开启了VPN连接
 */
+(BOOL)isVPNConnected;

/** 流量统计查询
 @param type 网络类型
 @param fromDate 开始日期 默认今天 开始日期不能大于结束日期，否则返回空数组
 @param toDate 结束日期 默认今天
 */
+(NSArray *)netFlow:(SGVNetType)type
               from:(NSDate *)fromDate
                 to:(NSDate *)toDate
             ofUser:(SGVUser *)user;

+(void)startRealNetFlowDeteck;
+(void)stopRealNetFlowDeteck;
/** 开网
 @param user 开网的用户信息
 @param complete 开网的返回结果
    response 说明
    * code 需要处理通用错误和码值为11101开头的错误。
    * data 无数据。
 */
+(void)openNetForUser:(SGVUser *)user
             Complete:(void(^)(SGVResponse *response))complete;


/** 关网
 @abatract 关闭用户的花生网络。一般在用户退出时调用
 @param user 要关闭网络的用户信息
 */
+(void)closeNetForUser:(SGVUser *)user
              Complete:(void(^)(SGVResponse *response))complete;



/**上传测速
 @param feedback 网速测试过程的回调信息
 @param complete 网速测试完成的回调信息
 */
+(void)upLoadDeteckFeedback:(SGVSpeedFeedbackBlock)feedback
                   complete:(SGVSpeedResultBlock)complete;


/**下载测速
 @param feedback 网速测试过程的回调信息
 @param complete 网速测试完成的回调信息
 */
+(void)downLoadDeteckFeedback:(SGVSpeedFeedbackBlock)feedback
                     complete:(SGVSpeedResultBlock)complete;



/** 设置用户信息。登录的时候，设置用户。登出的时候，设置用户为nil

 */
+(void)setSGVUser:(SGVUser *)user;

/** 当前设置的用户信息
 */
+(SGVUser *)currSGVUser;


+(void)reqApPosInfoComplete:(SGVApPosInfoResultBlock)complete;



+(void)test;



@end
