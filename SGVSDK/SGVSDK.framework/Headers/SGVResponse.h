//
//  SGVResponse.h
//  SGVSDK
//
//  Created by dengjian on 2017/2/13.
//  Copyright © 2017年 dengjian. All rights reserved.
//

#import <Foundation/Foundation.h>

/**错误码
 错误码总共有9位，总共分为3段，分别如下：
    模块（2位） + 类别（3位） + 错误码（4位）
 每段的码值最高位从1开始，比如模块从10，11往下排，类别从100，101往下排。
 
 其中模块码值对应如下：
    模块 10      通用模块
        11      WiFi模块
        12      账户系统模块
 
 其他段的码值参考下面的注释，和具体业务相关。
 业务说明：
    对于接口返回的码值，需要处理的是通用码值（10模块）和自己的业务码值（相应接口类别的码值）。
 */
typedef NS_ENUM(NSInteger, SGVRespCode) {
    
    ///成功
    SGVRespCodeSuccess                                          = 101001000,
    ///无法连接到服务器
    SGVRespCodeNetConnectFailure                                = 101011001,
    ///网络超时
    SGVRespCodeNetTimeOut                                       = 101011002,
    ///其他网络错误
    SGVRespCodeNetError                                         = 101011003,
    ///参数错误
    SGVRespCodeParamError                                       = 101011004,

    ///非地铁WiFi，可认为开网成功
    SGVRespCodeOpenNetNotSGVWiFi                                = 111001001,
    ///开网失败
    SGVRespCodeOpenNetFailure                                   = 111001002,
    ///正在开网，多次调用开网接口，后面的调用返回这个
    SGVRespCodeOpenNetDealing                                   = 111011003,
    ///非地铁WiFi，可认为关网成功
    SGVRespCodeCloseNetNotSGVWiFi                               = 111001004,
    ///关网失败
    SGVRespCodeCloseNetFailure                                  = 111001005,

    
    ///检测上行网速失败
    SGVRespCodeDeteckUploadError                                = 111021001,
    ///检测下行网速失败
    SGVRespCodeDeteckDownloadError                              = 111021002,
    
    ///获取AP信息,无效的AP，未连接WiFi或取不到AP MAC信息
    SGVRespCodeGetAPInofoInvalidAP                              = 111031001,

};

/** 响应对象
 一般用于异步响应的接口，承载异步返回的数据和结果。
 */
@interface SGVResponse : NSObject

/// 响应码。具体码值参考 SGVRespCode 的说明。
@property(nonatomic) SGVRespCode code;
/// 响应的说明。
@property(nonatomic, copy) NSString * msg;
/// 响应返回的数据。根据具体的业务有不同的结果和结构。具体结构参考具体的请求接口说明。
@property(nonatomic, strong)NSDictionary * data;

@end
