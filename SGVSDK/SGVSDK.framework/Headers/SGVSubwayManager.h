//
//  SGVSubwayManager.h
//  SGVSDK
//
//  Created by jian deng on 29/06/2017.
//  Copyright © 2017 dengjian. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SGVResponse.h"

extern NSString * kSGVCurrStationNotification;
extern NSString * kSGVTipStationNearByNotification;
extern NSString * kSGVStationNotificationStationKey;

/**查询站台信息结果回调
 @param code 结果错误码
 @param stations 站台信息
 */
typedef void(^SGVStationResultBlock)(SGVRespCode code, NSArray * stations);
typedef void(^SGVCityResultBlock)(SGVRespCode code, NSArray * citys);





/**
 用户信息
 */
@interface SGVCity : NSObject
/// 城市编码
@property(nonatomic) NSInteger cityCode;
/// 城市名称
@property(nonatomic, copy) NSString * cityName;

@end


@interface SGVSettedStation : NSObject
@property(nonatomic) NSInteger cityCode;
@property(nonatomic) NSInteger stationCode;
@end

/**
 站台信息
 */
@interface SGVStation : NSObject
@property(nonatomic) NSInteger lineCode;                // 线路编号
@property(nonatomic,copy) NSString * lineName;          // 线路名称
@property(nonatomic) NSInteger stationCode;             // 站台编号
@property(nonatomic, copy) NSString * stationName;      // 站台名称
@property(nonatomic) BOOL isTipValid;                   // 是否支持到站提醒
@end




typedef void(^SGVPositionResultBlock)(SGVRespCode code, SGVStation * station);


@interface SGVSubwayManager : NSObject


/** 设置当前城市
 */
+(void)setCurrentCityCode:(NSInteger)cityCode;

/** 获取当前城市代码
 */
+(SGVCity *)currentCity;

/** SDK支持的城市
 */
+(NSArray *)supportedCitys;

/** 单站点查询
 */
+(SGVStation *)stationOfCurrCityByCode:(NSInteger)stationCode;
+(SGVStation *)stationByCode:(NSInteger)stationCode cityCode:(NSInteger)cityCode;

/** 所有站点
 */
+(NSArray *)allStationsOfCurrCity;

/** 查询站点信息
 */
+(void)searchStation:(NSString *)stationName complete:(SGVStationResultBlock)complete;

+(void)refreshSubwayInfo;


+(void)updatePositon;
+(void)updatePositionComplete:(SGVPositionResultBlock)complete;

@end
