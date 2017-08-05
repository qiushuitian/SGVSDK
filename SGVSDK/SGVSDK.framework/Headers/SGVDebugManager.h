//
//  SGVDebugManager.h
//  Pods
//
//  Created by dengjian on 9/20/16.
//
//

#import <Foundation/Foundation.h>

extern NSString * const SGVDebugLogNotification;

/** log管理系统
 用于输出log
 */
@interface SGVDebugManager : NSObject

/** 打印info级别的log。
 */
+(void)logInfo:(NSString *)format, ...;

/** 打印严重错误级别的log。
 */
+(void)logFatal:(NSString *)format, ...;

/** 打印调试log。
 */
+(void)logDebug:(NSString *)format, ...;

@end
