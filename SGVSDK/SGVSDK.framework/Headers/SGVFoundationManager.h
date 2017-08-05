//
//  SGVFoundationManager.h
//  Pods
//
//  Created by dengjian on 9/12/16.
//
//

#import <Foundation/Foundation.h>



/** SDK配置
    SDK的配置信息请联系我们，由后台提供
 */
@interface SGVConfig : NSObject
/// 用于标识每个开发商的的key
@property(nonatomic, copy) NSString *appKey;
/// appSecret
@property(nonatomic, copy) NSString *appSecret;

/// hotspot 展示名字
@property(nonatomic, copy) NSString *hotspotDisplayName;

/// hotspot 通知字符串
@property(nonatomic, copy) NSString *hotspotNotifyTip;

/// 单例方法
+ (instancetype)shareInstance;
@end

/** SDK基础管理类
 */
@interface SGVFoundationManager : NSObject

/** SDK初始化
 @param config SDK配置
 @return 初始化成功，返回YES，否则返回NO
 */
+ (BOOL)startWithConfig:(SGVConfig *)config;


/** 获取SDK版本号
 @return 版本号字符串，格式如："2.1.3"
 */
+(NSString *)sdkVersion;

/** 开启debug模式
 @param onOff YES:开启debug模式，NO：关闭debug模式。 默认为NO
 */
+(void)setDebugMode:(BOOL)onOff;


/** 保存mac地址 保证SDK的mac地址和APP的mac地址同步
 @param mac mac地址
 */
+(void)saveMacAddress:(NSString *)mac;

@end
